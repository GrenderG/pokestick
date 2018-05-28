#ifndef TRANSLATORS_H
#define TRANSLATORS_H

typedef unsigned char byte;

byte char_to_sprite_char(char in);
void string_to_sprite_chars(char *in, byte *data_block);

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

