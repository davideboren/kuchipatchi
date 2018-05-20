/*
 * Frame.h
 * 
 * Object to hold individual sprite and position
 */

struct Frame{
  const uint8_t *bitmap;
  int xPos,yPos;

  Frame(const uint8_t *bmp, int x, int y);
};
