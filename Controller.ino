/*
 * Controller
 *
 * Coordinates all on screen entities
 */
 #include <EEPROM.h>

Controller::Controller(){

  MonsterDB mdb;

  frameDelay = 500;
  offFrameSlack = 16;

  xBoundL_vis = 64;
  xBoundR_vis = 96 + offFrameSlack;

  for(int slot = PRIMARY; slot != LAST_MON_SLOT; slot++){
    activeMonsters[slot] = NULL;
  }

}

void Controller::drawFrame(Frame f){
  //Serial.print("Drawing bitmap at: ");Serial.println((long)f.bitmap);
  if(f.xDir == -1){
    display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  } else if(f.xDir == 1){
    display.drawReverseBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  }
}

Monster* Controller::newMonster(MonsterName name){
  switch(mdb.getMonsterType(name)){
    case MOVER:
      return new MoverMon(mdb.getSprite1(name),mdb.getSprite2(name),0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
      break;
    case SITTER:
      if(mdb.getSprite1(name) == mdb.getSprite2(name)){
        return new Sitter(mdb.getSprite1(name),0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
      } else {
        return new Sitter(mdb.getSprite1(name), mdb.getSprite2(name), 0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
      }
      break;
  }
}

void Controller::addMonster(MonsterName name, ActiveMonsterSlot slot){
  activeMonsters[slot] = newMonster(name);
}

void Controller::deleteMonster(int slot){
  delete activeMonsters[slot];
  activeMonsters[slot] = NULL;
}

void Controller::evolveMonster(int slot){
  MonsterName nextMon = activeMonsters[slot] -> getNextMonsterName();

  int currentX = activeMonsters[slot] -> getXPos();
  int currentY = activeMonsters[slot] -> getYPos();
  int currentXBoundL = activeMonsters[slot] -> getXBoundL();
  int currentXBoundR = activeMonsters[slot] -> getXBoundR();

  delete activeMonsters[slot];

  activeMonsters[slot] = newMonster(nextMon);

  activeMonsters[slot] -> setXPos(currentX);
  activeMonsters[slot] -> setYPos(currentY);
  activeMonsters[slot] -> setBoundsX(currentXBoundL, currentXBoundR);
}

int Controller::getSavedMonsterID(){
  int id = 1;
  EEPROM.get(eMonsterIdAddr,id);
  Serial.print("EEPROM returned monster ID: "); Serial.println(id);
  return id;
}

void Controller::saveMonsterID(int id){
  EEPROM.put(eMonsterIdAddr,id);
}

void Controller::updateMonsters(){
  display.clearDisplay();
  for(int monSlot = PRIMARY; monSlot != LAST_MON_SLOT; monSlot++){
    if(activeMonsters[monSlot] != NULL){

      activeMonsters[monSlot] -> heartbeat();

      if(activeMonsters[monSlot] -> agedOut() && monSlot != POOP){
        evolveMonster(monSlot);
        monSlot--;
      } else {
        drawFrame(activeMonsters[monSlot] -> getFrame());
      }
    }
  }
  display.display();
  delay(frameDelay);
}

void Controller::sendMonsterToPos(int slot, int x){
  activeMonsters[slot] -> goTo(x);
  while(!activeMonsters[slot] -> taskComplete()){
    updateMonsters();
  }
}

void Controller::visitorEvent(){
  sendMonsterToPos(PRIMARY,24);
  activeMonsters[PRIMARY] -> setBoundsX(0 - offFrameSlack ,32);

  addMonster(Kurotsubutchi, VISITOR);
  activeMonsters[VISITOR] -> setXPos(116);
  sendMonsterToPos(VISITOR,80);
  activeMonsters[VISITOR] -> setBoundsX(xBoundL_vis,xBoundR_vis + offFrameSlack);

  for(int i = 0; i < 10; i++){
    updateMonsters();
  }

  sendMonsterToPos(VISITOR,128);
  deleteMonster(VISITOR);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);
  sendMonsterToPos(PRIMARY,48);
}

void Controller::poopEvent(){
  int dropZone = activeMonsters[PRIMARY] -> getPoopPos();
  int monX = activeMonsters[PRIMARY] -> getXPos();
  addMonster(Poop, POOP);
  activeMonsters[POOP] -> setXPos(dropZone);

  if(dropZone < monX){
    activeMonsters[PRIMARY] -> setBoundsX(monX,112);
  } else {
    activeMonsters[PRIMARY] -> setBoundsX(-16,monX);
  }

  while(!activeMonsters[POOP] -> agedOut()){
    updateMonsters();
  }
  deleteMonster(POOP);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);

}

void Controller::idleEvent(){
  for(int d = 0; d < 60; d++){
    updateMonsters();
  }
}

void Controller::activate(){

  //saveMonsterID(idKurotsubutchi);
  //int monID = getSavedMonsterID();

  //amdb.addMonster(monID);

  addMonster(Mimitchi, PRIMARY);

  while(1){
    int randEvent = random(LAST_EVENT);
    switch(randEvent){
      case IDLE_EVENT:
        idleEvent();
        break;
      case POOP_EVENT:
        poopEvent();
        break;
      case VISITOR_EVENT:
        visitorEvent();
        break;
    }
  }
}
