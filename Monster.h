/*
 * Monster.h
 *
 * Base class for all monsters
 */
#ifndef MONSTER_H
#define MONSTER_H

#include "Defs.h"
#include "MoveInstruction.h"
#include "MonsterCoordinates.h"
#include "MonsterRef.h"

class Monster{
  protected:
    MonsterCoordinates coords;

    MonsterRef dna;
    
    const uint8_t *currentBmp;
    
    int frameDir;

    bool eventsAllowed;

    unsigned int monsterAge;

    void updateAge();

    MoveInstruction moveQueue[4];
    int moveQueuePos;


    MonsterTask currentTask;
    bool taskDone;

  public:

    //Constructors
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);
    virtual ~Monster();

    bool isEventCapable();

    //Getters
    MonsterName getName();
    virtual Frame getFrame();
    int getXPos();
    int getYPos();
    int getXBoundL();
    int getXBoundR();
    int getPoopPos();
    MonsterStage getMonsterStage();

    //Setters
    void setXPos(int x);
    void setYPos(int y);
    void setBoundsX(int xL, int xR);
    void setSprite1(const uint8_t *bitmap1);
    void setSprite2(const uint8_t *bitmap2);
    void setXDir(int dir);

    void doMove(MoveInstruction move);
    void switchSprite(MoveInstruction move);
    virtual void heartbeat();

    void setTask(MonsterTask task);
    bool taskComplete();
    void goTo(int x);

    virtual MonsterName getNextMonsterName();
    bool agedOut();
    MonsterName nextMonster;
};

#endif
