/*
 * Controller
 * 
 * Coordinates all on screen entities
 */
 #include <EEPROM.h>

Controller::Controller(){
}

void Controller::drawFrame(Frame f){
  //Serial.print("Drawing bitmap at: ");Serial.println((long)f.bitmap);

  if(f.xDir == -1){
    display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  } else if(f.xDir == 1){
    display.drawReverseBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  }
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
  MonsterDB mdb;
  ActiveMonsterDB amdb(mdb);

  //saveMonsterID(idKurotsubutchi);  
  int monID = getSavedMonsterID();

  amdb.addMonster(monID);
  amdb.addMonster(monID);
  
  while(1){
    Serial.println("Looping");
    display.clearDisplay();
    for(int i = 0; i < amdb.numActiveMonsters(); i++){
      amdb.getMonster(i) -> heartbeat();
      if(amdb.getMonster(i) -> agedOut()){
        int nextMon = amdb.getMonster(i) -> getNextMonsterID();
        amdb.deleteMonster(i);
        amdb.addMonster(nextMon);
        i--;   //Adjust loop position to account for removed entry
      } else {
        drawFrame(amdb.getMonster(i) -> getFrame());
      }
    }
    display.display();
    delay(100);
  }
}

