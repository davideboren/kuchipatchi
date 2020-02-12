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

enum Biome {
	LAND,
	OCEAN,
	SNOW
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
  SNOW_FX,
  LAST_FX
};

enum ActiveFXSlot {
  EVOLVE_FX_SLOT,
  FLUSH_FX_SLOT,
  BUBBLE_FX_SLOT,
  SNOW_FX_SLOT,
  LAST_FX_SLOT
};

enum MoveQueueAction {
  MOVE_X_SPRITE_1,
  MOVE_X_SPRITE_2,
  WAIT_SPRITE_1,
  WAIT_SPRITE_2,
  LAST_MOVE_QUEUE_ACTION
};

enum MonsterTask {
  IDLE,
  GOTO,
  STAND
};

#endif
