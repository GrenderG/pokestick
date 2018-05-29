#ifndef POKEMON_GENERATOR_H
#define POKEMON_GENERATOR_H

#include <stdint.h>

typedef unsigned char byte;

struct pokemon
{
  uint8_t index;
  uint16_t hp;
  uint8_t pc_lvl;
  uint8_t status_cond;
  uint8_t type1;
  uint8_t type2;
  uint8_t catch_or_held_item;
  uint8_t mov1;
  uint8_t mov2;
  uint8_t mov3;
  uint8_t mov4;
  uint16_t trainer_id;
  uint32_t exp_pts; //Only the first 3 bytes of this are valid, but there's no uint24_t
  uint16_t hp_ev;
  uint16_t attack_ev;
  uint16_t defense_ev;
  uint16_t speed_ev;
  uint16_t special_ev;
  uint16_t iv_data;
  uint8_t mov1_pp;
  uint8_t mov2_pp;
  uint8_t mov3_pp;
  uint8_t mov4_pp;
  uint8_t lvl;
  uint16_t max_hp;
  uint16_t attack_stat;
  uint16_t defense_stat;
  uint16_t speed_stat;
  uint16_t special_stat;
};

struct trade
{
  char trader_name[10];
  uint8_t num_of_pokemon;
  uint8_t pki1;
  uint8_t pki2;
  uint8_t pki3;
  uint8_t pki4;
  uint8_t pki5;
  uint8_t pki6;
  uint8_t pki7;
  struct pokemon poke1;
  /*
   * Storing all 7 pokemon will quickly fill up the Arduino's RAM so I'm not doing it yet. Just going to fill the buffer with 0s
  struct pokemon poke2;
  struct pokemon poke3;
  struct pokemon poke4;
  struct pokemon poke5;
  struct pokemon poke6;
  struct pokemon poke7;
  */
  char poke_name1[10];
  char poke_name2[10];
  char poke_name3[10];
  char poke_name4[10];
  char poke_name5[10];
  char poke_name6[10];
  char poke_name7[10];
  char trainer_name1[10];
  char trainer_name2[10];
  char trainer_name3[10];
  char trainer_name4[10];
  char trainer_name5[10];
  char trainer_name6[10];
  char trainer_name7[10];
};
#endif

