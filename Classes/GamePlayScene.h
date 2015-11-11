/*
 * GamePlayScene.h
 *
 *  Created on: Aug 4, 2015
 *      Author: hangSoon
 */

#ifndef GAMEPLAYSCENE_H_
#define GAMEPLAYSCENE_H_

#include "cocos2d.h"
#include "TitleScene.h"
#include "AudioManager.h"
#include "Mallet.h"
USING_NS_CC;

class GamePlayScene : public cocos2d::LayerColor
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayScene)
	MenuItemImage* _homeButton;
	MenuItemImage* _muteButton;
	Sprite* _holdBack;
	Sprite* _slideBack;
	Sprite* _puck;
	LabelTTF* _upScore;
	LabelTTF* _downScore;
	bool _ismute;
	bool _backSlide;
	bool _uphitonce;
	bool _downhitonce;
	int initxV;
	int inityV;
	int _upscore;
	int _downscore;
	 Mallet* upmallet;
	 Mallet* downmallet ;
	int count;
	int xdir;
	int ydir;
	int startdir;
	//LabelTTF* _countLabel;
	virtual void onExit();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void backgroundSlideSchedule(float f);
	void collsionDetect(float f);
	void gototitle(float f);
};
#endif /* GAMEPLAYSCENE_H_ */
