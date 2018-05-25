MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, int type, int next1, int next2){
  sprite1 = s1;
  sprite2 = s2;
  monsterType = type;
  nextMonster[0] = next1;
  nextMonster[1] = next2;
}

