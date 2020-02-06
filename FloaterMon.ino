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
