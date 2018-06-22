MonsterDB::MonsterDB(){

  lifespans[EGG_STAGE] =      100;
  lifespans[BABY_STAGE] =     100;
  lifespans[TODDLER_STAGE] =  100;
  lifespans[TEEN_STAGE] =     100;
  lifespans[ADULT_STAGE] =    100;
  lifespans[POOP_STAGE] =     100;
  lifespans[SHIP_STAGE] =     100;

  monsterRepo[DigiEgg1] =       MonsterRef(degg1,degg2,degg3,EGG,EGG_STAGE,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Kurotsubutchi] =  MonsterRef(kurotsubutchi1,kurotsubutchi2,MOVER,BABY_STAGE,Kuchipatchi,Mimitchi);
  monsterRepo[Kuchipatchi] =    MonsterRef(kuchipatchi1,kuchipatchi2,MOVER,ADULT_STAGE,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Mimitchi] =       MonsterRef(mimitchi1,SITTER,ADULT_STAGE,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Poop] =           MonsterRef(poop1, poop2, SITTER, POOP_STAGE, Poop, Poop);

}

const uint8_t * MonsterDB::getSprite1(MonsterName name){
  return monsterRepo[name].sprite1;
}

const uint8_t * MonsterDB::getSprite2(MonsterName name){
  return monsterRepo[name].sprite2;
}

const uint8_t * MonsterDB::getSprite3(MonsterName name){
  return monsterRepo[name].sprite3;
}

MonsterType MonsterDB::getMonsterType(MonsterName name){
  return monsterRepo[name].monsterType;
}

MonsterStage MonsterDB::getMonsterStage(MonsterName name){
  return monsterRepo[name].monsterStage;
}

unsigned int MonsterDB::getMonsterLifespan(MonsterName name){
  return lifespans[monsterRepo[name].monsterStage];
}

MonsterName MonsterDB::getNextMonster(MonsterName name){
  return random(2)?monsterRepo[name].nextMonster[0]:monsterRepo[name].nextMonster[1];
}

Monster* MonsterDB::newMonster(MonsterName name){
  switch(getMonsterType(name)){
    case EGG:
      return new Egg(name, getSprite1(name), getSprite2(name), getSprite3(name),0,getMonsterLifespan(name), getNextMonster(name));
    case MOVER:
      return new MoverMon(getSprite1(name),getSprite2(name),getMonsterStage(name),0,getMonsterLifespan(name),getNextMonster(name));
      break;
    case SITTER:
      if(getSprite1(name) == getSprite2(name)){
        return new Sitter(getSprite1(name),getMonsterStage(name),0,getMonsterLifespan(name),getNextMonster(name));
      } else {
        return new Sitter(getSprite1(name), getSprite2(name),getMonsterStage(name), 0,getMonsterLifespan(name),getNextMonster(name));
      }
      break;
    case FLOATER:
      Serial.println("got floater");
      break;
  }
  return NULL;
}

MonsterName MonsterDB::getRandomMonster(MonsterStage stage){
  MonsterName rando;
  do{
    rando = static_cast<MonsterName>(random(LAST_MON_NAME));
  }while(getMonsterStage(rando) != stage);
  return rando;
}
