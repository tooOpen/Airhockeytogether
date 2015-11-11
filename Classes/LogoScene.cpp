

#include "LogoScene.h"


Scene* LogoScene::createScene() {
	auto scene = Scene::create();

	auto layer = LogoScene::create();

	scene->addChild(layer);

	return scene;
}

bool LogoScene::init() {

	if (!LayerColor::initWithColor(Color4B(255,	255	,255, 255))) {
		return false;
	}
	_one = false;
	_logo = Sprite::create("commons/images/logo.png");
	_logo->setPosition(Vec2(480 / 2, 800 / 2));
	this->addChild(_logo, 1);

	_swipe = CCSprite::create("commons/images/oil.png");
	_swipe->setAnchorPoint(Vec2(0.5, 0.0));
	_swipe->setPosition(Vec2(240, 800));
	this->addChild(_swipe, 2);

	auto transiActionblood = MoveBy::create(2.0, Vec2(0, -800));
	_swipe->runAction(transiActionblood);
	this->schedule(schedule_selector(LogoScene::logotime), 0.1f, 20 , 2.0f);

	_transi = CCSprite::create("commons/images/transition.png");
	_transi->setPosition(Vec2(480 + 240, 400));
	this->addChild(_transi, 3);
	//AudioManager::getAudioManager()->playEffectAudio(SOUND_INTRO);
	return true;
}

void LogoScene::logotime(float f) {

	if (!_one) {
		auto transiAction = MoveTo::create(1.0, Vec2(240, 400));
		_transi->runAction(transiAction);
		_one = true;
	}
	if (_transi->getPositionX() <= 240) {

		auto rScene = TitleScene::createScene();
			Director::getInstance()->replaceScene(rScene);

	}
}

