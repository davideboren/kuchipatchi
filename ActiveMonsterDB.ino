ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
}

void ActiveMonsterDB::addMover(int id){
  pacers.push_back(MoverMon(mdb.getSprite1(id),mdb.getSprite2(id)));
  monsters_p.push_back(&pacers.back());
}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

<<<<<<< HEAD
int ActiveMonsterDB::numActiveMonsters(){
  return monsters_p.size();
}

=======
>>>>>>> parent of e4f1310... ActiveMonsterDB functional
