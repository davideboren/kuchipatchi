/*
 * Controller
 *
 * Coordinates all on screen entities
 */
 

Controller::Controller(){

  MonsterDB mdb;

  frameDelay = 200;
  offFrameSlack = 16;

  xBoundL_vis = 64;
  xBoundR_vis = 96 + offFrameSlack;

  for(int slot = PRIMARY; slot != LAST_MON_SLOT; slot++){
    activeMonsters[slot] = NULL;
  }

  for(int slot = EVOLVE_FX_SLOT; slot != LAST_FX_SLOT; slot++){
    activeFX[slot] = NULL;
  }

}

void Controller::activate(){
	
	loadSavedMonster();
	//addMonster(botamon,PRIMARY);
	
	//Always idle for a moment before entering event loop
	//activeFX[SNOW_FX_SLOT] = mdb.newFX(SNOW_FX);
	idleEvent();
	
	while(1){

		int currentEvent;
		
		if(activeMonsters[PRIMARY] -> agedOut() && activeMonsters[PRIMARY] -> isEventCapable()){
			currentEvent = EVO_EVENT;
		} else if(activeMonsters[PRIMARY] -> agedOut() && !activeMonsters[PRIMARY] -> isEventCapable()){
			currentEvent = EVO_EVENT_NO_ANIM;
		} else if (!activeMonsters[PRIMARY] -> isEventCapable()){
			currentEvent = IDLE_EVENT;
		} else {
			currentEvent = generateRandomEvent();
		}

		switch(currentEvent){
			case IDLE_EVENT:
				Serial.println("Entering IDLE_EVENT case");
				idleEvent();
			break;
			case POOP_EVENT:
				Serial.println("Entering POOP_EVENT case");
				poopEvent();
			break;
			case VISITOR_EVENT:
				Serial.println("Entering VISITOR_EVENT case");
				visitorEvent();
			break;
			case EVO_EVENT:
				Serial.println("Entering EVO_EVENT case");
				evoEvent(PRIMARY);
			break;
			case EVO_EVENT_NO_ANIM:
				Serial.println("Entering EVO_EVENT_NO_ANIM case");
				evoEventNoAnim(PRIMARY);
			break;
		}
  }
}


void Controller::loadSavedMonster(){
	MonsterName savedMon = getSavedMonsterName();
	unsigned int savedMonAge = getSavedMonsterAge();
	
	addMonster(savedMon, PRIMARY);
	activeMonsters[PRIMARY] -> setAge(savedMonAge);
}

void Controller::addMonster(MonsterName name, ActiveMonsterSlot slot){
  activeMonsters[slot] = mdb.newMonster(name);

  if(slot == PRIMARY){
	spawnBiomeFX(mdb.getMonsterBiome(name));  
  }
}

void Controller::spawnBiomeFX(Biome biome){
	switch(biome){
		case LAND:
			break;
		case OCEAN:
			if(activeFX[BUBBLE_FX_SLOT] == NULL){
				activeFX[BUBBLE_FX_SLOT] = mdb.newFX(BUBBLE_FX);
			}
			break;
		case SNOW:
			if(activeFX[SNOW_FX_SLOT] == NULL){
				activeFX[SNOW_FX_SLOT] = mdb.newFX(SNOW_FX);
			}
			break;
		default:
			break;
	}
}

void Controller::despawnBiomeFX(Biome biome){
	switch(biome){
		case LAND:
			break;
		case OCEAN:
			if(activeFX[BUBBLE_FX_SLOT] != NULL){
				deleteFX(BUBBLE_FX_SLOT);
			}
			break;
		case SNOW:
			if(activeFX[SNOW_FX_SLOT] != NULL){
				deleteFX(BUBBLE_FX_SLOT);
			}
			break;
		default:
			break;
	}
}

Events Controller::generateRandomEvent(){
	if(random(100) > 10){
		return IDLE_EVENT;
	} else {
		return static_cast<Events>(random(NUM_RANDOM_EVENTS));
	}
}

void Controller::drawFrame(Frame f){
  if(f.xDir == -1){
    display.drawScaledBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  } else if(f.xDir == 1){
    display.drawReverseBitmap(f.xPos,f.yPos,f.bitmap,16,16,1,2);
  }
}

void Controller::deleteMonster(int slot){
	
	if(slot == PRIMARY){
		MonsterName currentMonster = activeMonsters[slot] -> getName();
		despawnBiomeFX(mdb.getMonsterBiome(currentMonster));
	}
	
	delete activeMonsters[slot];
	activeMonsters[slot] = NULL;
}

void Controller::evolveMonster(int slot){
  MonsterName nextMon = activeMonsters[slot] -> getNextMonsterName();

  int currentX = activeMonsters[slot] -> getXPos();
  //int currentY = activeMonsters[slot] -> getYPos();
  int currentXBoundL = activeMonsters[slot] -> getXBoundL();
  int currentXBoundR = activeMonsters[slot] -> getXBoundR();

  delete activeMonsters[slot];

  addMonster(nextMon, static_cast<ActiveMonsterSlot>(slot));

  activeMonsters[slot] -> setXPos(currentX);
  //activeMonsters[slot] -> setYPos(currentY);
  activeMonsters[slot] -> setBoundsX(currentXBoundL, currentXBoundR);
}

void Controller::saveMonster(){
	MonsterName monName = activeMonsters[PRIMARY] -> getName();
	unsigned int monAge = activeMonsters[PRIMARY] -> getMonsterAge();
	
	EEPROM.put(0,monName);
	EEPROM.put(32,monAge);
}
MonsterName Controller::getSavedMonsterName(){
	MonsterName savedMonName;
	EEPROM.get(0,savedMonName);
	return savedMonName;
}

unsigned int Controller::getSavedMonsterAge(){
	unsigned int monAge;
	EEPROM.get(32,monAge);
	return monAge;
}

void Controller::updateMonsters(){
  for(int monSlot = PRIMARY; monSlot != LAST_MON_SLOT; monSlot++){
    if(activeMonsters[monSlot] != NULL){
      activeMonsters[monSlot] -> heartbeat();
    }
  }
}

void Controller::drawMonsterFrames(){
  for(int monSlot = PRIMARY; monSlot != LAST_MON_SLOT; monSlot++){
    if(activeMonsters[monSlot] != NULL){
      drawFrame(activeMonsters[monSlot] -> getFrame());
    }
  }
}

void Controller::updateFX(){
  for(int fxSlot = EVOLVE_FX_SLOT; fxSlot != LAST_FX_SLOT; fxSlot++){
    if(activeFX[fxSlot] != NULL){
      activeFX[fxSlot] -> heartbeat();
    }
  }
}

void Controller::drawFXFrames(){
  for(int fxSlot = EVOLVE_FX_SLOT; fxSlot != LAST_FX_SLOT; fxSlot++){
    if(activeFX[fxSlot] != NULL){
      for(int i = 0; i < activeFX[fxSlot] -> getActiveFrameNum(); i++){
        drawFrame(activeFX[fxSlot] -> getFrame(i));
      }
    }
  }
}

void Controller::deleteFX(int slot){
  delete activeFX[slot];
  activeFX[slot] = NULL;
}

void Controller::updateAll(){
	display.clearDisplay();
	updateMonsters();
	updateFX();
	drawMonsterFrames();
	drawFXFrames();
	display.display();
	delay(frameDelay);

	display.clearDisplay();
	updateFX();
	drawMonsterFrames();
	drawFXFrames();
	display.display();
	delay(frameDelay);

	saveMonster();

}

void Controller::visitorEvent(){
  sendMonsterToPos(PRIMARY,24);
  activeMonsters[PRIMARY] -> setXDir(1);
  activeMonsters[PRIMARY] -> setBoundsX(0 - offFrameSlack ,32);

  addMonster(mdb.getRandomMonster(activeMonsters[PRIMARY] -> getName()), VISITOR);
  activeMonsters[VISITOR] -> setXPos(116);
  sendMonsterToPos(VISITOR,80);
  activeMonsters[VISITOR] -> setBoundsX(xBoundL_vis,xBoundR_vis + offFrameSlack);
  activeMonsters[PRIMARY] -> setTask(IDLE);
  activeMonsters[VISITOR] -> setTask(IDLE);

  for(int i = 0; i < eventDurationInCycles; i++){
    updateAll();
  }

  sendMonsterToPos(VISITOR,128);
  deleteMonster(VISITOR);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);
  sendMonsterToPos(PRIMARY,48);
  activeMonsters[PRIMARY] -> setTask(IDLE);

}

void Controller::sendMonsterToPos(int slot, int x){
  activeMonsters[slot] -> goTo(x);
  while(!activeMonsters[slot] -> taskComplete()){
    updateAll();
  }
}

void Controller::evoEvent(int slot){
  sendMonsterToPos(slot, 48);
  activeFX[EVOLVE_FX_SLOT] = mdb.newFX(EVOLVE_FX);
  activeMonsters[slot] -> setTask(STAND);
  for(int i = 0; i < eventDurationInCycles/4; i++){
    updateAll();
  }
  evolveMonster(slot);
  activeMonsters[slot] -> setTask(STAND);
  for(int i = 0; i < eventDurationInCycles/4; i++){
    updateAll();
  }
  deleteFX(EVOLVE_FX_SLOT);
  activeMonsters[slot] -> setTask(IDLE);
}

void Controller::evoEventNoAnim(int slot){
	//sendMonsterToPos(slot, 48);
	evolveMonster(slot);
}



void Controller::poopEvent(){
  int dropZone = activeMonsters[PRIMARY] -> getPoopPos();
  int monX = activeMonsters[PRIMARY] -> getXPos();
  addMonster(Poop, POOP);
  activeMonsters[POOP] -> setXPos(dropZone);

  if(dropZone < monX){
    activeMonsters[PRIMARY] -> setBoundsX(monX,112);
  } else {
    activeMonsters[PRIMARY] -> setBoundsX(-16,monX);
  }

  while(!activeMonsters[POOP] -> agedOut()){
    updateAll();
  }
  flushPoop(dropZone);

  activeMonsters[PRIMARY] -> setBoundsX(0,96);

}

void Controller::flushPoop(int poopXPos){
	
	activeFX[FLUSH_FX_SLOT] = mdb.newFX(FLUSH_FX);

	while(!activeFX[FLUSH_FX_SLOT] -> finished()){
		if(activeMonsters[POOP] != NULL && activeFX[FLUSH_FX_SLOT] -> getEffectPos() <= poopXPos){
		  deleteMonster(POOP);
		}
		updateAll();
	}

	deleteFX(FLUSH_FX_SLOT);
}

void Controller::idleEvent(){
  for(int d = 0; d < eventDurationInCycles; d++){
    updateAll();
  }
}




