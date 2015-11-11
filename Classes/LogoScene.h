/*
 * LogoScene.h
 *
 *  Created on: Aug 4, 2015
 *      Author: hangSoon
 */

#ifndef LOGOSCENE_H_
#define LOGOSCENE_H_

#pragma once

#include "cocos2d.h"
#include "TitleScene.h"
#include "AudioManager.h"
USING_NS_CC;
class LogoScene: public cocos2d::LayerColor {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LogoScene)

	bool _one;
	Sprite* _logo;
	Sprite* _swipe;
	Sprite* _transi;
	void logotime(float f);

};
#endif /* LOGOSCENE_H_ */
