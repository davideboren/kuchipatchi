Egg::Egg(MonsterName name, const uint8_t *bitmap1, const uint8_t *bitmap2, const uint8_t *bitmap3, unsigned int age, unsigned int lifespan, MonsterName next){

	myName = name;

	bmp1 = bitmap1;
	bmp2 = bitmap2;
	bmp3 = bitmap3;
	currentBmp = bmp1;

	moveInstrQueuePos = 0;

	monsterAge = age;
	monsterLifespan = lifespan;

	nextMonster = next;

  eventsAllowed = false;
  currentTask = STAND;

  queueStand();
}

void Egg::queueHatch1(){
	moveInstrQueue[0].setMove(-2,0,0,0,2);
	moveInstrQueue[1].setMove(4,0,0,0,2);
	moveInstrQueue[2].setMove(-4,0,0,0,2);
	moveInstrQueue[3].setMove(4,0,0,0,2);

	moveInstrQueuePos = 0;
}

void Egg::queueHatch2(){
	moveInstrQueue[0].setMove(-2,0,0,0,3);
	moveInstrQueue[1].setMove(0,0,0,0,3);
	moveInstrQueue[2].setMove(0,0,0,0,3);
	moveInstrQueue[3].setMove(0,0,0,0,3);

	moveInstrQueuePos = 0;
}

void Egg::queueStand(){
	moveInstrQueue[0].setMove(0,0,0,0,1);
	moveInstrQueue[1].setMove(0,0,0,0,2);
	moveInstrQueue[2].setMove(0,0,0,0,1);
	moveInstrQueue[3].setMove(0,0,0,0,2);

	moveInstrQueuePos = 0;
}

void Egg::heartbeat(){
	updateAge();

	if (monsterLifespan - monsterAge == 40){
		queueHatch1();
	} else if (monsterLifespan - monsterAge == 20){
		queueHatch2();
	} else if (moveInstrQueuePos > 3){
		queueStand();
	}

	doMove(moveInstrQueue[moveInstrQueuePos]);
	moveInstrQueuePos++;
}
