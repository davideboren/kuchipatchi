#ifndef MONSTERCOORDINATES_H
#define MONSTERCOORDINATES_H

struct MonsterCoordinates {
  int xPos, yPos;
  int xDir, yDir;
  int xBoundL, xBoundR;
  int yBoundTop, yBoundBottom;
  int xDest;

  MonsterCoordinates();
  void applyMoveInstruction(MoveInstruction move);
  
};

#endif
