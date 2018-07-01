/*
 * Monster
 *
 * Base class for all monsters
 */

//Constructors
Monster::Monster(){
}

Monster::Monster(const uint8_t *bitmap1, const uint8_t *bitmap2){
  dna.bmp1 = bitmap1;
  dna.bmp2 = bitmap2;
  currentBmp = dna.bmp1;
}

Monster::~Monster(){

}

void Monster::heartbeat(){

}

//Getters
MonsterName Monster::getName(){
  return dna.myName;
}

Frame Monster::getFrame(){
  return Frame(currentBmp,coords.xPos,coords.yPos,coords.xDir);
}

int Monster::getXPos(){
  return coords.xPos;
}

int Monster::getYPos(){
  return coords.yPos;
}

int Monster::getXBoundL(){
  return coords.xBoundL;
}

int Monster::getXBoundR(){
  return coords.xBoundR;
}

int Monster::getPoopPos(){
  return coords.xPos + (coords.xDir * 32);
}

MonsterStage Monster::getMonsterStage(){
  return dna.monsterStage;
}

bool Monster::isEventCapable(){
  return eventsAllowed;
}

//Setters
void Monster::setXPos(int x){
  coords.xPos = x;
}

void Monster::setYPos(int y){
  coords.yPos = y;
}

void Monster::setBoundsX(int xL, int xR){
  coords.xBoundL = xL;
  coords.xBoundR = xR;
}

void Monster::setTask(MonsterTask task){
  currentTask = task;
  taskDone = false;
}

void Monster::setXDir(int dir){
  coords.xDir = dir;
}

void Monster::doMove(MoveInstruction move){
  coords.applyMoveInstruction(move);
  switchSprite(move);
}

void Monster::switchSprite(MoveInstruction move)
{
  switch(move.sprite){
    case 1:
      currentBmp = dna.bmp1;
      break;
    case 2:
      currentBmp = dna.bmp2;
      break;
    case 3:
      currentBmp = dna.bmp3;
      break;
  }
}

bool Monster::taskComplete(){
  return taskDone;
}

void Monster::goTo(int x){
  if(coords.xPos == x){
    taskDone = true;
  } else {
    setTask(GOTO);
    coords.xDest = x;
    moveQueuePos = 4;
  }
}

//Age Functions
void Monster::updateAge(){
  monsterAge+=5;
  Serial.print("Age: "); Serial.print(monsterAge); Serial.print("/"); Serial.println(dna.monsterLifespan);
}

bool Monster::agedOut(){
  if( (monsterAge >= dna.monsterLifespan) && currentTask != GOTO){
    return true;
  } else {
    return false;
  }
}

MonsterName Monster::getNextMonsterName(){
  int i = random(2);
  return dna.nextMonster[i];
}
