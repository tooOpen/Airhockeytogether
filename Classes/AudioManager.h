/*
 * AudioManager.h
 *
 *  Created on: Aug 5, 2015
 *      Author: hangSoon
 */

#ifndef AUDIOMANAGER_H_
#define AUDIOMANAGER_H_

#include "ResourceID.h"
#include "audio/include/SimpleAudioEngine.h"
#include "cocos2d.h"

USING_NS_CC;

class AudioManager {
public:
	static AudioManager* getAudioManager()
	{
		if (!Audiomanager)
		{
			Audiomanager = new AudioManager();
		}
		return Audiomanager;
	}

	virtual ~AudioManager();
	void playEffectAudio(int id);
	void playSound(int id);
	void pauseSound();
	void stopSound();
	void resumeSound();
	bool isPlaySound();
	void setSFXvolume(float value);
	void mute();
	void clearSound(int id);
	bool ismute;


private:
	static AudioManager* Audiomanager;
	AudioManager();
};
#endif /* AUDIOMANAGER_H_ */
