/*
 * Frame
 * 
 * Object to hold individual sprite and position
 */

Frame::Frame(){
  bitmap = blank;
  xPos = 0;
  yPos = 0;
  xDir = 0;
}

Frame::Frame(const uint8_t *bmp, int x, int y, int dir){
  bitmap = bmp;
  xPos = x;
  yPos = y;
  xDir = dir;
}

void Frame::setFrame(const uint8_t *bmp, int x, int y, int dir){
  bitmap = bmp;
  xPos = x;
  yPos = y;
  xDir = dir;
}

