/*
 * Defs.h
 *
 * Contains:
 *	- enums for monster parameters
 *	- Raw sprite data
 * 
 */
#ifndef DEFS_H
#define DEFS_H

#include "sprites.h"

enum MonsterType {
  EGG,
  MOVER,
  SITTER,
  SHY_SITTER,
  FLOATER
};

enum MonsterStage {
  EGG_STAGE,
  BABY_STAGE,
  CHILD_STAGE,
  TEEN_STAGE,
  ADULT_STAGE,
  POOP_STAGE,
  DEATH_STAGE,
  LAST_STAGE
};

enum Events {
  POOP_EVENT,
  VISITOR_EVENT,
  NUM_RANDOM_EVENTS,
  IDLE_EVENT,
  EVO_EVENT,
  EVO_EVENT_NO_ANIM
};

enum ActiveMonsterSlot {
  PRIMARY,
  VISITOR,
  POOP,
  BUBBLES,
  LAST_MON_SLOT
};

enum FXType {
  EVOLVE_FX,
  FLUSH_FX,
  BUBBLE_FX,
  LAST_FX
};

enum ActiveFXSlot {
  EVOLVE_FX_SLOT,
  FLUSH_FX_SLOT,
  BUBBLE_FX_SLOT,
  LAST_FX_SLOT
};

enum MoveQueueAction {
  MOVE_X_SPRITE_1,
  MOVE_X_SPRITE_2,
  WAIT_SPRITE_1,
  WAIT_SPRITE_2,
  LAST_MOVE_QUEUE_ACTION
};

/*enum MonsterName {
  DigiEgg1,
  Betamon,
  Gizamon,
  Grave,
  Koromon,
  Kuchipatchi,
  Kurotsubutchi,
  Mimitchi,
  Poop,
  LAST_MON_NAME
};*/

enum MonsterTask {
  IDLE,
  GOTO,
  STAND
};

/*static const unsigned char PROGMEM betamon1 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x0, 0x10, 0xc0, 0x8, 0x20, 0xb, 0xd0, 0x14, 0x38, 0x20, 0x67, 0x52, 0x8d, 0x52, 0x13, 0x40, 0x2, 0x40, 0x29, 0xbe, 0x71, 0xf3, 0xde, 
};

static const unsigned char PROGMEM betamon2 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0x0, 0x10, 0xc0, 0x8, 0x20, 0xb, 0xd0, 0x14, 0x38, 0x20, 0x67, 0x52, 0x8d, 0x52, 0x13, 0x40, 0x2, 0xc2, 0x19, 0xff, 0xff, 
};

//Blank sprite for frame init
static const unsigned char PROGMEM blank [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//Bubble
static const unsigned char PROGMEM bubble [] = {
0x40, 0x00, 0xA0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//Evolution Overlay
static const unsigned char PROGMEM evolve [] = {
0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00,
0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00, 0xAA, 0x00, 0x55, 0x00
};

static const unsigned char PROGMEM evolve2 [] = {
0xCC, 0x00, 0xCC, 0x00, 0x33, 0x00, 0x33, 0x00, 0xCC, 0x00, 0xCC, 0x00, 0x33, 0x00, 0x33, 0x00,
0xCC, 0x00, 0xCC, 0x00, 0x33, 0x00, 0x33, 0x00, 0xCC, 0x00, 0xCC, 0x00, 0x33, 0x00, 0x33, 0x00
};

//Digi-Egg
static const unsigned char PROGMEM degg1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x06, 0x20, 0x0E, 0x10, 0x16, 0x18,
0x16, 0x38, 0x2C, 0x34, 0x2C, 0x34, 0x2C, 0x34, 0x2C, 0x34, 0x16, 0x38, 0x0E, 0x10, 0x07, 0xE0
};
static const unsigned char PROGMEM degg2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x0C, 0x30,
0x1C, 0x08, 0x2C, 0x1C, 0x2C, 0x1C, 0x58, 0x3A, 0x58, 0x32, 0x4C, 0x3A, 0x26, 0x1C, 0x1F, 0xF8
};
static const unsigned char PROGMEM degg3 [] = {
0x00, 0x1C, 0x30, 0x22, 0x48, 0x1E, 0x90, 0x0F, 0xA2, 0x4D, 0xA3, 0xC6, 0x45, 0xA0, 0x07, 0xE0,
0x06, 0x60, 0x16, 0x68, 0x2F, 0xF4, 0x26, 0x74, 0x26, 0x34, 0x17, 0x38, 0x0B, 0x10, 0x07, 0xE0
};

static const unsigned char PROGMEM gizamon1 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x80, 0x4, 0xb8, 0xb, 0xc8, 0x1f, 0xf8, 0x2c, 0xff, 0x48, 0x3d, 0x52, 0x7d, 0x52, 0xe, 0x40, 0x1e, 0x41, 0x9, 0xbe, 0x71, 0xf3, 0xdf, 
};

static const unsigned char PROGMEM gizamon2 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x80, 0x4, 0xb8, 0xb, 0xc8, 0x1f, 0xf8, 0x2c, 0xff, 0x48, 0x3d, 0x52, 0x7d, 0x52, 0xe, 0x40, 0x1e, 0xc1, 0x21, 0xff, 0xff, 
};

static const unsigned char PROGMEM gizamon3 [] = {
0x0, 0xe0, 0x3, 0x20, 0x4, 0xc0, 0x1f, 0xfe, 0x2d, 0x72, 0x73, 0x1c, 0x40, 0x3c, 0x6a, 0x8f, 0x3f, 0xc5, 0x1f, 0xc6, 0x1f, 0xc2, 0x35, 0x43, 0x40, 0x11, 0x7f, 0x39, 0x92, 0x31, 0xf3, 0xff, 
};

static const unsigned char PROGMEM grave1 [] = {
0x0, 0x0, 0x0, 0x0, 0x1, 0x80, 0x1, 0x80, 0xf, 0xf0, 0xf, 0xf0, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0x7, 0xe0, 0x8, 0x10, 0x13, 0xc8, 0x10, 0x8, 0x13, 0xc8, 0x10, 0x8, 0x3f, 0xfc, 
};

static const unsigned char PROGMEM grave2 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x80, 0x1, 0x80, 0xf, 0xf0, 0xf, 0xf0, 0x1, 0x80, 0x1, 0x80, 0x1, 0x80, 0xf, 0xf0, 0x37, 0xec, 0x20, 0x4, 0x27, 0xe4, 0x20, 0x4, 0x7f, 0xfe, 
};

static const unsigned char PROGMEM mimitchi1 [] = {
0x0, 0x0, 0x0, 0x0, 0xc, 0x18, 0x1e, 0x3c, 0x1e, 0x3c, 0xf, 0x78, 0xf, 0xf8, 0x8, 0x8, 0x14, 0x14, 0x11, 0xc4, 0x38, 0x6, 0x38, 0x6, 0x10, 0x4, 0x8, 0x18, 0x7, 0xf8, 0xf, 0x8, 
};

static const unsigned char PROGMEM mimitchi2 [] = {
0x0, 0x0, 0x0, 0x0, 0x18, 0x30, 0x3c, 0x78, 0x3c, 0x78, 0x1e, 0xf0, 0x1f, 0xf0, 0x10, 0x10, 0x28, 0x28, 0x23, 0x88, 0x60, 0x1c, 0x60, 0x1c, 0x20, 0x8, 0x18, 0x10, 0x1f, 0xe0, 0x10, 0xf0, 
};

int idKuchipatchi = 0;
static const unsigned char PROGMEM kuchipatchi1 [] = {
0x00, 0x00, 0x07, 0xE0, 0x08, 0x10, 0x14, 0x08, 0x70, 0x44, 0x80, 0x04, 0xF0, 0x04, 0x80, 0x04,
0x60, 0x04, 0x10, 0x02, 0x10, 0x52, 0x10, 0x52, 0x10, 0x22, 0x08, 0x04, 0x04, 0xC8, 0x03, 0x30
};
static const unsigned char PROGMEM kuchipatchi2 [] = {
0x00, 0x00, 0x07, 0xE0, 0xC8, 0x10, 0xB4, 0x08, 0x80, 0x44, 0x70, 0x04, 0x80, 0x04, 0xA0, 0x04,
0xD0, 0x04, 0x10, 0x02, 0x10, 0x12, 0x10, 0x4A, 0x10, 0x32, 0x08, 0x04, 0x09, 0x38, 0x06, 0xC0
};

static const unsigned char PROGMEM koromon1 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x30, 0x5, 0xd0, 0x8, 0x8, 0x12, 0x24, 0x12, 0x24, 0x11, 0xc4, 0x10, 0x4, 0x10, 0x4, 0x8, 0x8, 0x7, 0xf0, 0x0, 0x0, 0x0, 0x0, 
};

static const unsigned char PROGMEM koromon2 [] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x30, 0x5, 0xd0, 0x8, 0x8, 0x12, 0x24, 0x12, 0x24, 0x10, 0x84, 0x10, 0x4, 0xf, 0xf8, 
};

//Kurotsubutchi
int idKurotsubutchi = 1;
static const unsigned char PROGMEM kurotsubutchi1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x80, 0x03, 0xC0, 0x07, 0xE0, 0x0D, 0xF0, 0x0F, 0xB0, 0x0C, 0xF0, 0x0F, 0xF0, 0x07, 0xE0
};
static const unsigned char PROGMEM kurotsubutchi2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x80, 0x03, 0xC0, 0x07, 0xE0, 0x0D, 0xB0, 0x0F, 0xF0, 0x0E, 0x70, 0x07, 0xE0
};

//Poop
static const unsigned char PROGMEM poop1 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x10, 0x04, 0x20, 0x08, 0x10, 0x05, 0x00, 0x01, 0x80, 0x03, 0x40, 0x07, 0xA0, 0x07, 0xE0
};
static const unsigned char PROGMEM poop2 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x04, 0x20, 0x08, 0x10, 0x01, 0x20, 0x01, 0x80, 0x03, 0x40, 0x05, 0xE0, 0x07, 0xE0
};

static const unsigned char PROGMEM flusher [] = {
0x3A, 0x00, 0x64, 0x00, 0xC8, 0x00, 0x64, 0x00, 0x3A, 0x00, 0x64, 0x00, 0xC8, 0x00, 0x64, 0x00,
0x3A, 0x00, 0x64, 0x00, 0xC8, 0x00, 0x64, 0x00, 0x3A, 0x00, 0x64, 0x00, 0xC8, 0x00, 0x64, 0x00
};*/

#endif
