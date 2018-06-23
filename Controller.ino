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
  if(f.xDir == -1){
    display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  } else if(f.xDir == 1){
    display.drawReverseBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  }
}

void Controller::addMonster(MonsterName name, ActiveMonsterSlot slot){
  activeMonsters[slot] = mdb.newMonster(name);
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

  activeMonsters[slot] = mdb.newMonster(nextMon);

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
  activeMonsters[PRIMARY] -> setXDir(1);
  activeMonsters[PRIMARY] -> setBoundsX(0 - offFrameSlack ,32);

  addMonster(mdb.getRandomMonster(activeMonsters[PRIMARY] -> getMonsterStage()), VISITOR);
  activeMonsters[VISITOR] -> setXPos(116);
  sendMonsterToPos(VISITOR,80);
  activeMonsters[VISITOR] -> setBoundsX(xBoundL_vis,xBoundR_vis + offFrameSlack);
  activeMonsters[PRIMARY] -> setTask(IDLE);
  activeMonsters[VISITOR] -> setTask(IDLE);

  for(int i = 0; i < 10; i++){
    updateMonsters();
  }

  sendMonsterToPos(VISITOR,128);
  deleteMonster(VISITOR);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);
  sendMonsterToPos(PRIMARY,48);
  activeMonsters[PRIMARY] -> setTask(IDLE);

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
  for(int d = 0; d < 30; d++){
    updateMonsters();
  }
}

void Controller::activate(){

  //saveMonsterID(idKurotsubutchi);
  //int monID = getSavedMonsterID();

  //amdb.addMonster(monID);
  /*addMonster(DigiEgg1, PRIMARY);
  while(1){
    updateMonsters();
  }*/

  addMonster(DigiEgg1, PRIMARY);
  while(1){
    
    int currentEvent;
    if(activeMonsters[PRIMARY] -> isEventCapable()){
      currentEvent = random(LAST_EVENT);
    } else {
      currentEvent = IDLE_EVENT;
    }
    
    switch(currentEvent){
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
