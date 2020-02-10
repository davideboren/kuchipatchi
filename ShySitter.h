/*
 * Sitter.h
 *
 * AI for monster that moves stands in place
 */

#include "MonsterDB.h"

class ShySitter : public Sitter{
  public:
    ShySitter(MonsterRef ref, unsigned int age);
	ShySitter();

    void queueStand();
};
