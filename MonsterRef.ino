MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(const uint8_t *s1, MonsterType type, MonsterStage stage, MonsterName next1, MonsterName next2){
  sprite1 = s1;
  sprite2 = s1;

  monsterType = type;

  monsterStage = stage;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}

MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, MonsterType type, MonsterStage stage, MonsterName next1, MonsterName next2){
  sprite1 = s1;
  sprite2 = s2;

  monsterType = type;

  monsterStage = stage;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}

MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, MonsterName next1, MonsterName next2){
  sprite1 = s1;
  sprite2 = s2;
  sprite3 = s3;

  monsterType = type;

  monsterStage = stage;

  nextMonster[0] = next1;
  nextMonster[1] = next2;
}
