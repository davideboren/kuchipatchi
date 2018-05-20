/*
 * Frame
 * 
 * Object to hold individual sprite and position
 */

Frame::Frame(const uint8_t *bmp, int x, int y){
  bitmap = bmp;
  xPos = x;
  yPos = y;
}

