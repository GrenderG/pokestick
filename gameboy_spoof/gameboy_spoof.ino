#include "gameboy_spoof.h"
#include "translators.h"
#include "pokemon_generator.h"

//Set up all the pins
#define CLOCK_PIN 2
#define MISO_PIN 3
#define MOSI_PIN 4
#define STATUS 13

byte volatile in_buffer = 0x00;
byte volatile out_buffer = 0x00;

int volatile clock_cycle = 0;
int volatile trade_counter = 0;

volatile connection_state_t connection_state = NOT_CONNECTED;
volatile trade_center_state_t trade_center_state = INIT;

void setup() {
  //Setting up what all the pins will be doing
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(CLOCK_PIN, INPUT);
  pinMode(STATUS, OUTPUT);
  digitalWrite(MOSI_PIN, HIGH);
  digitalWrite(MISO_PIN, LOW);
  digitalWrite(CLOCK_PIN, HIGH);
  digitalWrite(STATUS, LOW);

  //Attaching an interrupt to trigger whenever the clock pin reads high
  attachInterrupt( digitalPinToInterrupt(CLOCK_PIN), clock_interrupt, RISING);
  Serial.begin(115200);
}

void clock_interrupt(void)
{
  in_buffer <<= 1;
  in_buffer |= (byte)digitalRead(MOSI_PIN);
  //delayMicroseconds(22);
  //Serial.println(in_buffer);
  if(clock_cycle == 7)
  {
    Serial.print("r");
    Serial.println(in_buffer, HEX);
    out_buffer = handle_in_byte(in_buffer);
    Serial.print("t");
    Serial.println(out_buffer, HEX);
    in_buffer = 0x00;
    clock_cycle = 0;
  }
  if(out_buffer & 0x80)
  {
    digitalWrite(MISO_PIN, HIGH);
  }
  else
  {
    digitalWrite(MISO_PIN, LOW);
  }
  out_buffer <<= 1;
  clock_cycle++;
}

byte handle_in_byte(byte in)
{
  byte send_byte = 0x00;
  switch(connection_state)
  {
    case NOT_CONNECTED:
      if(in == PKMN_MASTER)
      {
        send_byte = PKMN_SLAVE;
      }
      else if(in == PKMN_BLANK)
      {
        send_byte = PKMN_BLANK;
      }
      else if(in == PKMN_CONNECTED)
      {
        send_byte = PKMN_CONNECTED;
        connection_state = CONNECTED;
        //digitalWrite(STATUS, HIGH);
      }
      break;

    case CONNECTED:
      if(in == PKMN_CONNECTED)
      {
        send_byte = PKMN_CONNECTED;
      }
      else if(in == PKMN_TRADE_CENTER)
      {
        connection_state = TRADE_CENTER;
        send_byte = PKMN_TRADE_CENTER;
      }
      else if(in == PKMN_COLOSSEUM)
      {
        connection_state = COLOSSEUM;
        send_byte = COLOSSEUM;
      }
      else if((in == PKMN_BREAK_LINK) || (in == PKMN_MASTER))
      {
        connection_state = NOT_CONNECTED;
        send_byte = PKMN_BREAK_LINK;
        //digitalWrite(STATUS, LOW);
      }
      else
      {
        send_byte = in;
      }
      break;
      /*
    case TRADE_CENTER:
      if(trade_center_state == INIT && in == 0x00) 
      {
        if(trade_counter++ == 5)
        {
          trade_center_state = READY_TO_GO;
        }
        send_byte = in;
      }
      else if(trade_center_state == READY_TO_GO && (in & 0xF0) == 0xF0)
      {
        trade_center_state = SEEN_FIRST_WAIT;
        send_byte = in;
      }
      else if(trade_center_state == SEEN_FIRST_WAIT && (in & 0xF0) != 0xF0)
      {
        send_byte = in;
        trade_counter = 0;
        trade_center_state = SENDING_RANDOM_DATA;
      } 
      else if(trade_center_state == SENDING_RANDOM_DATA && (in & 0xF0) == 0xF0)
      {
        if(trade_counter++ == 5)
        {
          trade_center_state = WAITING_TO_SEND_DATA;
        }
        send_byte = in;
      }
      else if(trade_center_state == WAITING_TO_SEND_DATA && (in & 0xF0) != 0xF0)
      {
        trade_counter = 0;
        send_byte = POKEMON_DATA[trade_counter++];
        trade_center_state = SENDING_DATA;
      }
      else if(trade_center_state == SENDING_DATA)
      {
        send_byte = POKEMON_DATA[trade_counter++];
        if(trade_counter == 415)
        {
          trade_center_state = DATA_SENT;
        }
      }
      else
      {
        send_byte = in;
      }
      break;
*/  
    default:
      send_byte = in;
      return send_byte;

  }
  return send_byte;
}
void loop() 
{
}

