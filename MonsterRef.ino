MonsterRef::MonsterRef(){

}

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, const uint8_t *s3, MonsterType type, MonsterStage stage, bool isUnderwater, MonsterList evolist){
  lifespans[EGG_STAGE] =      	30*lifespanScaler;
  lifespans[BABY_STAGE] =     	60*lifespanScaler;
  lifespans[CHILD_STAGE] =  	60*lifespanScaler;
  lifespans[TEEN_STAGE] =     	60*lifespanScaler;
  lifespans[ADULT_STAGE] =     60*lifespanScaler;
  lifespans[POOP_STAGE] =     	10*lifespanScaler;
  lifespans[DEATH_STAGE] =     60*lifespanScaler;
  
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

MonsterRef::MonsterRef(MonsterName myname, const uint8_t *s1, const uint8_t *s2, MonsterType type, MonsterStage stage, bool isUnderwater, MonsterList evolist){
  lifespans[EGG_STAGE] =      	30*lifespanScaler;
  lifespans[BABY_STAGE] =     	60*lifespanScaler;
  lifespans[CHILD_STAGE] =  	60*lifespanScaler;
  lifespans[TEEN_STAGE] =     	60*lifespanScaler;
  lifespans[ADULT_STAGE] =     60*lifespanScaler;
  lifespans[POOP_STAGE] =     	10*lifespanScaler;
  lifespans[DEATH_STAGE] =     60*lifespanScaler;
  
  myName = myname;
  
  bmp1 = s1;
  bmp2 = s2;
  bmp3 = s1;

  monsterType = type;

  monsterStage = stage;

  monsterLifespan = lifespans[stage];

  oceanType = isUnderwater;
  
  evoList = evolist;

}
