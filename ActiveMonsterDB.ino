ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
  pacerPos = 0;
  monSize = 0;
}

void ActiveMonsterDB::addMonster(int id){
  Serial.print("Adding monster ID: "); Serial.println(id);
  switch(mdb.getMonsterType(id)){
    case 1: 
      addMover(id);
      break;
  }
  Serial.print("Added monster ID: "); Serial.println(id);
}

void ActiveMonsterDB::deleteMonster(int pos){
  Serial.print("Deleting monster at: "); Serial.println(pos);
  monsters_p[pos] = 0;
  monSize--;
  for(int i = pos; i < monSize; i++){
    monsters_p[pos] = monsters_p[pos+1];
  }
  monsters_p[monSize] = 0;
}

void ActiveMonsterDB::addMover(int id){
  //pacers.push_back(MoverMon(mdb.getSprite1(id),mdb.getSprite2(id)));
  //monsters_p.push_back(&pacers.back());
  
  pacers[pacerPos] = MoverMon(mdb.getSprite1(id),mdb.getSprite2(id),0,mdb.getMonsterLifespan(id),mdb.getNextMonster(id));
  monsters_p[monSize] = &pacers[pacerPos];
  pacerPos++;
  monSize++;
}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

int ActiveMonsterDB::numActiveMonsters(){
  //return monsters_p.size();
  return monSize;
}

