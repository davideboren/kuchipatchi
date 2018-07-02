/*
 * Sitter.h
 *
 * AI for monster that moves stands in place
 */

#include "MonsterDB.h"

class Sitter : public Monster{
  public:
    int frameDir; //Need separate xDir when walking since animation depends on xDir flipping

    Sitter();
    Sitter(MonsterRef ref, unsigned int age);

    Frame getFrame();

    void heartbeat();
    void queueWalk();
    void idleRoutine();
    void gotoRoutine();
};
