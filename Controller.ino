/*
 * Controller
 *
 * Coordinates all on screen entities
 */
 #include <EEPROM.h>

Controller::Controller(){
  numActiveMons = 0;
  MonsterDB mdb;
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
    case Mover:
      return new MoverMon(mdb.getSprite1(name),mdb.getSprite2(name),0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
      break;
  }
}

void Controller::addMonster(MonsterName name){
  activeMonsters[numActiveMons] = newMonster(name);
  Serial.print("Adding new monster @ "); Serial.println(numActiveMons);
  numActiveMons++;
}

void Controller::deleteMonster(int pos){
  if(activeMonsters[pos] != NULL){
    Serial.print("Got delete for monster "); Serial.println(pos);
    delete activeMonsters[pos];
    activeMonsters[pos] = NULL;

    //Cascade array
    Serial.print("pos = "); Serial.print(pos); Serial.print(" numActiveMon-1 "); Serial.println(numActiveMons-1);
    for(int i = pos; i < numActiveMons-1; i++){
      activeMonsters[i] = activeMonsters[i+1];
    }
    if(pos != numActiveMons-1 ){
      delete activeMonsters[numActiveMons-1 ];
      activeMonsters[numActiveMons-1 ] = NULL;
    }
    numActiveMons--;
  } else {
    Serial.print("Tried to delete null pointer @ monster "); Serial.println(pos);
  }
}

void Controller::evolveMonster(int pos){
  MonsterName nextMon = activeMonsters[pos] -> getNextMonsterName();
  delete activeMonsters[pos];
  Serial.print("Adding new monster @ "); Serial.println(pos);
  activeMonsters[pos] = newMonster(nextMon);

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

void Controller::activate(){

  //saveMonsterID(idKurotsubutchi);
  //int monID = getSavedMonsterID();

  //amdb.addMonster(monID);

  addMonster(Kuchipatchi);
  addMonster(Kurotsubutchi);


  while(1){
    display.clearDisplay();
    for(int i = 0; i < numActiveMons; i++){
      Serial.print("Entering loop for monster "); Serial.println(i);

      activeMonsters[i] -> heartbeat();

      if(activeMonsters[i] -> agedOut()){
        Serial.print("Monster aged out @ "); Serial.println(i);
        evolveMonster(i);
        i--;
      } else {
        drawFrame(activeMonsters[i] -> getFrame());
      }
    }
    display.display();
    delay(500);
  }
}
