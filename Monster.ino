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


//Age Functions
void Monster::updateAge(){
  age+=5;
}

bool Monster::agedOut(){
  return age >= lifespan;
}






//Workaround for Arduino STL non-compliance
namespace std {
  void __throw_bad_alloc()
  {
    Serial.println("Unable to allocate memory");
  }

  void __throw_length_error( char const*e )
  {
    Serial.print("Length Error :");
    Serial.println(e);
  }
}
