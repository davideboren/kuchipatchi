/*
 * MoverMon.h
 * 
 * AI for monster that moves left to right
 */
 
class MoverMon : Monster{
  int xDir;
  int xBoundL, xBoundR;

  MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2, int xBndL, int xBndR);
};

