Sitter::Sitter(const uint8_t *bitmap1, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next){

  xPos = 48;
  yPos = 32;

  bmp1 = bitmap1;
  bmp2 = bitmap1;
  currentBmp = bitmap1;

  xDir = -1;
  xDir_walking = -1;

  moveQueuePos = 0;

  monsterAge = age;
  monsterLifespan = lifespan;

  nextMonster = next;

  currentTask = IDLE;

  queueStand();
}

Sitter::Sitter(const uint8_t *bitmap1, const uint8_t *bitmap2, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next){

  xPos = 48;
  yPos = 32;

  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bitmap1;

  xDir = -1;
  xDir_walking = -1;

  moveQueuePos = 0;

  monStage = stage;
  monsterAge = age;
  monsterLifespan = lifespan;

  nextMonster = next;

  currentTask = IDLE;

  queueStand();
}

void Sitter::queueStand(){
  moveQueue[0] = WAIT_SPRITE_1;
  moveQueue[1] = WAIT_SPRITE_2;
  moveQueue[2] = WAIT_SPRITE_1;
  moveQueue[3] = WAIT_SPRITE_2;
}

void Sitter::queueWalk(){
  moveQueue[0] = MOVE_X_SPRITE_1;
  moveQueue[1] = MOVE_X_SPRITE_2;
  moveQueue[2] = MOVE_X_SPRITE_1;
  moveQueue[3] = MOVE_X_SPRITE_2;
}

void Sitter::idleRoutine(){

  if(moveQueuePos > 3){
    queueStand();
    moveQueuePos = 0;
  }
}

void Sitter::gotoRoutine(){
  int xOffset = xDest - xPos;

  if(xOffset == 0){
    taskDone = true;
    queueStand();
  } else if(moveQueuePos > 3) {
      xOffset < 0 ? xDir_walking = -1 : xDir_walking = 1;
      queueWalk();
    }
}

void Sitter::heartbeat(){
  updateAge();

  if(bmp1 == bmp2){
    xDir *= -1;
  }

  switch(currentTask){
    case IDLE:
      idleRoutine();
      break;
    case GOTO:
      gotoRoutine();
      break;
    case STAND:
      idleRoutine();
      break;
  }

  switch(moveQueue[moveQueuePos]){
    case MOVE_X_SPRITE_1:
      currentBmp = bmp1;
      xPos += xDir_walking*4;
      break;
    case MOVE_X_SPRITE_2:
      currentBmp = bmp2;
      xPos += xDir_walking*4;
      break;
    case WAIT_SPRITE_1: //Sit with sprite 1
      currentBmp = bmp1;
      break;
    case WAIT_SPRITE_2:
      currentBmp = bmp2;
      break;
  }
  moveQueuePos++;
}
