ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
  pacerCount = 0;
  pMonCount = 0;
}

void ActiveMonsterDB::addMover(int id){
  pacers[pacerCount] = MoverMon(mdb.getSprite1(id),mdb.getSprite2(id));
  monsters_p[pMonCount] = &pacers[pacerCount];
  pacerCount++;
  pMonCount++;
}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

