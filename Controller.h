/*
 * Controller.h
 * 
 * Coordinates all on screen entities
 */
 
#include "Monster.h"
 
class Controller{
  private:
    int monArrayPos = 0;
    int eMonsterIdAddr = 0;
    
  public:
    Controller();
    Monster* mon[5];
    void drawFrame(Frame f);
    void addMonster(Monster &m);
    int getSavedMonsterID();
    void saveMonsterID(int id);
    void activate();
};
