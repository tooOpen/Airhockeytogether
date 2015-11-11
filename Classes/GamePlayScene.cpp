#include "GamePlayScene.h"


Scene* GamePlayScene::createScene() {
	auto scene = Scene::create();

	auto layer = GamePlayScene::create();

	scene->addChild(layer);

	return scene;
}

bool GamePlayScene::init() {

	if (!LayerColor::initWithColor(Color4B(0, 255, 255, 255))) {
		return false;
	}
	xdir = 1;
	ydir = 1;
	_upscore = 0;
	_downscore = 0;

	_upScore = LabelTTF::create(CCString::createWithFormat("%d", _upscore)->getCString(), "fonts/junegull.ttf", 70);
	_upScore->setColor(Color3B::BLACK);
	_upScore->setRotation(180);
	_upScore->setPosition(Vec2(240, 500));
	this->addChild(_upScore, 15);


	_downScore = LabelTTF::create(CCString::createWithFormat("%d", _downscore)->getCString(), "fonts/junegull.ttf", 70);
	_downScore->setColor(Color3B::BLACK);
	_downScore->setPosition(Vec2(240, 300));
	this->addChild(_downScore, 15);



	_holdBack = Sprite::create("commons/images/holdback.png");
	_holdBack->setPosition(Vec2(240, 400));
	this->addChild(_holdBack, 0);
	_uphitonce = false;
	_downhitonce = false;
	startdir = RandomHelper::random_int(0, 1);
	if (startdir)
	{
		ydir = 1;
	}
	else
	{
		ydir = -1;
	}

	initxV = 2 * xdir;
	inityV = 2 * ydir;
	_upscore = 0;
	_downscore = 0;

	upmallet = Mallet::createWithTexture(Director::getInstance()->getTextureCache()->addImage("playscene/images/mallet.png"));
	upmallet->setPosition(Vec2(240, 60));
	this->addChild(upmallet, 3);

	downmallet = Mallet::createWithTexture(Director::getInstance()->getTextureCache()->addImage("playscene/images/mallet.png"));
	downmallet->setPosition(Vec2(240, 740));
	this->addChild(downmallet, 3);

	_puck = Sprite::create("playscene/images/puck.png");
	_puck->setPosition(Vec2(240, 400));
	this->addChild(_puck, 3);


	auto back = Sprite::create("playscene/images/back.png");
	back->setPosition(Vec2(240, 400));
	this->addChild(back, 2);


	_slideBack = Sprite::create("commons/images/slideback.png");
	_slideBack->setAnchorPoint(Vec2(0.5, 0.0));
	_slideBack->setPosition(Vec2(240, 0));
	this->addChild(_slideBack, 1);



	_homeButton = MenuItemImage::create(
		"playscene/images/home.png",
		"playscene/images/homeclicked.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_homeButton->setAnchorPoint(Vec2(0.5, 0.5));
	_homeButton->setPosition(Vec2(-200, 50));
	_homeButton->setTag(1);

	_muteButton = MenuItemImage::create(
		"playscene/images/sound.png",
		"playscene/images/sound.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_muteButton->setAnchorPoint(Vec2(0.5, 0.5));
	_muteButton->setPosition(Vec2(200, -50));
	_muteButton->setTag(2);
	auto menu = Menu::create(_homeButton, _muteButton, NULL);

	menu->setPosition(Vec2(240, 400));

	this->addChild(menu, 10);

	this->schedule(schedule_selector(GamePlayScene::backgroundSlideSchedule), 20.0f, CC_REPEAT_FOREVER, 20.0f);
	this->schedule(schedule_selector(GamePlayScene::collsionDetect), 0, CC_REPEAT_FOREVER, 0.0f);

	return true;
}
void GamePlayScene::menuCloseCallback(Ref* pSender)
{
	auto bmenuItem = (MenuItemImage*)pSender;


	if (bmenuItem->getTag() == 1)
	{
		//		AudioManager::getAudioManager()->stopSound();

		auto tscene = TitleScene::createScene();
		Director::getInstance()->replaceScene(tscene);
	}
	else if (bmenuItem->getTag() == 2)
	{


		if (!_ismute)
		{
			_muteButton->setNormalImage(Sprite::create("playscene/images/mute.png"));
			//	AudioManager::getAudioManager()->mute();

			_ismute = !_ismute;
		}
		else{
			_muteButton->setNormalImage(Sprite::create("playscene/images/sound.png"));
			//		AudioManager::getAudioManager()->mute();

			_ismute = !_ismute;
		}
	}


}
void GamePlayScene::onExit()
{

}
void GamePlayScene::collsionDetect(float f)
{

	if (_puck->getPositionX() + initxV < 60)
	{
		xdir *= -1;
		initxV *= xdir;
	}
	if (_puck->getPositionX() + initxV > 425)
	{
		xdir *= -1;
		initxV *= xdir;
	}
	if (upmallet->getBoundingBox().intersectsRect(_puck->getBoundingBox()) && !_uphitonce){
		_uphitonce = true;
		_downhitonce = false;
		xdir *= -1;
		ydir *= -1;
		initxV = RandomHelper::random_int(5, 20);
		inityV = RandomHelper::random_int(5, 20);
		initxV *= xdir;
		inityV *= ydir;

	}
	if (downmallet->getBoundingBox().intersectsRect(_puck->getBoundingBox()) && !_downhitonce){
		_uphitonce = false;
		_downhitonce = true;
		xdir *= -1;
		ydir *= -1;
		initxV = RandomHelper::random_int(5, 20);
		inityV = RandomHelper::random_int(5, 20);
		initxV *= xdir;
		inityV *= ydir;

	}

	_puck->setPosition(Vec2(_puck->getPositionX() + initxV, _puck->getPositionY() + inityV));

	if (_puck->getPositionY() + inityV < -80 || _puck->getPositionY() + inityV>880)
	{
		int whowin = 0;
		if (_puck->getPositionY() + inityV < -80)
		{
			whowin = -1;
			_upscore++;
			_upScore->setString(CCString::createWithFormat("%d", _upscore)->getCString());
			if (_upscore == 10)
			{
				auto win = Sprite::create("playscene/images/upwin.png");
				win->setPosition(Vec2(240, 400));
				this->addChild(win, 20);
				win->setRotation(180);
				this->unschedule(schedule_selector(GamePlayScene::collsionDetect));
				this->scheduleOnce(schedule_selector(GamePlayScene::gototitle), 2.0f);
			}
		}
		else
		{
			whowin = 1;
			_downscore++;
			_downScore->setString(CCString::createWithFormat("%d", _downscore)->getCString());
			if (_downscore == 10)
			{
				auto win = Sprite::create("playscene/images/downwin.png");
				win->setPosition(Vec2(240, 400));
				this->addChild(win, 20);
				this->unschedule(schedule_selector(GamePlayScene::collsionDetect));
				this->scheduleOnce(schedule_selector(GamePlayScene::gototitle), 2.0f);
			}
		}
		xdir = 1;
		ydir = whowin;
		initxV = 0;
		inityV = 5 * ydir;
		_uphitonce = false;
		_downhitonce = false;
		_puck->setPosition(Vec2(240, 400));
	}

}

void GamePlayScene::gototitle(float f)
{
	auto tscene = TitleScene::createScene();
	Director::getInstance()->replaceScene(tscene);
}
void GamePlayScene::backgroundSlideSchedule(float f)
{
	if (_backSlide)
	{
		auto transiAction = MoveTo::create(2.2, Vec2(240, 0));
		_slideBack->runAction(transiAction);
		_backSlide = !_backSlide;
	}
	else
	{
		auto transiAction = MoveTo::create(2.0, Vec2(240, 800));
		auto gotoAction = MoveTo::create(0.0, Vec2(240, -1000));
		auto upAction = MoveTo::create(1.0, Vec2(240, -930));
		auto backAction = Sequence::create(transiAction, gotoAction, upAction, NULL);

		_slideBack->runAction(backAction);
		_backSlide = !_backSlide;
	}
}



