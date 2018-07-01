MonsterDB::MonsterDB(){

  oceanTrue = true;
  oceanFalse = false;

  monsterRepo[DigiEgg1] =       MonsterRef(DigiEgg1,degg1,degg2,degg3,EGG,EGG_STAGE,oceanFalse,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Kurotsubutchi] =  MonsterRef(Kurotsubutchi,kurotsubutchi1,kurotsubutchi2,kurotsubutchi2,MOVER,BABY_STAGE,oceanTrue,Kuchipatchi,Mimitchi);
  monsterRepo[Kuchipatchi] =    MonsterRef(Kuchipatchi,kuchipatchi1,kuchipatchi2,kuchipatchi2,MOVER,ADULT_STAGE,oceanFalse,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Mimitchi] =       MonsterRef(Mimitchi,mimitchi1,mimitchi1,mimitchi1,SITTER,ADULT_STAGE,oceanFalse,Kurotsubutchi,Kurotsubutchi);
  monsterRepo[Poop] =           MonsterRef(Poop,poop1, poop2,poop2, SITTER, POOP_STAGE,oceanFalse, Poop, Poop);

}

const uint8_t * MonsterDB::getSprite1(MonsterName name){
  return monsterRepo[name].bmp1;
}

const uint8_t * MonsterDB::getSprite2(MonsterName name){
  return monsterRepo[name].bmp2;
}

const uint8_t * MonsterDB::getSprite3(MonsterName name){
  return monsterRepo[name].bmp3;
}

MonsterType MonsterDB::getMonsterType(MonsterName name){
  return monsterRepo[name].monsterType;
}

MonsterStage MonsterDB::getMonsterStage(MonsterName name){
  return monsterRepo[name].monsterStage;
}

bool MonsterDB::isUnderwater(MonsterName name){
  return monsterRepo[name].oceanType;
}

MonsterName MonsterDB::getNextMonster(MonsterName name){
  return random(2)?monsterRepo[name].nextMonster[0]:monsterRepo[name].nextMonster[1];
}

Monster* MonsterDB::newMonster(MonsterName name){
  switch(getMonsterType(name)){
    case EGG:
      return new Egg(monsterRepo[name],0);
    case MOVER:
      return new MoverMon(monsterRepo[name],0);
      break;
    case SITTER:
      return new Sitter(monsterRepo[name],0);
      break;
    case FLOATER:
      Serial.println("got floater");
      break;
  }
  return NULL;
}

ScreenFX* MonsterDB::newFX(FXType fx){
  switch(fx){
    case FLUSH_FX:
      return new FlusherFX();
      break;
    case BUBBLE_FX:
      return new BubbleFX();
      break;
    case EVOLVE_FX:
      return new EvolveFX();
      break;
  }
}

MonsterName MonsterDB::getRandomMonster(MonsterName name){
  MonsterName rando;
  do{
    rando = static_cast<MonsterName>(random(LAST_MON_NAME));
  }while(getMonsterStage(rando) != getMonsterStage(name) || isUnderwater(rando) != isUnderwater(name));
  return rando;
}
