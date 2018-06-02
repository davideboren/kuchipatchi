/*
 * MoverMon.h
 * 
 * AI for monster that moves left to right
 */

#include <queue>
#include "MonsterDB.h"
 
class MoverMon : public Monster{
  int xDir;      //-1 == facing left, 1 == facing right
  int xBoundL, xBoundR;
  
  std::queue<int> moveQueue;

  public:
    MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2);
    MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2, int xBndL, int xBndR);
    MoverMon();
    void queueWalk();
    void queueStand();
    void heartbeat();
    Frame getFrame();
    bool inBounds();
};

