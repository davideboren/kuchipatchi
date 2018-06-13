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

//Getters
Frame Monster::getFrame(){
  return Frame(currentBmp,xPos,yPos,xDir);
}

int Monster::getXPos(){
  return xPos;
}

int Monster::getYPos(){
  return yPos;
}

//Setters
void Monster::setXPos(int x){
  xPos = x;
}

void Monster::setYPos(int y){
  yPos = y;
}

void Monster::setSprite1(const uint8_t *bitmap1){
  bmp1 = bitmap1;
  currentBmp = bmp1;
}

void Monster::setSprite2(const uint8_t *bitmap2){
  bmp2 = bitmap2;
}


//Age Functions
void Monster::updateAge(){
  monsterAge+=5;
  Serial.print("Age Updated: ");Serial.println(monsterAge);
}

bool Monster::agedOut(){
  return monsterAge >= monsterLifespan;
}

MonsterName Monster::getNextMonsterName(){
  return nextMonster;
}
