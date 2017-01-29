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

byte convert_char(char in)
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
void convert_string(String in, byte& data_block)
{
  for(int i = 0; i < in.length(); i++)
  {
    data_block[i] = convert_char(in.charAt(i));
  }
  return;
}

