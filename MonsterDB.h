#ifndef MONSTERDB_H
#define MONSTERDB_H

#include "MonsterRef.h"
#include "Monster.h"
struct MonsterDB{
  MonsterRef monsterRepo[10];
  int lifespans[LAST_STAGE];
  MonsterDB();

  const uint8_t *   getSprite1(MonsterName name);
  const uint8_t *   getSprite2(MonsterName name);
  MonsterType   getMonsterType(MonsterName name);
  unsigned int  getMonsterLifespan(MonsterName name);
  MonsterName getNextMonster(MonsterName name);
  MonsterStage getMonsterStage(MonsterName name);
  Monster* newMonster(MonsterName name);
  MonsterName getRandomMonster(MonsterStage stage);
};

#endif
