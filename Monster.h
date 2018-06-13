/*
 * Monster.h
 *
 * Base class for all monsters
 */
#ifndef MONSTER_H
#define MONSTER_H

class Monster{
  protected:
    const uint8_t *bmp1, *bmp2, *currentBmp;
    int xPos, yPos;
    unsigned int monsterAge;
    unsigned int monsterLifespan;

    int xDir; //-1 == facing left, 1 == facing right
    void updateAge();

    MoveQueueAction moveQueue[4];
    int moveQueuePos;

  public:

    //Constructors
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);

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

    virtual MonsterName getNextMonsterName();
    bool agedOut();
    MonsterName nextMonster;
};

#endif
