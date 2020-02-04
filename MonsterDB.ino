MonsterDB::MonsterDB(){

  oceanTrue = true;
  oceanFalse = false;
  
	monsterRepo[Betamon] =
		MonsterRef(
			Betamon,
			betamon1,betamon2,betamon1,
			MOVER,
			TEEN_STAGE,
			oceanTrue,
			MonsterList(Kaitchi)
		);

	monsterRepo[DigiEgg1] =       
		MonsterRef(
			DigiEgg1,
			degg1,degg2,degg3,
			EGG,
			EGG_STAGE,
			oceanFalse,
			MonsterList(Kurotsubutchi)
		);
		
	monsterRepo[Gizamon] =
		MonsterRef(
			Gizamon,
			gizamon1,gizamon2,gizamon3,
			MOVER,
			TEEN_STAGE,
			oceanFalse,
			MonsterList(Mimitchi,Kuchipatchi)
		);
  
	monsterRepo[Grave] =
		MonsterRef(
			Grave,
			grave1,grave2,grave1,
			SITTER,
			DEATH_STAGE,
			oceanFalse,
			MonsterList(DigiEgg1)
		);
		
	monsterRepo[Kaitchi] =
		MonsterRef(
			Kaitchi,
			kaitchi1,kaitchi1,kaitchi2,
			SITTER,
			ADULT_STAGE,
			oceanTrue,
			MonsterList(Grave)
		);
		
	monsterRepo[Koromon] =
		MonsterRef(
			Koromon,
			koromon1,koromon2,koromon1,
			MOVER,
			TODDLER_STAGE,
			oceanFalse,
			MonsterList(Betamon,Gizamon)
		);
	
	monsterRepo[Kurotsubutchi] =  
		MonsterRef(
			Kurotsubutchi,
			kurotsubutchi1,kurotsubutchi2,kurotsubutchi1,
			MOVER,
			BABY_STAGE,
			oceanFalse,
			MonsterList(Koromon)
		);
	
	monsterRepo[Kuchipatchi] =    
		MonsterRef(
			Kuchipatchi,
			kuchipatchi1,kuchipatchi2,kuchipatchi3,
			MOVER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Grave)
		);
		
	monsterRepo[Mimitchi] =       
		MonsterRef(
			Mimitchi,
			mimitchi1,mimitchi2,mimitchi1,
			SITTER,
			ADULT_STAGE,
			oceanFalse,
			MonsterList(Grave)
		);
		
	monsterRepo[Poop] =           
		MonsterRef(
			Poop,
			poop1,poop2,poop1, 
			SITTER,
			POOP_STAGE,
			oceanFalse, 
			MonsterList(Poop)
		);

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
