FlusherFX::FlusherFX(){
	
	spr = flusher;
	flusherPos = 0;
	
	numActiveFrames = 2;
	
	animDone = false;
}

void FlusherFX::heartbeat(){
	if(flusherPos < 32){
		fx[0].setFrame(spr,128-flusherPos*12,0,-1);
    		fx[1].setFrame(spr,128-flusherPos*12,32,-1);
		flusherPos++;
	} else {
		animDone = true;
	}
}

int FlusherFX::getEffectPos(){
  return 128-flusherPos*12;
}

bool FlusherFX::finished(){
	return animDone;
}
