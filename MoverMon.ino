/*
 * MoverMon
 * 
 * AI for monster that moves left to right
 */

MoverMon::MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2, int xBndL, int xBndR){
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  xBoundL = xBndL;
  xBoundR = xBndR;
}

