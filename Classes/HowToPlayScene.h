/*
 * HowToPlayScene.h
 *
 *  Created on: Aug 7, 2015
 *      Author: hangSoon
 */

#ifndef HOWTOPLAYSCENE_H_
#define HOWTOPLAYSCENE_H_

#include "TitleScene.h"
#include "cocos2d.h"
USING_NS_CC;
class HowToPlayScene: public cocos2d::LayerColor {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HowToPlayScene)

	Sprite* _howtoplay;
	MenuItemImage* _backbtn;
	void menuCloseCallback(Ref* pSender);
};

#endif /* HOWTOPLAYSCENE_H_ */
