/*
 * MonsterList
 *
 * Container class to hold list of MonsterNames
 * This is used in MonsterRef to hold a monster name list of arbitrary length
 * to hold evolution options
 */

MonsterList::MonsterList(){
	numNames = 1;
	mlist[0] = Grave;
}

MonsterList::~MonsterList(){
	
}

MonsterList::MonsterList(MonsterName m1){
	numNames = 1;
	mlist[0] = m1;
}

MonsterList::MonsterList(MonsterName m1, MonsterName m2){
	numNames = 2;
	mlist[0] = m1;
	mlist[1] = m2;
}

MonsterList::MonsterList(MonsterName m1, MonsterName m2, MonsterName m3){
	numNames = 3;
	mlist[0] = m1;
	mlist[1] = m2;
	mlist[2] = m3;
}

MonsterList::MonsterList(MonsterName m1, MonsterName m2, MonsterName m3, MonsterName m4){
	numNames = 4;
	mlist[0] = m1;
	mlist[1] = m2;
	mlist[2] = m3;
	mlist[3] = m4;
}

MonsterList::MonsterList(MonsterName m1, MonsterName m2, MonsterName m3, MonsterName m4, MonsterName m5){
	numNames = 5;
	mlist[0] = m1;
	mlist[1] = m2;
	mlist[2] = m3;
	mlist[3] = m4;
	mlist[4] = m5;
}

MonsterName MonsterList::getRandomMonsterName(){
	int randId = random(numNames);
	return mlist[randId];
}

