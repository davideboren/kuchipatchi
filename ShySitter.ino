ShySitter::ShySitter(){
	
}

ShySitter::ShySitter(MonsterRef ref, unsigned int age){
  dna = ref;

  currentBmp = dna.bmp1;

  frameDir = -1;

  moveQueuePos = 0;

  monsterAge = age;

  currentTask = IDLE;

  queueStand();
}

void ShySitter::queueStand(){
	int specialFrame;
	
	if(random(4) == 1){
		specialFrame = 1;
	} else {
		specialFrame = 2;
	}
	
	moveQueue[0].setMove(0,0,0,0,2);
	moveQueue[1].setMove(0,0,0,0,2);
	moveQueue[2].setMove(0,0,0,0,specialFrame);
	moveQueue[3].setMove(0,0,0,0,specialFrame);

	moveQueuePos = 0;
}
