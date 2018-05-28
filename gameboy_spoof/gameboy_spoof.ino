#include "gameboy_spoof.h"
#include "translators.h"
#include "pokemon_generator.h"

int volatile CLOCK_PIN = 2;
int volatile MISO_PIN = 3;
int volatile MOSI_PIN = 4;
int volatile data = 0;
int volatile val = 0;
int ledStatus = 13;

unsigned volatile long t_last_rec = 0;
volatile byte out_buff = 0x00;
volatile int clock_cycle = 0;

volatile int data_counter = 0;
volatile connection_state_t connection_state = NOT_CONNECTED;
volatile int trade_center_state = INIT;



void setup() {
  pinMode(MOSI_PIN, INPUT);
  digitalWrite( MOSI_PIN, HIGH);  
  pinMode(MISO_PIN, OUTPUT);
  pinMode(ledStatus, OUTPUT);
  digitalWrite(ledStatus, LOW);
  digitalWrite(MISO_PIN, LOW);
  pinMode(CLOCK_PIN, INPUT);
  digitalWrite(CLOCK_PIN, HIGH);
  Serial.begin(9600);
  attachInterrupt( 0, clock_interrupt, RISING );
  
}


void clock_interrupt(void) {
  byte in;
  unsigned long t = 0;
  if(t_last_rec > 0) {
    if( micros() - t_last_rec > 120 ) {
      clock_cycle = 0;
      val = 0;
      in = 0x00;
    }
  }
  data = digitalRead(MOSI_PIN);
  if(data == HIGH){
    val |= ( 1 << (7-clock_cycle) );
    in |= ( 1 << (7-clock_cycle) );
  }
  if(clock_cycle == 7) {
    out_buff = handle_in_byte((byte)val);
    val = 0;
    in = 0x00;
    clock_cycle = -1;
  }
  
  clock_cycle++;
  t_last_rec = micros();
  while( ((digitalRead(CLOCK_PIN) | CLOCK_PIN) & CLOCK_PIN)  == 0);
  digitalWrite(MISO_PIN, out_buff & 0x80 ? MISO_PIN : 0);
  out_buff = out_buff << 1;
}
byte handle_in_byte(byte in) {
  byte send = 0x00;
  switch(connection_state) {
  case NOT_CONNECTED:
    if(in == PKMN_MASTER)
      send = PKMN_SLAVE;
    else if(in == PKMN_BLANK)
      send = PKMN_BLANK;
    else if(in == PKMN_CONNECTED) {
      send = PKMN_CONNECTED;
      connection_state = CONNECTED;
                        digitalWrite(ledStatus, HIGH);
    }
    break;

  case CONNECTED:
    if(in == PKMN_CONNECTED)
      send = PKMN_CONNECTED;
    else if(in == PKMN_TRADE_CENTER)
      connection_state = TRADE_CENTER;
    else if(in == PKMN_COLOSSEUM)
      connection_state = COLOSSEUM;
    else if(in == PKMN_BREAK_LINK || in == PKMN_MASTER) {
      connection_state = NOT_CONNECTED;
      send = PKMN_BREAK_LINK;
                        digitalWrite(ledStatus, LOW);
    } else {
      send = in;
    }
    break;

  case TRADE_CENTER:
    if(trade_center_state == INIT && in == 0x00) {
      if(data_counter++ == 5) {
        trade_center_state = READY_TO_GO;
      }
      send = in;
    } else if(trade_center_state == READY_TO_GO && (in & 0xF0) == 0xF0) {
      trade_center_state = SEEN_FIRST_WAIT;
      send = in;
    } else if(trade_center_state == SEEN_FIRST_WAIT && (in & 0xF0) != 0xF0) {
      send = in;
      data_counter = 0;
      trade_center_state = SENDING_RANDOM_DATA;
    } else if(trade_center_state == SENDING_RANDOM_DATA && (in & 0xF0) == 0xF0) {
      if(data_counter++ == 5) {
        trade_center_state = WAITING_TO_SEND_DATA;
      }
      send = in;
    } else if(trade_center_state == WAITING_TO_SEND_DATA && (in & 0xF0) != 0xF0) {
      data_counter = 0;
      send = PKMN_DATA[data_counter++];
      trade_center_state = SENDING_DATA;
    } else if(trade_center_state == SENDING_DATA) {
      send = PKMN_DATA[data_counter++];
      if(data_counter == 415) {
        trade_center_state = DATA_SENT;
      }
    } else {
      send = in;
    }
    break;

  case COLOSSEUM:
    send = in;
    break;

  default:
    send = in;
    break;
  }

  return send;
}

void loop() { 

 }




