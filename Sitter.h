/*
 * Sitter.h
 *
 * AI for monster that moves stands in place
 */

#include "MonsterDB.h"

class Sitter : public Monster{
  public:
    int xDir_walking; //Need separate xDir when walking since animation depends on xDir flipping

    Sitter();
    Sitter(const uint8_t *bitmap1, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next);
    Sitter(const uint8_t *bitmap1, const uint8_t *bitmap2, MonsterStage stage, unsigned int age, unsigned int lifespan, MonsterName next);

    void heartbeat();
    void queueStand();
    void queueWalk();
    void idleRoutine();
    void gotoRoutine();
};
