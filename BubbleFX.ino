BubbleFX::BubbleFX(){
	spr = bubble;
	
	numActiveFrames = 4;

  for(int i = 0; i < numActiveFrames; i++){
    bubblePosY[i] = -10;
    bubblePosX[i] = -1;
  }
}

void BubbleFX::heartbeat(){
	for(int b = 0; b < numActiveFrames; b++){
		if(bubblePosY[b] > -8){
			bubblePosY[b]-=4;
			bubblePosX[b]+=(random(3)-1)*4;
			fx[b].setFrame(spr,bubblePosX[b],bubblePosY[b],-1);
		} else if (!random(30)){
			bubblePosY[b]=64;
			bubblePosX[b]=random(128);
		}
	}
}

bool BubbleFX::finished(){
  return false;
}

int BubbleFX::getEffectPos(){
  return 0;
}

