struct MoveInstruction{
	int xDist, yDist;
	int xDir, yDir;
	int sprite;
	
	MoveInstruction();
	
	void setMove(int x, int y, int xdir, int ydir, int sprite);
};

