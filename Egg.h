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
	private:
		MoveInstruction moveInstrQueue[4];
		int moveInstrQueuePos;
		const uint8_t *bmp3;
	public:

		Egg();
		Egg(const uint8_t *bitmap1, const uint8_t *bitmap2, const uint8_t *bitmap3, unsigned int age, MonsterName next);

		void queueStand();
		void queueHatch1();
		void queueHatch2();
		void doMove(MoveInstruction move);

		void heartbeat();

};

#endif
