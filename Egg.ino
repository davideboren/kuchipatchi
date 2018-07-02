Egg::Egg(MonsterRef ref, unsigned int age){

	dna = ref;

	currentBmp = dna.bmp1;

	moveQueuePos = 0;

	monsterAge = age;

  eventsAllowed = false;
  currentTask = STAND;

  queueStand();
}

void Egg::queueHatch1(){
	moveQueue[0].setMove(-2,0,0,0,2);
	moveQueue[1].setMove(4,0,0,0,2);
	moveQueue[2].setMove(-4,0,0,0,2);
	moveQueue[3].setMove(4,0,0,0,2);

	moveQueuePos = 0;
}

void Egg::queueHatch2(){
	moveQueue[0].setMove(-2,0,0,0,3);
	moveQueue[1].setMove(0,0,0,0,3);
	moveQueue[2].setMove(0,0,0,0,3);
	moveQueue[3].setMove(0,0,0,0,3);

	moveQueuePos = 0;
}

void Egg::heartbeat(){
	updateAge();

	if (dna.monsterLifespan - monsterAge == 40){
		queueHatch1();
	} else if (dna.monsterLifespan - monsterAge == 20){
		queueHatch2();
	} else if (moveQueuePos > 3){
		queueStand();
	}

	doMove();
}
