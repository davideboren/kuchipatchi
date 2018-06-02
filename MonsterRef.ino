MonsterRef::MonsterRef(){
  
}

MonsterRef::MonsterRef(const uint8_t *s1, const uint8_t *s2, int type, int next1, int next2){
  //Serial.print("I got sprite1 at: "); Serial.println((long)s1);
  //Serial.print("I got sprite2 at: "); Serial.println((long)s2);
  sprite1 = s1;
  sprite2 = s2;
  //Serial.print("I saved sprite1 as: "); Serial.println((long)sprite1);
  //Serial.print("I saved sprite2 as: "); Serial.println((long)sprite2);
  
  monsterType = type;
  nextMonster[0] = next1;
  nextMonster[1] = next2;
}

const uint8_t * MonsterRef::getSprite1(){
  return sprite1;
}

