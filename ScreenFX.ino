ScreenFX::ScreenFX(){

}

ScreenFX::~ScreenFX(){

}

void ScreenFX::heartbeat(){
	Serial.println("Got FX base class heartbeat, something went wrong");
}

bool ScreenFX::finished(){
	return false;
}

int ScreenFX::getEffectPos(){
	return 0;
}

int ScreenFX::getActiveFrameNum(){
	return numActiveFrames;
}

Frame ScreenFX::getFrame(int index){
	return fx[index];
}
