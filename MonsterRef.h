#ifndef MONSTERREF_H
#define MONSTERREF_H

struct MonsterRef{
  const uint8_t *sprite1, *sprite2;
  int monsterType;
  unsigned int monsterLifespan;
  int nextMonster[2];

  MonsterRef();
  MonsterRef(const uint8_t *s1, const uint8_t *s2, int type, unsigned int lifespan, int next1, int next2);
};

#endif
