/*
 * Controller.h
 *
 * Coordinates all on screen entities
 */

#include "Monster.h"
#include "MonsterDB.h"

class Controller{
  private:
    int eMonsterIdAddr = 0;
    int frameDelay;

    Monster* activeMonsters[10];
    void addMonster(MonsterName name, ActiveMonsterSlot slot);
    Monster* newMonster(MonsterName name);
    void deleteMonster(int slot);
    void evolveMonster(int slot);
    void sendMonsterToPos(int slot, int x);
    void updateMonsters();

  public:
    Controller();
    MonsterDB mdb;
    void drawFrame(Frame f);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
