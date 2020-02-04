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

    MoveInstruction moveQueue[4];
    int moveQueuePos;

    MonsterTask currentTask;
    bool taskDone;

    void updateAge();
    void queueStand();

  public:
    Monster();
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
	unsigned int getMonsterAge();

    //Setters
    void setXPos(int x);
    void setYPos(int y);
    void setBoundsX(int xL, int xR);
    void setXDir(int dir);
	void setAge(unsigned int age);

    virtual void heartbeat();
    void doMove();
    void switchSprite(MoveInstruction move);

    void setTask(MonsterTask task);
    bool taskComplete();
    void goTo(int x);

    virtual MonsterName getNextMonsterName();
    bool agedOut();
    MonsterName nextMonster;
};

#endif
