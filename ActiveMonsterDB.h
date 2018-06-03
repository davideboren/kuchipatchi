#include <vector>

struct ActiveMonsterDB{
  MonsterDB mdb;

  //std::vector<MoverMon> pacers;

  //std::vector<Monster*> monsters_p;

  MoverMon pacers [5];
  int pacerPos;

  Monster* monsters_p[5];
  int monSize;

  ActiveMonsterDB(MonsterDB mondb);
  void addMonster(int id);
  void deleteMonster(int pos);
  void addMover(int id);
  Monster * getMonster(int pos);
  int numActiveMonsters();
};

