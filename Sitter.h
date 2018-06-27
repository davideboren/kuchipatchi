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
    Sitter(MonsterName name, const uint8_t *bitmap1, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next);
    Sitter(MonsterName name, const uint8_t *bitmap1, const uint8_t *bitmap2, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next);

    Frame getFrame();
    
    void heartbeat();
    void queueStand();
    void queueWalk();
    void idleRoutine();
    void gotoRoutine();
};
