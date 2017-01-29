#ifndef POKEMON_GENERATOR_H
#define POKEMON_GENERATOR_H

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
}

//All the status conditions
#define SLEP_STA 0x04
#define POSN_STA 0x08
#define BRND_STA 0x10
#define FRZN_STA 0x20
#define PARL_STA 0x40

//All the pokemon types
#define NRML_TYP  0x00
#define FGHT_TYP  0x01
#define FLYG_TYP  0x02
#define POSN_TYP  0x03
#define GRND_TYP  0x04
#define ROCK_TYP  0x05
#define BUG_TYP   0x07
#define GHST_TYP  0x08
#define FIRE_TYP  0x14
#define WATR_TYP  0x15
#define GRSS_TYP  0x16
#define ELCT_TYP  0x17
#define PSYC_TYP  0x18
#define ICE_TYP   0x19
#define DRGN_TYP  0x1A

#endif
