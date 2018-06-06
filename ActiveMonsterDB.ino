ActiveMonsterDB::ActiveMonsterDB(MonsterDB mondb){
  mdb = mondb;
  monSize = 0;
}

void ActiveMonsterDB::addMonster(MonsterName name){
  monsters_p[monSize] = spawnMonster(name);
  Serial.print("Adding new monster @ "); Serial.println(monSize);
  monSize++;

}

Monster* ActiveMonsterDB::spawnMonster(MonsterName name){
  switch(mdb.getMonsterType(name)){
    case Mover:
      return new MoverMon(mdb.getSprite1(name),mdb.getSprite2(name),0,mdb.getMonsterLifespan(name),mdb.getNextMonster(name));
      break;
  }
}

void ActiveMonsterDB::deleteMonster(int pos){
  Serial.print("Deleting at:"); Serial.println(pos);
  delete monsters_p[pos];
  monSize--;

//Cascade array and remove last element (unless we already removed the last element)
  if(pos != monSize){
    for(int i = pos; i < monSize; i++){
      Serial.print("i = "); Serial.print(i); Serial.print("monSize = "); Serial.println(monSize);
      monsters_p[pos] = monsters_p[pos+1];
      Serial.print("Monster@pos "); Serial.print(pos+1); Serial.print(" moves to "); Serial.println(pos);
    }
    //monsters_p[monSize] = 0;
    Serial.print("Deleting at:"); Serial.println(monSize);
    delete monsters_p[monSize];
  }

}

Monster * ActiveMonsterDB::getMonster(int pos){
  return monsters_p[pos];
}

int ActiveMonsterDB::numActiveMonsters(){
  return monSize;
}
