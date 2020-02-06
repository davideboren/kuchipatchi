/*
 * MoverMon.h
 *
 * AI for monster that moves left to right
 */

#include "MonsterDB.h"

class FloaterMon : public Monster{

  public:
    FloaterMon(MonsterRef ref, unsigned int age);
    FloaterMon();
    ~FloaterMon();
    void queueWalk();
	int generateFloatDist();
	void queueStand();
    void idleRoutine();
    void gotoRoutine();
    void standRoutine();
    void heartbeat();
    bool inBounds();
};
