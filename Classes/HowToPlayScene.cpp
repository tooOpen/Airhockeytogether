/*
 * HowToPlayScene.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: hangSoon
 */

#include "HowToPlayScene.h"


Scene* HowToPlayScene::createScene() {
	auto scene = Scene::create();

	auto layer = HowToPlayScene::create();

	scene->addChild(layer);

	return scene;
}

bool HowToPlayScene::init() {

	if (!LayerColor::initWithColor(Color4B(255,	255	,255, 255))) {
		return false;
	}

	_howtoplay = Sprite::create("commons/images/description.png");
	_howtoplay->setPosition(Vec2(240, 400));
	this->addChild(_howtoplay, 1);

			_backbtn = MenuItemImage::create(
					"commons/images/howbackbtn.png",
					"commons/images/howbackbtnclicked.png",
					CC_CALLBACK_1(HowToPlayScene::menuCloseCallback, this));
			_backbtn->setPosition(Vec2(0, 0));
auto hmenu = Menu::create(_backbtn,NULL);
hmenu->setPosition(Vec2(100,70));
this->addChild(hmenu,10);

	return true;
}

void HowToPlayScene::menuCloseCallback(Ref* pSender)
{
	//AudioManager::getAudioManager()->playEffectAudio(SOUND_CLICK);
	Director::getInstance()->popScene();

}


