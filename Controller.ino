/*
 * Controller
 * 
 * Coordinates all on screen entities
 */

void Controller::drawFrame(Frame f){
  display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
}

