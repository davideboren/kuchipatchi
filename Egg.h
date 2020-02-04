/*
*	Egg.h
*
*	Egg Monster Type
*/
#ifndef EGG_H
#define EGG_H

#include "MonsterDB.h"
#include "MoveInstruction.h"

class Egg : public Monster{
	public:

		Egg();
		Egg(MonsterRef ref, unsigned int age);

		void queueStand();
		void queueHatch1();
		void queueHatch2();

		void heartbeat();

};

#endif
