MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, bool underwater, MonsterName next1, MonsterName next2){
  
  lifespans[EGG_STAGE] =      500;
  lifespans[BABY_STAGE] =     500;
  lifespans[TODDLER_STAGE] =  500;
  lifespans[TEEN_STAGE] =     500;
  lifespans[ADULT_STAGE] =    500;
  lifespans[POOP_STAGE] =     500;
  lifespans[SHIP_STAGE] =     500;
  
  myName = myname;
  
  bmp1 = s1;
  bmp2 = s2;
  bmp3 = s3;

  monsterType = type;

  monsterStage = stage;

  monsterLifespan = lifespans[stage];

  oceanType = underwater;

  nextMonster[0] = next1;
  nextMonster[1] = next2;

}
