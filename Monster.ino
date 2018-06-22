/*
 * Monster
 *
 * Base class for all monsters
 */

//Constructors
Monster::Monster(){
  xPos = 56;
  yPos = 32;
}

Monster::Monster(const uint8_t *bitmap1, const uint8_t *bitmap2){
  bmp1 = bitmap1;
  bmp2 = bitmap2;
  currentBmp = bmp1;

  xPos = 56; // Centered
  yPos = 32;
}

Monster::~Monster(){

}

//Getters
MonsterName Monster::getName(){
  return myName;
}

Frame Monster::getFrame(){
  return Frame(currentBmp,xPos,yPos,xDir);
}

int Monster::getXPos(){
  return xPos;
}

int Monster::getYPos(){
  return yPos;
}

int Monster::getXBoundL(){
  return xBoundL;
}

int Monster::getXBoundR(){
  return xBoundR;
}

int Monster::getPoopPos(){
  return xPos + (xDir * 32);
}

MonsterStage Monster::getMonsterStage(){
  return monStage;
}

//Setters
void Monster::setXPos(int x){
  xPos = x;
}

void Monster::setYPos(int y){
  yPos = y;
}

void Monster::setBoundsX(int xL, int xR){
  xBoundL = xL;
  xBoundR = xR;
}

void Monster::setSprite1(const uint8_t *bitmap1){
  bmp1 = bitmap1;
  currentBmp = bmp1;
}

void Monster::setSprite2(const uint8_t *bitmap2){
  bmp2 = bitmap2;
}

void Monster::setTask(MonsterTask task){
  currentTask = task;
  taskDone = false;
}

void Monster::setXDir(int dir){
  xDir = dir;
}

bool Monster::taskComplete(){
  return taskDone;
}

void Monster::goTo(int x){
  if(xPos == x){
    taskDone = true;
  } else {
    setTask(GOTO);
    xDest = x;
    moveQueuePos = 4;
  }
}

//Age Functions
void Monster::updateAge(){
  monsterAge+=5;
  Serial.print("Age Updated: ");Serial.println(monsterAge);
}

bool Monster::agedOut(){
  if( (monsterAge >= monsterLifespan) && currentTask == IDLE){
    return true;
  } else {
    return false;
  }
}

MonsterName Monster::getNextMonsterName(){
  return nextMonster;
}
