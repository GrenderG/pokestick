#ifndef POKEMON_GENERATOR_H
#define POKEMON_GENERATOR_H

typedef unsigned char byte;

struct pokemon
{
  byte ind_num;
  unsigned int hp;
  byte pc_lvl;
  byte stat_cond;
  byte type1;
  byte type2;
  byte catch_or_held_itm;
  byte mov_1;
  byte mov_2;
  byte mov_3;
  byte mov_4;
  unsigned int train_id;
  unsigned long ex_pts;
  unsigned int hp_ev;
  unsigned int att_ev;
  unsigned int def_ev;
  unsigned int spd_ev;
  unsigned int spc_ev;
  unsigned int iv_dat;
  byte mov_1_pp;
  byte mov_2_pp;
  byte mov_3_pp;
  byte mov_4_pp;
  byte lvl;
  unsigned int max_hp;
  unsigned int att;
  unsigned int def;
  unsigned int spd;
  unsigned int spc;
};

#endif
