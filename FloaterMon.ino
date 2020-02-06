/*
 * MoverMon
 *
 * AI for monster that floats around the screen
 */
FloaterMon::FloaterMon(){
}

FloaterMon::FloaterMon(MonsterRef ref, unsigned int age){
  dna = ref;

  currentBmp = dna.bmp1;

  currentTask = IDLE;

  moveQueuePos = 0;

  monsterAge = age;

  queueStand();
}

FloaterMon::~FloaterMon(){
}

void FloaterMon::queueWalk(){
	int specialFrame;
	
	if(random(3) == 1){
		specialFrame = 3;
	} else {
		specialFrame = 1;
	}
	
	int yDist = generateFloatDist();
	
	//Only rise on frame 2, only drop on frame 1
	//This makes for a smoother animation based on how the sprites are structured
	if(yDist < 0){
		moveQueue[0].setMove(4,0,0,0,specialFrame);
		moveQueue[1].setMove(4,0,0,0,specialFrame);
		moveQueue[2].setMove(4,yDist,0,0,2);
		moveQueue[3].setMove(4,yDist,0,0,2);
	} else if(yDist >= 0){
		moveQueue[0].setMove(4,yDist,0,0,specialFrame);
		moveQueue[1].setMove(4,yDist,0,0,specialFrame);
		moveQueue[2].setMove(4,0,0,0,2);
		moveQueue[3].setMove(4,0,0,0,2);
	}

	moveQueuePos = 0;
}

int FloaterMon::generateFloatDist(){
	int floatDist = 0;
	
	bool floatUp;
	if(random(5) > 2){
		floatUp = true;
	} else {
		floatUp = false;
	}
	
	if(floatUp){
		if(getYPos() > 0){
			return -2;
		}
	} else {
		if(getYPos() < 32){
			return 2;
		}
	}
	return 0;
}

void FloaterMon::queueStand(){
	int specialFrame;
	
	if(random(3) == 1){
		specialFrame = 3;
	} else {
		specialFrame = 1;
	}
	
	int yDist = generateFloatDist();
	
	if(yDist < 0){
		moveQueue[0].setMove(0,0,0,0,specialFrame);
		moveQueue[1].setMove(0,yDist,0,0,2);
		moveQueue[2].setMove(0,0,0,0,specialFrame);
		moveQueue[3].setMove(0,yDist,0,0,2);
	} else if(yDist >= 0){
		moveQueue[0].setMove(0,yDist,0,0,specialFrame);
		moveQueue[1].setMove(0,0,0,0,2);
		moveQueue[2].setMove(0,yDist,0,0,specialFrame);
		moveQueue[3].setMove(0,0,0,0,2);
	}

	moveQueuePos = 0;
}

void FloaterMon::idleRoutine(){
  if(moveQueuePos > 3){
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

void FloaterMon::gotoRoutine(){
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

void FloaterMon::standRoutine(){
  if(moveQueuePos > 3){
    queueStand();
  }
}

void FloaterMon::heartbeat(){
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

bool FloaterMon::inBounds(){
  if((coords.xPos > coords.xBoundL) && (coords.xPos < coords.xBoundR)){
    return true;
  } else {
    return false;
  }
}
