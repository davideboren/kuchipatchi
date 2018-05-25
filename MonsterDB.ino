MonsterDB::MonsterDB(){
  monsterLookups[idKurotsubutchi] = MonsterRef(kurotsubutchi1,kurotsubutchi2,1,idKuchipatchi,idKuchipatchi);
  monsterLookups[idKuchipatchi] = MonsterRef(kuchipatchi1,kuchipatchi2,1,idKurotsubutchi,idKurotsubutchi);
}

const uint8_t * MonsterDB::getSprite1(int id){
  return monsterLookups[id].sprite1;
}

const uint8_t * MonsterDB::getSprite2(int id){
  return monsterLookups[id].sprite2;
}
