/*
 * Controller
 * 
 * Coordinates all on screen entities
 */

void Controller::drawFrame(Frame f){
  if(f.xDir == -1){
    display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  } else if(f.xDir == 1){
    display.drawReverseBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  }
}

void Controller::addMonster(Monster &m){
  m1 = &m;
}

void Controller::activate(){
  while(1){
    m1->heartbeat();
    display.clearDisplay();
    drawFrame(m1->getFrame());
    display.display();
    delay(500);
  }
}

