#ifndef MONSTERDB_H
#define MONSTERDB_H

#include "MonsterRef.h"
#include "Monster.h"
struct MonsterDB{
  MonsterRef monsterRepo[10];
  MonsterDB();

  const uint8_t *   getSprite1(int id);
  const uint8_t *   getSprite2(int id);
  MonsterType   getMonsterType(int id);
  unsigned int  getMonsterLifespan(int id);
  int getNextMonster(int id);
};

#endif
