/*
 * MoverMon.h
 * 
 * AI for monster that moves left to right
 */

#include <queue>
 
class MoverMon : public Monster{
  int xDir;      //-1 == facing left, 1 == facing right
  int xBoundL, xBoundR;
  
  std::queue<int> moveQueue;

  public:
    MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2);
    MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2, int xBndL, int xBndR);
    void walk();
    void stand();
    void heartbeat();
    Frame getFrame();
};

