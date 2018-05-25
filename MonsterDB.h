#ifndef MONSTERDB_H
#define MONSTERDB_H

#include "MonsterRef.h"
struct MonsterDB{
  MonsterRef monsterLookups [];
  MonsterDB();

  const uint8_t * getSprite1(int id);
  const uint8_t * getSprite2(int id);
};

#endif
