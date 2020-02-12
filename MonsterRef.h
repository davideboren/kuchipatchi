#ifndef MONSTERREF_H
#define MONSTERREF_H

#include "Defs.h"
#include "MonsterList.h"

struct MonsterRef{

  unsigned int lifespans[LAST_STAGE];
  int lifespanScaler = 600;
  
  MonsterName myName;
  const uint8_t *bmp1, *bmp2, *bmp3;
  MonsterType monsterType;
  MonsterStage monsterStage;
  bool oceanType;
  Biome biome;
  unsigned int monsterLifespan;
  
  MonsterList evoList;

  MonsterRef();
  MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, Biome bio, MonsterList evolist);
  MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, MonsterType type, MonsterStage stage, Biome bio, MonsterList evolist);

};

#endif
