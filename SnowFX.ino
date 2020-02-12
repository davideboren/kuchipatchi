SnowFX::SnowFX(){
	spr = dot;
	
	numActiveFrames = 6;

  for(int i = 0; i < numActiveFrames; i++){
    snowPosY[i] = -10;
    snowPosX[i] = -1;
  }
}

void SnowFX::heartbeat(){
	for(int b = 0; b < numActiveFrames; b++){
		if(snowPosY[b] < 64){
			snowPosY[b]+=2;
			snowPosX[b]+=(random(3)-1)*4;
			fx[b].setFrame(spr,snowPosX[b],snowPosY[b],-1);
		} else if (!random(30)){
			snowPosY[b]=0;
			snowPosX[b]=random(128);
		}
	}
}

bool SnowFX::finished(){
  return false;
}

int SnowFX::getEffectPos(){
  return 0;
}

