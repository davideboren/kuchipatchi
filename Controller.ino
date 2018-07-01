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

  for(int slot = EVOLVE_FX_SLOT; slot != LAST_FX_SLOT; slot++){
    activeFX[slot] = NULL;
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

  if(slot == PRIMARY){
    if(mdb.isUnderwater(name) && activeFX[BUBBLE_FX_SLOT] == NULL){
      activeFX[BUBBLE_FX_SLOT] = mdb.newFX(BUBBLE_FX);
    }
    else if(!mdb.isUnderwater(name) && activeFX[BUBBLE_FX_SLOT] != NULL){
      deleteFX(BUBBLE_FX_SLOT);
    }
  }
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

  //activeMonsters[slot] = mdb.newMonster(nextMon);
  addMonster(nextMon, static_cast<ActiveMonsterSlot>(slot));

  activeMonsters[slot] -> setXPos(currentX);
  activeMonsters[slot] -> setYPos(currentY);
  activeMonsters[slot] -> setBoundsX(currentXBoundL, currentXBoundR);
}

void Controller::evoEvent(int slot){
  sendMonsterToPos(slot, 48);
  activeFX[EVOLVE_FX_SLOT] = mdb.newFX(EVOLVE_FX);
  for(int i = 0; i < 10; i++){
    updateAll();
  }
  evolveMonster(slot);
  activeMonsters[slot] -> setTask(STAND);
  for(int i = 0; i < 10; i++){
    updateAll();
  }
  deleteFX(EVOLVE_FX_SLOT);
  activeMonsters[slot] -> setTask(IDLE);
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
  for(int monSlot = PRIMARY; monSlot != LAST_MON_SLOT; monSlot++){
    if(activeMonsters[monSlot] != NULL){
      activeMonsters[monSlot] -> heartbeat();

      if(activeMonsters[monSlot] -> agedOut() && !activeMonsters[monSlot] -> isEventCapable()){
        evolveMonster(monSlot);
        monSlot--;
      }
    }
  }
}

void Controller::drawMonsterFrames(){
  for(int monSlot = PRIMARY; monSlot != LAST_MON_SLOT; monSlot++){
    if(activeMonsters[monSlot] != NULL){
      drawFrame(activeMonsters[monSlot] -> getFrame());
    }
  }
}

void Controller::updateFX(){
  for(int fxSlot = EVOLVE_FX_SLOT; fxSlot != LAST_FX_SLOT; fxSlot++){
    if(activeFX[fxSlot] != NULL){
      activeFX[fxSlot] -> heartbeat();
    }
  }
}

void Controller::drawFXFrames(){
  for(int fxSlot = EVOLVE_FX_SLOT; fxSlot != LAST_FX_SLOT; fxSlot++){
    if(activeFX[fxSlot] != NULL){
      for(int i = 0; i < activeFX[fxSlot] -> getActiveFrameNum(); i++){
        drawFrame(activeFX[fxSlot] -> getFrame(i));
      }
    }
  }
}

void Controller::deleteFX(int slot){
  delete activeFX[slot];
  activeFX[slot] = NULL;
}

void Controller::updateAll(){
  display.clearDisplay();
  updateMonsters();
  updateFX();
  drawMonsterFrames();
  drawFXFrames();
  display.display();
  delay(250);

  display.clearDisplay();
  updateFX();
  drawMonsterFrames();
  drawFXFrames();
  display.display();
  delay(250);

}

void Controller::sendMonsterToPos(int slot, int x){
  activeMonsters[slot] -> goTo(x);
  while(!activeMonsters[slot] -> taskComplete()){
    updateAll();
  }
}

void Controller::visitorEvent(){
  sendMonsterToPos(PRIMARY,24);
  activeMonsters[PRIMARY] -> setXDir(1);
  activeMonsters[PRIMARY] -> setBoundsX(0 - offFrameSlack ,32);

  addMonster(mdb.getRandomMonster(activeMonsters[PRIMARY] -> getName()), VISITOR);
  activeMonsters[VISITOR] -> setXPos(116);
  sendMonsterToPos(VISITOR,80);
  activeMonsters[VISITOR] -> setBoundsX(xBoundL_vis,xBoundR_vis + offFrameSlack);
  activeMonsters[PRIMARY] -> setTask(IDLE);
  activeMonsters[VISITOR] -> setTask(IDLE);

  for(int i = 0; i < 10; i++){
    updateAll();
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
    updateAll();
  }
  flushPoop(dropZone);
  //deleteMonster(POOP);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);

}

void Controller::flushPoop(int poopXPos){
  activeFX[FLUSH_FX_SLOT] = mdb.newFX(FLUSH_FX);

  while(!activeFX[FLUSH_FX_SLOT] -> finished()){
    if(activeMonsters[POOP] != NULL && activeFX[FLUSH_FX_SLOT] -> getEffectPos() <= poopXPos){
      deleteMonster(POOP);
    }
    updateAll();
  }

  deleteFX(FLUSH_FX_SLOT);
}

void Controller::idleEvent(){
  for(int d = 0; d < 30; d++){
    updateAll();
  }
}

void Controller::activate(){

  addMonster(DigiEgg1, PRIMARY);
  while(1){

    int currentEvent;
    if(activeMonsters[PRIMARY] -> isEventCapable()){
      if(activeMonsters[PRIMARY] -> agedOut()){
        currentEvent = EVO_EVENT;
      } else {
        currentEvent = random(LAST_EVENT);
      }
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
      case EVO_EVENT:
        evoEvent(PRIMARY);
        break;
    }
  }
}
