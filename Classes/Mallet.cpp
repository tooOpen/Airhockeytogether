/*
 * Mallet.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: hangSoon
 */

#include "Mallet.h"

Mallet::Mallet() {
	// TODO Auto-generated constructor stub

}

Mallet::~Mallet() {
	// TODO Auto-generated destructor stub
}

Rect Mallet::getRect()
{
    auto s = getTexture()->getContentSize();
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}

Mallet* Mallet::createWithTexture(Texture2D* aTexture)
{
	Mallet* pPaddle = new (std::nothrow) Mallet();
	pPaddle->initWithTexture(aTexture);
	pPaddle->autorelease();

    return pPaddle;
}

bool Mallet::initWithTexture(Texture2D* aTexture)
{
    if( Sprite::initWithTexture(aTexture) )
    {
        _state = kPaddleStateUngrabbed;
    }

    return true;
}

void Mallet::onEnter()
{
    Sprite::onEnter();

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(Mallet::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Mallet::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Mallet::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Mallet::onExit()
{
//    auto director = Director::getInstance();
//    director->getTouchDispatcher()->removeDelegate(this);
    Sprite::onExit();
}

bool Mallet::containsTouchLocation(Touch* touch)
{
    return getRect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool Mallet::onTouchBegan(Touch* touch, Event* event)
{
    CCLOG("Paddle::onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);

    if (_state != kPaddleStateUngrabbed) return false;
    if ( !containsTouchLocation(touch) ) return false;

    _state = kPaddleStateGrabbed;
    CCLOG("return true");
    return true;
}

void Mallet::onTouchMoved(Touch* touch, Event* event)
{
    // If it weren't for the TouchDispatcher, you would need to keep a reference
    // to the touch from touchBegan and check that the current touch is the same
    // as that one.
    // Actually, it would be even more complicated since in the Cocos dispatcher
    // you get Sets instead of 1 UITouch, so you'd need to loop through the set
    // in each touchXXX method.

    CCLOG("Paddle::onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);

    CCASSERT(_state == kPaddleStateGrabbed, "Paddle - Unexpected state!");

	
	CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());

  // auto touchPoint = touch->getLocation();
    int bposx = 0;
	if (touchPoint.x < 50 || touchPoint.x>425)
	{
		if (touchPoint.x < 50)
			bposx = 50;
		else 
			bposx = 425;
	}
    else
		bposx = touchPoint.x;



    setPosition( Vec2(bposx, getPosition().y) );
}

Mallet* Mallet::clone() const
{
	Mallet* ret = Mallet::createWithTexture(_texture);
    ret->_state = _state;
    ret->setPosition(getPosition());
    ret->setAnchorPoint(getAnchorPoint());
    return ret;
}

void Mallet::onTouchEnded(Touch* touch, Event* event)
{
    CCASSERT(_state == kPaddleStateGrabbed, "Paddle - Unexpected state!");

    _state = kPaddleStateUngrabbed;
}
