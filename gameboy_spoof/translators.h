#ifndef TRANSLATORS_H
#define TRANSLATORS_H

typedef unsigned char byte;

byte char_to_sprite_char(char in);
void string_to_sprite_chars(char *in, byte *data_block);

#endif

