#ifndef MONSTERREF_H
#define MONSTERREF_H

#include "Defs.h"

struct MonsterRef{

  unsigned int lifespans[LAST_STAGE];
  
  MonsterName myName;
  const uint8_t *bmp1, *bmp2, *bmp3;
  MonsterType monsterType;
  MonsterName nextMonster[2];
  MonsterStage monsterStage;
  bool oceanType;
  unsigned int monsterLifespan;

  MonsterRef();
  MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, bool underwater, MonsterName next1, MonsterName next2);

};

#endif
