/*
 * Sitter.h
 *
 * AI for monster that moves stands in place
 */

#include "MonsterDB.h"

class Sitter : public Monster{
  public:
    Sitter();
    Sitter(const uint8_t *bitmap1, unsigned int age, unsigned int lifespan, MonsterName next);

    void heartbeat();
    void queueStand();
};
