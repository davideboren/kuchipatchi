/*
 * MoverMon
 *
 * AI for monster that moves left to right
 */
MoverMon::MoverMon(){
  xBoundL = 0;
  xBoundR = 112;
  xDir = -1;
  monsterAge = 0;
  monsterLifespan = 500;
  xPos = 56;
  yPos = 32;
}

MoverMon::MoverMon(MonsterName name, const uint8_t *bitmap1, const uint8_t *bitmap2, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next){
  myName = name;
  
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bitmap1;

  currentTask = IDLE;

  xBoundL = 0;
  xBoundR = 112;

  xDir = -1;  //-1 == facing left, 1 == facing right

  moveQueuePos = 0;

  monStage = stage;
  monsterAge = age;
  monsterLifespan = lifespan;

  nextMonster = next;
}

MoverMon::~MoverMon(){
  Serial.println("Tearing down a monster");
}

void MoverMon::queueWalk(){
  moveQueue[0] = MOVE_X_SPRITE_1;
  moveQueue[1] = MOVE_X_SPRITE_1;
  moveQueue[2] = MOVE_X_SPRITE_2;
  moveQueue[3] = MOVE_X_SPRITE_2;

  moveQueuePos = 0;
  Serial.println("Queued Walk");
}

void MoverMon::queueStand(){
  moveQueue[0] = WAIT_SPRITE_1;
  moveQueue[1] = WAIT_SPRITE_2;
  moveQueue[2] = WAIT_SPRITE_1;
  moveQueue[3] = WAIT_SPRITE_2;

  moveQueuePos = 0;
  Serial.println("Queued Stand");
}

void MoverMon::idleRoutine(){
  //Choose next move
  if(moveQueuePos > 3){
    Serial.println("Entered moveQueue");
    random(8)?queueWalk():queueStand();
  }

  if(xPos <= xBoundL){
    xDir = 1;
  } else if(xPos >= xBoundR){
    xDir = -1;
  } else if(!random(12) && inBounds()){
    xDir = -1;
  }
}

void MoverMon::gotoRoutine(){
  int xOffset = xDest - xPos;

  if(xOffset == 0){
    taskDone = true;
    currentTask = STAND;
    queueStand();
    if(currentBmp == bmp1){
      moveQueuePos++; //to avoid hanging on the same sprite twice
    }
  } else if(moveQueuePos > 3) {
      xOffset < 0 ? xDir = -1 : xDir = 1;
      queueWalk();
    }
}

void MoverMon::standRoutine(){
  if(moveQueuePos > 3){
    queueStand();
  }
}

void MoverMon::heartbeat(){
  Serial.println("Heartbeat received");

  updateAge();

  switch(currentTask){
    case IDLE:
      idleRoutine();
      break;
    case GOTO:
      gotoRoutine();
      break;
    case STAND:
      standRoutine();
      break;
  }

  switch(moveQueue[moveQueuePos]){
    case MOVE_X_SPRITE_1: //Move with sprite 1
      currentBmp = bmp1;
      xPos += xDir*4;
      break;
    case MOVE_X_SPRITE_2: //Move with sprite 2
      currentBmp = bmp2;
      xPos += xDir*4;
      break;
    case WAIT_SPRITE_1: //Sit with sprite 1
      currentBmp = bmp1;
      break;
    case WAIT_SPRITE_2: //Sit with sprite 2
      currentBmp = bmp2;
      break;
  }
  moveQueuePos++;
}

bool MoverMon::inBounds(){
  if((xPos > xBoundL) && (xPos < xBoundR)){
    return true;
  } else {
    return false;
  }
}
