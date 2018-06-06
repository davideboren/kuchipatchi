#include <vector>

struct ActiveMonsterDB{
  MonsterDB mdb;

  MoverMon pacers [5];
  int pacerPos;

  Monster* monsters_p[5];
  int monSize;

  ActiveMonsterDB(MonsterDB mondb);
  Monster* spawnMonster(MonsterName name);
  void addMonster(MonsterName name);
  void deleteMonster(int pos);
  void addMover(MonsterName name);
  Monster * getMonster(int pos);
  int numActiveMonsters();
};
