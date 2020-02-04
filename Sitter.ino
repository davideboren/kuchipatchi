Sitter::Sitter(MonsterRef ref, unsigned int age){
  dna = ref;

  currentBmp = dna.bmp1;

  frameDir = -1;

  moveQueuePos = 0;

  monsterAge = age;

  currentTask = IDLE;

  queueStand();
}

Frame Sitter::getFrame(){
  return Frame(currentBmp,coords.xPos,coords.yPos,frameDir);
}

void Sitter::queueWalk(){
  moveQueue[0].setMove(4,0,0,0,1);
  moveQueue[1].setMove(4,0,0,0,2);
  moveQueue[2].setMove(4,0,0,0,1);
  moveQueue[3].setMove(4,0,0,0,2);

  moveQueuePos = 0;
}

void Sitter::idleRoutine(){
  if(moveQueuePos > 3){
    queueStand();
    moveQueuePos = 0;
  }
}

void Sitter::gotoRoutine(){
  int xOffset = coords.xDest - coords.xPos;

  if(xOffset == 0){
    taskDone = true;
    currentTask = STAND;
    queueStand();
  } else if(moveQueuePos > 3) {
      xOffset < 0 ? coords.xDir = -1 : coords.xDir = 1;
      queueWalk();
    }
}

void Sitter::heartbeat(){
  updateAge();

  if(dna.bmp1 == dna.bmp2){
   frameDir *= -1;
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

  doMove();
}
