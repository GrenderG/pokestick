#include "pokemon_generator.h"
#include "translators.h"
#include "dictionaries.h"
#include "pkmn_constants.h"

uint8_t* gen_pokemon(struct pokemon *in_poke)
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

uint8_t* gen_trade(struct trade *in_trade)
{
  //The final buffer to hold the whole trade
  uint8_t* data; 
  data = (uint8_t*)malloc(415);
  for(int i = 0; i < 10; i++)
  {
    data[i] = char_to_sprite_char(in_trade->trader_name[i]);
  }
  data[10] = 0;
  data[11] = in_trade->num_of_pokemon;
  data[12] = in_trade->pki1;
  data[13] = in_trade->pki2;
  data[14] = in_trade->pki3;
  data[15] = in_trade->pki4;
  data[16] = in_trade->pki5;
  data[17] = in_trade->pki6;
  data[18] = in_trade->pki7;
  uint8_t* pokemon1_data = gen_pokemon(&in_trade->poke1);
  for(int i = 0; i < 44; i++)
  {
    data[19+i] = pokemon1_data[i];
  }
  free(pokemon1_data);
  //Right now I don't want to try and trade 7 pokemon at once, so I'm just going to fill the rest of this with garbage data
  for(int i = 63; i < 283; i++)
  {
    data[i] = 85;
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+283] = char_to_sprite_char(in_trade->trainer_name1[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+294] = char_to_sprite_char(in_trade->trainer_name2[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+305] = char_to_sprite_char(in_trade->trainer_name3[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+316] = char_to_sprite_char(in_trade->trainer_name4[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+327] = char_to_sprite_char(in_trade->trainer_name5[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+338] = char_to_sprite_char(in_trade->trainer_name6[i]);
  }
  for(int i = 0; i < 10; i++)
  {
    data[i+349] = char_to_sprite_char(in_trade->poke_name1[i]);
  }
  data[359] = 0x50;
  //Again, don't want to deal with the rest of the pokemon so I'm zeroing this out with terminators
  for(int i = 360; i < 415; i++)
  {
    data[i] = 0x50;
  }
}
