ScreenFX::ScreenFX(){
	
}

int ScreenFX::getActiveFrameNum(){
	return numActiveFrames;
}

Frame ScreenFX::getFrame(int index){
	return fx[index];
}
