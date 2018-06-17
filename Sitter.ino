Sitter::Sitter(const uint8_t *bitmap1, unsigned int age, unsigned int lifespan, MonsterName next){

  xPos = 48;
  yPos = 32;

  bmp1 = bitmap1;
  bmp2 = bitmap1;
  currentBmp = bitmap1;

  xDir = -1;

  moveQueuePos = 0;

  monsterAge = age;
  monsterLifespan = lifespan;

  nextMonster = next;

  queueStand();
}

void Sitter::queueStand(){
  moveQueue[0] = WAIT_SPRITE_1;
  moveQueue[1] = WAIT_SPRITE_1;
  moveQueue[2] = WAIT_SPRITE_1;
  moveQueue[3] = WAIT_SPRITE_1;
}

void Sitter::heartbeat(){
  Serial.println("Sitter received heartbeat");
  Serial.print("Sitter xPos: "); Serial.println(xPos);
  //Increment Age
  updateAge();

  //Flip Direction
  xDir *= -1;

  if(moveQueuePos > 3){
    queueStand();
    moveQueuePos = 0;
  }

  //switch(moveQueue.front()){
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
      //Serial.println("Got WAIT_SPRITE_1");
      break;
  }
  moveQueuePos++;
}
