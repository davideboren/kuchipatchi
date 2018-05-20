/*
 * Monster.h
 * 
 * AI for individual monster
 */
#ifndef MONSTER_H
#define MONSTER_H

class Monster{
  protected:
    const uint8_t *bmp1, *bmp2, *currentBmp;
    int xPos, yPos;
  
  public:
    Frame getFrame();
    Monster();
    Monster(const uint8_t *bitmap1, const uint8_t *bitmap2);
    void heartbeat();
};

#endif
