//
//  Stage.h
//  BreakGongDae
//
//  Created by 유정민 on 2014. 10. 24..
//
//
//  Revised by 이상민 on 2014. 10. 28..

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
    
    //virtual bool onTouchBegan(Touch *touch, Event * event);
    //virtual void onTouchEnded(Touch *touch, Event * event);
    

    
    //void doAction(Ref* sender);
    //void addNewSpriteAtPosition(Point p);

protected:
    static Size visibleSize;
    PhysicsWorld* m_world;
    Sprite* makeGrossini(Vec2 point);
    //onContact Listener
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void jump_scheduler(float time);
private:
    static float posCharacter[3];
};

Size Stage::visibleSize=Director::getInstance()->getVisibleSize();
float Stage::posCharacter[3]={Stage::visibleSize.width/2-Stage::visibleSize.width/3,Stage::visibleSize.width/2,Stage::visibleSize.width/2+Stage::visibleSize.width/3};


#endif /* defined(__BreakGongDae__Stage__) */
