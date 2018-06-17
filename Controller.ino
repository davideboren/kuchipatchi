/*
 * Controller
 *
 * Coordinates all on screen entities
 */
 #include <EEPROM.h>

Controller::Controller(){

  MonsterDB mdb;

  frameDelay = 500;

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
      return new Sitter(mdb.getSprite1(name),0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
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

  delete activeMonsters[slot];

  activeMonsters[slot] = newMonster(nextMon);

  activeMonsters[slot] -> setXPos(currentX);
  activeMonsters[slot] -> setYPos(currentY);
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
      //Serial.print("Entering loop for monster "); Serial.println(monSlot);

      activeMonsters[monSlot] -> heartbeat();

      if(activeMonsters[monSlot] -> agedOut()){
        Serial.print("Monster aged out @ "); Serial.println(monSlot);
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
  Serial.println("Task Complete");
}

void Controller::activate(){

  //saveMonsterID(idKurotsubutchi);
  //int monID = getSavedMonsterID();

  //amdb.addMonster(monID);

  addMonster(Kuchipatchi, PRIMARY);
  //addMonster(Kuchipatchi, VISITOR);
  //addMonster(Kuchipatchi, POOP);

  //for(int i = 0; i < 3; i++) {sendMonsterToPos(PRIMARY,random(0,28)*4);}
  while(1){
    //updateMonsters();
    sendMonsterToPos(PRIMARY,random(0,28)*4);
  }
}
