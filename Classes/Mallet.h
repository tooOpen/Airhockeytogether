/*
 * Mallet.h
 *
 *  Created on: Aug 15, 2015
 *      Author: hangSoon
 */

#ifndef MALLET_H_
#define MALLET_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum tagPaddleState
{
    kPaddleStateGrabbed,
    kPaddleStateUngrabbed
} PaddleState;

class Mallet : public Sprite, public Clonable
{
    PaddleState        _state;

public:
    Mallet(void);
    virtual ~Mallet(void);

    Rect getRect();
    bool initWithTexture(Texture2D* aTexture) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    virtual Mallet* clone() const override;

    static Mallet* createWithTexture(Texture2D* aTexture);
};

#endif /* MALLET_H_ */
