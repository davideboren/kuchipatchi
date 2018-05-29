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
  mon[monArrayPos] = &m;
  monArrayPos++;
}

void Controller::activate(){
  MonsterDB mdb;
  //MoverMon Kurotsubutchi(mdb.getSprite1(idKurotsubutchi),mdb.getSprite2(idKurotsubutchi));
  MoverMon Kurotsubutchi(mdb,idKuchipatchi);
  addMonster(Kurotsubutchi);
  
  while(1){
    display.clearDisplay();
    for(int i = 0; i < monArrayPos; i++){
      
      mon[i] -> heartbeat();
      drawFrame(mon[i] -> getFrame());
    }
    display.display();
    delay(500);
  }
}

