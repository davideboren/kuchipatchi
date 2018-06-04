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
    void updateAge();
  
  public:
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);
    virtual Frame getFrame();
    void setSprite1(const uint8_t *bitmap1);
    void setSprite2(const uint8_t *bitmap2);
    virtual void heartbeat();
    virtual int getNextMonsterID();
    bool agedOut();
    int nextMonster;
};

#endif
