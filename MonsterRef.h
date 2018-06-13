#ifndef MONSTERREF_H
#define MONSTERREF_H

struct MonsterRef{
  const uint8_t *sprite1, *sprite2;
  MonsterType monsterType;
  unsigned int monsterLifespan;
  MonsterName nextMonster[2];

  MonsterRef();
  MonsterRef(const uint8_t *s1, MonsterType type, unsigned int lifespan, MonsterName next1, MonsterName next2);
  MonsterRef(const uint8_t *s1, const uint8_t *s2, MonsterType type, unsigned int lifespan, MonsterName next1, MonsterName next2);

};

#endif
