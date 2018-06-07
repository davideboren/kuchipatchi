/*
 * Controller.h
 *
 * Coordinates all on screen entities
 */

#include "Monster.h"
#include "MonsterDB.h"

class Controller{
  private:
    int monArrayPos = 0;
    int eMonsterIdAddr = 0;
    int numActiveMons;

    Monster* activeMonsters[10];
    void addMonster(MonsterName name);
    Monster* newMonster(MonsterName name);
    void deleteMonster(int pos);
    void evolveMonster(int pos);

  public:
    Controller();
    MonsterDB mdb;
    void drawFrame(Frame f);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
