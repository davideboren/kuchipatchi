/*
 * EvolveFX.h
 *
 * Evolution overlay
 */

#ifndef EVOLVEFX_H
#define EVOLVEFX_H

class EvolveFX : public ScreenFX{
	public:
		EvolveFX();

    void heartbeat();
    bool finished();
    int getEffectPos();
};

#endif
