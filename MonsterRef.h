struct MonsterRef{
  const uint8_t *sprite1, *sprite2;
  int monsterType;
  int nextMonster;

  MonsterRef(const uint8_t *s1, const uint8_t *s2, int type, int next);
};

