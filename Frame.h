/*
 * Frame.h
 * 
 * Object to hold individual sprite and position
 */

struct Frame{
  const uint8_t *bitmap;
  int xPos,yPos;
  int xDir;
  
  Frame();
  Frame(const uint8_t *bmp, int x, int y, int dir);

  void setFrame(const uint8_t *bmp, int x, int y, int dir);
};
