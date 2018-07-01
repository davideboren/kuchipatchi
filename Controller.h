/*
 * Controller.h
 *
 * Coordinates all on screen entities
 */

#include "Monster.h"
#include "ScreenFX.h"
#include "MonsterDB.h"

class Controller{
  private:
    int offFrameSlack;

    int eMonsterIdAddr = 0;
    int frameDelay;

    int xBoundL_vis, xBoundR_vis;

    Monster* activeMonsters[10];
    ScreenFX* activeFX[3];

    void addMonster(MonsterName name, ActiveMonsterSlot slot);
    void deleteMonster(int slot);
    void evolveMonster(int slot);
    void evoEvent(int slot);
    void sendMonsterToPos(int slot, int x);
    void visitorEvent();
    void poopEvent();
    void flushPoop(int poopXPos);
    void idleEvent();

    void updateMonsters();
    void drawMonsterFrames();

    void updateFX();
    void drawFXFrames();
    void deleteFX(int slot);

    void updateAll();

  public:
    Controller();
    MonsterDB mdb;
    void drawFrame(Frame f);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
