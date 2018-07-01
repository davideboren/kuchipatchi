/*
 * FlusherFX.h
 *
 * Water flush animation for poop event
 */

#ifndef FLUSHERFX_H
#define FLUSHERFX_H

class FlusherFX : public ScreenFX{
	private:
		int flusherPos;
		
		bool animDone;
	
	public:
	
		FlusherFX();

    void heartbeat();
		bool finished();
    int getEffectPos();
		
};

#endif
