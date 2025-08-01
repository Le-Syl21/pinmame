#include "driver.h"
#include "core.h"
#include "by35.h"
#include "sndbrd.h"
#include "stsnd.h"

static const core_tLCDLayout dispst6[] = {
  {0, 0, 2,6,CORE_SEG7}, {0,14,10,6,CORE_SEG7},
  {2, 0,18,6,CORE_SEG7}, {2,14,26,6,CORE_SEG7},
  {4, 4,35,2,CORE_SEG7}, {4,10,38,2,CORE_SEG7},{0}
};
static const core_tLCDLayout dispst7[] = {
  {0, 0, 1,7,CORE_SEG87F},{0,16, 9,7,CORE_SEG87F},
  {2, 0,17,7,CORE_SEG87F},{2,16,25,7,CORE_SEG87F},
  {4, 4,35,2,CORE_SEG7}, {4,10,38,2,CORE_SEG7},{0}
};

BY35_INPUT_PORTS_START(st,1) BY35_INPUT_PORTS_END

#define INITGAME(name, gen, disp, flip, lamps, sb, db) \
static core_tGameData name##GameData = {gen,disp,{flip,0,lamps,0,sb,db}}; \
static void init_##name(void) { core_gameData = &name##GameData; }

/*----------------------------------
/ Black Sheep Squadron (Astro game)
/---------------------------------*/
INITGAME(blkshpsq,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
ASTRO_ROMSTART88(blkshpsq,"cpu_u2.716",CRC(23d6cd54) SHA1(301ba10f3f333109630dd8abd13a6b4063f805a9),
                          "cpu_u6.716",CRC(ea68b9f7) SHA1(ebb69f4faadf457454939e47d8ae6e79eb0e1a11))
BY17_ROMEND
#define input_ports_blkshpsq input_ports_st
CORE_GAMEDEFNV(blkshpsq,"Black Sheep Squadron",1978,"Astro",by35_mST100,GAME_USES_CHIMES)

/*--------------------------------
/ Gamatron (Pinstar game, 1985)
/-------------------------------*/
INITGAME(gamatron,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
PS_ROMSTART8K(gamatron,"gamatron.764",CRC(fa9f7676) SHA1(8c56868eb6af7bb8ad73523ab6583100fcadc3c1))
BY35_ROMEND
#define input_ports_gamatron input_ports_st
CORE_CLONEDEFNV(gamatron,flight2k,"Gamatron",1985,"Pinstar",by35_mST200,0)

/****************************************************/
/* STERN MPU-100 (almost identical to Bally MPU-17) */
/****************************************************/
/*--------------------------------
/ Pinball
/-------------------------------*/
INITGAME(pinball,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(pinball,"cpu_u2.716",CRC(1db32a33) SHA1(2f0a3ca36968b81f29373e4f2cf7ee28a4071882),
                         "cpu_u6.716",CRC(432e9b9e) SHA1(292e509f50bc841f6e469c198fc82c2a9095f008))
BY35_ROMEND
#define input_ports_pinball input_ports_st
CORE_GAMEDEFNV(pinball,"Pinball",1977,"Stern",by35_mST100,GAME_USES_CHIMES)

INITGAME(pinbalfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(pinbalfp,"fppinb_2.716",CRC(380667c1) SHA1(a2363c1795fe9b44064a9959dca2cf5aa08920df),
                          "fppinb_6.716",CRC(9fd9e2bb) SHA1(092e9b5d35dc59a7999b99998b0f240c93c7ba3c))
BY35_ROMEND
#define input_ports_pinbalfp input_ports_st
CORE_CLONEDEFNV(pinbalfp,pinball,"Pinball (Free Play)",1977,"Stern",by35_mST100,GAME_USES_CHIMES)

/*--------------------------------
/ Stingray (uses same ROMs as Pinball)
/-------------------------------*/
INITGAME(stingray,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(stingray,"cpu_u2.716",CRC(1db32a33) SHA1(2f0a3ca36968b81f29373e4f2cf7ee28a4071882),
                          "cpu_u6.716",CRC(432e9b9e) SHA1(292e509f50bc841f6e469c198fc82c2a9095f008))
BY35_ROMEND
#define input_ports_stingray input_ports_st
CORE_GAMEDEFNV(stingray,"Stingray",1977,"Stern",by35_mST100,GAME_USES_CHIMES)

INITGAME(stingrfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(stingrfp,"fppinb_2.716",CRC(380667c1) SHA1(a2363c1795fe9b44064a9959dca2cf5aa08920df),
                          "fppinb_6.716",CRC(9fd9e2bb) SHA1(092e9b5d35dc59a7999b99998b0f240c93c7ba3c))
BY35_ROMEND
#define input_ports_stingrfp input_ports_st
CORE_CLONEDEFNV(stingrfp,stingray,"Stingray (Free Play)",1977,"Stern",by35_mST100,GAME_USES_CHIMES)

// One of these MOD updates requires rewiring some lamps/switches to give the game more depth
// (the game originally has a number of switches and lamps shared making them rather redundant).
// See https://pinside.com/pinball/forum/topic/stingray-stern-1977-software-update
INITGAME(stingrab,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(stingrab,"Stingray_CPU_U2.2716",CRC(3084977e) SHA1(9956ac1076523e3358f3e381c8ee00d42e88751c),
                          "Stingray_CPU_U6.2716",CRC(68d18413) SHA1(6f4802a0a3e057bb87f263e0ac61a01184041e41))
BY35_ROMEND
#define input_ports_stingrab input_ports_st
CORE_CLONEDEFNV(stingrab,stingray,"Stingray (MOD rev. 14)",2022,"Stern / Quench",by35_mST100,GAME_USES_CHIMES)

/*--------------------------------
/ Stars
/-------------------------------*/
// There exists a newer 'A' version, that is so far undumped (25A-ROM-P3A.U2, 25A-ROM-P4A.U6) 
// also a tournament MOD exists (allentownpinball)
INITGAME(stars,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(stars, "25A-ROM-P3.U2",CRC(630d05df) SHA1(2baa16265d524297332fa951d9eab3e0e8d26078), /*cpu_u2.716*/
                        "25A-ROM-P4.U6",CRC(57e63d42) SHA1(619ef955553654893c3071d8b70855fee8a5e6a7)) /*cpu_u6.716*/
BY35_ROMEND
#define input_ports_stars input_ports_st
CORE_GAMEDEFNV(stars,"Stars",1978,"Stern",by35_mST100,GAME_USES_CHIMES)

INITGAME(starsfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(starsfp, "fpstars2.716",CRC(4fe7f1aa) SHA1(9da462c0973bd9531ff38a3b6d57f69cb6a2e219),
                          "fpstars6.716",CRC(c4560fd3) SHA1(1ee8863b57ae781a6dac9ebfc92f467b60e54138))
BY35_ROMEND
#define input_ports_starsfp input_ports_st
CORE_CLONEDEFNV(starsfp,stars,"Stars (Free Play)",1978,"Stern",by35_mST100,GAME_USES_CHIMES)

INITGAME(starsb,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(starsb, "starsR_v07_U2.716",CRC(896b6950) SHA1(19e84508de644ebcfd941b7ff50abc63f570dfb7),
                         "starsR_v07_U6.716",CRC(52731d64) SHA1(c007159a9cf0799cd3934b02ec2018d0dc5a39a0))
BY35_ROMEND
#define input_ports_starsb input_ports_st
CORE_CLONEDEFNV(starsb,stars,"Stars (MOD rev. 103)",2024,"Stern / slochar",by35_mST100,GAME_USES_CHIMES)

INITGAME(starsb7,GEN_STMPU100,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(starsb7,"STARS_72.U2",CRC(83064fe5) SHA1(83d6fdf8f4375bd354c7ae101cebc095ec775da8),
                         "STARS_72.U6",CRC(a34f4226) SHA1(7d9a5b9f80b41b6d7754d67ec8989105e7815957))
BY35_ROMEND
#define input_ports_starsb7 input_ports_st
CORE_CLONEDEFNV(starsb7,stars,"Stars (MOD rev. 103, 7-digit conversion)",2025,"Stern / slochar",by35_mST100,GAME_USES_CHIMES)

/*--------------------------------
/ Memory Lane
/-------------------------------*/
INITGAME(memlane,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(memlane, "cpu_u2.716",CRC(aff1859d) SHA1(5a9801d139bf2477b6d351a2654ae07516be144a),
                          "cpu_u6.716",CRC(3e236e3c) SHA1(7f631a5fac8a1b1af3b5332ba38d52553f13531a))
BY35_ROMEND
#define input_ports_memlane input_ports_st
CORE_GAMEDEFNV(memlane,"Memory Lane",1978,"Stern",by35_mST100,GAME_USES_CHIMES)

INITGAME(memlanfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_NONE,0)
BY17_ROMSTARTx88(memlanfp, "fpmeml_2.716",CRC(d6df6538) SHA1(b086eb84fbcb39b2e4067f9c939e526685c095d6),
                           "fpmeml_6.716",CRC(2c3bb145) SHA1(94e7888f8e1653fd4f5f01111f636944a3517ff2))
BY35_ROMEND
#define input_ports_memlanfp input_ports_st
CORE_CLONEDEFNV(memlanfp,memlane,"Memory Lane (Free Play)",1978,"Stern",by35_mST100,GAME_USES_CHIMES)

/* ---------------------------------------------------*/
/* All games below used MPU-100 - Sound Board: SB-100 */
/* ---------------------------------------------------*/

/*--------------------------------
/ Lectronamo
/-------------------------------*/
INITGAME(lectrono,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(lectrono,"cpu_u2.716",CRC(79e918ff) SHA1(a728eb26d941a9c7484be593a216905237d32551),
                          "cpu_u6.716",CRC(7c6e5fb5) SHA1(3aa4e0c1f377ba024e6b34bd431a188ff02d4eaa))
BY35_ROMEND
#define input_ports_lectrono input_ports_st
CORE_GAMEDEFNV(lectrono,"Lectronamo",1978,"Stern",by35_mST100s,0)

INITGAME(lectrofp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(lectrofp,"fplect_2.716",CRC(c7584530) SHA1(71d9d9081be1358af42d6ac9bfe4bdbae3d59471),
                          "fplect_6.716",CRC(11393e70) SHA1(d7a99ec82a26f8dadfef58c7d075e8e97a512d64))
BY35_ROMEND
#define input_ports_lectrofp input_ports_st
CORE_CLONEDEFNV(lectrofp,lectrono,"Lectronamo (Free Play)",1978,"Stern",by35_mST100s,0)

/*--------------------------------
/ Wild Fyre
/-------------------------------*/
INITGAME(wildfyre,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(wildfyre,"cpu_u2.716",CRC(063f8b5e) SHA1(80434de549102bff829b474603d6736b839b8999),
                          "cpu_u6.716",CRC(00336fbc) SHA1(d2c360b8a80b209ecf4ec02ee19a5234c0364504))
BY35_ROMEND
#define input_ports_wildfyre input_ports_st
CORE_GAMEDEFNV(wildfyre,"Wild Fyre",1978,"Stern",by35_mST100s,0)

INITGAME(wildfyfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(wildfyfp,"fpwldf_2.716",CRC(c53b2f2b) SHA1(e722239167abf160ff1b3dcdd5971ae51d5d5d21),
                          "fpwldf_6.716",CRC(fa3c8b9a) SHA1(627f569495c86885a2c45c2f8c65bf8c433bab61))
BY35_ROMEND
#define input_ports_wildfyfp input_ports_st
CORE_CLONEDEFNV(wildfyfp,wildfyre,"Wild Fyre (Free Play)",1978,"Stern",by35_mST100s,0)

INITGAME(wildfyrc,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(wildfyrc,"DRAC_ONE_BALL_CPU_U2.716",CRC(4f760e53) SHA1(42c87e8f41b78f81f025fcb00f7ff8b9098726f6),
                          "DRAC_ONE_BALL_CPU_U6.716",CRC(bf92e905) SHA1(5f82e30d8d43d307cb10ed0b708acd5f065b4d74))
BY35_ROMEND
#define input_ports_wildfyrc input_ports_st
CORE_CLONEDEFNV(wildfyrc,wildfyre,"Wild Fyre (One Ball MOD)",2022,"Stern / Idleman",by35_mST100s,0)

/*--------------------------------
/ Nugent (uses same ROMs as Lectronamo)
/-------------------------------*/
INITGAME(nugent,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(nugent,"cpu_u2.716",CRC(79e918ff) SHA1(a728eb26d941a9c7484be593a216905237d32551),
                        "cpu_u6.716",CRC(7c6e5fb5) SHA1(3aa4e0c1f377ba024e6b34bd431a188ff02d4eaa))
BY35_ROMEND
#define input_ports_nugent input_ports_st
CORE_GAMEDEFNV(nugent,"Nugent",1978,"Stern",by35_mST100s,0)

INITGAME(nugentfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(nugentfp,"fplect_2.716",CRC(c7584530) SHA1(71d9d9081be1358af42d6ac9bfe4bdbae3d59471),
                          "fplect_6.716",CRC(11393e70) SHA1(d7a99ec82a26f8dadfef58c7d075e8e97a512d64))
BY35_ROMEND
#define input_ports_nugentfp input_ports_st
CORE_CLONEDEFNV(nugentfp,nugent,"Nugent (Free Play)",1978,"Stern",by35_mST100s,0)

/*--------------------------------
/ Dracula (uses same ROMs as Wild Fyre)
/-------------------------------*/
// tournament MOD exists "Stern Dracula Tournament Rom V4" https://zacaj.com/p.php?id=19&title=Stern+Dracula+Tournament+Rom+V4
INITGAME(dracula,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(dracula,"cpu_u2.716",CRC(063f8b5e) SHA1(80434de549102bff829b474603d6736b839b8999),
                         "cpu_u6.716",CRC(00336fbc) SHA1(d2c360b8a80b209ecf4ec02ee19a5234c0364504))
BY35_ROMEND
#define input_ports_dracula input_ports_st
CORE_GAMEDEFNV(dracula,"Dracula",1979,"Stern",by35_mST100s,0)

INITGAME(draculfp,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(draculfp,"fpwldf_2.716",CRC(c53b2f2b) SHA1(e722239167abf160ff1b3dcdd5971ae51d5d5d21),
                          "fpwldf_6.716",CRC(fa3c8b9a) SHA1(627f569495c86885a2c45c2f8c65bf8c433bab61))
BY35_ROMEND
#define input_ports_draculfp input_ports_st
CORE_CLONEDEFNV(draculfp,dracula,"Dracula (Free Play)",1979,"Stern",by35_mST100s,0)

INITGAME(draculc,GEN_STMPU100,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100,0)
BY17_ROMSTARTx88(draculc,"DRAC_ONE_BALL_CPU_U2.716",CRC(4f760e53) SHA1(42c87e8f41b78f81f025fcb00f7ff8b9098726f6),
                         "DRAC_ONE_BALL_CPU_U6.716",CRC(bf92e905) SHA1(5f82e30d8d43d307cb10ed0b708acd5f065b4d74))
BY35_ROMEND
#define input_ports_draculc input_ports_st
CORE_CLONEDEFNV(draculc,dracula,"Dracula (One Ball MOD)",2022,"Stern / Idleman",by35_mST100s,0)

/*--------------------------------
/ Trident - uses MPU-200 inports
/-------------------------------*/
INITGAME(trident,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(trident,"25AROM_P11A.U2", CRC(6dcd6ad3) SHA1(f748acc8628c5013b630a5c7b25a1bf72e36b16d),
                         "25AROM_P12AU.U6",CRC(fb955a6f) SHA1(387080d5af318463475797fecff026d6db776a0c)) // U6 is the same as the one from Magic/Hot Hand/Cosmic Princess
BY35_ROMEND
#define input_ports_trident input_ports_st
CORE_GAMEDEFNV(trident,"Trident",1979,"Stern",by35_mST100bs,0) // Game ROM 'A'

INITGAME(tridenta,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(tridenta,"cpu_u2.716",CRC(934e49dd) SHA1(cbf6ca2759166f522f651825da0c75cf7248d3da),
                          "cpu_u6.716",CRC(540bce56) SHA1(0b21385501b83e448403e0216371487ed54026b7))
BY35_ROMEND
#define input_ports_tridenta input_ports_st
CORE_CLONEDEFNV(tridenta,trident,"Trident (Old)",1979,"Stern",by35_mST100bs,0)

INITGAME(tridenfp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(tridenfp,"fptrid_2.716",CRC(985c931b) SHA1(673a2f7aa825b2092c5b68ad1edd36e19f2ded96),
                          "fptrid_6.716",CRC(944fe5de) SHA1(8b331f03bcb761253b0e4df6a8a20e5ff33bb163))
BY35_ROMEND
#define input_ports_tridenfp input_ports_st
CORE_CLONEDEFNV(tridenfp,trident,"Trident (Old Free Play)",1979,"Stern",by35_mST100bs,0)

// New version with various changes
INITGAME(tridentb,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
ST200_ROMSTART8888(tridentb,"23ctriu1.716",CRC(5827531d) SHA1(416a469f60227815be3fc7cea1c69e6ef88d5596),
                            "23ctriu5.716",CRC(e110e8c5) SHA1(15074ba7b0fd5ea94f48fb010dd70d96dd443116),
                            "23ctriu2.716",CRC(73149e19) SHA1(5d1714588547f661e3a461dc90b8543cdc63f2e1),
                            "23ctriu6.716",CRC(4cdb117a) SHA1(c702a5eb7c01526c63af163bd2b694afc4c22f81))
BY35_ROMEND
#define input_ports_tridentb input_ports_st
CORE_CLONEDEFNV(tridentb,trident,"Trident (MOD 1 rev. 23c)",2009,"Stern / Idleman",by35_mST100bs,0)

INITGAME(tridentc,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY35_ROMSTARTx00(tridentc,"Trident_CPU_U2.2732",CRC(de4381c6) SHA1(605c7761999a0b17d8490371f42ad70c0509059e),
                          "Trident_CPU_U6.2732",CRC(e7f72cdc) SHA1(3cddc0613dd4c6cffc37955816bf1d756dfb1757))
BY35_ROMEND
#define input_ports_tridentc input_ports_st
CORE_CLONEDEFNV(tridentc,trident,"Trident (MOD 2 rev. 19)",2022,"Stern / Quench",by35_mST100bs,0)

/*--------------------------------
/ Hot Hand - uses MPU-200 inports
/-------------------------------*/
// tournament MOD exists (by idleman??)
INITGAME(hothand,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(hothand,"cpu_u2.716",     CRC(5e79ea2e) SHA1(9b45c59b2076fcb3a35de1dd3ba2444ea852f149),
                         "25AROM_P12AU.U6",CRC(fb955a6f) SHA1(387080d5af318463475797fecff026d6db776a0c)) /*cpu_u6.716*/
BY35_ROMEND
#define input_ports_hothand input_ports_st
CORE_GAMEDEFNV(hothand,"Hot Hand",1979,"Stern",by35_mST100bs,0)

INITGAME(hothanfp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(hothanfp,"fphoth_2.716",CRC(8757431b) SHA1(7ea13f2abc2b2322d08e419c66cca8cf22040e7f),
                          "fphoth_6.716",CRC(709dbde2) SHA1(c8ee72344b098e0edb16d4957627d283b1a34f50))
BY35_ROMEND
#define input_ports_hothanfp input_ports_st
CORE_CLONEDEFNV(hothanfp,hothand,"Hot Hand (Free Play)",1979,"Stern",by35_mST100bs,0)

/*--------------------------------
/ Magic - uses MPU-200 inports
/-------------------------------*/
INITGAME(magic,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(magic,"cpu_u2.716",     CRC(8838091f) SHA1(d2702b5e15076793b4560c77b78eed6c1da571b6),
                       "25AROM_P12AU.U6",CRC(fb955a6f) SHA1(387080d5af318463475797fecff026d6db776a0c)) /*cpu_u6.716*/
BY35_ROMEND
#define input_ports_magic input_ports_st
CORE_GAMEDEFNV(magic,"Magic",1979,"Stern",by35_mST100bs,0)

INITGAME(magicfp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(magicfp,"fpmagic2.716",CRC(7b770230) SHA1(f3aa59779a1662d3e7accb12786e14e9f344c657),
                         "fpmagic6.716",CRC(3bc9594a) SHA1(7cd3954b28bac605e7dc08b6144bfdd237d75643))
BY35_ROMEND
#define input_ports_magicfp input_ports_st
CORE_CLONEDEFNV(magicfp,magic,"Magic (Free Play)",1979,"Stern",by35_mST100bs,0)

INITGAME(magicb,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY35_ROMSTARTx00(magicb,"Magic_CPU_U2.2732",CRC(cc3e7fac) SHA1(1653e738e395a6fa397ae78b8e4d2ca2561946da),
                        "Magic_CPU_U6.2732",CRC(e7f72cdc) SHA1(3cddc0613dd4c6cffc37955816bf1d756dfb1757))
BY35_ROMEND
#define input_ports_magicb input_ports_st
CORE_CLONEDEFNV(magicb,magic,"Magic (MOD rev. 19)",2022,"Stern / Quench",by35_mST100bs,0)

/*-------------------------------------
/ Cosmic Princess (uses same ROMs as Magic)
/-------------------------------------*/
INITGAME(princess,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(princess,"cpu_u2.716",     CRC(8838091f) SHA1(d2702b5e15076793b4560c77b78eed6c1da571b6),
                          "25AROM_P12AU.U6",CRC(fb955a6f) SHA1(387080d5af318463475797fecff026d6db776a0c)) /*cpu_u6.716*/
BY35_ROMEND
#define input_ports_princess input_ports_st
CORE_GAMEDEFNV(princess,"Cosmic Princess",1979,"Stern",by35_mST100bs,0)

INITGAME(princefp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY17_ROMSTARTx88(princefp,"fpmagic2.716",CRC(7b770230) SHA1(f3aa59779a1662d3e7accb12786e14e9f344c657),
                          "fpcosp_6.716",CRC(27e45565) SHA1(55e56b12225ecccecb3c71f9c7134246436eb2d1)) //!! why is this one different compared to the Magic free play u6?
BY35_ROMEND
#define input_ports_princefp input_ports_st
CORE_CLONEDEFNV(princefp,princess,"Cosmic Princess (Free Play)",1979,"Stern",by35_mST100bs,0)

INITGAME(princesb,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST100B,0)
BY35_ROMSTARTx00(princesb,"CosmicPrincess_CPU_U2.2732",CRC(12138d2e) SHA1(523773843a113faeaa4869541db5a7dcaadfb42c),
                          "Magic_CPU_U6.2732",         CRC(e7f72cdc) SHA1(3cddc0613dd4c6cffc37955816bf1d756dfb1757))
BY35_ROMEND
#define input_ports_princesb input_ports_st
CORE_CLONEDEFNV(princesb,princess,"Cosmic Princess (MOD rev. 19)",2022,"Stern / Quench",by35_mST100bs,0)

/****************************************************/
/* STERN MPU-200 (almost identical to Bally MPU-35) */
/****************************************************/
/* ---------------------------------------------------*/
/* All games below used MPU-200 - Sound Board: SB-300 */
/* ---------------------------------------------------*/

/*--------------------------------
/ Meteor
/-------------------------------*/
INITGAME(meteor,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteor,"cpu_u1.716",CRC(e0fd8452) SHA1(a13215378a678e26a565742d81fdadd2e161ba7a),
                          "cpu_u5.716",CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                          "cpu_u2.716",CRC(fd396792) SHA1(b5d051a7ce7e7c2f9c4a0d900cef4f9ef2089476),
                          "cpu_u6.716",CRC(03fa346c) SHA1(51c04123cb433e90920c241e2d1f89db4643427b))
BY35_ROMEND
#define input_ports_meteor input_ports_st
CORE_GAMEDEFNV(meteor,"Meteor",1979,"Stern",by35_mST200,0)

/*pinside:
The bug isn't necessarily dependent on the spinner, but does have to do with the Bonus X and the 'Collect All Rockets' light on the outlanes -
As I understand it, the 'Collect All Rockets' routine saves data to a RAM location that is right adjacent to the Bonus 'X' save location. If something CPU intensive happens, a race condition will occur where the 'Collect All Rockets' code will save and then clear a value as another thread is trying to read the Bonus X. The Bonus X thread will then get an incorrect number (255), and think that's your bonus. It will then count down your rockets (even if you have none) from 255x. Interestingly, how the lights are stored in RAM, you can watch the 'Game Over' light on the backbox switch on and off - that light, essentially, is your '8x' bonus light.
The ROM set listed as 'Alternate' is officially released from Stern, and it changes the RAM location for one of those two functions, avoiding the collision. */

/*rec.games.pinball:
If you have all rockets lit on the outlanes, AND you have a lot of other
scoring things going on(usually related to a spinner hit since that
keeps repeating) you can overload the thread engine in the game, such
that the 'collect all rockets' thread(which unnecessarily gives a sound
effect and scores for each rocket instead of just scoring it at
once...i.e.there are delays built into the thread which turn out to
cause the error.).

Once the collect all rockets thread is running AND the thread starts
that collects the bonus in the outhole, you will get a zero inserted
into the bonus multiplier....which will count down 255x (if you wait
long enough).It's not infinite, and has nothing to do with the speed
of the game.Its simply because the collect all rockets thread isn't
finished when the collect bonus thread starts....and the error is
because the multiplier in the collect bonus thread is stored in the same
memory location that the collect all rockets thread uses as well.  2
threads that were never intended to run at the same time using the same
memory location is sure to cause errors.

It's more likely to happen the more rockets you have (since that extends
out the collect all rockets thread execution) and with the spinner as it
keeps adding another thread onto the execution(the spinner thread is
exceptionally long as it has almost 2k (that's 25% of the entire
codebase!) dedicated to seeing which lamps are lit, what multiplier you
have, and moving those lamps around.)  This is extremely sloppy in
stern's thread language and really could be changed to inline assembly
to save TONS of space.

Stern's fix from way back when was to utilize the lower part of the
stack to do the same thing.I don't think that way is 100% safe (they
didn't use the BOTTOM of the stack - they used somewhere in the middle)
- but it's probably safe enough.  Put enough extra threads in play
though and you'd probably clobber it.*/
INITGAME(meteora,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteora,"cpu_u1a.716",CRC(9ee33909) SHA1(5f58e4e72af47047c8f060f98706ed9607720705), // U1A is Stern's factory bug-fixed version of their original buggy U1
                           "cpu_u5.716", CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                           "cpu_u2.716", CRC(fd396792) SHA1(b5d051a7ce7e7c2f9c4a0d900cef4f9ef2089476),
                           "cpu_u6.716", CRC(03fa346c) SHA1(51c04123cb433e90920c241e2d1f89db4643427b))
BY35_ROMEND
#define input_ports_meteora input_ports_st
CORE_GAMEDEFNV(meteora,"Meteor (Bonus Count Offical Fix)",1979,"Stern",by35_mST200,0)

// see above, differently fixed version (before it was known what meteora actually fixed)
INITGAME(meteorbf,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorbf,"cpu_u1.716",  CRC(e0fd8452) SHA1(a13215378a678e26a565742d81fdadd2e161ba7a),
                            "cpu_u5.716",  CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                            "cpu_u2bf.716",CRC(8d1a4a0b) SHA1(12c75b613fba34c4db87afb78f598c8cd9989bf4),
                            "cpu_u6bf.716",CRC(e185ca50) SHA1(b82521d2dd97a9af2a522745256f6ebc2db95eab))
BY35_ROMEND
#define input_ports_meteorbf input_ports_st
CORE_CLONEDEFNV(meteorbf,meteor,"Meteor (Bonus Count Fix)",1979,"Stern",by35_mST200,0)

// see above, plus some sound issues with NVRAM have been addressed in the modified U6a rom by a specific clearing of the sound registers during bootup before machine initialization
INITGAME(meteora2,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteora2,"cpu_u1a.716",CRC(9ee33909) SHA1(5f58e4e72af47047c8f060f98706ed9607720705),
                            "cpu_u5.716", CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                            "cpu_u2.716", CRC(fd396792) SHA1(b5d051a7ce7e7c2f9c4a0d900cef4f9ef2089476),
                            "cpu_u6a.716",CRC(95e95131) SHA1(92f7563802d22007f6da3d7c5fdfa6af2ca35e2d))
BY35_ROMEND
#define input_ports_meteora2 input_ports_st
CORE_CLONEDEFNV(meteora2,meteor,"Meteor (Bonus Count and Sound Fix)",2019,"Stern / Idleman",by35_mST200,0)

INITGAME(meteorfp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorfp,"fpmet_u1.716",CRC(7a5472ce) SHA1(7e3be954b66e5f61cfdbb189fa60ca33ad40a975),
                            "cpu_u5.716",  CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                            "cpu_u2.716",  CRC(fd396792) SHA1(b5d051a7ce7e7c2f9c4a0d900cef4f9ef2089476),
                            "fpmet_u6.716",CRC(0bd52abc) SHA1(2a40bcffbfc28b44c5badf1833ce6b1bd76a02e5))
BY35_ROMEND
#define input_ports_meteorfp input_ports_st
CORE_CLONEDEFNV(meteorfp,meteor,"Meteor (Free Play)",1979,"Stern",by35_mST200,0)

/* From rec.games.pinball, No background sound in Meteor:
In Rom U1, offset A6 change 57 to 2f. Change offset A9 from 2f to 57.
In Rom U2, offset CC - CD change fe 02 to 39 c7.
Test it out and let me know how it sounds I can only tell so far in
pinmame. It will no longer play the add a player sound as far as I can
tell but the background sound should be off. */
INITGAME(meteorns,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorns,"cpu_u1ns.716",CRC(579aa7ce) SHA1(71b6b749aeb22064bbaf632a5129ab512b69b982),
                            "cpu_u5.716",  CRC(43a46997) SHA1(2c74ca10cf9091db10542960f499f39f3da277ee),
                            "cpu_u2ns.716",CRC(1680af01) SHA1(e9dd51e0cbe87ff55963ca1c57ee765c10630eed),
                            "cpu_u6.716",  CRC(03fa346c) SHA1(51c04123cb433e90920c241e2d1f89db4643427b))
BY35_ROMEND
#define input_ports_meteorns input_ports_st
CORE_CLONEDEFNV(meteorns,meteor,"Meteor (No Background Sound)",2011,"Stern / Scott",by35_mST200,0)

INITGAME(meteore,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteore,"meteor64a-u1.716",CRC(1854eeef) SHA1(3d7c0eafc06e98ea6a6ba838926db77f246689b4),
                           "meteor64a-u5.716",CRC(3562c73a) SHA1(de6fb056190459bec9c4f51505278ab06db81958),
                           "meteor64a-u2.716",CRC(2036529d) SHA1(5c2fbaea21180d28d959a79a39640379dc2e9d37),
                           "meteor64a-u6.716",CRC(88148373) SHA1(af443866b05916646b2615fe242c577b4ae0edb9))
BY35_ROMEND
#define input_ports_meteore input_ports_st
CORE_CLONEDEFNV(meteore,meteor,"Meteor (Bonus Count Fix, MOD, Free Play rev. 64)",2019,"Stern / Idleman",by35_mST200,0)

INITGAME(meteorf,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorf,"meteor65-u1.716", CRC(9ccd236f) SHA1(4261ab6188aa3534459f2818100de19a8c64657f),
                           "meteor65-u5.716", CRC(d79fa4ee) SHA1(968ced25ae1cb823dedb004211281e6a0e8f178e),
                           "meteor65-u2.716", CRC(2efca800) SHA1(bb1810d37904fff1226028e70eac45ad9e967dc7),
                           "meteor65-u6.716", CRC(ccca52d5) SHA1(fbf74dba227517531dac9a3deb2bc44a295697e9))
BY35_ROMEND
#define input_ports_meteorf input_ports_st
CORE_CLONEDEFNV(meteorf,meteor,"Meteor (Bonus Count Fix, MOD, Free Play rev. 65)",2020,"Stern / Idleman",by35_mST200,0)

// Adds some features, fixes endless bonus bug
INITGAME(meteorg,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorg,"meteor-v66-u1.716", CRC(55c6bee9) SHA1(8f7a132de597770f245622243c5b462f7553a138),
                           "meteor-v66-u5.716", CRC(7e803d1f) SHA1(62c7f31a0aafe4f9795b77f6a17d7bccd4cd8cdd),
                           "meteor-v66-u2.716", CRC(3fe2b858) SHA1(23937813f3e89bc7481e45a5e45cdf47b5fb308d),
                           "meteor-v66-u6.716", CRC(d79faaca) SHA1(c9c62da064aa81a3c342d7fcde7f8c0185870a72))
BY35_ROMEND
#define input_ports_meteorg input_ports_st
CORE_CLONEDEFNV(meteorg,meteor,"Meteor (Bonus Count Fix, MOD, Free Play rev. 66)",2021,"Stern / Idleman",by35_mST200,0)

/*--------------------------------
/ Meteor (7-digit conversion)
/-------------------------------*/
INITGAME(meteorb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorb,"cpu_u1.716",CRC(e0fd8452) SHA1(a13215378a678e26a565742d81fdadd2e161ba7a),
                          "cpu_u5b.716",CRC(fe374449) SHA1(6ed39ae54a65a37d1d9bff52a12c5e9caee90cf1),
                          "cpu_u2b.716",CRC(62cd0484) SHA1(754bb6a7c3c6024b642dba4bc148ed110ab14295),
                          "cpu_u6b.716",CRC(10cb5d60) SHA1(1d3da195fbe06b49d08e4ce2ebc5d9d811126aa6))
BY35_ROMEND
#define input_ports_meteorb input_ports_meteor
CORE_CLONEDEFNV(meteorb,meteor,"Meteor (7-digit conversion)",2003,"Stern / Oliver",by35_mST200,0)

INITGAME(meteorc,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorc,"fp10met1.716",CRC(4b92583f) SHA1(44c78d856694d7fb34089f78212deac18a7c149f),
                           "fp10met5.716",CRC(cd795f7a) SHA1(8f6113c7415cf5d2cf09d17c7de7f8e3d1c84334),
                           "fp10met2.716",CRC(5a33ed97) SHA1(86c0c6cc68c33cdab603b65ec1dd30e208e0b1c1),
                           "fp10met6.716",CRC(2ae8e9fb) SHA1(60af7ffef90382c7bf4ec7612e079114481825e1))
BY35_ROMEND
#define input_ports_meteorc input_ports_meteor
CORE_CLONEDEFNV(meteorc,meteor,"Meteor (7-digit conversion Free Play)",2003,"Stern / Oliver",by35_mST200,0)

INITGAME(meteord,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteord,"cpu_u1.716",    CRC(e0fd8452) SHA1(a13215378a678e26a565742d81fdadd2e161ba7a),
                           "cpu_u5_d10.716",CRC(a0ac4dac) SHA1(05943374cdc9d67a20a00c62213e04f8f72c772c),
                           "fp10met2.716",  CRC(5a33ed97) SHA1(86c0c6cc68c33cdab603b65ec1dd30e208e0b1c1),
                           "fp10met6.716",  CRC(2ae8e9fb) SHA1(60af7ffef90382c7bf4ec7612e079114481825e1))
BY35_ROMEND
#define input_ports_meteord input_ports_meteor
CORE_CLONEDEFNV(meteord,meteor,"Meteor (/10 Scoring)",2005,"Stern / Oliver",by35_mST200,0)

INITGAME(meteore7,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteore7,"meteor74a-u1.716",CRC(92e9c6a1) SHA1(4b044efd5d3136d4749bf2184f714f2af9a6d487),
                            "meteor74a-u5.716",CRC(25de4151) SHA1(530e75e2c28e5480bf13682c4c7def19bbb9ab87),
                            "meteor74a-u2.716",CRC(3ab7e5fa) SHA1(a751b40ecea0e0d6054bffed6be09d971a3c748a),
                            "meteor74a-u6.716",CRC(8d6e6e97) SHA1(0fde3ee4956071f1fcad7acd5311588d6e442a39))
BY35_ROMEND
#define input_ports_meteore7 input_ports_st
CORE_CLONEDEFNV(meteore7,meteor,"Meteor (Bonus Count Fix, MOD, 7-Digit, Free Play rev. 74)",2019,"Stern / Idleman",by35_mST200,0)

INITGAME(meteorf7,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorf7,"meteor75-u1.716",CRC(7b7ee764) SHA1(860edb5870a4f0c6c243dd7be053e003d3f1cdc6),
                            "meteor75-u5.716",CRC(98ec3e9d) SHA1(32613c126bda418037e97329f87edb09ee58fb6c),
                            "meteor75-u2.716",CRC(3f0c5bca) SHA1(da3c887a4dd719926af090cd2c96d6b3b57540b5),
                            "meteor75-u6.716",CRC(eb1693a6) SHA1(955d7a9292e6bc6fb9e3a9ee41fab9e9ac6077b2))
BY35_ROMEND
#define input_ports_meteorf7 input_ports_st
CORE_CLONEDEFNV(meteorf7,meteor,"Meteor (Bonus Count Fix, MOD, 7-Digit, Free Play rev. 75)",2020,"Stern / Idleman",by35_mST200,0)

// Adds some features, fixes endless bonus bug
INITGAME(meteorg7,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(meteorg7,"meteor-v76-u1.716",CRC(b2757ae2) SHA1(f786e4431e5fa353dd7f0c359b56e5d16deff258),
                            "meteor-v76-u5.716",CRC(c118cb50) SHA1(a525f1b250727238b87279788c68579238adbbc4),
                            "meteor-v76-u2.716",CRC(40fdcd36) SHA1(4edb6a3d1998f5d817e13e04739667fcbc57b692),
                            "meteor-v76-u6.716",CRC(9a38cd43) SHA1(f35f8f2ffa390d2485cb51ecab3829fe8ab410ca))
BY35_ROMEND
#define input_ports_meteorg7 input_ports_st
CORE_CLONEDEFNV(meteorg7,meteor,"Meteor (Bonus Count Fix, MOD, 7-Digit, Free Play rev. 76)",2021,"Stern / Idleman",by35_mST200,0)

/*--------------------------------
/ Galaxy
/-------------------------------*/
INITGAME(galaxy,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(galaxy,"cpu_u1.716",CRC(35656b67) SHA1(e1ad9456c561d19220f8607576cb505588512179),
                          "cpu_u5.716",CRC(12be0601) SHA1(d651b834348c071dda660f37b4e359bf01cbd8d3),
                          "cpu_u2.716",CRC(08bdb285) SHA1(7984835ac151e5dac05628f3d5146d20e3623c38),
                          "cpu_u6.716",CRC(ad846a42) SHA1(303c9cb933ca60d35e12793a4ac0cf7ef11bc92e))
BY35_ROMEND
#define input_ports_galaxy input_ports_st
CORE_GAMEDEFNV(galaxy,"Galaxy",1980,"Stern",by35_mST200,0)

/* From rec.games.pinball:
OK, because I'm a masochist who likes a challenge, spots planet
including giving you the score for it and multiplier:
Spot next planet when you go into saucer:

Rom U6, offset $FA:
Change 3b 00 5b
TO: 27 5f 00

Offset 700-706:
should be all $FF at this point
change to:
700: 3b 00 5b 27 6b e7 0a*/
INITGAME(galaxyps,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(galaxyps,"cpu_u1.716",  CRC(35656b67) SHA1(e1ad9456c561d19220f8607576cb505588512179),
                            "cpu_u5.716",  CRC(12be0601) SHA1(d651b834348c071dda660f37b4e359bf01cbd8d3),
                            "cpu_u2.716",  CRC(08bdb285) SHA1(7984835ac151e5dac05628f3d5146d20e3623c38),
                            "cpu_u6ps.716",CRC(de4af8c0) SHA1(ed10dc48045cd8e3d6996eeca6baf695ccd3fcfd))
BY35_ROMEND
#define input_ports_galaxyps input_ports_st
CORE_CLONEDEFNV(galaxyps,galaxy,"Galaxy (Planet Skillshot)",2011,"Stern / Scott",by35_mST200,0)

INITGAME(galaxyfp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(galaxyfp,"cpu_u1.716",  CRC(35656b67) SHA1(e1ad9456c561d19220f8607576cb505588512179),
                            "cpu_u5.716",  CRC(12be0601) SHA1(d651b834348c071dda660f37b4e359bf01cbd8d3),
                            "fpgal_u2.716",CRC(c41ce9e8) SHA1(15e344cb72ce80fa5baa0136f2ca461b1d7d39ac),
                            "fpgal_u6.716",CRC(a5ab7492) SHA1(b7c2635ab721d50f87e87cbf779cab7c787be222))
BY35_ROMEND
#define input_ports_galaxyfp input_ports_st
CORE_CLONEDEFNV(galaxyfp,galaxy,"Galaxy (Free Play)",1980,"Stern",by35_mST200,0)

/*--------------------------------
/ Galaxy (7-digit conversion)
/-------------------------------*/
INITGAME(galaxyb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(galaxyb,"cpu_u1b.716",CRC(53f7c0c9) SHA1(c3ee8bbdd1eca7a044c7abf4e0ba6059f523c323),
                           "cpu_u5b.716",CRC(1b1cd31b) SHA1(65a6a58d2c509419fce3142a9ae88d8ea7d25f1c),
                           "cpu_u2b.716",CRC(f0b4e60b) SHA1(e1628ec94585fbf4935e824721472cc9c91bbf89),
                           "cpu_u6b.716",CRC(be4eacc1) SHA1(3d95e8e859312ef0a7ed52356dabe35ed0bebdef))
BY35_ROMEND
#define input_ports_galaxyb input_ports_galaxy
CORE_CLONEDEFNV(galaxyb,galaxy,"Galaxy (7-digit conversion)",2003,"Stern / Oliver",by35_mST200,0) // rev. 2

INITGAME(galaxyc,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(galaxyc,"GALAXYF_708_U1.716",CRC(3ed417b0) SHA1(76c81b7f7ec56bccea8696e57889a453686281e5),
                           "GALAXYF_708_U5.716",CRC(f90d54e1) SHA1(bbccaf1fafceea73e96a503b853557520fe43a0d),
                           "GALAXYF_708_U2.716",CRC(4e74e6ec) SHA1(324a85c38d91a7ce74e32c94b849d5db23e35641),
                           "GALAXYF_708_U6.716",CRC(75630cb2) SHA1(44bd55d2eefc3c0eaeb610ca4c54c1c09dc3d5d6))
BY35_ROMEND
#define input_ports_galaxyc input_ports_galaxy
CORE_CLONEDEFNV(galaxyc,galaxy,"Galaxy (7-Digit conversion, Fixes & modified rules)",2023,"Stern / Idleman",by35_mST200,0)

/*--------------------------------
/ Ali
/-------------------------------*/
INITGAME(ali,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ali,"cpu_u1.716",CRC(92e75b40) SHA1(bace68db0ea12d50a546157d11084f3b00949136),
                       "cpu_u5.716",CRC(119a4300) SHA1(e913d9bd399b90502efe110c8bf7f23ae07df276),
                       "cpu_u2.716",CRC(9c91d08f) SHA1(a3e8c8e8c2c8b03d86b36eea8c84e5c0a27b8444),
                       "cpu_u6.716",CRC(7629db56) SHA1(f922d31ec4dd1755da0a24bec4e3fa3a7a9b22fc))
BY35_ROMEND
#define input_ports_ali input_ports_st
CORE_GAMEDEFNV(ali,"Ali",1980,"Stern",by35_mST200,0)

INITGAME(alifp,GEN_STMPU200,dispst6,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(alifp,"fpali_u1.716",CRC(85888cfa) SHA1(286bce3a2e1cbedc224c10d884f5db8b7ffa2a75),
                         "fpali_u5.716",CRC(52b8e39e) SHA1(267921c2a5636d1f2cc93f0913f005a3e50801a4),
                         "cpu_u2.716",  CRC(9c91d08f) SHA1(a3e8c8e8c2c8b03d86b36eea8c84e5c0a27b8444),
                         "cpu_u6.716",  CRC(7629db56) SHA1(f922d31ec4dd1755da0a24bec4e3fa3a7a9b22fc))
BY35_ROMEND
#define input_ports_alifp input_ports_st
CORE_CLONEDEFNV(alifp,ali,"Ali (Free Play)",1980,"Stern",by35_mST200,0)

INITGAME(alib,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(alib,"alif_F76_U1.716",CRC(4fbeee49) SHA1(99617d8e8408ee2728328328176878fe061a1f7e),
                        "alif_F76_U5.716",CRC(c0a705fb) SHA1(dab391b57f5648cb6a827008af9bbbcc3000ce92),
                        "alif_F76_U2.716",CRC(3ed8f851) SHA1(229d0c07e597e156c43b5c945ee21c62a091ce25),
                        "alif_F76_U6.716",CRC(09486559) SHA1(fda5596b26590b565aad3dd802bb042b266d99d7))
BY35_ROMEND
#define input_ports_alib input_ports_st
CORE_GAMEDEFNV(alib,"Ali (7-digit conversion Free Play rev. 76)",2023,"Stern / Idleman",by35_mST200,0)

INITGAME(alic,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(alic,"alif_85_U1.716",CRC(431417f1) SHA1(4be628cee11c454b5e16e10cb407435c376d390f),
                        "alif_85_U5.716",CRC(7ca78289) SHA1(22dfcfd1dd442b2e46bb697cbf450f10558e4ee5),
                        "alif_85_U2.716",CRC(10298e80) SHA1(ea66c215d8d880b0e871131053c5225499dccc17),
                        "alif_85_U6.716",CRC(522f48ec) SHA1(e6a1a042309ef31db57e86db95c1fb01a62da5cf))
BY35_ROMEND
#define input_ports_alic input_ports_st
CORE_GAMEDEFNV(alic,"Ali (7-digit conversion Free Play rev. 85)",2023,"Stern / slochar",by35_mST200,0)

/*--------------------------------
/ Big Game
/-------------------------------*/
INITGAME(biggame,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggame,"cpu_u1.716",CRC(f59c7514) SHA1(49ab034a21e70956f63327aec4cbae115cd66a66),
                           "cpu_u5.716",CRC(57df1dc5) SHA1(283f45879b76d56ba0db0fb3d9d9771f91a70d02),
                           "cpu_u2.716",CRC(0251039b) SHA1(0a0e662788cf012dfb773d200c542a2a363748a8),
                           "cpu_u6.716",CRC(801e9a66) SHA1(8634d6bd4af3e5ec3b736679393462961b76ede1))
BY35_ROMEND
#define input_ports_biggame input_ports_st
CORE_GAMEDEFNV(biggame,"Big Game",1980,"Stern",by35_mST200,0)

INITGAME(biggamfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggamfp,"cpu_u1.716", CRC(f59c7514) SHA1(49ab034a21e70956f63327aec4cbae115cd66a66),
                            "cpu_u5.716", CRC(57df1dc5) SHA1(283f45879b76d56ba0db0fb3d9d9771f91a70d02),
                            "fpbg_u2.716",CRC(e74dc6fe) SHA1(37d178d236f921ea4d95bed42f7683e428ca2da9),
                            "cpu_u6.716", CRC(801e9a66) SHA1(8634d6bd4af3e5ec3b736679393462961b76ede1))
BY35_ROMEND
#define input_ports_biggamfp input_ports_st
CORE_CLONEDEFNV(biggamfp,biggame,"Big Game (Free Play)",1980,"Stern",by35_mST200,0)

INITGAME(biggameb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggameb,"big7d_u1.716",CRC(3ada866e) SHA1(e56474422960dee6332aa97e41951c480492b049),
                            "big7d_u5.716",CRC(014418c1) SHA1(24b869e51b64f92ba2217c075cac6243b3634c97),
                            "big7d_u2.716",CRC(5389867f) SHA1(fd4cc8d7ccd7cff72fa883c962567e21117507b9),
                            "big7d_u6.716",CRC(35406708) SHA1(ec86ef0070f6ce1f8ce3b5ebae81ca6a035f64ca))
BY35_ROMEND
#define input_ports_biggameb input_ports_st
CORE_CLONEDEFNV(biggameb,biggame,"Big Game (MOD rev. 7)",2019,"Stern / Idleman",by35_mST200,0)

INITGAME(biggamec,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggamec,"big08_u1.716",CRC(b5cdce2d) SHA1(70f0c81d2db71921df8379782320e5b58c0e8a09),
                            "big08_u5.716",CRC(ed7b5113) SHA1(1a0bcdd288e46bdd2f5f51a8ec0c6c982286213f),
                            "big7d_u2.716",CRC(5389867f) SHA1(fd4cc8d7ccd7cff72fa883c962567e21117507b9),
                            "big08_u6.716",CRC(7d83db44) SHA1(cf7a7187e234a9905b0c9d74a18f2915c83f70c0))
BY35_ROMEND
#define input_ports_biggamec input_ports_st
CORE_CLONEDEFNV(biggamec,biggame,"Big Game (MOD rev. 8)",2020,"Stern / Idleman",by35_mST200,0)

INITGAME(biggamed,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggamed,"bigV09_u1.716",CRC(97a7a525) SHA1(c5cf03ef6b7f57dcb82de0479564d13b83abb6bc),
                            "bigV09_u5.716",CRC(fff35283) SHA1(3a2f2a40ff62aaed9dc8cc580fdbd55391448ec9),
                            "bigV09_u2.716",CRC(5389867f) SHA1(fd4cc8d7ccd7cff72fa883c962567e21117507b9),
                            "bigV09_u6.716",CRC(16a72b30) SHA1(2e429f4b29d41df230fbc2baf7e20f758a314093))
BY35_ROMEND
#define input_ports_biggamed input_ports_st
CORE_CLONEDEFNV(biggamed,biggame,"Big Game (MOD rev. 9)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(biggamee,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggamee,"biggame_V12-u1.716",CRC(94efc96f) SHA1(476f1f67b3875a3764cb71f11bb6825a6ad2630c),
                            "biggame_V12-u5.716",CRC(44a9a2ba) SHA1(b7ef9b565c90ec71dd8779220203c3b203658904),
                            "biggame_V12-u2.716",CRC(e5595e87) SHA1(95d8fe376f1e0c4cb847cd911e2ed831a0e14cfd),
                            "biggame_V12-u6.716",CRC(7a7e67e4) SHA1(7a964db3f92775ea7fc50a90e77fb846fa3f9d9f))
BY35_ROMEND
#define input_ports_biggamee input_ports_st
CORE_CLONEDEFNV(biggamee,biggame,"Big Game (MOD rev. 12)",2023,"Stern / Idleman",by35_mST200,0)

INITGAME(biggamef,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(biggamef,"biggame_13-u1.716", CRC(a05b5a3e) SHA1(dfedcc5faf06ce37c4487ca574c56f3285458a36),
                            "biggame_V12-u5.716",CRC(44a9a2ba) SHA1(b7ef9b565c90ec71dd8779220203c3b203658904),
                            "biggame_13-u2.716", CRC(4c321f34) SHA1(923b43a6dcd2e714fbc13aeb28651325885e4220),
                            "biggame_V12-u6.716",CRC(7a7e67e4) SHA1(7a964db3f92775ea7fc50a90e77fb846fa3f9d9f))
BY35_ROMEND
#define input_ports_biggamef input_ports_st
CORE_CLONEDEFNV(biggamef,biggame,"Big Game (MOD rev. 13)",2024,"Stern / Idleman",by35_mST200,0)

/*--------------------------------
/ Seawitch
/-------------------------------*/
INITGAME(seawitch,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitch,"cpu_u1.716",CRC(c214140b) SHA1(4d68ddd3b0f051c5f601ea5b9d5d5195d6017304),
                            "cpu_u5.716",CRC(ab2eab3a) SHA1(80a8c1ccd554be279720a26466bd6c59e1e56df0),
                            "cpu_u2.716",CRC(b8844174) SHA1(6e01321196fd6fce7b5526efc402044c87fe96a6),
                            "cpu_u6.716",CRC(6c296d8f) SHA1(8cdb77f382ef1214ef45579213cf8f19141366ad))
BY35_ROMEND
#define input_ports_seawitch input_ports_st
CORE_GAMEDEFNV(seawitch,"Seawitch",1980,"Stern",by35_mST200,0)

INITGAME(seawitfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitfp,"fpsw_u1.716",CRC(058aa5d4) SHA1(a6aafbcb7c720f1c02ee98a170d2985eda58076c),
                            "fpsw_u5.716",CRC(d3072929) SHA1(6dcc2fdc334d3f3f39355570346406d6eea3ca89),
                            "cpu_u2.716", CRC(b8844174) SHA1(6e01321196fd6fce7b5526efc402044c87fe96a6),
                            "cpu_u6.716", CRC(6c296d8f) SHA1(8cdb77f382ef1214ef45579213cf8f19141366ad))
BY35_ROMEND
#define input_ports_seawitfp input_ports_st
CORE_CLONEDEFNV(seawitfp,seawitch,"Seawitch (Free Play)",1980,"Stern",by35_mST200,0)

INITGAME(seawitcha,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitcha,"seawitch_05-u1.716",CRC(4b4d9927) SHA1(e31f297a83a96af964b713fe944c7c40ef10dcdf),
                             "seawitch_05-u5.716",CRC(afc10bfe) SHA1(a58c8a4e00272d54dfcb9cb815a816b46a16ee25),
                             "seawitch_05-u2.716",CRC(d85701af) SHA1(86314f0c348de7f75802eb844c6cde9aa32c93e6),
                             "seawitch_05-u6.716",CRC(51644c70) SHA1(916dd5df4ba506afd1d0fad9c52345110072633a))
BY35_ROMEND
#define input_ports_seawitcha input_ports_st
CORE_CLONEDEFNV(seawitcha,seawitch,"Seawitch (MOD rev. 5)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(seawitchb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitchb,"seawitch_V06-u1.716",CRC(394b14ae) SHA1(754c463922d6b5385397ed54b21730e31d156d9a),
                             "seawitch_V06-u5.716",CRC(9684dcda) SHA1(74ae76101b84e29e4776f398bc70c9d579357932),
                             "seawitch_V06-u2.716",CRC(1cfabb92) SHA1(a5122abec43d3e7df916e516ca26b0fd788d9ba9),
                             "seawitch_V06-u6.716",CRC(9c1bc88d) SHA1(27de8f3c5295a362d544bb5c992d99451b1ef0a4))
BY35_ROMEND
#define input_ports_seawitchb input_ports_st
CORE_CLONEDEFNV(seawitchb,seawitch,"Seawitch (MOD rev. 6)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(seawitchc,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitchc,"seawitch_V07-u1.716",CRC(0a1c5a87) SHA1(4497beaaeecf9de73c78abce58b5cb5702df208d),
                             "seawitch_V07-u5.716",CRC(16d8f17c) SHA1(6dc677f8db2283f6557539778c0f3c143149734b),
                             "seawitch_V07-u2.716",CRC(c3fd00a0) SHA1(fdf5e2ba040d21793ec2b11f965686441cf998f0),
                             "seawitch_V07-u6.716",CRC(eb1cf81b) SHA1(20114578f4e7fa040d535ccd63f224243495cdfa))
BY35_ROMEND
#define input_ports_seawitchc input_ports_st
CORE_CLONEDEFNV(seawitchc,seawitch,"Seawitch (MOD rev. 7)",2021,"Stern / Idleman",by35_mST200,0)

// New version with spinner counter, standup carryover options, and consecutive loop award option
INITGAME(seawitchd,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitchd,"seawitch_V08-u1.716",CRC(756f8e91) SHA1(3be921799b54525e464a3a92ddef92e116c97038),
                             "seawitch_V08-u5.716",CRC(72ff7b4a) SHA1(34cc77f7971715c0b8ab296d056559fd99150f93),
                             "seawitch_V08-u2.716",CRC(a6dc5885) SHA1(d4866bfdcb87c604c7a47de22745f080ca8fdd63),
                             "seawitch_V08-u6.716",CRC(babb19c4) SHA1(88ed6c2ea0971e73d0f8629653040a0e8e6288a3))
BY35_ROMEND
#define input_ports_seawitchd input_ports_st
CORE_CLONEDEFNV(seawitchd,seawitch,"Seawitch (MOD rev. 8)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(seawitche,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitche,"seawitch_V09-u1.716",CRC(3f01a1d9) SHA1(12f0f17febe1fad4e570bf82ede821416d79e655),
                             "seawitch_V09-u5.716",CRC(cc4799ee) SHA1(6f4a3929c821d77ebfd706c614669d28728c2746),
                             "seawitch_V09-u2.716",CRC(c300fd13) SHA1(8ca456c0b15a344858afb22af9c9152cc212b3fe),
                             "seawitch_V09-u6.716",CRC(bf9de5c1) SHA1(5d16d4f544d25ffa1b6c20ed0d6acead56301c62))
BY35_ROMEND
#define input_ports_seawitche input_ports_st
CORE_CLONEDEFNV(seawitche,seawitch,"Seawitch (MOD rev. 9)",2023,"Stern / slochar",by35_mST200,0)

INITGAME(seawitchf,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(seawitchf,"seawitch_V093-u1.716",CRC(a47fe686) SHA1(b65a474e6c6679a336bc71db7cb5a69e0cee5a73),
                             "seawitch_V093-u5.716",CRC(c5a04e0a) SHA1(67650e32e2871df87354046e5808874100838db6),
                             "seawitch_V093-u2.716",CRC(9900103e) SHA1(39f35d7bd726a2a90cd75bfa72e14d3eff6ff67f),
                             "seawitch_V093-u6.716",CRC(a73000e6) SHA1(f050f8083e90552424923d9033376cce9f545b8e))
BY35_ROMEND
#define input_ports_seawitchf input_ports_st
CORE_CLONEDEFNV(seawitchf,seawitch,"Seawitch (MOD rev. 9.3)",2024,"Stern / slochar",by35_mST200,0)

/*--------------------------------
/ Cheetah
/-------------------------------*/
INITGAME(cheetah,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetah,"CHEETAH__R_B20.U1",CRC(6a845d94) SHA1(c272d5895edf2270f5f06fc33345bb4911abbee4), /*cpu_u1.716*/
                           "CHEETAH__R_B20.U5",CRC(e7bdbe6c) SHA1(8b213c2271dbd5157e0d34a33672130b935d76be), /*cpu_u5.716*/
                           "CHEETAH__R_B20.U2",CRC(a827a1a1) SHA1(723ebf193b5ce7b19df70e83caa9bb80f2e3fa66), /*cpu_u2.716*/
                           "CHEETAH__R_B20.U6",CRC(ed33c227) SHA1(a96ba2814cef7663728bb5fdea2dc6ecfa219038)) /*cpu_u6.716*/
BY35_ROMEND
#define input_ports_cheetah input_ports_st
CORE_GAMEDEFNV(cheetah,"Cheetah (Black cabinet)",1980,"Stern",by35_mST200,0)

INITGAME(cheetahb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetahb,"CHEETAH__X_B16.U1",CRC(2f736a0a) SHA1(e0dc14215d90145881ac1b407fbe057770696122), /*cheetah.u1*/
                            "CHEETAH__X_B16.U5",CRC(168f0650) SHA1(5b3294bf64f06cc9d193bb14891b2acfbb5c06d4), /*cheetah.u5*/
                            "CHEETAH__X_B16.U2",CRC(f6bd41bc) SHA1(ac94f4ba17c31dfe10ab7efab63d98aa3401e4ae), /*cheetah.u2*/
                            "CHEETAH__X_B16.U6",CRC(c7eba210) SHA1(ced377e53f30b371e74c26527e5f8bebcc10ee59)) /*cheetah.u6*/
BY35_ROMEND
#define input_ports_cheetahb input_ports_st
CORE_CLONEDEFNV(cheetahb,cheetah,"Cheetah (Blue cabinet)",1980,"Stern",by35_mST200,0) // different sounds and bonus countdown

INITGAME(cheetafp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetafp,"fpch_u1.716",      CRC(af26e00e) SHA1(9573cf5a56bbd7a534022b43752c7c25042d707b),
                            "fpch_u5.716",      CRC(f6c34e1d) SHA1(732b94196a45c0a818fe5613c106f9aad5eae53e),
                            "CHEETAH__R_B20.U2",CRC(a827a1a1) SHA1(723ebf193b5ce7b19df70e83caa9bb80f2e3fa66),
                            "CHEETAH__R_B20.U6",CRC(ed33c227) SHA1(a96ba2814cef7663728bb5fdea2dc6ecfa219038))
BY35_ROMEND
#define input_ports_cheetafp input_ports_st
CORE_CLONEDEFNV(cheetafp,cheetah,"Cheetah (Black cabinet Free Play)",1980,"Stern",by35_mST200,0)

INITGAME(cheetah1,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetah1,"CHEETAH__R_B20.U1",CRC(6a845d94) SHA1(c272d5895edf2270f5f06fc33345bb4911abbee4),
                            "bgcpu_u5.716",     CRC(fb7e0400) SHA1(81443e93e68d8dfecc3a33d61a1a39e6e9ea34ca),
                            "CHEETAH__R_B20.U2",CRC(a827a1a1) SHA1(723ebf193b5ce7b19df70e83caa9bb80f2e3fa66),
                            "CHEETAH__R_B20.U6",CRC(ed33c227) SHA1(a96ba2814cef7663728bb5fdea2dc6ecfa219038))
BY35_ROMEND
#define input_ports_cheetah1 input_ports_st
CORE_CLONEDEFNV(cheetah1,cheetah,"Cheetah (Black cabinet Bonus shot 1/game)",1980,"Stern",by35_mST200,0)

// Slight tweak, 'collect bonus' is only available once per ball once earned. This is sound package #2
INITGAME(cheetah2,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetah2,"bbcpu_u1.716",     CRC(568db33e) SHA1(a62f48f77dc170d88a5bf2d033e92e409839e749),
                            "bbcpu_u5.716",     CRC(d4e4b50d) SHA1(c59f465ade7512d129a0e60519ec7066db2cbde9),
                            "CHEETAH__R_B20.U2",CRC(a827a1a1) SHA1(723ebf193b5ce7b19df70e83caa9bb80f2e3fa66),
                            "bbcpu_u6.716",     CRC(f9e66c18) SHA1(41ba7eecf2ff9305d79cc5ae30c08d5b89f03909))
BY35_ROMEND
#define input_ports_cheetah2 input_ports_st
CORE_CLONEDEFNV(cheetah2,cheetah,"Cheetah (Black cabinet Bonus shot 1/ball)",2011,"Stern / Idleman",by35_mST200,0)

// Slight tweak as previous, but with the roms that have different sounds
INITGAME(cheetahb2,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetahb2,"b16_mod.u1",       CRC(137a84a0) SHA1(7e6e69eb154afdc2ac7ee935d7d327eee8065fe1),
                             "b16_mod.u5"       ,CRC(ec51118f) SHA1(ec8c1fe76ac6283d43d09fa859d2b32fca45c115),
                             "CHEETAH__X_B16.U2",CRC(f6bd41bc) SHA1(ac94f4ba17c31dfe10ab7efab63d98aa3401e4ae),
                             "b16_mod.u6",       CRC(d33e0c2f) SHA1(eccf39c030c217f6cd93e58031d5e8f5525d1b7c))
BY35_ROMEND
#define input_ports_cheetahb2 input_ports_st
CORE_CLONEDEFNV(cheetahb2,cheetah,"Cheetah (Blue cabinet Bonus shot 1/ball)",2018,"Stern / Idleman",by35_mST200,0)

INITGAME(cheetah84,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cheetah84,"cheetah_proto_84_U1.716",CRC(4d544bb3) SHA1(61e10d0d70720762c1ccf9de80e3f4e5eeac2617),
                             "cheetah_proto_84_U5.716",CRC(73f93a1a) SHA1(dd540bb984bf19432b1951bd7c126bd361409588),
                             "cheetah_proto_84_U2.716",CRC(428e1615) SHA1(91b27843797b5ef06d0abbc88c6a315de24fff6e),
                             "cheetah_proto_84_U6.716",CRC(27445ef7) SHA1(042b23812c9f243d5752165c4ae6e19b2acc56a9))
BY35_ROMEND
#define input_ports_cheetah84 input_ports_st
CORE_CLONEDEFNV(cheetah84,cheetah,"Cheetah (Prototype Sounds + MOD 84)",2023,"Stern / slochar",by35_mST200,0)

// https://zacaj.com/p.php?id=65&title=Stern+Cheetah+Tournament+Rom+V1 exists

/*--------------------------------
/ Quicksilver
/-------------------------------*/
INITGAME(quicksil,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(quicksil,"cpu_u1.716",CRC(fc1bd20a) SHA1(e3c547f996dfc5d1567223d234443cf31d648ef6),
                            "cpu_u5.716",CRC(0bcaceb4) SHA1(461d2fe5772a5ac84d31a4a186b9f639c683ca8a),
                            "cpu_u2.716",CRC(8cb01165) SHA1(b42e2ccce2c20ad570cdcdb63c9d12e414f9b255),
                            "cpu_u6.716",CRC(8c0e336a) SHA1(8d3a5b7c07d03c7e2945ea60c72f9181d3ee2a14))
BY35_ROMEND
#define input_ports_quicksil input_ports_st
CORE_GAMEDEFNV(quicksil,"Quicksilver",1980,"Stern",by35_mST200,0)

INITGAME(quicksfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(quicksfp,"cpu_u1.716", CRC(fc1bd20a) SHA1(e3c547f996dfc5d1567223d234443cf31d648ef6),
                            "cpu_u5.716", CRC(0bcaceb4) SHA1(461d2fe5772a5ac84d31a4a186b9f639c683ca8a),
                            "cpu_u2.716", CRC(8cb01165) SHA1(b42e2ccce2c20ad570cdcdb63c9d12e414f9b255),
                            "fpqs_u6.716",CRC(0514d8c3) SHA1(4ebbc5a76ac25d38ec97a2fd443b492ea5335ae2))
BY35_ROMEND
#define input_ports_quicksfp input_ports_st
CORE_CLONEDEFNV(quicksfp,quicksil,"Quicksilver (Free Play)",1980,"Stern",by35_mST200,0)

// New version with spinner counters and drop sweep awards
INITGAME(quicksib,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(quicksib,"QS-V07D_u1.716",CRC(69bbe180) SHA1(e69d8affc98f8993553697f6be702f86583f6f87),
                            "QS-V07D_u5.716",CRC(bdb8af82) SHA1(5222355e99f0dc28fd3c8df18c4cb04407702084),
                            "QS-V07D_u2.716",CRC(015d4f59) SHA1(d3481bb922415992471d0a37e8e316bef4cf91c7),
                            "QS-V07D_u6.716",CRC(586c3d09) SHA1(03a9f88e4cca6adc1979559228ea05ae59471044))
BY35_ROMEND
#define input_ports_quicksib input_ports_st
CORE_CLONEDEFNV(quicksib,quicksil,"Quicksilver (Free Play & modified rules rev. 07D)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(quicksic,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(quicksic,"QS-V081_u1.716",CRC(c9e8d14f) SHA1(afe5920f092b227b377a9bccb35db7770c655c32),
                            "QS-V081_u5.716",CRC(19bbbc0f) SHA1(05428e621ed1b4d85ede2adf66285407f7eed5e2),
                            "QS-V081_u2.716",CRC(09c36fd0) SHA1(c6d73d185d10a59f7bff29dff1a10ae5746b9c5e),
                            "QS-V081_u6.716",CRC(21f1fc2e) SHA1(01d6965c91f92b6f39f414ec9ba04e0c0f48d8a2))
BY35_ROMEND
#define input_ports_quicksic input_ports_st
CORE_CLONEDEFNV(quicksic,quicksil,"Quicksilver (Free Play & modified rules rev. 8.1)",2024,"Stern / slochar",by35_mST200,0)

/*--------------------------------
/ Star Gazer
/-------------------------------*/
INITGAME(stargzr,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(stargzr,"cpu_u1.716",CRC(83606fd4) SHA1(7f6448bc0dabe50de40fd47a7242c1be4a93e84d),
                           "cpu_u5.716",CRC(c54ae389) SHA1(062e64e8ced723adb7f4040539ba6400fc4a9c9a),
                           "cpu_u2.716",CRC(1a4c7dcb) SHA1(54888a8867b8d60f215b7e683ae4966f14ddca15),
                           "cpu_u6.716",CRC(4e1f4dc6) SHA1(1f63a0b71af84fb6e1168ff77cbcbabcaa1323f3))
BY35_ROMEND
#define input_ports_stargzr input_ports_st
CORE_GAMEDEFNV(stargzr,"Star Gazer",1980,"Stern",by35_mST200,0)

INITGAME(stargzfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(stargzfp,"fpsg_u1.716",CRC(4a4e3847) SHA1(87205061f5c981a2e6be6b8d56c8bc563611a30c),
                           "fpsg_u5.716",CRC(902398ad) SHA1(6ab51ac90819167a8c8da3d5aacafdc0e9f939fb),
                           "cpu_u2.716",CRC(1a4c7dcb) SHA1(54888a8867b8d60f215b7e683ae4966f14ddca15),
                           "cpu_u6.716",CRC(4e1f4dc6) SHA1(1f63a0b71af84fb6e1168ff77cbcbabcaa1323f3))
BY35_ROMEND
#define input_ports_stargzfp input_ports_st
CORE_CLONEDEFNV(stargzfp,stargzr,"Star Gazer (Free Play)",1980,"Stern",by35_mST200,0)

/*--------------------------------
/ Star Gazer (modified rules rev .9)
/-------------------------------*/
INITGAME(stargzrb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(stargzrb,"cpu_u1.716",CRC(83606fd4) SHA1(7f6448bc0dabe50de40fd47a7242c1be4a93e84d),
                           "cpu_u5b.716",CRC(29682d85) SHA1(3f449270cd4098a7ed1ee9c0d801110b1b653913),
                           "cpu_u2b.716",CRC(360427cc) SHA1(ad76124b7fd088a5e2d24cf369c1620cdcc80309),
                           "cpu_u6b.716",CRC(b68b11c5) SHA1(1af6aca8ecf70d2adf588a1e856f753193c05abd))
BY35_ROMEND
#define input_ports_stargzrb input_ports_stargzr
CORE_CLONEDEFNV(stargzrb,stargzr,"Star Gazer (modified rules rev. 9)",2006,"Stern / Oliver",by35_mST200,0)

/*--------------------------------
/ Flight 2000
/-------------------------------*/
INITGAME(flight2k,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(flight2k,"cpu_u1.716",CRC(df9efed9) SHA1(47727664e745e77ca1c221a32bd56d936f5b31bc),
                            "cpu_u5.716",CRC(38c13649) SHA1(bcdbd17b48edd41ec7d38261595ac06eb8fc6a4d),
                            "cpu_u2.716",CRC(425fae6a) SHA1(fde8d23e6ebb176ba72f763d66c2e17e51237fa1),
                            "cpu_u6.716",CRC(dc243186) SHA1(046ce51b8a8218214088c4264548c753bd880e19))
VSU100_SOUNDROM_U9(         "snd_u9.716",CRC(d816573c) SHA1(75134a017c34abbb149159ca001d35464a3f5128))
BY35_ROMEND
#define input_ports_flight2k input_ports_st
CORE_GAMEDEFNV(flight2k,"Flight 2000",1980,"Stern",by35_mST200v,0)

INITGAME(flightfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(flightfp,"cpu_u1.716",CRC(df9efed9) SHA1(47727664e745e77ca1c221a32bd56d936f5b31bc),
                            "free2ku5.716",CRC(c3854b59) SHA1(1ca80f481f98106ebd415268d1ea4538650cd115),
                            "cpu_u2.716",CRC(425fae6a) SHA1(fde8d23e6ebb176ba72f763d66c2e17e51237fa1),
                            "free2ku6.716",CRC(228bd69e) SHA1(067576f9893effc1daff94568363bcc49177d4b1))
VSU100_SOUNDROM_U9(         "snd_u9.716",CRC(d816573c) SHA1(75134a017c34abbb149159ca001d35464a3f5128))
BY35_ROMEND
#define input_ports_flightfp input_ports_st
CORE_CLONEDEFNV(flightfp,flight2k,"Flight 2000 (Free Play)",1980,"Stern",by35_mST200v,0)

INITGAME(flight2m,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(flight2m,"cpu_u1m.716",CRC(da0850ba) SHA1(9f8d9781b67c388f21a39ca8c17f778ed99caae9),
                            "cpu_u5m.716",CRC(cb73782e) SHA1(28ba926647d814f88bcd02082a995ae0a2c80f6f),
                            "cpu_u2m.716",CRC(1a9b72b5) SHA1(ad814e2f9c619838a80039674edfdf0f5c6591e6),
                            "cpu_u6m.716",CRC(437bcd19) SHA1(764ab4a8cde90cdd2138883d2470275b50a5423c))
VSU100_SOUNDROM_U9(         "snd_u9.716", CRC(d816573c) SHA1(75134a017c34abbb149159ca001d35464a3f5128))
BY35_ROMEND
#define input_ports_flight2m input_ports_st
CORE_CLONEDEFNV(flight2m,flight2k,"Flight 2000 (modified rules rev. 3335)",2020,"Stern / Idleman",by35_mST200v,0)

// New version to eliminate ball relocking during multiball and add speech and other gameplay changes
INITGAME(flight2mb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(flight2mb,"f2k-3347M-CPU_U1.716", CRC(fd1c738f) SHA1(527c32a03a1274ca18190ec67a45fc9bb76ef648),
                             "f2k-3347M-CPU_U5.716", CRC(1e28df6c) SHA1(d6b831d454c419366d687b5beea56aa634d6b2dd),
                             "f2k-3347M-CPU_U2.716", CRC(f3dee323) SHA1(05170b5092f3ac5b626e229a8b63a2153980ce09),
                             "f2k-3347M-CPU_U6.716", CRC(1c039bd8) SHA1(20f45d9506e0684e1935a0b09812e639ca3f1119))
VSU100_SOUNDROM_U9U10(       "f2k-3347M-snd_u9.716", CRC(321ab040) SHA1(572f9ef0b1f7eef000c778ae232340416d27f974),
                             "f2k-3347M-snd_u10.716",CRC(0b0ec806) SHA1(f00f48ff3c145d78a13d0e28686a06e68c7554b6))
BY35_ROMEND
#define input_ports_flight2mb input_ports_st
CORE_CLONEDEFNV(flight2mb,flight2k,"Flight 2000 (modified rules & sound rev. 3347)",2020,"Stern / Idleman",by35_mST200v,0)

/*--------------------------------
/ Nine Ball
/-------------------------------*/
INITGAME(nineball,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(nineball,"cpu_u1.716",CRC(fcb58f97) SHA1(6510a6d0b466bd27ade50992260cea716d79fda2),
                            "cpu_u5.716",CRC(c7c62161) SHA1(624eab2fdf7bafbf4af012df521bd09f9b2da8d8),
                            "cpu_u2.716",CRC(bdd7f258) SHA1(2a38de09827100cbbd4e79be50aad03a3f2b63b4),
                            "cpu_u6.716",CRC(7e831499) SHA1(8d3c148b91c21938b1b5fca85ecd8f6d7f1e76b0))
BY35_ROMEND
#define input_ports_nineball input_ports_st
CORE_GAMEDEFNV(nineball,"Nine Ball",1980,"Stern",by35_mST200,0)

INITGAME(ninebafp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ninebafp,"cpu_u1.716",CRC(fcb58f97) SHA1(6510a6d0b466bd27ade50992260cea716d79fda2),
                            "cpu_u5.716",CRC(c7c62161) SHA1(624eab2fdf7bafbf4af012df521bd09f9b2da8d8),
                            "fp9b_u2.716",CRC(f22c2fb6) SHA1(51b927d01d9d1e0b6a3169677a559c4a2b02c198),
                            "fp9b_u6.716",CRC(d4599ee8) SHA1(0b9cfa48e335dffb427fd02c0f63814350c52aca))
BY35_ROMEND
#define input_ports_ninebafp input_ports_st
CORE_CLONEDEFNV(ninebafp,nineball,"Nine Ball (Free Play)",1980,"Stern",by35_mST200,0)

// When you have a 2 ball multiball, the multiplier 2x flashes and all scores are 2x
// When you have a 3 ball multiball, the multiplier 4x flashes and all scores are 4x
// Checksum validation is now correct. Limitation: Selftest is not complete. Freegame only.
INITGAME(ninebalb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ROM_START(ninebalb)
  NORMALREGION(0x10000, BY35_CPUREGION)
    ROM_LOAD("nineball.256", 0x0000, 0x8000, CRC(06cb8a63) SHA1(c901bba0b41b45c5cfa6d04181f1e035beab5a08))
    ROM_RELOAD(0x8000, 0x8000)
ST200_ROMEND
#define input_ports_ninebalb input_ports_st
CORE_CLONEDEFNV(ninebalb,nineball,"Nine Ball (modified rules rev. 85)",2007,"Stern / Oliver",by35_mST200,0)

INITGAME(ninebala,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ninebala,"cpu_u1a.716",CRC(52891fc8) SHA1(81a0d9105136d6b561321cd96974a7497c49a8b6),
                            "cpu_u5a.716",CRC(0dfbc660) SHA1(ad2f3f2176624f24b655609808351c1157e14438),
                            "cpu_u2a.716",CRC(f89d1b8f) SHA1(d5b2bcdea335367ce31576a67a9464fc146a6fb4),
                            "cpu_u6a.716",CRC(78aeba96) SHA1(da091b90a0be4c521d323d6fd012210e341c410e))
BY35_ROMEND
#define input_ports_ninebala input_ports_st
CORE_CLONEDEFNV(ninebala,nineball,"Nine Ball (Ball handling MOD beta18)",2020,"Stern / Idleman",by35_mST200,0)

INITGAME(ninebalc,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ninebalc,"cpu_u1c.716",CRC(fec7f986) SHA1(b13528000131a29a16b2e4c6f29c2d4d1b16eaf3),
                            "cpu_u5c.716",CRC(178237db) SHA1(113ee01a7d3891b570910a0ec1e46284a2f145e5),
                            "cpu_u2c.716",CRC(de915e58) SHA1(f19e3606bb59f703e0ca43521ead02ffbc92ed64),
                            "cpu_u6c.716",CRC(e8104924) SHA1(801563a66427b73a1c3187eae46de2a8e9922220))
BY35_ROMEND
#define input_ports_ninebalc input_ports_st
CORE_CLONEDEFNV(ninebalc,nineball,"Nine Ball (Ball handling MOD beta19)",2021,"Stern / Idleman",by35_mST200,0)

// New version to fix many bugs
INITGAME(ninebald,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ninebald,"cpu_u1d.716",CRC(61e3ca99) SHA1(aac60b9554bc1d245be78c5955b414420a158b8e),
                            "cpu_u5d.716",CRC(d20be57a) SHA1(2779fd95e642b8a1226b9c9195834b5023f21d02),
                            "cpu_u2d.716",CRC(f7714f55) SHA1(efaf742dcfc7b79d0de2a01412f86e24044a96b5),
                            "cpu_u6d.716",CRC(34491b9f) SHA1(ba47dfc72ae4b93fb80b984dec9c77a1bf704f3c))
BY35_ROMEND
#define input_ports_ninebald input_ports_st
CORE_CLONEDEFNV(ninebald,nineball,"Nine Ball (Gameplay MOD beta21)",2021,"Stern / Idleman",by35_mST200,0)

/*--------------------------------
/ Free Fall
/-------------------------------*/
INITGAME(freefall,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(freefall,"cpu_u1.716",CRC(d13891ad) SHA1(afb40c51f2d5695c74ce9979c0a818845f95edd4),
                            "cpu_u5.716",CRC(77bc7759) SHA1(3f739757180b3dcce5426935a51e4b615f157199),
                            "cpu_u2.716",CRC(82bda054) SHA1(32772e878d2a4bba8f67e419a68a81fec2a5f6d7),
                            "cpu_u6.716",CRC(68168b97) SHA1(defa4bba465182db22debddb4070c40c048c95e2))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(ea8cf062) SHA1(55c840a9bea363fd436c00a115cb61d15a9f8c47),
                           "snd_u10.716",CRC(dd681a79) SHA1(d954cae375fb0145e10536e43d1cb03902de2ea3))
BY35_ROMEND
#define input_ports_freefall input_ports_st
CORE_GAMEDEFNV(freefall,"Free Fall",1981,"Stern",by35_mST200v,0)

INITGAME(freefafp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(freefafp,"cpu_u1.716",CRC(d13891ad) SHA1(afb40c51f2d5695c74ce9979c0a818845f95edd4),
                            "cpu_u5.716",CRC(77bc7759) SHA1(3f739757180b3dcce5426935a51e4b615f157199),
                            "fpff_u2.716",CRC(b4f811ac) SHA1(0af78971a2ee32c423b8a95a486e1b8ad0ddd1d9),
                            "cpu_u6.716",CRC(68168b97) SHA1(defa4bba465182db22debddb4070c40c048c95e2))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(ea8cf062) SHA1(55c840a9bea363fd436c00a115cb61d15a9f8c47),
                           "snd_u10.716",CRC(dd681a79) SHA1(d954cae375fb0145e10536e43d1cb03902de2ea3))
BY35_ROMEND
#define input_ports_freefafp input_ports_st
CORE_CLONEDEFNV(freefafp,freefall,"Free Fall (Free Play)",1981,"Stern",by35_mST200v,0)

/*--------------------------------
/ Lightning
/-------------------------------*/
static core_tLCDLayout dispLightnin[] = {
  {0, 0, 1,7,CORE_SEG87F},{0,16, 9,7,CORE_SEG87F},
  {2, 0,17,7,CORE_SEG87F},{2,16,25,7,CORE_SEG87F},
  {4, 4,34,2,CORE_SEG7}, {4,10,38,2,CORE_SEG7}, {4,20,36,2,CORE_SEG7},{0}
};
INITGAME(lightnin,GEN_STMPU200,dispLightnin,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(lightnin,"cpu_u1.716",CRC(d3469d0a) SHA1(18565f5c85694da8eaf850146d3d9a90a17b7816),
                            "cpu_u5.716",CRC(cd52262d) SHA1(099aeda2183822046cce907b265b42319007ac32),
                            "cpu_u2.716",CRC(e0933419) SHA1(1f7cad915496f34473dffde7e320d51838acd0fd),
                            "cpu_u6.716",CRC(df221c6b) SHA1(5935020d3a24d829fbeaa8cf764daff48a151a81))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(00ffa77c) SHA1(242efd800731a7f84369c6ce54298d0a227dd8ba),
                           "snd_u10.716",CRC(80fe9158) SHA1(20fcdb4c09b25e494f02bbfb20c07ff2870d5798))
BY35_ROMEND
#define input_ports_lightnin input_ports_st
CORE_GAMEDEFNV(lightnin,"Lightning",1981,"Stern",by35_mST200v,0)

INITGAME(lightnfp,GEN_STMPU200,dispLightnin,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(lightnfp,"cpu_u1.716",  CRC(d3469d0a) SHA1(18565f5c85694da8eaf850146d3d9a90a17b7816),
                            "fpltg_u5.716",CRC(696b8f87) SHA1(becb662f8c5b160eff968079706dee957f5cfb83),
                            "cpu_u2.716",  CRC(e0933419) SHA1(1f7cad915496f34473dffde7e320d51838acd0fd),
                            "fpltg_u6.716",CRC(2a652b4e) SHA1(25d048afc42e31373a3b957bb7fce4c3acfe9668))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",  CRC(00ffa77c) SHA1(242efd800731a7f84369c6ce54298d0a227dd8ba),
                            "snd_u10.716", CRC(80fe9158) SHA1(20fcdb4c09b25e494f02bbfb20c07ff2870d5798))
BY35_ROMEND
#define input_ports_lightnfp input_ports_st
CORE_CLONEDEFNV(lightnfp,lightnin,"Lightning (Free Play)",1981,"Stern",by35_mST200v,0)

INITGAME(lightnib,GEN_STMPU200,dispLightnin,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(lightnib,"light_19-u1.716",CRC(3e653df7) SHA1(c05970e793069cb713486a43908d2f320db6db56),
                            "light_19-u5.716",CRC(917d5c00) SHA1(4b64ab925f7e54be836d58826eaa3a71e75689e9),
                            "light_19-u2.716",CRC(d8eedf05) SHA1(f137ab00b53bd7860776488407f625ce3110a677),
                            "light_19-u6.716",CRC(3956ff8b) SHA1(269912df7976f1ab9a06493aa5e8e87deb3aa75e))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",     CRC(00ffa77c) SHA1(242efd800731a7f84369c6ce54298d0a227dd8ba),
                            "snd_u10.716",    CRC(80fe9158) SHA1(20fcdb4c09b25e494f02bbfb20c07ff2870d5798))
BY35_ROMEND
#define input_ports_lightnib input_ports_st
CORE_CLONEDEFNV(lightnib,lightnin,"Lightning (Free Play & MOD rev. 19)",2021,"Stern / Idleman",by35_mST200v,0)

// rev 22: New version to eliminate ball relocking during multiball

// rev 23: New version, eliminates ball relocking during multiball and resets standup targets to half completed if you complete all without balls locked

INITGAME(lightnic,GEN_STMPU200,dispLightnin,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(lightnic,"light_25-u1.716",CRC(812b6521) SHA1(5ac4f9160c180b2022a49f03ee36575cbdae7382),
                            "light_25-u5.716",CRC(8d6b87c4) SHA1(efae61490855bee8ae3883868607ed5b17e25c0f),
                            "light_25-u2.716",CRC(b73f68a6) SHA1(e7ffb42ed27d9704d38a25f397f54ded5c4e2756),
                            "light_25-u6.716",CRC(3c0efce0) SHA1(27c9d03de96732b44c52c89dd45b80152df4eec3))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",     CRC(00ffa77c) SHA1(242efd800731a7f84369c6ce54298d0a227dd8ba),
                            "snd_u10.716",    CRC(80fe9158) SHA1(20fcdb4c09b25e494f02bbfb20c07ff2870d5798))
BY35_ROMEND
#define input_ports_lightnic input_ports_st
CORE_CLONEDEFNV(lightnic,lightnin,"Lightning (Free Play & MOD rev. 25)",2022,"Stern / Idleman",by35_mST200v,0)

INITGAME(lightnid,GEN_STMPU200,dispLightnin,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(lightnid,"light_V27-u1.716",CRC(41ff4fae) SHA1(796bda930e2a010d18491a803b32af8e6acae304),
                            "light_V27-u5.716",CRC(7b0875cf) SHA1(c91090a7c8e177579b6509ac7537c492aead3f08),
                            "light_V27-u2.716",CRC(c125f224) SHA1(421c6446ed4af8fc3a771e2d58f11858f6dc1326),
                            "light_V27-u6.716",CRC(2e8acbcb) SHA1(41f00404268676dadd05dd64cf32c97b35c5fb4c))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",      CRC(00ffa77c) SHA1(242efd800731a7f84369c6ce54298d0a227dd8ba),
                            "snd_u10.716",     CRC(80fe9158) SHA1(20fcdb4c09b25e494f02bbfb20c07ff2870d5798))
BY35_ROMEND
#define input_ports_lightnid input_ports_st
CORE_CLONEDEFNV(lightnid,lightnin,"Lightning (Free Play & MOD rev. 27)",2024,"Stern / Idleman",by35_mST200v,0)

/*--------------------------------
/ Split Second
/-------------------------------*/
INITGAME(splitsec,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(splitsec,"cpu_u1.716",CRC(c6ff9aa9) SHA1(39f80faca16c869ac14df7c5fc3dfa80b47dad95),
                            "cpu_u5.716",CRC(fda74efc) SHA1(31becc243ada23e2f4d17927985772c9fcf8a3c3),
                            "cpu_u2.716",CRC(81b9f784) SHA1(43cf71b51eda70a3c126340ea658c03c438e4f18),
                            "cpu_u6.716",CRC(ecbedb0a) SHA1(8cc7281dd2bd300ab95a08761c12733d98599ebd))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(e6ed5f48) SHA1(ea2bbc607acb2b816667cd54f3d07605110c252e),
                           "snd_u10.716",CRC(36e6ee70) SHA1(61bd89d69627bea89b7f31af63ff90ace6db3c85))
BY35_ROMEND
#define input_ports_splitsec input_ports_st
CORE_GAMEDEFNV(splitsec,"Split Second",1981,"Stern",by35_mST200v,0)

INITGAME(splitsfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(splitsfp,"cpu_u1.716",CRC(c6ff9aa9) SHA1(39f80faca16c869ac14df7c5fc3dfa80b47dad95),
                            "fpspscu5.716",CRC(230e3be4) SHA1(4e2268e61af2105bdc92a55eeb99cbbb68d007ba),
                            "cpu_u2.716",CRC(81b9f784) SHA1(43cf71b51eda70a3c126340ea658c03c438e4f18),
                            "fpspscu6.716",CRC(8e8c831e) SHA1(28985ea7342284ffcc69a53b63053f15a0cd408b))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(e6ed5f48) SHA1(ea2bbc607acb2b816667cd54f3d07605110c252e),
                           "snd_u10.716",CRC(36e6ee70) SHA1(61bd89d69627bea89b7f31af63ff90ace6db3c85))
BY35_ROMEND
#define input_ports_splitsfp input_ports_st
CORE_CLONEDEFNV(splitsfp,splitsec,"Split Second (Free Play)",1981,"Stern",by35_mST200v,0)

/*--------------------------------
/ Catacomb
/-------------------------------*/
INITGAME(catacomb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(catacomb,"cpu_u1.716",CRC(d445dd40) SHA1(9ff5896977d7e2a0cf788c77dcfd7c010e17d2fb),
                            "cpu_u5.716",CRC(d717a545) SHA1(a183f3b1f766c3a82ae52defc38d84328fb7b31a),
                            "cpu_u2.716",CRC(bc504409) SHA1(cd3e948d34a8db71fc841261e683988c9df31ef8),
                            "cpu_u6.716",CRC(da61b5a2) SHA1(ec4a914cd57b37921578699bc427f12a3670c7eb))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(a13cb591) SHA1(b64a2dc3429803095dc05cdd1718db2404b13eb8),
                           "snd_u10.716",CRC(2b31f8be) SHA1(05b394bd8b6c04e34fe2bab19cbd0f06d9e4b90d))
BY35_ROMEND
#define input_ports_catacomb input_ports_st
CORE_GAMEDEFNV(catacomb,"Catacomb",1981,"Stern",by35_mST200v,0)

INITGAME(catacofp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(catacofp,"cpu_u1.716",CRC(d445dd40) SHA1(9ff5896977d7e2a0cf788c77dcfd7c010e17d2fb),
                            "fpcat_u5.716",CRC(3114512f) SHA1(660286e223ad87ddeefdcc7887cdb77bd7a42cee),
                            "cpu_u2.716",CRC(bc504409) SHA1(cd3e948d34a8db71fc841261e683988c9df31ef8),
                            "cpu_u6.716",CRC(da61b5a2) SHA1(ec4a914cd57b37921578699bc427f12a3670c7eb))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(a13cb591) SHA1(b64a2dc3429803095dc05cdd1718db2404b13eb8),
                           "snd_u10.716",CRC(2b31f8be) SHA1(05b394bd8b6c04e34fe2bab19cbd0f06d9e4b90d))
BY35_ROMEND
#define input_ports_catacofp input_ports_st
CORE_CLONEDEFNV(catacofp,catacomb,"Catacomb (Free Play)",1981,"Stern",by35_mST200v,0)

// No after ball bagatelle round, for tournaments.  Not very polished, quick n dirty hack
INITGAME(cataconb,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(cataconb,"cat_NOBAGATELLE-u1.716",CRC(bf674561) SHA1(e66fdf9f8a0d5f51cb45550f46f936f4377e34da),
                            "cat_NOBAGATELLE-u5.716",CRC(721f3cbe) SHA1(96b21157874e645d7ea26ddacba36ccf38ecf206),
                            "cat_NOBAGATELLE-u2.716",CRC(c76a58e4) SHA1(1ae74f7edabc4a8996dde101e82341393b5fa002),
                            "cat_NOBAGATELLE-u6.716",CRC(9f2ca810) SHA1(4de16d9ed1a5bef74d9450a54f8441343b0cb66f))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(a13cb591) SHA1(b64a2dc3429803095dc05cdd1718db2404b13eb8),
                           "snd_u10.716",CRC(2b31f8be) SHA1(05b394bd8b6c04e34fe2bab19cbd0f06d9e4b90d))
BY35_ROMEND
#define input_ports_cataconb input_ports_st
CORE_CLONEDEFNV(cataconb,catacomb,"Catacomb (No Bagatelle)",2021,"Stern / Idleman",by35_mST200v,0)

/*--------------------------------
/ Iron Maiden
/-------------------------------*/
INITGAME(ironmaid,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ironmaid,"cpu_u1.716",CRC(e15371a4) SHA1(fe441ed8abd325190d8eee6d907e17c7fc02be64),
                            "cpu_u5.716",CRC(84a29c01) SHA1(0e0ff8821c7028ce690328cd08a77bb51c0993c9),
                            "cpu_u2.716",CRC(981ac0dd) SHA1(c585907b74695812f333867cf359a01a5ea6ed81),
                            "cpu_u6.716",CRC(4e6f9c25) SHA1(9053e1d335a29f7acade7752adffe69f42032959))
BY35_ROMEND
#define input_ports_ironmaid input_ports_st
CORE_GAMEDEFNV(ironmaid,"Iron Maiden",1981,"Stern",by35_mST200,0)

INITGAME(ironmafp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(ironmafp,"cpu_u1.716",CRC(e15371a4) SHA1(fe441ed8abd325190d8eee6d907e17c7fc02be64),
                            "fp_imu5.716",CRC(31c16c20) SHA1(ebc022157cf794ecc397217db3e9c5bf6d45113b),
                            "cpu_u2.716",CRC(981ac0dd) SHA1(c585907b74695812f333867cf359a01a5ea6ed81),
                            "cpu_u6.716",CRC(4e6f9c25) SHA1(9053e1d335a29f7acade7752adffe69f42032959))
BY35_ROMEND
#define input_ports_ironmafp input_ports_st
CORE_CLONEDEFNV(ironmafp,ironmaid,"Iron Maiden (Free Play)",1981,"Stern",by35_mST200,0)

/*--------------------------------
/ Viper
/-------------------------------*/
INITGAME(viper,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(viper, "cpu_u1.716",CRC(d0ea0aeb) SHA1(28f4df9f45807abd1528aa6e5a80933156e6d692),
                          "cpu_u5.716",CRC(d26c7273) SHA1(303c18861941463932fdf47e9606159936b28dc1),
                          "cpu_u2.716",CRC(d03f1612) SHA1(d390ec1e953148ac26bf218701117855c941fc65),
                          "cpu_u6.716",CRC(96ff5f60) SHA1(a9df887ca338db208a684540f6c9fc07722c3aa5))
BY35_ROMEND
#define input_ports_viper input_ports_st
CORE_GAMEDEFNV(viper,"Viper",1981,"Stern",by35_mST200,0)

INITGAME(viperfp,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(viperfp, "cpu_u1.716",CRC(d0ea0aeb) SHA1(28f4df9f45807abd1528aa6e5a80933156e6d692),
                          "fpvip_u5.716",CRC(a6802658) SHA1(81d6366694491cf16f4427ee20a068802410db26),
                          "cpu_u2.716",CRC(d03f1612) SHA1(d390ec1e953148ac26bf218701117855c941fc65),
                          "cpu_u6.716",CRC(96ff5f60) SHA1(a9df887ca338db208a684540f6c9fc07722c3aa5))
BY35_ROMEND
#define input_ports_viperfp input_ports_st
CORE_CLONEDEFNV(viperfp,viper,"Viper (Free Play)",1981,"Stern",by35_mST200,0)

/*--------------------------------
/ Dragonfist
/-------------------------------*/
static core_tLCDLayout dispDragfist[] = {
  {0, 0, 1,7,CORE_SEG87F},{0,16, 9,7,CORE_SEG87F},
  {2, 0,17,7,CORE_SEG87F},{2,16,25,7,CORE_SEG87F},
  {4, 4,36,2,CORE_SEG7}, {4,10,38,2,CORE_SEG7}, {4,20,34,2,CORE_SEG7},{0}
};
INITGAME(dragfist,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfist,"cpu_u1.716",CRC(4cbd1a38) SHA1(73b7291f38cd0a3300107605db26d474ecfc3101),
                            "cpu_u5.716",CRC(1783269a) SHA1(75151b79844d26d9e8ecf00dec96643ee2fedc5b),
                            "cpu_u2.716",CRC(9ac8292b) SHA1(99ad3ad6e1d1b19695ce1b5b76f6bd85c9c6530d),
                            "cpu_u6.716",CRC(a374c8f9) SHA1(481116025a52353f298f3d93dfe33b3ad9f86d18))
BY35_ROMEND
#define input_ports_dragfist input_ports_st
CORE_GAMEDEFNV(dragfist,"Dragonfist",1982,"Stern",by35_mST200,0)

INITGAME(dragfifp,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfifp,"cpu_u1.716",CRC(4cbd1a38) SHA1(73b7291f38cd0a3300107605db26d474ecfc3101),
                            "fpdf_u5.716",CRC(90b0247b) SHA1(7126459abd160d62cbc5c41c4759464d6def640f),
                            "cpu_u2.716",CRC(9ac8292b) SHA1(99ad3ad6e1d1b19695ce1b5b76f6bd85c9c6530d),
                            "cpu_u6.716",CRC(a374c8f9) SHA1(481116025a52353f298f3d93dfe33b3ad9f86d18))
BY35_ROMEND
#define input_ports_dragfifp input_ports_st
CORE_CLONEDEFNV(dragfifp,dragfist,"Dragonfist (Free Play)",1982,"Stern",by35_mST200,0)

INITGAME(dragfis3,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfis3,"df-1105-u1.716",CRC(5c08ec76) SHA1(56dc76e1bf54054d9d685f80213776bae2135b78),
                            "df-1105-u5.716",CRC(3d7ddc6e) SHA1(d26176df1307f61ae3ab3ed7b5dbad5cba6b6221),
                            "df-1105-u2.716",CRC(d7d761cd) SHA1(46f8120c9e4b392ca6bf631fa8a10c638674b04d),
                            "df-1105-u6.716",CRC(d34b4f61) SHA1(4eda993da4fc61fd247871e992ca37c1ae97cea8))
BY35_ROMEND
#define input_ports_dragfis3 input_ports_st
CORE_CLONEDEFNV(dragfis3,dragfist,"Dragonfist (MOD 3 rev. 1105)",2020,"Stern / Idleman",by35_mST200,0)

INITGAME(dragfis3b,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfis3b,"df-1109-u1.716",CRC(696e0ca1) SHA1(21c3c8963283eecfc0e62d988eedb5d075637d35),
                             "df-1109-u5.716",CRC(1eba53d5) SHA1(3a49012dee1d17266e370f047e5f71570334ecd4),
                             "df-1109-u2.716",CRC(768bb72c) SHA1(99b6fc4949449c9f69dcd5ae68d7b3a5bb68e3ee),
                             "df-1109-u6.716",CRC(c08edefc) SHA1(12322203b246a7aae00b1a6b7786a24d0ce9808c))
BY35_ROMEND
#define input_ports_dragfis3b input_ports_st
CORE_CLONEDEFNV(dragfis3b,dragfist,"Dragonfist (MOD 3 rev. 1109)",2020,"Stern / Idleman",by35_mST200,0)

// Rewrite to eliminate some bugs and add some tournmament friendly options
INITGAME(dragfis14,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfis14,"fisted_VB14-u1.716",CRC(92c3e3d6) SHA1(9b09b9685b34d93c804acd0d1693d7803360bd4f),
                             "fisted_VB14-u5.716",CRC(9b0f6210) SHA1(62dd7dbe1f714e58aaa927bb798bfee80f241635),
                             "fisted_VB14-u2.716",CRC(07f06e31) SHA1(edf63c8dc25381a5d204e1da13eb0a556c1a1d27),
                             "fisted_VB14-u6.716",CRC(e0799fca) SHA1(876311a9ecbcddaf4b0aeeba81857a2f0f1fdd2e))
BY35_ROMEND
#define input_ports_dragfis14 input_ports_st
CORE_CLONEDEFNV(dragfis14,dragfist,"Dragonfist (MOD 14)",2021,"Stern / Idleman",by35_mST200,0)

INITGAME(dragfis15,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfis15,"fisted_b02_v15-u1.716",CRC(f4d0499b) SHA1(fe213c9faf1346332cdc4b236140067f443ce1dc),
                             "fisted_b02_v15-u5.716",CRC(fc02ea95) SHA1(c08afb80110fe35b276fbfc1f8229abecb17b74b),
                             "fisted_b02_v15-u2.716",CRC(8ef21e97) SHA1(0739bc4bd8eda82765086a2fb7fdbbbe663a03f4),
                             "fisted_b02_v15-u6.716",CRC(28ead29c) SHA1(2c97363f8a59198727649609cf80ce5cf2631ef6))
BY35_ROMEND
#define input_ports_dragfis15 input_ports_st
CORE_CLONEDEFNV(dragfis15,dragfist,"Dragonfist (MOD 15)",2023,"Stern / slochar",by35_mST200,0)

INITGAME(dragfis16,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfis16,"fisted_VB216-u1.716",CRC(ca30b6ee) SHA1(b056e4661210546ac316eef952525b8500ce6993),
                             "fisted_VB216-u5.716",CRC(b65e49c3) SHA1(1a71cd13f0c8c8898fc09c0582969643c0290979),
                             "fisted_VB216-u2.716",CRC(3b1510ef) SHA1(b2785e9a743a3062e5bc56096c6e81f1a26e59a0),
                             "fisted_VB216-u6.716",CRC(b5f95a47) SHA1(6407c36dd598671321ef2c5661af13ad31c8f15c))
BY35_ROMEND
#define input_ports_dragfis16 input_ports_st
CORE_CLONEDEFNV(dragfis16,dragfist,"Dragonfist (MOD 16)",2024,"Stern / slochar",by35_mST200,0)

/*--------------------------------
/ Dragonfist (bootleg - modified to match instruction card/manual)
/-------------------------------*/
INITGAME(dragfisb,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfisb,"cpu_u1.716",CRC(4cbd1a38) SHA1(73b7291f38cd0a3300107605db26d474ecfc3101),
                            "cpu_u5.716",CRC(1783269a) SHA1(75151b79844d26d9e8ecf00dec96643ee2fedc5b),
                            "cpu_u2.716",CRC(9ac8292b) SHA1(99ad3ad6e1d1b19695ce1b5b76f6bd85c9c6530d),
                            "bcpu_u6.716",CRC(7e8db47b) SHA1(4a42636c1baf39072bbe123855c9cc5f20ca6888))
BY35_ROMEND
#define input_ports_dragfisb input_ports_st
CORE_CLONEDEFNV(dragfisb,dragfist,"Dragonfist (MOD Drop Target Score patch)",1982,"Stern",by35_mST200,0)

// This one from ipdb patches some more additional bytes from dragfisb, but no more documentation found
INITGAME(dragfib2,GEN_STMPU200,dispDragfist,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(dragfib2,"cpu_u1.716",CRC(4cbd1a38) SHA1(73b7291f38cd0a3300107605db26d474ecfc3101),
                            "cpu_u5.716",CRC(1783269a) SHA1(75151b79844d26d9e8ecf00dec96643ee2fedc5b),
                            "cpu_u2.716",CRC(9ac8292b) SHA1(99ad3ad6e1d1b19695ce1b5b76f6bd85c9c6530d),
                            "b2cpu_u6.716",CRC(90b3baad) SHA1(ac2982baff3c4d61d38b39d446a3b8aa012acb30))
BY35_ROMEND
#define input_ports_dragfib2 input_ports_st
CORE_CLONEDEFNV(dragfib2,dragfist,"Dragonfist (MOD Drop Target Score patch 2)",1982,"Stern",by35_mST200,0)

/*--------------------------------
/ Orbitor 1
/-------------------------------*/
static core_tLCDLayout dispOrbitor[] = {
  {0, 0, 1,7,CORE_SEG87F},{0,16, 9,7,CORE_SEG87F},
  {2, 0,17,7,CORE_SEG87F},{2,16,25,7,CORE_SEG87F},
  {4, 4,36,2,CORE_SEG7}, {4,10,38,2,CORE_SEG7}, {4,20,33,3,CORE_SEG7},{0}
};
INITGAME(orbitor1,GEN_STMPU200,dispOrbitor,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(orbitor1,"cpu_u1.716",CRC(575520e3) SHA1(9d52b065a14d4f95cebd48f60f628f2c246385fa),
                            "cpu_u5.716",CRC(d31f27a8) SHA1(0442260db42192a95f6292e6b57000c127871d28),
                            "cpu_u2.716",CRC(4421d827) SHA1(9b617215f2d92ef2c69104eb4e63a924704665aa),
                            "cpu_u6.716",CRC(8861155a) SHA1(81a1b3434d4f80dee5704454f8359200faea173d))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(2ba24569) SHA1(da2f4a4eeed9ae7ff8a342f4d630e12dcb2decf5),
                           "snd_u10.716",CRC(8e5b4a38) SHA1(de3f59363553f5f0d6098401734436930e64fbbd))
BY35_ROMEND
#define input_ports_orbitor1 input_ports_st
CORE_GAMEDEFNV(orbitor1,"Orbitor 1",1982,"Stern",by35_mST200v,0)

INITGAME(orbitofp,GEN_STMPU200,dispOrbitor,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(orbitofp,"cpu_u1.716",CRC(575520e3) SHA1(9d52b065a14d4f95cebd48f60f628f2c246385fa),
                           "fpo1_u5.716",CRC(d6eadb75) SHA1(dc3b483d76f3d02a3f8dd1d298f432ff594b968d),
                           "fpo1_u2.716",CRC(83a6dc48) SHA1(ab6e8e5078ce94bd052ebaef9d323154b5c053bf),
                            "cpu_u6.716",CRC(8861155a) SHA1(81a1b3434d4f80dee5704454f8359200faea173d))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(2ba24569) SHA1(da2f4a4eeed9ae7ff8a342f4d630e12dcb2decf5),
                           "snd_u10.716",CRC(8e5b4a38) SHA1(de3f59363553f5f0d6098401734436930e64fbbd))
BY35_ROMEND
#define input_ports_orbitofp input_ports_st
CORE_CLONEDEFNV(orbitofp,orbitor1,"Orbitor 1 (Free Play)",1982,"Stern",by35_mST200v,0)

INITGAME(orbitora,GEN_STMPU200,dispOrbitor,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(orbitora,"o1v3_u1.716",CRC(31677402) SHA1(5814c4eaa8c36842b6a9c3bbafed1efff39c7b3a),
                            "o1v3_u5.716",CRC(e0e1c8a0) SHA1(40c030c2d80ce3d894a85b1687678e5a545dc701),
                            "cpu_u2.716",CRC(4421d827) SHA1(9b617215f2d92ef2c69104eb4e63a924704665aa),
                            "cpu_u6.716",CRC(8861155a) SHA1(81a1b3434d4f80dee5704454f8359200faea173d))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(2ba24569) SHA1(da2f4a4eeed9ae7ff8a342f4d630e12dcb2decf5),
                           "snd_u10.716",CRC(8e5b4a38) SHA1(de3f59363553f5f0d6098401734436930e64fbbd))
BY35_ROMEND
#define input_ports_orbitora input_ports_st
CORE_CLONEDEFNV(orbitora,orbitor1,"Orbitor 1 (MOD)",1982,"Stern",by35_mST200v,0)

INITGAME(orbitorb,GEN_STMPU200,dispOrbitor,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(orbitorb,"o1v4u1.716",CRC(fcf502bd) SHA1(f1c84d5b29e20eada1aa35e811bd9fec451099f7),
                            "o1v4u5.716",CRC(4dafd165) SHA1(4a5e09200282c4d9d432bd3f839a16dbb3198e31),
                            "o1v4u2.716",CRC(7b708b68) SHA1(cc649d2e6bed80f5608e53578239dca76615c746),
                            "cpu_u6.716",CRC(8861155a) SHA1(81a1b3434d4f80dee5704454f8359200faea173d))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(2ba24569) SHA1(da2f4a4eeed9ae7ff8a342f4d630e12dcb2decf5),
                           "snd_u10.716",CRC(8e5b4a38) SHA1(de3f59363553f5f0d6098401734436930e64fbbd))
BY35_ROMEND
#define input_ports_orbitorb input_ports_st
CORE_CLONEDEFNV(orbitorb,orbitor1,"Orbitor 1 (MOD Free Play)",1982,"Stern",by35_mST200v,0)

INITGAME(orbitorc,GEN_STMPU200,dispOrbitor,FLIP_SW(FLIP_L),0,SNDBRD_ST300V,0)
ST200_ROMSTART8888(orbitorc,"o1v3_u1.716",CRC(31677402) SHA1(5814c4eaa8c36842b6a9c3bbafed1efff39c7b3a), // called MOD1.716 on ipdb.org
                            "MOD5.716",  CRC(57896ec0) SHA1(a8aefa1fd8f05f3e2e112f2c2de474e71070ae05),
                            "cpu_u2.716",CRC(4421d827) SHA1(9b617215f2d92ef2c69104eb4e63a924704665aa),
                            "cpu_u6.716",CRC(8861155a) SHA1(81a1b3434d4f80dee5704454f8359200faea173d))
VSU100_SOUNDROM_U9U10(      "snd_u9.716",CRC(2ba24569) SHA1(da2f4a4eeed9ae7ff8a342f4d630e12dcb2decf5),
                           "snd_u10.716",CRC(8e5b4a38) SHA1(de3f59363553f5f0d6098401734436930e64fbbd))
BY35_ROMEND
#define input_ports_orbitorc input_ports_st
CORE_CLONEDEFNV(orbitorc,orbitor1,"Orbitor 1 (MOD No Timed Game)",1982,"Stern",by35_mST200v,0)

/*--------------------------------
/ Cue (Proto - Never released)
/-------------------------------*/
static const core_tLCDLayout dispCue[] = {
  {0,16, 1,7,CORE_SEG87F},
  {3, 3,34,1,CORE_SEG7}, {3, 6,35,1,CORE_SEG7}, {3, 9,36,2,CORE_SEG7}, {3, 14,38,2,CORE_SEG7},{0}
};
INITGAME(cue,GEN_STMPU200,dispCue,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(cue,"cpu_u1.716",CRC(0e1b4136) SHA1(ce69436a8cd30e2056df2ef86339f2e98e749774),
                       "cpu_u5.716",CRC(65e15866) SHA1(a5f0d156b7429e2565da762d53decf8bc1589a5e),
                       "cpu_u2.716",CRC(7a30ea8e) SHA1(5c8b1ad0add887c5986559c640d620971739e9a1),
                       "cpu_u6.716",CRC(412d4592) SHA1(2bcc8832875bd6be49e17328069c19c955f35f8d))
BY35_ROMEND
#define input_ports_cue input_ports_st
CORE_GAMEDEFNV(cue,"Cue (Prototype)",1982,"Stern",by35_mST200,0)

/*----------------------------------------
/ Lazer Lord (Proto - Never released)
/---------------------------------------*/
INITGAME(lazrlord,GEN_STMPU200,dispst7,FLIP_SW(FLIP_L),0,SNDBRD_ST300,0)
ST200_ROMSTART8888(lazrlord,"cpu_u1.716",CRC(32a6f341) SHA1(75922c6831463d240fe057a0f72280d417899fa4),
                            "cpu_u5.716",CRC(17583ba4) SHA1(4807e3ab18c2e40a292b499fe038975bb4b9fc17),
                            "cpu_u2.716",CRC(669f3a8e) SHA1(4beb0e4c75f4e3c1788808b57081612d4774d130),
                            "cpu_u6.716",CRC(395327a3) SHA1(e2a3a8ea696bcc4b5e11b08b6c7a6d9a991aa4af))
BY35_ROMEND
#define input_ports_lazrlord input_ports_st
CORE_GAMEDEFNV(lazrlord,"Lazer Lord (Prototype)",1984,"Stern",by35_mST200,0)

/*----------------------------------
/ SAM (Service Assistance Module) Test Bench
/---------------------------------*/
static const core_tLCDLayout dispBench[] = {
  {0, 0, 1,7,CORE_SEG87F},{0,16, 9,7,CORE_SEG87F},
  {2, 0,17,7,CORE_SEG87F},{2,16,25,7,CORE_SEG87F},
  {4, 0,33,7,CORE_SEG87}, {4,16,40,4,CORE_SEG7},  {0}
};
static core_tLampDisplay benchLamps = {
  { 0, 0 }, /* top left */
  {13, 17}, /* size */
  {
    {1,{{12,2,YELLOW}}},{1,{{8,2,YELLOW}}},  {1,{{10,2,YELLOW}}}, {1,{{0,2,YELLOW}}},  {1,{{2,2,YELLOW}}}, {1,{{4,2,YELLOW}}},  {1,{{6,2,YELLOW}}},  {1,{{6,0,YELLOW}}},
    {1,{{0,0,YELLOW}}}, {1,{{2,0,YELLOW}}},  {1,{{4,0,YELLOW}}},  {1,{{12,0,YELLOW}}}, {1,{{2,4,YELLOW}}}, {1,{{8,0,YELLOW}}},  {1,{{10,0,YELLOW}}}, {0},
    {1,{{6,8,YELLOW}}}, {1,{{10,6,YELLOW}}}, {1,{{12,6,YELLOW}}}, {1,{{4,10,YELLOW}}}, {1,{{2,10,YELLOW}}},{1,{{0,6,YELLOW}}},  {1,{{8,6,YELLOW}}},  {1,{{6,6,YELLOW}}},
    {1,{{4,6,YELLOW}}}, {1,{{4,4,YELLOW}}},  {1,{{2,6,YELLOW}}},  {1,{{12,4,YELLOW}}}, {1,{{0,4,YELLOW}}}, {1,{{6,4,YELLOW}}},  {1,{{8,4,YELLOW}}},  {0},
    {1,{{6,10,YELLOW}}},{1,{{10,10,YELLOW}}},{1,{{8,12,YELLOW}}}, {1,{{4,14,YELLOW}}}, {1,{{2,14,YELLOW}}},{1,{{8,10,YELLOW}}}, {1,{{12,8,YELLOW}}}, {1,{{10,4,YELLOW}}},
    {1,{{4,12,YELLOW}}},{1,{{2,12,YELLOW}}}, {1,{{0,12,YELLOW}}}, {1,{{12,10,YELLOW}}},{1,{{0,10,YELLOW}}},{1,{{8,8,YELLOW}}},  {1,{{10,8,YELLOW}}}, {0},
    {1,{{6,16,YELLOW}}},{1,{{6,14,YELLOW}}}, {1,{{8,14,YELLOW}}}, {1,{{0,16,YELLOW}}}, {1,{{2,16,YELLOW}}},{1,{{12,16,YELLOW}}},{1,{{10,16,YELLOW}}},{1,{{8,16,YELLOW}}},
    {1,{{4,16,YELLOW}}},{1,{{12,12,YELLOW}}},{1,{{10,14,YELLOW}}},{1,{{12,14,YELLOW}}},{1,{{0,14,YELLOW}}},{1,{{6,12,YELLOW}}}, {1,{{10,12,YELLOW}}}
  }
};
static core_tGameData benchGameData = {GEN_ASTRO,dispBench,{FLIP_SW(FLIP_L),0,0,0,SNDBRD_ASTRO,0,0,0,NULL,NULL,NULL,NULL,&benchLamps}};
static void init_sam_iii(void) { core_gameData = &benchGameData; }
ASTRO_ROMSTART88(sam_iii, "sam_iii_rev_c5.u2",CRC(b9ac5204) SHA1(1ac4e336eb62c091e61e9b6b21a858e70ac9ab38),
                          "sam_iii_rev_c5.u6",CRC(e16fbde1) SHA1(f7fe2f2ef9251792af1227f82dcc95239dd8baa1))
BY35_ROMEND
#define input_ports_sam_iii input_ports_st
CORE_GAMEDEFNV(sam_iii,"S.A.M. III Board Tester (on-board)",19??,"Stern",by35_mST200,0)

static void init_sam_iv(void) { core_gameData = &benchGameData; }
ROM_START(sam_iv)
  NORMALREGION(0x10000, REGION_CPU1)
    ROM_LOAD("sam_iv_r_c5.u1", 0x3c00, 0x400, CRC(5fc44fc9) SHA1(aef3b9dbb0ba1c110b20b8e577168f4c67b6c99d))
      ROM_RELOAD(0xfc00, 0x400)
    ROM_LOAD("sam_iii_rev_c5.u2", 0x1000, 0x800, CRC(b9ac5204) SHA1(1ac4e336eb62c091e61e9b6b21a858e70ac9ab38))
      ROM_RELOAD(0x5000, 0x800)
    ROM_LOAD("sam_iv_r_c5.u3", 0x3800, 0x400, CRC(121a4db0) SHA1(a6a94fb4e17ca1ebcd009b96de6a3c253c7fb510))
    ROM_LOAD("sam_iv_r_c5.u5", 0x3400, 0x400, CRC(361af770) SHA1(1d9698bf261e4f34c7304569c3b5c6d31edaa16a))
    ROM_LOAD("sam_iii_rev_c5.u6", 0x1800, 0x800, CRC(e16fbde1) SHA1(f7fe2f2ef9251792af1227f82dcc95239dd8baa1))
      ROM_RELOAD(0x5800, 0x800)
    ROM_LOAD("sam_iv_r_c5.u7", 0x3000, 0x400, CRC(8766c667) SHA1(d6e6d1927016487f1429d084ec6b1abf54c004c5))
BY35_ROMEND
#define input_ports_sam_iv input_ports_st
CORE_CLONEDEFNV(sam_iv,sam_iii,"S.A.M. IV Board Tester (external)",19??,"Stern",by35_mSTSAM,0)
