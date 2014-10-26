//
//  Stage.h
//  BreakGongDae
//
//  Created by 유정민 on 2014. 10. 24..
//
//

#ifndef __BreakGongDae__Stage__
#define __BreakGongDae__Stage__

#include "cocos2d.h"
USING_NS_CC;

class Stage : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    /*
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    */
    // implement the "static create()" method manually
    CREATE_FUNC(Stage);
    
    
    
    void setPhyWorld(PhysicsWorld* world){ m_world = world; }
    
    virtual bool onTouchBegan(Touch *touch, Event * event);
    virtual void onTouchEnded(Touch *touch, Event * event);
    
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void jump_scheduler(float time);
    
    void doAction(Ref* sender);
    void addNewSpriteAtPosition(Point p);

protected:
    
    PhysicsWorld* m_world;
    Sprite* makeGrossini(Vec2 point);
    //Key Input Listener
    //onContact Listener
    
private:
    Size visibleSize;
    //물리공간
    //캐릭터
    //건물
};


#endif /* defined(__BreakGongDae__Stage__) */
