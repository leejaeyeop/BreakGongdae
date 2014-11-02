<<<<<<< HEAD
//
//  Stage.h
//  BreakGongDae
//
//  Created by À¯Á¤¹Î on 2014. 10. 24..
//
//
//  Revised by ÀÌ»ó¹Î on 2014. 10. 28..

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

    CREATE_FUNC(Stage);
    
    //void setPhyWorld(PhysicsWorld* world){ m_world = world; }
    //~Stage();
    //virtual bool onTouchBegan(Touch *touch, Event * event);
    //virtual void onTouchEnded(Touch *touch, Event * event);
    

protected:
    static const int GROUND = 50;
    static const int CHARACTER_TAG = 11;
	static Size visibleSize;

	//PhysicsWorld* m_world;
    //Sprite *character;
    
    //onContact Listener
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void jump_scheduler(float time); //Á¡ÇÁÇÏ¸é ¹Ýº¹ÀûÀ¸·Î È£ÃâµÇ´Â ÇÔ¼ö
	//void skill_blocking();
	bool onContactBegin(PhysicsContact& contact);

private:
    static float posCharacter[3]; //Ä³¸¯ÅÍÀÇ xÁÂÇ¥·Î °¡´ÉÇÑ °Íµé
    static int cntofPosCharacter; //Ä³¸¯ÅÍ°¡ ÇöÀç ¾îµð ÀÖ´ÂÁö posCharacterÀÇ index·Î ³ªÅ¸³¿. Ã³À½Àº Áß¾ÓÀÌ¹Ç·Î 1
};



#endif /* defined(__BreakGongDae__Stage__) */
=======
ï»¿//
//  Stage.h
//  BreakGongDae
//
//  Created by ìœ ì •ë¯¼ on 2014. 10. 24..
//
//
//  Revised by ì´ìƒë¯¼ on 2014. 10. 28..

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

    CREATE_FUNC(Stage);
    
    //void setPhyWorld(PhysicsWorld* world){ m_world = world; }
    //~Stage();
    //virtual bool onTouchBegan(Touch *touch, Event * event);
    //virtual void onTouchEnded(Touch *touch, Event * event);
    

protected:
    static const int GROUND = 50;
    static const int CHARACTER_TAG = 11;
    static Size visibleSize;
    //PhysicsWorld* m_world;
    //Sprite *character;
    
    //onContact Listener
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void jump_scheduler(float time); //ì í”„í•˜ë©´ ë°˜ë³µì ìœ¼ë¡œ í˜¸ì¶œë˜ëŠ” í•¨ìˆ˜
private:
    static float posCharacter[3]; //ìºë¦­í„°ì˜ xì¢Œí‘œë¡œ ê°€ëŠ¥í•œ ê²ƒë“¤
    static int cntofPosCharacter; //ìºë¦­í„°ê°€ í˜„ìž¬ ì–´ë”” ìžˆëŠ”ì§€ posCharacterì˜ indexë¡œ ë‚˜íƒ€ëƒ„. ì²˜ìŒì€ ì¤‘ì•™ì´ë¯€ë¡œ 1
};

Size Stage::visibleSize=Director::getInstance()->getVisibleSize();
float Stage::posCharacter[3]={Stage::visibleSize.width/2-Stage::visibleSize.width/3,Stage::visibleSize.width/2,Stage::visibleSize.width/2+Stage::visibleSize.width/3};
int Stage::cntofPosCharacter=1;


#endif /* defined(__BreakGongDae__Stage__) */
>>>>>>> 03a735b2bd71b7ff773cefb96ae1085319b33fc4
