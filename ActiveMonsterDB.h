struct ActiveMonsterDB{
  MonsterDB mdb;
  
  int pacerCount;
  MoverMon pacers[2];

  int pMonCount;
  Monster * monsters_p[5];

  ActiveMonsterDB(MonsterDB mondb);
  void addMover(int id);
  Monster * getMonster(int pos);
};

