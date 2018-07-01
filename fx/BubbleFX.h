/*
 * BubbleFX.h
 *
 * Animated bubbles for ocean monsters
 */

#ifndef BUBBLEFX_H
#define BUBBLEFX_H

class BubbleFX : public ScreenFX{
	private:
	
		int bubblePosX[4];
		int bubblePosY[4];
		
	public:
	
	  BubbleFX();
    void heartbeat();
    bool finished();
    int getEffectPos();
	
};

#endif
