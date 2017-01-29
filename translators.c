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

byte convert_move(String in)
{
  switch(in)
  {
    case: "Pound"
      return 1;
    case: "Karate Chop"
      return 2;
    case "Double Slap"
      return 3;
    case "Comet Punch"
      return 4;
    case "Mega Punch"
      return 5;
    case "Pay Day"
      return 6;
    case "Fire Punch"
      return 7;
    case "Ice Punch:
      return 8;
      
  }
}

