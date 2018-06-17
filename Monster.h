/*
 * Monster.h
 *
 * Base class for all monsters
 */
#ifndef MONSTER_H
#define MONSTER_H

#include "Defs.h"

class Monster{
  protected:
    const uint8_t *bmp1, *bmp2, *currentBmp;
    int xPos, yPos;
    int xDest;
    unsigned int monsterAge;
    unsigned int monsterLifespan;

    int xDir; //-1 == facing left, 1 == facing right
    void updateAge();

    MoveQueueAction moveQueue[4];
    int moveQueuePos;

    MonsterTask currentTask;
    bool taskDone;

  public:

    //Constructors
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);

    int xBoundL, xBoundR;

    //Getters
    Frame getFrame();
    int getXPos();
    int getYPos();

    //Setters
    void setXPos(int x);
    void setYPos(int y);
    void setSprite1(const uint8_t *bitmap1);
    void setSprite2(const uint8_t *bitmap2);

    virtual void heartbeat();

    void setTask(MonsterTask task);
    bool taskComplete();
    void goTo(int x);

    virtual MonsterName getNextMonsterName();
    bool agedOut();
    MonsterName nextMonster;
};

#endif
