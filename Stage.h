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

class Stage : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Stage);
};

#endif /* defined(__BreakGongDae__Stage__) */
