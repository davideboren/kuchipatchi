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
    unsigned int age;
    unsigned int lifespan;
    void updateAge();
  
  public:
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);
    virtual Frame getFrame();
    void setSprites(const uint8_t *bitmap1, const uint8_t *bitmap2);
    virtual void heartbeat();
    bool agedOut();
};

#endif
