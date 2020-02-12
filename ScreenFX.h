/*
 * ScreenFX.h
 *
 * Base for screen overlays and effects
 */
 
#ifndef SCREENFX_H
#define SCREENFX_H

class ScreenFX{
	public:
		Frame fx[16];
		int numActiveFrames;
		
		const uint8_t *spr;
		
		
		ScreenFX();
		virtual ~ScreenFX();
		
		virtual void heartbeat();
    virtual bool finished();
    virtual int getEffectPos();
		
		int getActiveFrameNum();
		Frame getFrame(int index);
};

#endif
