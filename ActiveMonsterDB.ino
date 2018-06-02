ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
  pacerCount = 0;
  pMonCount = 0;
}

void ActiveMonsterDB::addMonster(int id){
  switch(mdb.getMonsterType(id)){
    case 1: 
      addMover(id);
      break;
  }
}

void ActiveMonsterDB::addMover(int id){
  pacers[pacerCount] = MoverMon(mdb.getSprite1(id),mdb.getSprite2(id));
  //vPacers.push_back(MoverMon(mdb.getSprite1(id),mdb.getSprite2(id)));
  
  monsters_p[pMonCount] = &pacers[pacerCount];
  //monsters_p[pMonCount] = &vPacers.front();
  pacerCount++;
  pMonCount++;
}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

int ActiveMonsterDB::numActiveMonsters(){
  return pMonCount;
}

