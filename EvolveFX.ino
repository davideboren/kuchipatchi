EvolveFX::EvolveFX(){
	spr = evolve;

	numActiveFrames = 0;
}

void EvolveFX::heartbeat(){
	if(numActiveFrames < 16){
		fx[numActiveFrames].setFrame(spr,numActiveFrames*8,0,-1);
    fx[numActiveFrames+1].setFrame(spr,numActiveFrames*8,32,-1);
		numActiveFrames+=2;
	}
}

bool EvolveFX::finished(){
  return false;
}

int EvolveFX::getEffectPos(){
  return 0;
}
