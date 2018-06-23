#ifndef MONSTERREF_H
#define MONSTERREF_H

#include "Defs.h"

struct MonsterRef{
  const uint8_t *sprite1, *sprite2, *sprite3;
  MonsterType monsterType;
  MonsterName nextMonster[2];
  MonsterStage monsterStage;
  bool oceanType;
  unsigned int monsterLifespan;

  MonsterRef();
  MonsterRef(const uint8_t *s1, MonsterType type, MonsterStage stage, bool underwater, MonsterName next1, MonsterName next2);
  MonsterRef(const uint8_t *s1, const uint8_t *s2, MonsterType type, MonsterStage stage, bool underwater, MonsterName next1, MonsterName next2);
  MonsterRef(const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, bool underwater, MonsterName next1, MonsterName next2);

};

#endif
