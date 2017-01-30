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
#define STA_SLEP 0x04
#define STA_POSN 0x08
#define STA_BRND 0x10
#define STA_FRZN 0x20
#define STA_PARL 0x40

//All the pokemon types
#define TYP_NRML  0x00
#define TYP_FGHT  0x01
#define TYP_FLYG  0x02
#define TYP_POSN  0x03
#define TYP_GRND  0x04
#define TYP_ROCK  0x05
#define TYP_BUG   0x07
#define TYP_GHST  0x08
#define TYP_FIRE  0x14
#define TYP_WATR  0x15
#define TYP_GRSS  0x16
#define TYP_ELCT  0x17
#define TYP_PSYC  0x18
#define TYP_ICE   0x19
#define TYP_DRGN  0x1A

#endif
