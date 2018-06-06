MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, MonsterType type, unsigned int lifespan, int next1, int next2){
  sprite1 = s1;
  sprite2 = s2;

  monsterType = type;

  monsterLifespan = lifespan;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}
