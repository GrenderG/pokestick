typedef enum {
  NOT_CONNECTED,
  CONNECTED,
  TRADE_CENTRE,
  COLOSSEUM
} connection_state_t;

typedef enum {
  INIT,
  READY_TO_GO,
  SEEN_FIRST_WAIT,
  SENDING_RANDOM_DATA,
  WAITING_TO_SEND_DATA,
  START_SENDING_DATA,
  SENDING_DATA,
  DATA_SENT
} trade_centre_state_t;

typedef unsigned char byte;

#define PKMN_BLANK                0x00

#define ITEM_1_HIGHLIGHTED        0xD0
#define ITEM_2_HIGHLIGHTED        0xD1
#define ITEM_3_HIGHLIGHTED        0xD2
#define ITEM_1_SELECTED           0xD4
#define ITEM_2_SELECTED           0xD5
#define ITEM_3_SELECTED           0xD6

#define PKMN_MASTER               0x01
#define PKMN_SLAVE                0x02
#define PKMN_CONNECTED            0x60
#define PKMN_WAIT                 0x7F

#define PKMN_ACTION               0x60

#define PKMN_TRADE_CENTRE         ITEM_1_SELECTED
#define PKMN_COLOSSEUM            ITEM_2_SELECTED
#define PKMN_BREAK_LINK           ITEM_3_SELECTED

#define TRADE_CENTRE_WAIT         0xFD

//Set up all the pins
int volatile CLOCK_PIN = 2;
int volatile SO_PIN = 4;
int volatile SI_PIN = 3;
int STATUS = 13;

byte volatile byte_in = 0x00;
byte volatile out_buffer = 0x00;
//A counter for the current clock cycle
int volatile clock_cycle = 0;
unsigned volatile long lastReceive = 0;
//Tracks the current state of the connection
volatile connection_state_t connection_state = NOT_CONNECTED;
//Tracks the current state of the trade
volatile trade_centre_state_t trade_centre_state = INIT;

void setup() {   
  //Setting up what all the pins will be doing             
  pinMode(SI_PIN, INPUT);
  pinMode(CLOCK_PIN, INPUT);
  pinMode(SO_PIN, OUTPUT);
  pinMode(STATUS, OUTPUT);
  digitalWrite(STATUS, LOW);
  digitalWrite(SO_PIN, LOW);
  digitalWrite(CLOCK_PIN, HIGH);
  digitalWrite( SI_PIN, HIGH);  
  //Attaching an interrupt to trigger whenever the clock pin reads high
  //attachInterrupt( digitalPinToInterrupt(CLOCK_PIN), clock_interrupt, RISING);
  Serial.begin(115200);
}

void clock_interrupt(void)
{
  //Serial.print("I");
  //Serial.print(digitalRead(SI_PIN));
  //Serial.print("\n");
  /*
  if(lastReceive > 0) {
    if( micros() - lastReceive > 120 ) {
      clock_cycle = 0;
      byte_in = 0x00;
    }
  }
  */
  byte_in <<= 1;  
  byte_in |= digitalRead(SI_PIN);
  //Serial.print("Unfinished Read Byte is 0x");
  //Serial.print(byte_in);
  //Serial.print("\n");
  if(clock_cycle > 7 )
  {
    //Reset the clock cycle and the current in byte
    Serial.print("rx");
    Serial.print(byte_in, HEX);
    Serial.print("\n");
    out_buffer = handle_in_byte(byte_in);
    Serial.print("tx");
    Serial.print(out_buffer, HEX);
    Serial.print("\n");
    byte_in = 0x00;
    clock_cycle = 0;
  }
  bool current_send_bit = out_buffer & 0x80;
  //Serial.print(current_send_bit);
  //while( ((digitalRead(CLOCK_PIN) | CLOCK_PIN) & CLOCK_PIN) == 0)
  //{
    digitalWrite(SO_PIN, current_send_bit);
  //}
  out_buffer <<= 1;
  //lastReceive = micros();
  clock_cycle++;
}

byte handle_in_byte(byte in)
{
  byte send = 0x00;
  switch(connection_state)
  {
    case NOT_CONNECTED:
      if(in == PKMN_MASTER)
      {
        send = PKMN_SLAVE;
        //Serial.print("s\n");
      }
      else if(in == PKMN_BLANK)
      {
        send = PKMN_BLANK;
        //Serial.print("b\n");
      }
      else if(in == PKMN_CONNECTED)
      {
        send = PKMN_CONNECTED;
        connection_state = CONNECTED;
        digitalWrite(STATUS, HIGH);
        //Serial.print("nc\n");
      }
      break;
      
    case CONNECTED:
      if(in == PKMN_CONNECTED)
      {
        send = PKMN_CONNECTED;
        //Serial.print("c\n");
      }
      else if(in == PKMN_TRADE_CENTRE)
      {
        connection_state = TRADE_CENTRE;
        //Serial.print("t\n");
      }
      else if(in == PKMN_COLOSSEUM)
      {
        connection_state = COLOSSEUM;
         //Serial.print("co\n");
      }
      else if(in == PKMN_BREAK_LINK || in == PKMN_MASTER) 
      {
        connection_state = NOT_CONNECTED;
        send = PKMN_BREAK_LINK;
        digitalWrite(STATUS, LOW);
        //Serial.print("br\n");
      } 
      else 
      {
        send = byte_in;
        //Serial.print("e\n");
      }
      break;
      
    default:
      send = byte_in;
      //Serial.print("le\n");
      break;
  }
  return send;
}
void loop() {
  while(digitalRead(CLOCK_PIN))
  clock_interrupt();
}
