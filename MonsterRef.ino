MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, bool isUnderwater, MonsterList evolist){
  lifespans[EGG_STAGE] =      600;
  lifespans[BABY_STAGE] =     600;
  lifespans[CHILD_STAGE] =  1000;
  lifespans[TEEN_STAGE] =     1000;
  lifespans[ADULT_STAGE] =    1000;
  lifespans[POOP_STAGE] =     300;
  lifespans[DEATH_STAGE] =     700;
  
  myName = myname;
  
  bmp1 = s1;
  bmp2 = s2;
  bmp3 = s3;

  monsterType = type;

  monsterStage = stage;

  monsterLifespan = lifespans[stage];

  oceanType = isUnderwater;
  
  evoList = evolist;

}
