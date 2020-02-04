#ifndef MONSTERLIST_H
#define MONSTERLIST_H

#include "Defs.h"

class MonsterList{
	private:
		//std::vector<MonsterName> mlist; 
		int numNames;
		MonsterName mlist[5];
		
	public:
		MonsterList();
		~MonsterList();
		
		MonsterList(MonsterName m1);
		MonsterList(MonsterName m1, MonsterName m2);
		MonsterList(MonsterName m1, MonsterName m2, MonsterName m3);
		MonsterList(MonsterName m1, MonsterName m2, MonsterName m3, MonsterName m4);
		MonsterList(MonsterName m1, MonsterName m2, MonsterName m3, MonsterName m4, MonsterName m5);
		
		MonsterName getRandomMonsterName();
};

#endif