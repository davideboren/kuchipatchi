/*
 * Monster
 * 
 * AI for individual monster
 */

Monster::Monster(){
  xPos = 56;
  yPos = 32;
}

Monster::Monster(const uint8_t *bitmap1, const uint8_t *bitmap2){
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bmp1;
  
  xPos = 56; // Centered
  yPos = 32;
};

Frame Monster::getFrame(){
  return Frame(currentBmp,xPos,yPos);
}

void Monster::heartbeat(){
}

