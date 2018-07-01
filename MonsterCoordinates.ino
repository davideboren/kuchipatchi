MonsterCoordinates::MonsterCoordinates(){
  xPos = 48;
  yPos = 32;

  xDir = -1;
  yDir = 0;

  xBoundL = 0;
  xBoundR = 96;

  yBoundTop = 0;
  yBoundBottom = 32;

  xDest = 0;
}

void MonsterCoordinates::applyMoveInstruction(MoveInstruction move){
  if(move.xDir != 0){
    xDir = move.xDir;
  }

  if(move.yDir != 0){
    yDir = move.yDir;
  }

  xPos = xPos + xDir*move.xDist;
  yPos = yPos + yDir*move.yDist;
}

