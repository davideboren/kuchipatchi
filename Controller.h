/*
 * Controller.h
 * 
 * Coordinates all on screen entities
 */
 
#include "Monster.h"
 
class Controller{
  private:
  public:
    Monster *m1;
    void drawFrame(Frame f);
    void addMonster(Monster &m);
    void activate();
};
