/*
 * BubbleFX.h
 *
 * Animated bubbles for ocean monsters
 */

#ifndef SNOWFX_H
#define SNOWFX_H

class SnowFX : public ScreenFX{
	private:
	
		int snowPosX[6];
		int snowPosY[6];
		
	public:
	
	  SnowFX();
    void heartbeat();
    bool finished();
    int getEffectPos();
	
};

#endif
