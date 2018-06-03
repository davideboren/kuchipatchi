ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
}

void ActiveMonsterDB::addMonster(int id){
  switch(mdb.getMonsterType(id)){
    case 1: 
      addMover(id);
      break;
  }
}

void ActiveMonsterDB::addMover(int id){
  pacers.push_back(MoverMon(mdb.getSprite1(id),mdb.getSprite2(id)));
  monsters_p.push_back(&pacers.back());
}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

int ActiveMonsterDB::numActiveMonsters(){
  return monsters_p.size();
}

