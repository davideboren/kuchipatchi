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

  public:
    Controller();
    void drawFrame(Frame f);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
