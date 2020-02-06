/*
 * MoverMon.h
 *
 * AI for monster that moves left to right
 */

#include "MonsterDB.h"

class FloaterMon : public MoverMon{

  public:
    FloaterMon(MonsterRef ref, unsigned int age);
    FloaterMon();
    ~FloaterMon();
    void queueWalk();
	int generateFloatDist();
	void queueStand();
};
