/*
 * MoverMon.h
 *
 * AI for monster that moves left to right
 */

#include "MonsterDB.h"

class MoverMon : public Monster{

  public:
    MoverMon(MonsterRef ref, unsigned int age);
    MoverMon();
    ~MoverMon();
    virtual void queueWalk();
    void idleRoutine();
    void gotoRoutine();
    void standRoutine();
    void heartbeat();
    bool inBounds();
};
