/*
 * MoverMon
 *
 * AI for monster that moves left to right
 */
MoverMon::MoverMon(){
}

MoverMon::MoverMon(MonsterRef ref, unsigned int age){
  dna = ref;

  currentBmp = dna.bmp1;

  currentTask = IDLE;

  moveQueuePos = 0;

  monsterAge = age;

  queueStand();
}

MoverMon::~MoverMon(){
}

void MoverMon::queueWalk(){
	int specialFrame;
	
	if(random(3) == 1){
		specialFrame = 3;
	} else {
		specialFrame = 1;
	}

	moveQueue[0].setMove(4,0,0,0,specialFrame);
	moveQueue[1].setMove(4,0,0,0,specialFrame);
	moveQueue[2].setMove(4,0,0,0,2);
	moveQueue[3].setMove(4,0,0,0,2);

	moveQueuePos = 0;
}

void MoverMon::idleRoutine(){
  //Choose next move
  if(moveQueuePos > 3){
    //Serial.println("Entered moveQueue");
    random(8)?queueWalk():queueStand();
  }

  if(coords.xPos <= coords.xBoundL){
    coords.xDir = 1;
  } else if(coords.xPos >= coords.xBoundR){
    coords.xDir = -1;
  } else if(!random(12) && inBounds()){
    coords.xDir *= -1;
  }
}

void MoverMon::gotoRoutine(){
  int xOffset = coords.xDest - coords.xPos;

  if(xOffset == 0){
    taskDone = true;
    currentTask = STAND;
    queueStand();
    if(currentBmp == dna.bmp1){
      moveQueuePos++; //to avoid hanging on the same sprite twice
    }
  } else if(moveQueuePos > 3) {
      xOffset < 0 ? coords.xDir = -1 : coords.xDir = 1;
      queueWalk();
    }
}

void MoverMon::standRoutine(){
  if(moveQueuePos > 3){
    queueStand();
  }
}

void MoverMon::heartbeat(){
  //Serial.println("Heartbeat received");

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

  doMove();
}

bool MoverMon::inBounds(){
  if((coords.xPos > coords.xBoundL) && (coords.xPos < coords.xBoundR)){
    return true;
  } else {
    return false;
  }
}
