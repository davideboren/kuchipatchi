MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, Biome bio, MonsterList evolist){
  lifespans[EGG_STAGE] =      	60*lifespanScaler;
  lifespans[BABY_STAGE] =     		200*lifespanScaler;
  lifespans[CHILD_STAGE] =  		240*lifespanScaler;
  lifespans[TEEN_STAGE] =     		300*lifespanScaler;
  lifespans[ADULT_STAGE] =     	300*lifespanScaler;
  lifespans[ELDER_STAGE] =     	200*lifespanScaler;
  lifespans[POOP_STAGE] =     		10*lifespanScaler;
  lifespans[DEATH_STAGE] =     	60*lifespanScaler;
  
  myName = myname;
  
  bmp1 = s1;
  bmp2 = s2;
  bmp3 = s3;

  monsterType = type;

  monsterStage = stage;

  monsterLifespan = lifespans[stage];

  biome = bio;
  
  evoList = evolist;

}

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, MonsterType type, MonsterStage stage, Biome bio, MonsterList evolist){
  lifespans[EGG_STAGE] =      	60*lifespanScaler;
  lifespans[BABY_STAGE] =     		200*lifespanScaler;
  lifespans[CHILD_STAGE] =  		240*lifespanScaler;
  lifespans[TEEN_STAGE] =     		300*lifespanScaler;
  lifespans[ADULT_STAGE] =     	300*lifespanScaler;
  lifespans[ELDER_STAGE] =     	200*lifespanScaler;
  lifespans[POOP_STAGE] =     		10*lifespanScaler;
  lifespans[DEATH_STAGE] =     	60*lifespanScaler;
  
  myName = myname;
  
  bmp1 = s1;
  bmp2 = s2;
  bmp3 = s1;

  monsterType = type;

  monsterStage = stage;

  monsterLifespan = lifespans[stage];

  biome = bio;
  
  evoList = evolist;

}
