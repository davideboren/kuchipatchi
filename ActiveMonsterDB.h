#include <vector>

struct ActiveMonsterDB{
  MonsterDB mdb;
  
  int pacerCount;
  MoverMon pacers[2];
  std::vector<MoverMon> vPacers;

  int pMonCount;
  Monster * monsters_p[5];

  ActiveMonsterDB(MonsterDB mondb);
  void addMonster(int id);
  void addMover(int id);
  Monster * getMonster(int pos);
  int numActiveMonsters();
};

