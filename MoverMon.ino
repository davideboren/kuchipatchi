/*
 * MoverMon
 * 
 * AI for monster that moves left to right
 */

MoverMon::MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2){
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bitmap1;
  
  xBoundL = 0;
  xBoundR = 112;

  xDir = -1;

  age = 0;
  lifespan = 50;
}

MoverMon::MoverMon(const uint8_t *bitmap1, const uint8_t *bitmap2, int xBndL, int xBndR){
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bitmap1;
  
  xBoundL = xBndL;
  xBoundR = xBndR;

  xDir = -1;
}

MoverMon::MoverMon(MonsterDB &mdb, int monsterID){
  bmp1 = mdb.getSprite1(monsterID);
  bmp2 = mdb.getSprite2(monsterID);
}


void MoverMon::queueWalk(){
  moveQueue.push(1);
  moveQueue.push(1);
  moveQueue.push(2);
  moveQueue.push(2);
}

void MoverMon::queueStand(){
  moveQueue.push(3);
  moveQueue.push(4);
  moveQueue.push(3);
  moveQueue.push(4);
}

void MoverMon::heartbeat(){
  //Increment Age
  updateAge();
  
  //Choose next move
  if(moveQueue.empty()){
    random(8)?queueWalk():queueStand();
  }

  //Random Chance to turn around
  if(!random(12) && inBounds()){ 
    xDir *= -1; 
  }
  
  //Turn around if up against a boundary
  if(!inBounds()){
    xDir *= -1;
  }
  
  switch(moveQueue.front()){
    case 1: //Move with sprite 1
      currentBmp = bmp1;
      xPos += xDir*4;
      break;
    case 2: //Move with sprite 2
      currentBmp = bmp2;
      xPos += xDir*4;
      break;
    case 3: //Sit with sprite 1
      currentBmp = bmp1;
      break;
    case 4: //Sit with sprite 2
      currentBmp = bmp2;
      break;
  }
  moveQueue.pop();
}

Frame MoverMon::getFrame(){
  return Frame(currentBmp,xPos,yPos,xDir);
}

bool MoverMon::inBounds(){
  if((xPos > xBoundL) && (xPos < xBoundR)){
    return true;
  } else {
    return false;
  }
}

