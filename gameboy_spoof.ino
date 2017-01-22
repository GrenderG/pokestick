#include "pokemon.h"


#define CLOCK 2
#define MOSI 3
#define MISO 4

volatile connection_state_t connection_state = NOT_CONNECTED;
volatile trade_centre_state_t trade_centre_state = INIT;
volatile int clock_cycle = 0;
volatile byte byte_in = 0x00;
volatile byte byte_out = 0x00;

void handle_serial_bit(void)
{
  byte_in |= (digitalRead(MOSI) << clock_cycle);
  if(++clock_cycle > 7)
  {
    clock_cycle = 0;
    byte_out = handle_byte_in(byte_in);
    Serial.print("\n");
    Serial.print(byte_in, HEX);
    Serial.print(" ");
    Serial.print(byte_out, HEX);
    Serial.print("\n");
    byte_in = 0x00;
  }

  while(!digitalRead(CLOCK))
  {
    
    if(byte_out & 0x80)
    {
        digitalWrite(MISO, HIGH);
        Serial.print("1");
    }
    else
    {
        digitalWrite(MISO, LOW);
        Serial.print("0");
    }
  }
  byte_out <<= 1;
}

int handle_byte_in(byte in)
{
  byte send = 0x00;
  switch(connection_state) 
  {
    case NOT_CONNECTED:
      if(in == PKMN_MASTER)
      {
        send = PKMN_SLAVE;
      }
      else if(in == PKMN_BLANK)
      {
        send = PKMN_BLANK;
      }
      else if(in == PKMN_CONNECTED) 
      {
        send = PKMN_CONNECTED;
        connection_state = CONNECTED;
      }
      break;
  
    case CONNECTED:
      if(in == PKMN_CONNECTED)
      {
        send = PKMN_CONNECTED;
      }
      else if(in == PKMN_TRADE_CENTRE)
      {
        connection_state = TRADE_CENTRE;
      } 
      else if(in == PKMN_COLOSSEUM)
      {
        connection_state = COLOSSEUM;
      }
      else if(in == PKMN_BREAK_LINK || in == PKMN_MASTER) 
      {
        connection_state = NOT_CONNECTED;
        send = PKMN_BREAK_LINK;
      } 
      else 
      {
        send = in;
      }
      break;
  }
  return send;
}

void setup() 
{
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(CLOCK, INPUT);
  digitalWrite(MISO, LOW);
  Serial.begin(115200);
  digitalWrite(CLOCK, HIGH);
  attachInterrupt( digitalPinToInterrupt(CLOCK), handle_serial_bit, RISING );
}

void loop() 
{

}


