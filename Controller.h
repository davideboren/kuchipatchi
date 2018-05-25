/*
 * Controller.h
 * 
 * Coordinates all on screen entities
 */
 
#include "Monster.h"
 
class Controller{
  private:
    int monArrayPos = 0;
    
  public:
    Monster *mon[5];
    void drawFrame(Frame f);
    void addMonster(Monster &m);
    void activate();
};
