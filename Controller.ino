/*
 * Controller
 * 
 * Coordinates all on screen entities
 */
 #include <EEPROM.h>

Controller::Controller(){
}

void Controller::drawFrame(Frame f){
  Serial.print("Drawing bitmap at: ");
  Serial.println((long)f.bitmap);

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
  MoverMon m1;

  const uint8_t *k1 = kuchipatchi1;
  //saveMonsterID(idKuchipatchi);
  
  
  int monID = getSavedMonsterID();
  int monType = mdb.getMonsterType(monID);
  Serial.print("Got monster type: "); Serial.println(monType);
  MoverMon kuchi(mdb.getSprite1(idKuchipatchi),mdb.getSprite2(idKuchipatchi));
  addMonster(kuchi);

  /*if(monType == 1){
    m1.setSprites(mdb.getSprite1(monID),mdb.getSprite2(monID));
    addMonster(m1);
  }*/

  
  
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

