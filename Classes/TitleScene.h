/*
 * TitleScene.h
 *
 *  Created on: Aug 4, 2015
 *      Author: hangSoon
 */

#ifndef TITLESCENE_H_
#define TITLESCENE_H_


#include "cocos2d.h"
#include "GamePlayScene.h"
#include "AudioManager.h"
#include "HowToPlayScene.h"

USING_NS_CC;
class TitleScene : public cocos2d::Layer {
public:
	static const int START_BUTTON_CLICKED = 1;
	static const int STAGE_BUTTON_CLICKED = 2;
	static const int MARKET_BUTTON_CLICKED = 3;
	static const int MUTE_BUTTON_CLICKED = 4;
	static const int DEVELOPER_BUTTON_CLICKED = 5;

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TitleScene)

	bool _isMute = false;
	bool _backSlide = false;
	MenuItemImage* _startButton;
	MenuItemImage* _stageButton;
	MenuItemImage* _marketButton;
	MenuItemImage* _muteButton;
	MenuItemImage* _developerButton;
	Sprite* _title;
	Sprite* _holdBack;
	Sprite* _slideBack;
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void titleRotateAction(float f);
	void backgroundSlideSchedule(float f);

};

#endif /* TITLESCENE_H_ */
