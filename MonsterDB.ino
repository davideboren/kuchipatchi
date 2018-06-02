MonsterDB::MonsterDB(){

  monsterRepo[idKurotsubutchi] = MonsterRef(kurotsubutchi1,kurotsubutchi2,1,idKuchipatchi,idKuchipatchi);
  monsterRepo[idKuchipatchi] = MonsterRef(kuchipatchi1,kuchipatchi2,1,idKurotsubutchi,idKurotsubutchi);
}

const uint8_t * MonsterDB::getSprite1(int id){
  Serial.print("MDB returned sprite1 addr: "); Serial.println((long)monsterRepo[id].sprite1);
  return monsterRepo[id].sprite1;
}

const uint8_t * MonsterDB::getSprite2(int id){
  return monsterRepo[id].sprite2;
}

int MonsterDB::getMonsterType(int id){
  return monsterRepo[id].monsterType;
}

