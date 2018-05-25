#ifndef MONSTERREF_H
#define MONSTERREF_H

struct MonsterRef{
  const uint8_t *sprite1, *sprite2;
  int monsterType;
  int nextMonster[2];

  MonsterRef(const uint8_t *s1, const uint8_t *s2, int type, int next1, int next2);
};

#endif
