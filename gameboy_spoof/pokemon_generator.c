#include "pokemon_generator.h"
#include "translators.h"
#include "dictionaries.h"

typedef unsigned char byte;

uint8_t* gen_pokemon(struct pokemon* in_poke)
{
  //The final buffer to hold the whole pokemon
  uint8_t* data; 
  data = (uint8_t*)malloc(44);

  uint32_t tmp = 0;
  uint8_t byte_1 = 0;
  uint8_t byte_2 = 0;
  uint8_t byte_3 = 0;
    
  data[0x00] = in_poke->index;
  
  tmp = in_poke->hp;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF); 
  data[0x01] = byte_1;
  data[0x02] = byte_2;
  
  data[0x03] = in_poke->pc_lvl;
  data[0x04] = in_poke->status_cond;
  data[0x05] = in_poke->type1;
  data[0x06] = in_poke->type2;
  data[0x07] = in_poke->catch_or_held_item;
  data[0x08] = in_poke->mov1;
  data[0x09] = in_poke->mov2;
  data[0x0A] = in_poke->mov3;
  data[0x0B] = in_poke->mov4;

  tmp = in_poke->trainer_id;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x0C] = byte_1;
  data[0x0D] = byte_2;

  tmp = in_poke->exp_pts;
  byte_3 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x0E] = byte_1;
  data[0x0F] = byte_2;
  data[0x10] = byte_3;

  tmp = in_poke->hp_ev;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x11] = byte_1;
  data[0x12] = byte_2;

  tmp = in_poke->attack_ev;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x13] = byte_1;
  data[0x14] = byte_2;

  tmp = in_poke->defense_ev;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x15] = byte_1;
  data[0x16] = byte_2;

  tmp = in_poke->speed_ev;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x17] = byte_1;
  data[0x18] = byte_2;

  tmp = in_poke->special_ev;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x19] = byte_1;
  data[0x1A] = byte_2;

  tmp = in_poke->iv_data;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x1B] = byte_1;
  data[0x1C] = byte_2;
  
  data[0x1D] = in_poke->mov1_pp;
  data[0x1E] = in_poke->mov2_pp;
  data[0x1F] = in_poke->mov3_pp;
  data[0x20] = in_poke->mov4_pp;
  data[0x21] = in_poke->lvl;

  tmp = in_poke->max_hp;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x22] = byte_1;
  data[0x23] = byte_2;

  tmp = in_poke->attack_stat;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x24] = byte_1;
  data[0x25] = byte_2;

  tmp = in_poke->defense_stat;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x26] = byte_1;
  data[0x27] = byte_2;

  tmp = in_poke->speed_stat;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x28] = byte_1;
  data[0x29] = byte_2;

  tmp = in_poke->special_stat;
  byte_2 = (tmp & 0x000000FF); 
  tmp >>= 8;
  byte_1 = (tmp & 0x000000FF);
  data[0x2A] = byte_1;
  data[0x2B] = byte_2;

  return data;
}

uint8_t* gen_trade(struct trade* in_trade)
{
  //The final buffer to hold the whole trade
  uint8_t* data; 
  data = (uint8_t*)malloc(415);
  
}

struct pokemon pk_test = {
  //Index Number
  PKI_MRMIME,
  //HP
  40,
  //PC Level (Redundant, same as Level
  1,
  //Status Flags
  STA_BURNED,
  //Type 1
  TYP_PSYCHIC,
  //Type 2
  TYP_PSYCHIC,
  //Catch/Held Item
  0,
  //Move 1
  MOV_PSYCHIC,
  //Move 2
  MOV_PSYCHIC,
  //Move 3
  MOV_PSYCHIC,
  //Move 4
  MOV_PSYCHIC,
  //Original Trainer ID Number
  54321,
  //EXP
  100,
  //HP EV Data
  0xFFFF,
  //Attack EV Data
  0xFFFF,
  //Defense EV Data
  0xFFFF,
  //Speed EV Data
  0xFFFF,
  //Special EV Data
  0xFFFF,
  //IV Data
  0xFFFF,
  //Move 1 PP
  0,
  //Move 2 PP
  0,
  //Move 3 PP
  0,
  //Move 4 PP
  0,
  //Level
  5,
  //Max HP
  40,
  //Attack
  0xFFFF,
  //Defense
  0xFFFF,
  //Speed
  0xFFFF,
  //Special
  0xFFFF
};
