/*
 * AudioManager.cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: hangSoon
 */

#include "AudioManager.h"

AudioManager::AudioManager() {

}
AudioManager::~AudioManager() {
	// TODO Auto-generated destructor stub

}

AudioManager* AudioManager::Audiomanager;

void AudioManager::playEffectAudio(int id){
	switch(id){
	case SOUND_CLICK:
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("commons/sounds/buttonclick.ogg",false,1,1,1);
		break;
	case SOUND_HITEARTH:
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("playscene/sounds/heatearth.mp3",false,1,1,1);
			break;

	case SOUND_MENUAUDIO:
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("titlescene/sounds/mainback.mp3",true);
		//menuid =CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("titlescene/sounds/mainback.mp3",true,1,1,1);
			break;

	case SOUND_PALYAUDIO:
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2);
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("playscene/sounds/gameback.mp3",true);
	//	playid =CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("playscene/sounds/gameback.mp3",true,1,1,1);
			break;

	case SOUND_EXPLOSION:
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("playscene/sounds/explosion.mp3",false,1,1,1);
		//	stageid =CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("stageselectscene/sounds/stageback.mp3",true,1,1,1);
			break;
	case SOUND_INTRO:
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("commons/sounds/intro.mp3",false,1,1,1);
			break;


	default:

		break;
	}

}
void AudioManager::playSound(int id){
	switch(id){
	default:

		break;
	}
}
void AudioManager::pauseSound(){
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
void AudioManager::stopSound(){
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}
void AudioManager::resumeSound(){
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
void AudioManager::mute(){

	if(!ismute)
	{
	CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0);
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0);
	ismute = true;
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
			CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
			ismute = false;
	}

}

void AudioManager::clearSound(int id){
	CocosDenshion::SimpleAudioEngine::end();
}
bool AudioManager::isPlaySound(){
return CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
}
void AudioManager::setSFXvolume(float value)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(value/10.0);
}

