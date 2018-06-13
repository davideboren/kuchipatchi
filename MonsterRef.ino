MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(const uint8_t *s1, MonsterType type, unsigned int lifespan, MonsterName next1, MonsterName next2){
  sprite1 = s1;
  sprite2 = s1;

  monsterType = type;

  monsterLifespan = lifespan;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}

MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, MonsterType type, unsigned int lifespan, MonsterName next1, MonsterName next2){
  sprite1 = s1;
  sprite2 = s2;

  monsterType = type;

  monsterLifespan = lifespan;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}
