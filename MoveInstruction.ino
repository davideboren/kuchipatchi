MoveInstruction::MoveInstruction(){

	xDist = 0;
	yDist = 0;

	xDir = -1;
	yDir = -1;

	sprite = 1;
}

void MoveInstruction::setMove(int x, int y, int xdir, int ydir, int spr){
	xDist = x;
	yDist = y;

	xDir = xdir;
	yDir = ydir;

	sprite = spr;
}
