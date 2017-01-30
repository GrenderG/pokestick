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



//All the moves
char mov_pound[]              = "Pound";
char mov_karate_chop[]        = "Karate Chop";
char mov_double_slap[]        = "Double Slap";
char mov_comet_punch[]        = "Comet Punch";
char mov_mega_punch[]         = "Mega Punch";
char mov_pay_day[]            = "Pay Day";
char mov_fire_punch[]         = "Fire Punch";
char mov_ice_punch[]          = "Ice Punch";
char mov_thunder_punch[]      = "Thunder Punch";
char mov_scratch[]            = "Scratch";
char mov_vice_grip[]          = "Vice Grip";
char mov_guillotine[]         = "Guillotine";
char mov_razor_wind[]         = "Razor Wind";
char mov_swords_dance[]       = "Swords Dance";
char mov_cut[]                = "Cut";
char mov_gust[]               = "Gust";
char mov_wing_attack[]        = "Wing Attack";
char mov_whirlwind[]          = "Whirlwind";
char mov_fly[]                = "Fly";
char mov_bind[]               = "Bind";
char mov_slam[]               = "Slam";
char mov_vine_whip[]          = "Vine Whip";
char mov_stomp[]              = "Stomp";
char mov_double_kick[]        = "Double Kick";
char mov_mega_kick[]          = "Mega Kick";
char mov_jump_kick[]          = "Jump Kick";
char mov_rolling_kick[]       = "Rolling Kick";
char mov_sand_attack[]        = "Sand Attack";
char mov_headbutt[]           = "Headbutt";
char mov_horn_attack[]        = "Horn Attack";
char mov_fury_attack[]        = "Fury Attack";
char mov_horn_drill[]         = "Horn Drill";
char mov_tackle[]             = "Tackle";
char mov_body_slam[]          = "Body Slam";
char mov_wrap[]               = "Wrap";
char mov_take_down[]          = "Take Down";
char mov_thrash[]             = "Thrash";
char mov_double_edge[]        = "Double Edge";
char mov_tail_whip[]          = "Tail Whip";
char mov_poison_sting[]       = "Poison String";
char mov_twineedle[]          = "Twineedle";
char mov_pin_missile[]        = "Pin Missle";
char mov_leer[]               = "Leer";
char mov_bite[]               = "Bite";
char mov_growl[]              = "Growl";
char mov_roar[]               = "Roar";
char mov_sing[]               = "Sing";
char mov_supersonic[]         = "Supersonic";
char mov_sonic_boom[]         = "Sonic Boom";
char mov_disable[]            = "Disable";
char mov_acid[]               = "Acid";
char mov_ember[]              = "Ember";
char mov_flamethrower[]       = "Flamethrower";
char mov_mist[]               = "Mist";
char mov_water_gun[]          = "Water Gun";
char mov_hydro_pump[]         = "Hydro Pump";
char mov_surf[]               = "Surf";
char mov_ice_beam[]           = "Ice Beam";
char mov_blizzard[]           = "Blizzard";
char mov_psybeam[]            = "Psybeam";
char mov_bubble_beam[]        = "Bubble Beam";
char mov_aurora_beam[]        = "Aurora Beam";
char mov_hyper_beam[]         = "Hyper Beam";
char mov_peck[]               = "Peck";
char mov_drill_peck[]         = "Drill Peck";
char mov_submission[]         = "Submission";
char mov_low_kick[]           = "Low Kick";
char mov_counter[]            = "Counter";
char mov_seismic_toss[]       = "Seismic Toss";
char mov_strength[]           = "Strength";
char mov_absorb[]             = "Absorb";
char mov_mega_drain[]         = "Mega Drain";
char mov_leech_seed[]         = "Leech Seed";
char mov_growth[]             = "Growth";
char mov_razor_leaf[]         = "Razor Leaf";
char mov_solar_beam[]         = "Solar Beam";
char mov_poison_powder[]      = "Poison Powder";
char mov_stun_spore[]         = "Stun Spore";
char mov_sleep_powder[]       = "Sleep Powder";
char mov_petal_dance[]        = "Petal Dance";
char mov_string_shot[]        = "String Shot";
char mov_dragon_rage[]        = "Dragon Rage";
char mov_fire_spin[]          = "Fire Spin";
char mov_thunder_shock[]      = "Thunder Shock";
char mov_thunderbolt[]        = "Thunderbolt";
char mov_thunder_wave[]       = "Thunder Wave";
char mov_thunder[]            = "Thunder";
char mov_rock_throw[]         = "Rock Throw";
char mov_earthquake[]         = "Earthquake";
char mov_fissure[]            = "Fissure";
char mov_dig[]                = "Dig";
char mov_toxic[]              = "Toxic";
char mov_confusion[]          = "Confusion";
char mov_psychic[]            = "Psychic";
char mov_hypnosis[]           = "Hypnosis";
char mov_meditate[]           = "Meditate";
char mov_agility[]            = "Agility";
char mov_quick_attack[]       = "Quick Attack";
char mov_rage[]               = "Rage";
char mov_teleport[]           = "Teleport";
char mov_night_shade[]        = "Night Shade";
char mov_mimic[]              = "Mimic";
char mov_screech[]            = "Screech";
char mov_double_team[]        = "Double Team";
char mov_recover[]            = "Recover";
char mov_harden[]             = "Harden";
char mov_minimize[]           = "Minimize";
char mov_smokescreen[]        = "Smokescreen";
char mov_confuse_ray[]        = "Confuse Ray";
char mov_withdraw[]           = "Withdraw";
char mov_defense_curl[]       = "Defense Curl";
char mov_barrier[]            = "Barrier";
char mov_light_screen[]       = "Light Screen";
char mov_haze[]               = "Haze";
char mov_reflect[]            = "Reflect";
char mov_focus_energy[]       = "Focus Energy";
char mov_bide[]               = "Bide";
char mov_metronome[]          = "Metronome";
char mov_mirror_mov[]         = "Mirror Move";
char mov_self_destruct[]      = "Self Destruct";
char mov_egg_bomb[]           = "Egg Bomb";
char mov_lick[]               = "Lick";
char mov_smog[]               = "Smog";
char mov_sludge[]             = "Sludge";
char mov_bone_club[]          = "Bone Club";
char mov_fire_blast[]         = "Fire Blast";
char mov_waterfall[]          = "Waterfall";
char mov_clamp[]              = "Clamp";
char mov_swift[]              = "Swift";
char mov_skull_bash[]         = "Skull Bash";
char mov_spike_cannon[]       = "Spike Cannon";
char mov_constrict[]          = "Constrict";
char mov_amnesia[]            = "Amnesia";
char mov_kinesis[]            = "Kinesis";
char mov_soft_boiled[]        = "Soft Boiled";
char mov_high_jump_kick[]     = "High Jump Kick";
char mov_glare[]              = "Glare";
char mov_dream_eater[]        = "Dream Eater";
char mov_poison_gas[]         = "Poison Gas";
char mov_barrage[]            = "Barrage";
char mov_leech_life[]         = "Leech Life";
char mov_lovely_kiss[]        = "Lovely Kiss";
char mov_sky_attack[]         = "Sky Attack";
char mov_transform[]          = "Transform";
char mov_bubble[]             = "Bubble";
char mov_dizzy_punch[]        = "Dizzy Punch";
char mov_spore[]              = "Spore";
char mov_flash[]              = "Flash";
char mov_psywave[]            = "Psywave";
char mov_splash[]             = "Splash";
char mov_acid_armor[]         = "Acid Armor";
char mov_crabhammer[]         = "Crabhammer";
char mov_explosion[]          = "Explosion";
char mov_fury_swipes[]        = "Fury Swipes";
char mov_bonemerang[]         = "Bonemerang";
char mov_rest[]               = "Rest";
char mov_rock_slide[]         = "Rock Slide";
char mov_hyper_fang[]         = "Hyper Fang";
char mov_sharpen[]            = "Sharpen";
char mov_conversion[]         = "Conversion";
char mov_tri_attack[]         = "Tri Attack";
char mov_super_fang[]         = "Super Fang";
char mov_slash[]              = "Slash";
char mov_substitute[]         = "Substitute";
char mov_struggle[]           = "Struggle";

//An index of all all the pointers to the move names, in order of move number
char* move_list[165] =
{
  mov_pound,
  mov_karate_chop,
  mov_double_slap,
  mov_comet_punch,
  mov_mega_punch,
  mov_pay_day,
  mov_fire_punch,
  mov_ice_punch,
  mov_thunder_punch,
  mov_scratch,
  mov_vice_grip,
  mov_guillotine,
  mov_razor_wind,
  mov_swords_dance,
  mov_cut,
  mov_gust,
  mov_wing_attack,
  mov_whirlwind,
  mov_fly,
  mov_bind,
  mov_slam,
  mov_vine_whip,
  mov_stomp,
  mov_double_kick,
  mov_mega_kick,
  mov_jump_kick,
  mov_rolling_kick,
  mov_sand_attack,
  mov_headbutt,
  mov_horn_attack,
  mov_fury_attack,
  mov_horn_drill,
  mov_tackle,
  mov_body_slam,
  mov_wrap,
  mov_take_down,
  mov_thrash,
  mov_double_edge,
  mov_tail_whip,
  mov_poison_sting,
  mov_twineedle,
  mov_pin_missile,
  mov_leer,
  mov_bite,
  mov_growl,
  mov_roar,
  mov_sing,
  mov_supersonic,
  mov_sonic_boom,
  mov_disable,
  mov_acid,
  mov_ember,
  mov_flamethrower,
  mov_mist,
  mov_water_gun,
  mov_hydro_pump,
  mov_surf,
  mov_ice_beam,
  mov_blizzard,
  mov_psybeam,
  mov_bubble_beam,
  mov_aurora_beam,
  mov_hyper_beam,
  mov_peck,
  mov_drill_peck,
  mov_submission,
  mov_low_kick,
  mov_counter,
  mov_seismic_toss,
  mov_strength,
  mov_absorb,
  mov_mega_drain,
  mov_leech_seed,
  mov_growth,
  mov_razor_leaf,
  mov_solar_beam,
  mov_poison_powder,
  mov_stun_spore,
  mov_sleep_powder,
  mov_petal_dance,
  mov_string_shot,
  mov_dragon_rage,
  mov_fire_spin,
  mov_thunder_shock,
  mov_thunderbolt,
  mov_thunder_wave,
  mov_thunder,
  mov_rock_throw,
  mov_earthquake,
  mov_fissure,
  mov_dig,
  mov_toxic,
  mov_confusion,
  mov_psychic,
  mov_hypnosis,
  mov_meditate,
  mov_agility,
  mov_quick_attack,
  mov_rage,
  mov_teleport,
  mov_night_shade,
  mov_mimic,
  mov_screech,
  mov_double_team,
  mov_recover,
  mov_harden,
  mov_minimize,
  mov_smokescreen,
  mov_confuse_ray,
  mov_withdraw,
  mov_defense_curl,
  mov_barrier,
  mov_light_screen,
  mov_haze,
  mov_reflect,
  mov_focus_energy,
  mov_bide,
  mov_metronome,
  mov_mirror_mov,
  mov_self_destruct,
  mov_egg_bomb,
  mov_lick,
  mov_smog,
  mov_sludge,
  mov_bone_club,
  mov_fire_blast,
  mov_waterfall,
  mov_clamp,
  mov_swift,
  mov_skull_bash,
  mov_spike_cannon,
  mov_constrict,
  mov_amnesia,
  mov_kinesis,
  mov_soft_boiled,
  mov_high_jump_kick,
  mov_glare,
  mov_dream_eater,
  mov_poison_gas,
  mov_barrage,
  mov_leech_life,
  mov_lovely_kiss,
  mov_sky_attack,
  mov_transform,
  mov_bubble,
  mov_dizzy_punch,
  mov_spore,
  mov_flash,
  mov_psywave,
  mov_splash,
  mov_acid_armor,
  mov_crabhammer,
  mov_explosion,
  mov_fury_swipes,
  mov_bonemerang,
  mov_rest,
  mov_rock_slide,
  mov_hyper_fang,
  mov_sharpen,
  mov_conversion,
  mov_tri_attack,
  mov_super_fang,
  mov_slash,
  mov_substitute,
  mov_struggle
};
