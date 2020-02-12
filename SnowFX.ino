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
		if(snowPosY[b] < 62){
			snowPosY[b]+=2;
			snowPosX[b]+=(random(3)-1)*4;
			fx[b].setFrame(spr,snowPosX[b],snowPosY[b],-1);
		} else if (!random(40)){
			snowPosY[b]=0;
			snowPosX[b]=random(128);
		} else if(snowPosY[b] == 62){
			fx[b].setFrame(spr,snowPosX[b],snowPosY[b],-1);
		}
	}
}

bool SnowFX::finished(){
  return false;
}

int SnowFX::getEffectPos(){
  return 0;
}

