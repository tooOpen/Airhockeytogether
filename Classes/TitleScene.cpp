#include "TitleScene.h"
#include "audio/include/SimpleAudioEngine.h"
Scene* TitleScene::createScene() {
	auto scene = Scene::create();

	auto layer = TitleScene::create();

	scene->addChild(layer);

	return scene;
}

bool TitleScene::init() {

	if (!Layer::init()) {
		return false;
	}

	this->setKeypadEnabled(true);

	_holdBack= Sprite::create("commons/images/holdback.png");
	_holdBack->setPosition(Vec2(240,400));
	this->addChild(_holdBack, 0);

	_slideBack = Sprite::create("commons/images/slideback.png");
	_slideBack->setAnchorPoint(Vec2(0.5,0.0));
	_slideBack->setPosition(Vec2(240, 0));
	this->addChild(_slideBack, 1);

	_title = Sprite::create("titlescene/images/title.png");
	_title->setPosition(Vec2(240, 650));
	_title->setScale(0.1);
	this->addChild(_title, 3);


	auto titleAciton = ScaleTo::create(0.7, 1.0);
	_title->runAction(titleAciton);

	this->scheduleOnce(schedule_selector(TitleScene::titleRotateAction), 1.0f);

	_startButton = MenuItemImage::create(
		"titlescene/images/startbutton.png",
		"titlescene/images/startbuttoncliked.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));
	_startButton->setScale(0.1);
	_startButton->setPosition(Vec2(0, 102));
	_startButton->setTag(1);

	_stageButton = MenuItemImage::create(
		"titlescene/images/howtoplaybutton.png",
		"titlescene/images/howtoplaybuttonclicked.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));
	_stageButton->setPosition(Vec2(-99, 0));
	_stageButton->setScale(0.1);
	_stageButton->setTag(2);

	_marketButton = MenuItemImage::create(
		"titlescene/images/marketbutton.png",
		"titlescene/images/marketbuttoncliked.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));
	_marketButton->setPosition(Vec2(0, 0));
	_marketButton->setScale(0.1);
	_marketButton->setTag(3);

	_muteButton = MenuItemImage::create(
		"titlescene/images/volumebutton.png",
		"titlescene/images/volumebuttoncliked.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));
	_muteButton->setPosition(Vec2(99, 0));
	_muteButton->setScale(0.1);
	_muteButton->setTag(4);

	_developerButton = MenuItemImage::create(
		"titlescene/images/developerbutton.png",
		"titlescene/images/developerbuttoncliked.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));
	_developerButton->setPosition(Vec2(0, -75));
	_developerButton->setScale(0.1);
	_developerButton->setTag(5);

	auto menu = Menu::create(_startButton, _stageButton, _marketButton, _muteButton, _developerButton ,NULL);

	menu->setPosition(Vec2(240, 300));

	this->addChild(menu, 3);
	auto startAction = ScaleTo::create(0.5, 1.0);
	auto stageAction = ScaleTo::create(0.5, 1.0);
	auto marketAction = ScaleTo::create(0.5, 1.0);
	auto muteAction = ScaleTo::create(0.5, 1.0);
	auto developerAction = ScaleTo::create(0.5, 1.0);
	_startButton->runAction(startAction);
	_stageButton->runAction(stageAction);
	_marketButton->runAction(marketAction);
	_muteButton->runAction(muteAction);
	_developerButton->runAction(developerAction);


	this->schedule(schedule_selector(TitleScene::backgroundSlideSchedule), 20.0f, CC_REPEAT_FOREVER, 20.0f);



	return true;
}


void TitleScene::backgroundSlideSchedule(float f)
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


void TitleScene::titleRotateAction(float f)
{
	auto titleRotateAction = RotateTo::create(3.0f, 25);
	auto titleReverseRotateAction = RotateTo::create(3.0f, -25);
	auto titleAction = Sequence::create(titleRotateAction, titleReverseRotateAction, NULL);
	auto repeatRotate = RepeatForever::create(titleAction);
	_title->runAction(repeatRotate);



	auto particleTest1 = ParticleExplosion::create();

	auto texture1 = Director::getInstance()->getTextureCache()->addImage("titlescene/images/mallet.png");
	particleTest1->setTexture(texture1);
	if (particleTest1 != NULL)
	{
		particleTest1->setScale(1.0);
		particleTest1->setEmissionRate(10.0);
		particleTest1->setStartSize(50.0);
		particleTest1->setLife(1.5);
		particleTest1->setDuration(-1);
		particleTest1->setEndSize(0.0);
		particleTest1->setPosition(Vec2(240, 650));
		particleTest1->setStartColor(Color4F(255, 255, 255, 255));
		particleTest1->setEndColor(Color4F(255, 255, 255, 255));
		this->addChild(particleTest1, 2);
	}

	auto particleTest2 = ParticleExplosion::create();

	auto texture2 = Director::getInstance()->getTextureCache()->addImage("titlescene/images/puck.png");
	particleTest2->setTexture(texture2);
	if (particleTest2 != NULL)
	{
		particleTest2->setScale(1.0);
		particleTest2->setEmissionRate(10.0);
		particleTest2->setStartSize(50.0);
		particleTest2->setLife(1.5);
		particleTest2->setDuration(-1);
		particleTest2->setEndSize(0.0);
		particleTest2->setPosition(Vec2(240, 650));
		particleTest2->setStartColor(Color4F(255, 255, 255, 255));
		particleTest2->setEndColor(Color4F(255, 255, 255, 255));
		this->addChild(particleTest2, 2);
	}

}

void TitleScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	 //dlog_print(DLOG_INFO, "USR_TAG", CCString::createWithFormat("AAAAAA%d", keycode)->getCString());

	if (keycode == EventKeyboard::KeyCode::KEY_BACK) {

//		AudioManager::getAudioManager()->clearSound(1);
//		CocosDenshion::SimpleAudioEngine::getInstance()->stopAllEffects();
//		CocosDenshion::SimpleAudioEngine::getInstance()->end();
		Director::getInstance()->end();
	}

}


void TitleScene::menuCloseCallback(Ref* pSender)
{
	auto bmenuItem = (MenuItemImage*)pSender;
	//AudioManager::getAudioManager()->playEffectAudio(SOUND_CLICK);


	if(bmenuItem->getTag() ==1 )
	{
		auto gscene  = GamePlayScene::createScene();
		Director::getInstance()->replaceScene(TransitionZoomFlipAngular::create(1.0,gscene,TransitionScene::Orientation::RIGHT_OVER));
	}
	else if(bmenuItem->getTag() ==2 )
	{
		auto rScene2 = HowToPlayScene::createScene();
							Director::getInstance()->pushScene(rScene2);
	}
	else if(bmenuItem->getTag() ==3 )
	{

	}
	else if(bmenuItem->getTag() ==4 )
	{

		if(!_isMute)
			{
			_muteButton->setNormalImage(Sprite::create("titlescene/images/mutetitle.png"));
			AudioManager::getAudioManager()->mute();
			_isMute =!_isMute;
			}
			else{
				_muteButton->setNormalImage(Sprite::create("titlescene/images/volumebutton.png"));
				AudioManager::getAudioManager()->mute();
				_isMute =!_isMute;
			}

	}
	else if(bmenuItem->getTag() ==5 )
	{
				 Application::getInstance()->openURL("https://www.facebook.com/monkeyhandle");
	}





}
