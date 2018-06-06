#include <vector>

struct ActiveMonsterDB{
  MonsterDB mdb;

  Monster* monsters_p[5];
  int monSize;

  ActiveMonsterDB(MonsterDB mondb);
  Monster* spawnMonster(MonsterName name);
  void addMonster(MonsterName name);
  void deleteMonster(int pos);
  Monster * getMonster(int pos);
  int numActiveMonsters();
};
