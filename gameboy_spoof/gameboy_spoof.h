#ifndef GAMEBOY_SPOOF_H
#define GAMEBOY_SPOOF_H

//Connection States
typedef enum
{
  NOT_CONNECTED,
  CONNECTED,
  TRADE_CENTER,
  COLOSSEUM
}
connection_state_t;

//Trade States
typedef enum
{
  INIT,
  READY_TO_GO,
  SEEN_FIRST_WAIT,
  SENDING_RANDOM_DATA,
  WAITING_TO_SEND_DATA,
  START_SENDING_DATA,
  SENDING_DATA,
  DATA_SENT
}
trade_center_state_t;

typedef unsigned char byte;

//Trade Constants
#define PKMN_BLANK                0x00

#define ITEM_1_HIGHLIGHTED        0xD0
#define ITEM_2_HIGHLIGHTED        0xD1
#define ITEM_3_HIGHLIGHTED        0xD2
#define ITEM_1_SELECTED           0xD4
#define ITEM_2_SELECTED           0xD5
#define ITEM_3_SELECTED           0xD6

#define PKMN_MASTER               0x01
#define PKMN_SLAVE                0x02
#define PKMN_CONNECTED            0x60
#define PKMN_WAIT                 0x7F

#define PKMN_ACTION               0x60

#define PKMN_TRADE_CENTER         ITEM_1_SELECTED
#define PKMN_COLOSSEUM            ITEM_2_SELECTED
#define PKMN_BREAK_LINK           ITEM_3_SELECTED

#define TRADE_CENTER_WAIT         0xFD

uint8_t pokemon_data1[44];
uint8_t pokemon_data2[44];
uint8_t pokemon_data3[44];
uint8_t pokemon_data4[44];
uint8_t pokemon_data5[44];
uint8_t pokemon_data6[44];
uint8_t pokemon_data7[44];

//An example annotated trade.
unsigned char TRADE_DATA[415] = {
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
0x01,  //Num of Pokemon in Party
0x4D, //Meowth Index
0xFF, //No Pokemon
0xFF, //No Pokemon
0xFF, //No Pokemon
0xFF, //No Pokemon
0xFF, //No Pokemon
0xFF, //No Pokemon

//Begin Data Structure of Pokemon 1
0x4D, //Pokemon Index (Meowth)
0x01, //HP Byte 1 (300)
0x2c, //HP Byte 2
0x01, //Level Byte (Level 1)
0x00, //Status Condition Flags (No status condition)
0x00, //Type 1, (Normal)
0x00, //Type 2, (Normal)
0x1F, //Catch Rate/Held Item
0x06, //Move 1 (Payday)
0x06, //Move 2 (Payday)
0x06, //Move 3 (Payday)
0x06, //Move 4 (Payday)
0x01, //Trainer ID Number Byte 1 (256)
0x00, //Trainer ID Number Byte 2
0x00, //EXP Byte 1 (0)
0x00, //EXP Byte 2
0x00, //EXP Byte 3
0xff, //HP EV Data Byte 1 (65535)
0xff, //HP EV Data Byte 2
0xff, //Attack EV Data Byte 1 (65535)
0xff, //Attack EV Data Byte 2
0xff, //Defense EV Data Byte 1 (65535)
0xff, //Defense EV Data Byte 2
0xff, //Speed EV Data Byte 1 (65535)
0xff, //Speed EV Data Byte 2
0xff, //Special EV Data Byte 1 (65535)
0xff, //Special EV Data Byte 2 (65535)
0xff, //IV Data Byte 1 (65535)
0xff, //IV Data Byte 2 (65535)
0x00, //Move 1 PP  (0)
0x00, //Move 2 PP (0)
0x00, //Move 3 PP (0)
0x00, //Move 4 PP (0)
0x01, //Level Byte (Level 1)
0x01, //Max HP Byte 1 (300)
0x2c, //Max HP Byte 2
0x00, //Attack Stat Byte 1
0x96, //Attack Stat Byte 2
0x0,  //Defense Stat Byte 1
0x97, //Defense Stat Byte 2
0x00, //Speed Stat Byte 1 
0x98, //Speed Stat Byte 2
0x0,  //Special Stat Byte 1
0x99, //Special Stat Byte 2

//The rest of the Pokemon Data Structures, I'm only using 1
0x4D, 
0x1,  
0x2c, 
0x01, 
0x00, 
0x14, 
0x08, 
0x1F, 
0x7E, 
0x38, 
0x09, 
0x19, 
0x4, 
0xd2, 
0x3, 
0xd, 
0x40,
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xc0, 
0xc0, 
0xc0, 
0xc0, 
0x4a, 
0x1, 
0x2c, 
0x0, 
0x96, 
0x0, 
0x97, 
0x0, 
0x98, 
0x0, 
0x99, 
0x4A, 
0x1, 
0x2c, 
0x4a, 
0x00, 
0x14, 
0x08, 
0x1F, 
0x7E, 
0x38, 
0x09, 
0x19, 
0x4, 
0xd2, 
0x3, 
0xd, 
0x40, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xc0, 
0xc0, 
0xc0, 
0xc0, 
0x4a, 
0x1, 
0x2c, 
0x0, 
0x96, 
0x0, 
0x97, 
0x0, 
0x98, 
0x0, 
0x99, 
0x4A, 
0x1, 
0x2c, 
0x4a, 
0x00, 
0x14, 
0x08, 
0x1F, 
0x7E, 
0x38, 
0x09, 
0x19, 
0x4, 
0xd2, 
0x3, 
0xd, 
0x40, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xc0, 
0xc0, 
0xc0, 
0xc0, 
0x4a, 
0x1, 
0x2c, 
0x0, 
0x96, 
0x0, 
0x97, 
0x0, 
0x98, 
0x0, 
0x99, 
0x4A, 
0x1, 
0x2c, 
0x4a, 
0x00, 
0x14, 
0x08, 
0x1F, 
0x7E, 
0x38, 
0x09, 
0x19, 
0x4, 
0xd2, 
0x3, 
0xd, 
0x40, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xc0, 
0xc0, 
0xc0, 
0xc0, 
0x4a, 
0x1, 
0x2c, 
0x0, 
0x96, 
0x0, 
0x97, 
0x0, 
0x98, 
0x0, 
0x99, 
0x4A, 
0x1, 
0x2c, 
0x4a, 
0x00, 
0x14, 
0x08, 
0x1F, 
0x7E, 
0x38, 
0x09, 
0x19, 
0x4, 
0xd2, 
0x3, 
0xd, 
0x40, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xff, 
0xc0, 
0xc0, 
0xc0, 
0xc0, 
0x4a, 
0x1, 
0x2c, 
0x0, 
0x96, 
0x0, 
0x97, 
0x0, 
0x98, 
0x0, 
0x99, 

//End of Pokemon Data
//Original Trainer Name, Pokemon 1
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Original Trainer Name, Pokemon 2
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Original Trainer Name, Pokemon 2
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Original Trainer Name, Pokemon 2
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Original Trainer Name, Pokemon 2
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Original Trainer Name, Pokemon 2
0x86, //'G'
0xB1, //'r'
0xA0, //'a'
0xAD, //'n'
0xB3, //'t'
0x00,
0x00,
0x00, 
0x00, 
0x00, 
0x00, 
//Pokemon Nickname 1
0x8C, //'M'
0xAE, //'o'
0xAB, //'l'
0xAB, //'l'
0xB8, //'y'
0x00, 
0x00, 
0x00, 
0x00, 
0x00, 
0x50, // Terminator
//Pokemon Nickname 2
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
//Pokemon Nickname 3
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
//Pokemon Nickname 4
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
//Pokemon Nickname 5
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
//Pokemon Nickname 6
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50, 
0x50
};

//Dictionaries
//All the move name strings
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
char* mov_list[165] =
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

//All the Pokemon names
char pkn_bulbasaur[]      = "Bulbasaur";
char pkn_ivysaur[]        = "Ivysaur";
char pkn_venusaur[]       = "Venusaur";
char pkn_charmander[]     = "Charmander";
char pkn_charmeleon[]     = "Charmeleon";
char pkn_charizard[]      = "Charizard";
char pkn_squirtle[]       = "Squirtle";
char pkn_wartortle[]      = "Wartortle";
char pkn_blastoise[]      = "Blastoise";
char pkn_caterpie[]       = "Caterpie";
char pkn_metapod[]        = "Metapod";
char pkn_butterfree[]     = "Butterfree";
char pkn_weedle[]         = "Weedle";
char pkn_kakuna[]         = "Kakuna";
char pkn_beedrill[]       = "Beedrill";
char pkn_pidgey[]         = "Pidgey";
char pkn_pidgeotto[]      = "Pidgeotto";
char pkn_pidgeot[]        = "Pidgeot";
char pkn_rattata[]        = "Rattata";
char pkn_raticate[]       = "Raticate";
char pkn_spearow[]        = "Spearow";
char pkn_fearow[]         = "Fearow";
char pkn_ekans[]          = "Ekans";
char pkn_arbok[]          = "Arbok";
char pkn_pikachu[]        = "Pikachu";
char pkn_raichu[]         = "Raichu";
char pkn_sandshrew[]      = "Sandshrew";
char pkn_sandslash[]      = "Sandslash";
char pkn_nidoranf[]       = "Nidoran F";
char pkn_nidorina[]       = "Nidorina";
char pkn_nidoqueen[]      = "Nidoqueen";
char pkn_nidoranm[]       = "Nidoran M";
char pkn_nidorino[]       = "Nidorino";
char pkn_nidoking[]       = "Nidoking";
char pkn_clefairy[]       = "Clefairy";
char pkn_clefable[]       = "Clefable";
char pkn_vulpix[]         = "Vulpix";
char pkn_ninetails[]      = "Ninetails";
char pkn_jigglypuff[]     = "Jigglypuff";
char pkn_wigglytuff[]     = "Wigglytuff";
char pkn_zubat[]          = "Zubat";
char pkn_golbat[]         = "Golbat";
char pkn_oddish[]         = "Oddish";
char pkn_gloom[]          = "Gloom";
char pkn_vileplume[]      = "Vileplume";
char pkn_paras[]          = "Paras";
char pkn_parasect[]       = "Parasect";
char pkn_venonat[]        = "Venonat";
char pkn_venomoth[]       = "Venomoth";
char pkn_diglett[]        = "Diglett";
char pkn_dugtrio[]        = "Dugtrio";
char pkn_meowth[]         = "Meowth";
char pkn_persian[]        = "Persian";
char pkn_psyduck[]        = "Psyduck";
char pkn_golduck[]        = "Golduck";
char pkn_mankey[]         = "Mankey";
char pkn_primeape[]       = "Primeape";
char pkn_growlithe[]      = "Growlithe";
char pkn_arcanine[]       = "Arcanine";
char pkn_poliwag[]        = "Poliwag";
char pkn_poliwhirl[]      = "Poliwhirl";
char pkn_poliwrath[]      = "Poliwrath";
char pkn_abra[]           = "Abra";
char pkn_kadabra[]        = "Kadabra";
char pkn_alakazam[]       = "Alakazam";
char pkn_machop[]         = "Machop";
char pkn_machoke[]        = "Machoke";
char pkn_machamp[]        = "Machamp";
char pkn_bellsprout[]     = "Bellsprout";
char pkn_weepinbell[]     = "Weepinbell";
char pkn_victreebel[]     = "Victreebel";
char pkn_tentacool[]      = "Tentacool";
char pkn_tentacruel[]     = "Tentacruel";
char pkn_geodude[]        = "Geodude";
char pkn_graveler[]       = "Graveler";
char pkn_golem[]          = "Golem";
char pkn_ponyta[]         = "Ponyta";
char pkn_rapidash[]       = "Rapidash";
char pkn_slowpoke[]       = "Slowpoke";
char pkn_slowbro[]        = "Slowbro";
char pkn_magnemite[]      = "Magnemite";
char pkn_magneton[]       = "Magneton";
char pkn_farfetchd[]      = "Farfetch'd";
char pkn_doduo[]          = "Doduo";
char pkn_dodrio[]         = "Dodrio";
char pkn_seel[]           = "Seel";
char pkn_dewgong[]        = "Dewgong";
char pkn_grimer[]         = "Grimer";
char pkn_muk[]            = "Muk";
char pkn_shellder[]       = "Shellder";
char pkn_cloyster[]       = "Cloyster";
char pkn_gastly[]         = "Gastly";
char pkn_haunter[]        = "Haunter";
char pkn_gengar[]         = "Gengar";
char pkn_onix[]           = "Onix";
char pkn_drowzee[]        = "Drowzee";
char pkn_hypno[]          = "Hypno";
char pkn_krabby[]         = "Krabby";
char pkn_kingler[]        = "Kingler";
char pkn_voltorb[]        = "Voltorb";
char pkn_electrode[]      = "Electrode";
char pkn_exeggcute[]      = "Exeggcute";
char pkn_exeggutor[]      = "Exeggutor";
char pkn_cubone[]         = "Cubone";
char pkn_marowak[]        = "Marowak";
char pkn_hitmonlee[]      = "Hitmonlee";
char pkn_hitmonchan[]     = "Hitmonchan";
char pkn_lickitung[]      = "Lickitung";
char pkn_koffing[]        = "Koffing";
char pkn_weezing[]        = "Weezing";
char pkn_rhyhorn[]        = "Rhyhorn";
char pkn_rhydon[]         = "Rhydon";
char pkn_chansey[]        = "Chansey";
char pkn_tangela[]        = "Tangela";
char pkn_kangaskhan[]     = "Kangaskhan";
char pkn_horsea[]         = "Horsea";
char pkn_seadra[]         = "Seadra";
char pkn_goldeen[]        = "Goldeen";
char pkn_seaking[]        = "Seaking";
char pkn_staryu[]         = "Staryu";
char pkn_starmie[]        = "Starmie";
char pkn_mrmime[]         = "Mr. Mime";
char pkn_scyther[]        = "Scyther";
char pkn_jynx[]           = "Jynx";
char pkn_electrabuzz[]    = "Electrabuzz";
char pkn_magmar[]         = "Magmar";
char pkn_pinsir[]         = "Pinsir";
char pkn_tauros[]         = "Tauros";
char pkn_magikarp[]       = "Magikarp";
char pkn_gyarados[]       = "Gyrados";
char pkn_lapras[]         = "Lapras";
char pkn_ditto[]          = "Ditto";
char pkn_eevee[]          = "Eevee";
char pkn_vaporeon[]       = "Vaporeon";
char pkn_jolteon[]        = "Joltean";
char pkn_flareon[]        = "Flareon";
char pkn_porygon[]        = "Porygon";
char pkn_omanyte[]        = "Omanyte";
char pkn_omastar[]        = "Omastar";
char pkn_kabuto[]         = "Kabuto";
char pkn_kabutops[]       = "Kabutops";
char pkn_aerodactyl[]     = "Aerodactyl";
char pkn_snorlax[]        = "Snorlax";
char pkn_articuno[]       = "Articuno";
char pkn_zapdos[]         = "Zapdos";
char pkn_moltres[]        = "Moltres";
char pkn_dratini[]        = "Dratini";
char pkn_dragonair[]      = "Dragonair";
char pkn_dragonite[]      = "Dragonite";
char pkn_mewtwo[]         = "Mewtwo";
char pkn_mew[]            = "Mew";
char pkn_missingno[]      = "MissingNo.";

//An index of all the pokemon names in pokedex order
char* pkn_list[152] = 
{
  pkn_bulbasaur,
  pkn_ivysaur,
  pkn_venusaur,
  pkn_charmander,
  pkn_charmeleon,
  pkn_charizard,
  pkn_squirtle,
  pkn_wartortle,
  pkn_blastoise,
  pkn_caterpie,
  pkn_metapod,
  pkn_butterfree,
  pkn_weedle,
  pkn_kakuna,
  pkn_beedrill,
  pkn_pidgey,
  pkn_pidgeotto,
  pkn_pidgeot,
  pkn_rattata,
  pkn_raticate,
  pkn_spearow,
  pkn_fearow,
  pkn_ekans,
  pkn_arbok,
  pkn_pikachu,
  pkn_raichu,
  pkn_sandshrew,
  pkn_sandslash,
  pkn_nidoranf,
  pkn_nidorina,
  pkn_nidoqueen,
  pkn_nidoranm,
  pkn_nidorino,
  pkn_nidoking,
  pkn_clefairy,
  pkn_clefable,
  pkn_vulpix,
  pkn_ninetails,
  pkn_jigglypuff,
  pkn_wigglytuff,
  pkn_zubat,
  pkn_golbat,
  pkn_oddish,
  pkn_gloom,
  pkn_vileplume,
  pkn_paras,
  pkn_parasect,
  pkn_venonat,
  pkn_venomoth,
  pkn_diglett,
  pkn_dugtrio,
  pkn_meowth,
  pkn_persian,
  pkn_psyduck,
  pkn_golduck,
  pkn_mankey,
  pkn_primeape,
  pkn_growlithe,
  pkn_arcanine,
  pkn_poliwag,
  pkn_poliwhirl,
  pkn_poliwrath,
  pkn_abra,
  pkn_kadabra,
  pkn_alakazam,
  pkn_machop,
  pkn_machoke, 
  pkn_machamp,
  pkn_bellsprout,
  pkn_weepinbell,
  pkn_victreebel,
  pkn_tentacool,
  pkn_tentacruel,
  pkn_geodude,
  pkn_graveler,
  pkn_golem,
  pkn_ponyta,
  pkn_rapidash,
  pkn_slowpoke,
  pkn_slowbro,
  pkn_magnemite,
  pkn_magneton,
  pkn_farfetchd,
  pkn_doduo,
  pkn_dodrio,
  pkn_seel,
  pkn_dewgong,
  pkn_grimer,
  pkn_muk,
  pkn_shellder,
  pkn_cloyster,
  pkn_gastly,
  pkn_haunter,
  pkn_gengar,
  pkn_onix,
  pkn_drowzee,
  pkn_hypno,
  pkn_krabby,
  pkn_kingler,
  pkn_voltorb,
  pkn_electrode,
  pkn_exeggcute,
  pkn_exeggutor,
  pkn_cubone,
  pkn_marowak,
  pkn_hitmonlee,
  pkn_hitmonchan,
  pkn_lickitung,
  pkn_koffing,
  pkn_weezing,
  pkn_rhyhorn,
  pkn_rhydon,
  pkn_chansey,
  pkn_tangela,
  pkn_kangaskhan,
  pkn_horsea,
  pkn_seadra,
  pkn_goldeen,
  pkn_seaking,
  pkn_staryu,
  pkn_starmie,
  pkn_mrmime,
  pkn_scyther,
  pkn_jynx,
  pkn_electrabuzz,
  pkn_magmar,
  pkn_pinsir,
  pkn_tauros,
  pkn_magikarp,
  pkn_gyarados,
  pkn_lapras,
  pkn_ditto,
  pkn_eevee,
  pkn_vaporeon,
  pkn_jolteon,
  pkn_flareon,
  pkn_porygon,
  pkn_omanyte,
  pkn_omastar,
  pkn_kabuto,
  pkn_kabutops,
  pkn_aerodactyl,
  pkn_snorlax,
  pkn_articuno,
  pkn_zapdos,
  pkn_moltres,
  pkn_dratini,
  pkn_dragonair,
  pkn_dragonite,
  pkn_mewtwo,
  pkn_mew,
  pkn_missingno
};

//Pokemon Constants
//All the Pokemon by index numbers
//MN prefix denotes a MissingNo. Pokemon
#define PKI_RHYDON        0x01
#define PKI_KANGASKAN     0x02
#define PKI_NIDORAN       0x03
#define PKI_CLEFAIRY      0x04
#define PKI_SPEAROW       0x05
#define PKI_VOLTORB       0x06
#define PKI_NIDOKING      0x07
#define PKI_SLOWBROW      0x08
#define PKI_IVYSAUR       0x09
#define PKI_EXEGGUTOR     0x0A
#define PKI_LICKITUNG     0x0B
#define PKI_EXEGGCUTE     0x0C
#define PKI_GRIMER        0x0D
#define PKI_GENGAR        0x0E
#define PKI_NIDORAN       0x0F
#define PKI_NIDOQUEEN     0x10
#define PKI_CUBONE        0x11
#define PKI_RYHORN        0x12
#define PKI_LAPRAS        0x13
#define PKI_ARCANINE      0x14
#define PKI_MEW           0x15
#define PKI_GYRADOS       0x16
#define PKI_SHELLDER      0x17
#define PKI_TENTACOOL     0x18
#define PKI_GASTLY        0x19
#define PKI_SCYTHER       0x1A
#define PKI_STARYU        0x1B
#define PKI_BLASTOISE     0x1C
#define PKI_PINSIR        0x1D
#define PKI_TANGELA       0x1E
#define PKI_MNSCIZOR      0x1F
#define PKI_MNSHUCKLE     0x20
#define PKI_GROWLITH      0x21
#define PKI_ONIX          0x22
#define PKI_FEAROW        0x23
#define PKI_PIDGEY        0x24
#define PKI_SLOWPOKE      0x25
#define PKI_KADABRA       0x26
#define PKI_GRAVELER      0x27
#define PKI_CHANSEY       0x28
#define PKI_MACHOKE       0x29
#define PKI_MRMIME        0x2A
#define PKI_HITMONLEE     0x2B
#define PKI_HITMONCHAN    0x2C
#define PKI_ARBOK         0x2D
#define PKI_PARASECT      0x2E
#define PKI_PSYDUCK       0x2F
#define PKI_DROWZEE       0x30
#define PKI_GOLEM         0x31
#define PKI_MNHERACROSS   0x32
#define PKI_MAGMAR        0x33
#define PKI_MNHOOH        0x34
#define PKI_ELECTRABUZZ   0x35
#define PKI_MAGNETON      0x36
#define PKI_KOFFING       0x37
#define PKI_MNSNEASEL     0x38
#define PKI_MANKEY        0x39
#define PKI_SEEL          0x3A
#define PKI_DIGLETT       0x3B
#define PKI_TAUROS        0x3C
#define PKI_MNTEDDIURSA   0x3D
#define PKI_MNURSARING    0x3E
#define PKI_MNSLUGMA      0x3F
#define PKI_FARFETCHD     0x40
#define PKI_VENONAT       0x41
#define PKI_DRAGONITE     0x42
#define PKI_MNMAGCARGO    0x43
#define PKI_MNSWINUB      0x44
#define PKI_MNPILOSWINE   0x45
#define PKI_DODUO         0x46
#define PKI_POLIWAG       0x47
#define PKI_JYNX          0x48
#define PKI_MOLTRES       0x49
#define PKI_ARTICUNO      0x4A
#define PKI_ZAPDOS        0x4B
#define PKI_DITTO         0x4C
#define PKI_MEOWTH        0x4D
#define PKI_KRABBY        0x4E
#define PKI_MNCORSOLA     0x4F
#define PKI_MNREMORAID    0x50
#define PKI_MNOCTILLERY   0x51
#define PKI_VULPIX        0x52
#define PKI_NINETAILS     0x53
#define PKI_PIKACHU       0x54
#define PKI_RAICHU        0x55
#define PKI_MNDELIBIRD    0x56
#define PKI_MANTINE       0x57
#define PKI_DRATINI       0x58
#define PKI_DRAGONAIR     0x59
#define PKI_KABUTO        0x5A
#define PKI_KABUTOPS      0x5B
#define PKI_HORSEA        0x5C
#define PKI_SEADRA        0x5D
#define PKI_MNSKARMORY    0x5E
#define PKI_MNHOUNDOUR    0x5F
#define PKI_SANDSHREW     0x60
#define PKI_SANDSLASH     0x61
#define PKI_OMANYTE       0x62
#define PKI_OMASTAR       0x63
#define PKI_JIGGLYPUFF    0x64
#define PKI_WIGGLYTUFF    0x65
#define PKI_EEVEE         0x66
#define PKI_FLAREON       0x67
#define PKI_JOLTEON       0x68
#define PKI_VAPOREON      0x69
#define PKI_MACHOP        0x6A
#define PKI_ZUBAT         0x6B
#define PKI_EKANS         0x6C
#define PKI_PARAS         0x6D
#define PKI_POLIWHIRL     0x6E
#define PKI_POLIWRATH     0x6F
#define PKI_WEEDLE        0x70
#define PKI_KAKUNA        0x71
#define PKI_BEEDRILL      0x72
#define PKI_MNHOUNDOOM    0x73
#define PKI_DODRIO        0x74
#define PKI_PRIMEAPE      0x75
#define PKI_DUGTRIO       0x76
#define PKI_VENOMOTH      0x77
#define PKI_DEWGONG       0x78
#define PKI_MNKINGDRA     0x79
#define PKI_MNPHANPY      0x7A
#define PKI_CATERPIE      0x7B
#define PKI_METAPOD       0x7C
#define PKI_BUTTERFREE    0x7D
#define PKI_MACHAMP       0x7E
#define PKI_MNDONPHAN     0x7F
#define PKI_GOLDUCK       0x80
#define PKI_HYPNO         0x81
#define PKI_GOLBAT        0x82
#define PKI_MEWTWO        0x83
#define PKI_SNORLAX       0x84
#define PKI_MAGIKARP      0x85
#define PKI_MNPORIGON2    0x86
#define PKI_MNSTANTLER    0x87
#define PKI_MUK           0x88
#define PKI_MNSMEARGLE    0x89
#define PKI_KINGLER       0x8A
#define PKI_CLOYSTER      0x8B
#define PKI_MNTYROGUE     0x8C
#define PKI_ELECTRODE     0x8D
#define PKI_CLEFABLE      0x8E
#define PKI_WEEZING       0x8F
#define PKI_PERSIAN       0x90
#define PKI_MAROWAK       0x91
#define PKI_MNHITMONTOP   0x92
#define PKI_HAUNTER       0x93
#define PKI_ABRA          0x94
#define PKI_ALAKAZAM      0x95
#define PKI_PIDGEOTTO     0x96
#define PKI_PIDGEOT       0x97
#define PKI_STARMIE       0x98
#define PKI_BULBASAUR     0x99
#define PKI_VENOSAUR      0x9A
#define PKI_TENTACRUEL    0x9B
#define PKI_MNSMOOCHUM    0x9C
#define PKI_GOLDEEN       0x9D
#define PKI_SEAKING       0x9E
#define PKI_MNELEKID      0x9F
#define PKI_MNMAGBY       0xA0
#define PKI_MNMILTANK     0xA1
#define PKI_MNBLISSEY     0xA2
#define PKI_PONYTA        0xA3
#define PKI_RAPIDASH      0xA4
#define PKI_RATTATA       0xA5
#define PKI_RATICATE      0xA6
#define PKI_NIDORINO      0xA7
#define PKI_NIDORINA      0xA8
#define PKI_GEODUDE       0xA9
#define PKI_PORYGON       0xAA
#define PKI_AERODACTYL    0xAB
#define PKI_RAIKOU        0xAC
#define PKI_MAGNEMITE     0xAD
#define PKI_MNENTEI       0xAE
#define PKI_MNSUICUNE     0xAF
#define PKI_CHARMANDER    0xB0
#define PKI_SQUIRTLE      0xB1
#define PKI_CHARMELEON    0xB1
#define PKI_WARTORTLE     0xB3
#define PKI_CHARIZARD     0xB4
#define PKI_MNLARVITAR    0xB5
#define PKI_MNKBTFOSSIL   0xB6
#define PKI_MNAROFOSSIL   0xB7
#define PKI_MNGHOST       0xB8
#define PKI_ODDISH        0xB9
#define PKI_GLOOM         0xBA
#define PKI_VILEPLUME     0xBB
#define PKI_BELLSPROUT    0xBC
#define PKI_WEEPINBELL    0xBD
#define PKI_VICTREEBELL   0xBE

//All the pokemon by Pokedex Number
#define PKD_BULBASAUR     1
#define PKD_IVYSAUR       2
#define PKD_VENUSAUR      3
#define PKD_CHARMANDER    4
#define PKD_CHARMELEON    5
#define PKD_CHARIZARD     6
#define PKD_SQUIRTLE      7
#define PKD_WARTORTLE     8
#define PKD_BLASTOISE     9
#define PKD_CATERPIE      10
#define PKD_METAPOD       11
#define PKD_BUTTERFREE    12
#define PKD_WEEDLE        13
#define PKD_KAKUNA        14
#define PKD_BEEDRILL      15
#define PKD_PIDGEY        16
#define PKD_PIDGEOTTO     17
#define PKD_PIDGEOT       18
#define PKD_RATTATA       19
#define PKD_RATICATE      20
#define PKD_SPEAROW       21
#define PKD_FEAROW        22
#define PKD_EKANS         23
#define PKD_ARBOK         24
#define PKD_PIKACHU       25
#define PKD_RAICHU        26
#define PKD_SANDSHREW     27
#define PKD_SANDSLASH     28
#define PKD_NIDORANF      29
#define PKD_NIDORINA      30
#define PKD_NIDOQUEEN     31
#define PKD_NIDORANM      32
#define PKD_NIDORINO      33
#define PKD_NIDOKING      34
#define PKD_CLEFAIRY      35
#define PKD_CLEFABLE      36
#define PKD_VULPIX        37
#define PKD_NINETAILS     38
#define PKD_JIGGLYPUFF    39
#define PKD_WIGGLYPUFF    40
#define PKD_ZUBAT         41
#define PKD_GOLBAT        42
#define PKD_ODDISH        43
#define PKD_GLOOM         44
#define PKD_VILEPLUME     45
#define PKD_PARAS         46
#define PKD_PARASECT      47
#define PKD_VENONAT       48
#define PKD_VENOMOTH      49
#define PKD_DIGLETT       50
#define PKD_DUGTRIO       51
#define PKD_MEOWTH        52
#define PKD_PERSIAN       53
#define PKD_PSYDUCK       54
#define PKD_GOLDUCK       55
#define PKD_MANKEY        56
#define PKD_PRIMEAPE      57
#define PKD_GROWLITHE     58
#define PKD_ARCANINE      59
#define PKD_POLIWAG       60
#define PKD_POLIWHIRL     61
#define PKD_POLIWRATH     62
#define PKD_ABRA          63
#define PKD_KADABRA       64
#define PKD_ALAKAZAM      65
#define PKD_MACHOP        66
#define PKD_MACHOKE       67
#define PKD_MACHAMP       68
#define PKD_BELLSPROUT    69
#define PKD_WEEPINBELL    70
#define PKD_VICTREEBEL    71
#define PKD_TENTACOOL     72
#define PKD_TENTACRUEL    73
#define PKD_GEODUDE       74
#define PKD_GRAVELER      75
#define PKD_GOLEM         76
#define PKD_PONYTA        77
#define PKD_RAPIDASH      78
#define PKD_SLOWPOKE      79
#define PKD_SLOWBRO       80
#define PKD_MAGNEMITE     81
#define PKD_MAGNETON      82
#define PKD_FARFETCHD     83
#define PKD_DODUO         84
#define PKD_DODRIO        85
#define PKD_SEEL          86
#define PKD_DEWGONG       87
#define PKD_GRIMER        88
#define PKD_MUK           89
#define PKD_SHELLDER      90
#define PKD_CLOYSTER      91
#define PKD_GASTLY        92
#define PKD_HAUNTER       93
#define PKD_GENGAR        94
#define PKD_ONIX          95
#define PKD_DROWZEE       96
#define PKD_HYPNO         97
#define PKD_KRABBY        98
#define PKD_KINGLER       99
#define PKD_VOLTORB       100
#define PKD_ELECTRODE     101
#define PKD_EXEGGCUTE     102
#define PKD_EXEGUTOR      103
#define PKD_CUBONE        104
#define PKD_MAROWAK       105
#define PKD_HITMONLEE     106
#define PKD_HITMONCHAN    107
#define PKD_LICKITUNG     108
#define PKD_KOFFING       109
#define PKD_WEEZING       110
#define PKD_RHYHORN       111
#define PKD_RHYDON        112
#define PKD_CHANSEY       113
#define PKD_TANGELA       114
#define PKD_KANGASKHAN    115
#define PKD_HORSEA        116
#define PKD_SEADRA        117
#define PKD_GOLDEEN       118
#define PKD_SEAKING       119
#define PKD_STARYU        120
#define PKD_STARMIE       121
#define PKD_MRMIME        122
#define PKD_SCYTHER       123
#define PKD_JYNX          124
#define PKD_ELECTRABUZZ   125
#define PKD_MAGMAR        126
#define PKD_PINSIR        127
#define PKD_TAUROS        128
#define PKD_MAGIKARP      129
#define PKD_GYARADOS      130
#define PKD_LAPRAS        131
#define PKD_DITTO         132
#define PKD_EEVEE         133
#define PKD_VAPOREON      134
#define PKD_JOLTEON       135
#define PKD_FLAREON       136
#define PKD_PORYGON       137
#define PKD_OMANYTE       138
#define PKD_OMASTAR       139
#define PKD_KABUTO        140
#define PKD_KABUTOPS      141
#define PKD_AERODATYL     142
#define PKD_SNORLAX       143
#define PKD_ARTICUNO      144
#define PKD_ZAPDOS        145
#define PKD_MOLTRES       146
#define PKD_DRATINI       147
#define PKD_DRAGONAIR     148
#define PKD_DRAGONITE     149
#define PKD_MEWTWO        150
#define PKD_MEW           151

//All the status conditions
#define STA_SLEEP       0x04
#define STA_POISON      0x08
#define STA_BURNED      0x10
#define STA_FROZEN      0x20
#define STA_PARALYZED   0x40

//All the pokemon types
#define TYP_NORMAL      0x00
#define TYP_FIGHTING    0x01
#define TYP_FLYING      0x02
#define TYP_POISON      0x03
#define TYP_GROUND      0x04
#define TYP_ROCK        0x05
#define TYP_BUG         0x07
#define TYP_GHOST       0x08
#define TYP_FIRE        0x14
#define TYP_WATER       0x15
#define TYP_GRASS       0x16
#define TYP_ELECTRIC    0x17
#define TYP_PSYCHIC     0x18
#define TYP_ICE         0x19
#define TYP_DRAGON      0x1A

//All the moves
#define MOV_POUND             1
#define MOV_KARATE_CHOP       2
#define MOV_DOUBLE_SLAP       3
#define MOV_COMET_PUNCH       4
#define MOV_MEGA_PUNCH        5
#define MOV_PAY_DAY           6
#define MOV_FIRE_PUNCH        7
#define MOV_ICE_PUNCH         8
#define MOV_THUNDER_PUNCH     9
#define MOV_SCRATCH           10
#define MOV_VICE_GRIP         11
#define MOV_GUILLOTINE        12
#define MOV_RAZOR_WIND        13
#define MOV_SWORDS_DANCE      14
#define MOV_CUT               15
#define MOV_GUST              16
#define MOV_WING_ATTACK       17
#define MOV_WHIRLWIND         18
#define MOV_FLY               19
#define MOV_BIND              20
#define MOV_SLAM              21
#define MOV_VINE_WHIP         22
#define MOV_STOMP             23
#define MOV_DOUBLE_KICK       24
#define MOV_MEGA_KICK         25
#define MOV_JUMP_KICK         26
#define MOV_ROLLING_KICK      27
#define MOV_SAND_ATTACK       28
#define MOV_HEADBUTT          29
#define MOV_HORN_ATTACK       30
#define MOV_FURY_ATTACK       31
#define MOV_HORN_DRILL        32
#define MOV_TACKLE            33
#define MOV_BODY_SLAM         34
#define MOV_WRAP              35
#define MOV_TAKE_DOWN         36
#define MOV_THRASH            37
#define MOV_DOUBLE_EDGE       38
#define MOV_TAIL_WHIP         39
#define MOV_POISON_STING      40
#define MOV_TWINEEDLE         41
#define MOV_PIN_MISSLE        42
#define MOV_LEER              43
#define MOV_BITE              44
#define MOV_GROWL             45
#define MOV_ROAR              46
#define MOV_SING              47
#define MOV_SUPERSONIC        48
#define MOV_SONIC_BOOM        49
#define MOV_DISABLE           50
#define MOV_ACID              51
#define MOV_EMBER             52
#define MOV_FLAMETHROWER      53
#define MOV_MIST              54
#define MOV_WATER_GUN         55
#define MOV_HYDRO_PUMP        56
#define MOV_SURF              57
#define MOV_ICE_BEAM          58
#define MOV_BLIZZARD          59
#define MOV_PSYBEAM           60
#define MOV_BUBBLE_BEAM       61
#define MOV_AURORA_BEAM       62
#define MOV_HYPER_BEAM        63
#define MOV_PECK              64
#define MOV_DRILL_PECK        65
#define MOV_SUBMISSION        66
#define MOV_LOW_KICK          67
#define MOV_COUNTER           68
#define MOV_SEISMIC_TOSS      69
#define MOV_STRENGTH          70
#define MOV_ABSORB            71
#define MOV_MEGA_DRAIN        72
#define MOV_LEECH_SEED        73
#define MOV_GROWTH            74
#define MOV_RAZOR_LEAF        75
#define MOV_SOLAR_BEAM        76
#define MOV_POISON_POWDER     77
#define MOV_STUN_SPORE        78
#define MOV_SLEEP_POWDER      79
#define MOV_PETAL_DANCE       80
#define MOV_STRING_SHOT       81
#define MOV_DRAGON_RAGE       82
#define MOV_FIRE_SPIN         83
#define MOV_THUNDER_SHOCK     84
#define MOV_THUNDERBOLT       85
#define MOV_THUNDER_WAVE      86
#define MOV_THUNDER           87
#define MOV_ROCK_THROW        88  
#define MOV_EARTHQUAKE        89
#define MOV_FISSURE           90
#define MOV_DIG               91
#define MOV_TOXIC             92
#define MOV_CONFUSION         93
#define MOV_PSYCHIC           94
#define MOV_HYPNOSIS          95
#define MOV_MEDITATE          96
#define MOV_AGILITY           97
#define MOV_QUICK_ATTACK      98
#define MOV_RAGE              99
#define MOV_TELEPORT          100
#define MOV_NIGHT_SHADE       101
#define MOV_MIMIC             102
#define MOV_SCREECH           103
#define MOV_DOUBLE_TEAM       104
#define MOV_RECOVER           105
#define MOV_HARDEN            106
#define MOV_MINIMIZE          107
#define MOV_SMOKESCREEN       108
#define MOV_CONFUSE_RAY       109
#define MOV_WITHDRAW          110
#define MOV_DEFENSE_CURL      111
#define MOV_BARRIER           112
#define MOV_LIGHT_SCREEN      113
#define MOV_HAZE              114
#define MOV_REFLECT           115
#define MOV_FOCUS_ENERGY      116
#define MOV_BIDE              117
#define MOV_METRONOME         118
#define MOV_MIRROR_MOVE       119
#define MOV_SELF_DESTRUCT     120
#define MOV_EGG_BOMB          121
#define MOV_LICK              122
#define MOV_SMOG              123
#define MOV_SLUDGE            124
#define MOV_BONE_CLUB         125
#define MOV_FIRE_BLAST        126
#define MOV_WATERFALL         127
#define MOV_CLAMP             128
#define MOV_SWIFT             129
#define MOV_SKULL_BASH        130
#define MOV_SPIKE_CANNON      131
#define MOV_CONSTRICT         132
#define MOV_AMNESIA           133
#define MOV_KINESIS           134
#define MOV_SOFT_BOILED       135
#define MOV_HIGH_JUMP_KICK    136
#define MOV_GLARE             137
#define MOV_DREAM_EATER       138
#define MOV_POISON_GAS        139
#define MOV_BARRAGE           140
#define MOV_LEECH_LIFE        141
#define MOV_LOVELY_KISS       142
#define MOV_SKY_ATTACK        143
#define MOV_TRANSFORM         144
#define MOV_BUBBLE            145
#define MOV_DIZZY_PUNCH       146
#define MOV_SPORE             147
#define MOV_FLASH             148
#define MOV_PSYWAVE           149
#define MOV_SPLASH            150
#define MOV_ACID_ARMOR        151
#define MOV_CRABHAMMER        152
#define MOV_EXPLOSION         153
#define MOV_FURY_SWIPES       154
#define MOV_BONEMERANG        155
#define MOV_REST              156
#define MOV_ROCK_SLIDE        157
#define MOV_HYPER_FANG        158
#define MOV_SHARPEN           159
#define MOV_CONVERSION        160
#define MOV_TRI_ATTACK        161
#define MOV_SUPER_FANG        162
#define MOV_SLASH             163
#define MOV_SUBSTITUTE        164
#define MOV_STRUGGLE          165

//Generators
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

void gen_pokemon(struct pokemon *in_poke);
void gen_trade(struct trade *in_trade);

//Translators
byte char_to_sprite_char(char in);
void string_to_sprite_chars(char *in, byte *data_block);

#endif

