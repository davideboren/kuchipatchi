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
};

//Frame Functions
Frame Monster::getFrame(){
  return Frame(currentBmp,xPos,yPos,-1);
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

int Monster::getNextMonsterID(){
  return nextMonster;
}



//Workaround for Arduino STL non-compliance (no need after removing std::queue)
/*namespace std {
  void __throw_bad_alloc()
  {
    Serial.println("Unable to allocate memory");
  }

  void __throw_length_error( char const*e )
  {
    Serial.print("Length Error :");
    Serial.println(e);
  }
}*/
