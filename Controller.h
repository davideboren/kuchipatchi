/*
 * Controller.h
 *
 * Coordinates all on screen entities
 */

#include "Monster.h"
#include "MonsterDB.h"

class Controller{
  private:
    int offFrameSlack;

    int eMonsterIdAddr = 0;
    int frameDelay;

    int xBoundL_vis, xBoundR_vis;

    Monster* activeMonsters[10];
    void addMonster(MonsterName name, ActiveMonsterSlot slot);
    void deleteMonster(int slot);
    void evolveMonster(int slot);
    void sendMonsterToPos(int slot, int x);
    void visitorEvent();
    void poopEvent();
    void idleEvent();
    void updateMonsters();

  public:
    Controller();
    MonsterDB mdb;
    void drawFrame(Frame f);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
