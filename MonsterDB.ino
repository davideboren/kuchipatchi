MonsterDB::MonsterDB(){
  unsigned int lifespanBaby =  2000;
  unsigned int lifespanAdult = 4000;
  monsterRepo[idKurotsubutchi] = MonsterRef(kurotsubutchi1,kurotsubutchi2,Mover,lifespanBaby,idKuchipatchi,idKuchipatchi);
  monsterRepo[idKuchipatchi] = MonsterRef(kuchipatchi1,kuchipatchi2,Mover,lifespanAdult,idKurotsubutchi,idKurotsubutchi);
}

const uint8_t * MonsterDB::getSprite1(int id){
  return monsterRepo[id].sprite1;
}

const uint8_t * MonsterDB::getSprite2(int id){
  return monsterRepo[id].sprite2;
}

MonsterType MonsterDB::getMonsterType(int id){
  return monsterRepo[id].monsterType;
}

unsigned int MonsterDB::getMonsterLifespan(int id){
  return monsterRepo[id].monsterLifespan;
}

int MonsterDB::getNextMonster(int id){
  return random(2)?monsterRepo[id].nextMonster[0]:monsterRepo[id].nextMonster[1];
}
