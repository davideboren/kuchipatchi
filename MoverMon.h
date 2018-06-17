/*
 * MoverMon.h
 *
 * AI for monster that moves left to right
 */

#include "MonsterDB.h"

class MoverMon : public Monster{
  //int xDir;      //-1 == facing left, 1 == facing right
  //int xBoundL, xBoundR;

  public:
    MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2,unsigned int age, unsigned int lifespan, MonsterName next);
    MoverMon();
    ~MoverMon();
    void queueWalk();
    void queueStand();
    void idleRoutine();
    void gotoRoutine();
    void heartbeat();
    bool inBounds();
};
