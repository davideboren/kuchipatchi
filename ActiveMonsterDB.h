#include <vector>

struct ActiveMonsterDB{
  MonsterDB mdb;

  std::vector<MoverMon> pacers;

  std::vector<Monster*> monsters_p;

  ActiveMonsterDB(MonsterDB mondb);
  void addMonster(int id);
  void addMover(int id);
  Monster * getMonster(int pos);
  int numActiveMonsters();
};

