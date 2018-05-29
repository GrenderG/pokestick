#include "translators.h"

typedef unsigned char byte;

byte char_to_sprite_char(char in)
{
  //All the numbers
  if(in >= '1' && in <= '2')
  {
    return 0xF6 - ('1' - in);
  }
  //All the uppercase letters
  if(in >= 'A' && in <= 'Z')
  {
    return 0x80 - ('A' - in);
  }
  //All the lower case letters
  if(in >= 'a' && in <= 'z')
  {
    return 0xA0 - ('a' - in);
  }
  //All the other characters
  if(in == ' ')
  {
    return 0x7F;
  }
  if(in == '-')
  {
    return 0xE3;
  }
  if(in == '?')
  {
    return 0xE6;
  }
  if(in == '!')
  {
    return 0xE7;
  }
  if(in == '.')
  {
    return 0xE8;
  }
  if(in == ',')
  {
    return 0xF4;
  }
  //If there's bad input, return a question mark
  else
  {
    return 0xE6;
  }
}

//There is NO out of bounds checking on the data_block being modified in this function. Be careful!
void string_to_sprite_chars(char *in, byte *data_block)
{
  for(int i = 0; in[i] != '\0'; i++)
  {
    data_block[i] = char_to_sprite_char(in[i]);
  }
  return;
}
