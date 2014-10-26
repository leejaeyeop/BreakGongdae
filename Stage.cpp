//
//  Stage.cpp
//  BreakGongDae
//
//  Created by 유정민 on 2014. 10. 24..
//
//

#include "Stage.h"

Scene* Stage::createScene()
{
    Size visibleSize;
    
    visibleSize=Director::getInstance()->getVisibleSize();
    //origin=Director::getInstance()->getVisibleOrigin();
    Vect gravity = Vect(0.0f, -400.0f);
    
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(gravity);
    
    auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width,visibleSize.height), PHYSICSBODY_MATERIAL_DEFAULT, 6);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    edgeNode->setPhysicsBody(body);
    scene->addChild(edgeNode);
    
    auto layer = Stage::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    
    scene->addChild(layer);
    
    return scene;
    
    //물리공간 정의
    //캐릭터 정의
    //건물 정의
}

// on "init" you need to initialize your instance
/*
bool Stage::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    */

bool Stage::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    visibleSize=Director::getInstance()->getVisibleSize();
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(Stage::onKeyPressed, this);
    keylistener->onKeyReleased = CC_CALLBACK_2(Stage::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
    //addChild(makeGrossini(Point(400, 400)));
    
    /*auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(Stage::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Stage::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);*/
    
    
    //√÷√ ∑Œ »≠∏Èø° ¬Ô»˙ Ω∫«¡∂Û¿Ã∆Æ∏¶ ∏∏µÈæÓ ¡ÿ¥Ÿ.
    Sprite *grossini = Sprite::create("grossini_dance_05.png");
    grossini->setPosition(visibleSize.width/2, 100+grossini->getContentSize().height/2);
    auto material = PhysicsMaterial(0.1f, 0.0f, 0.1f);
    
    auto body = PhysicsBody::createBox(grossini->getContentSize(),material,Vec2(0,-100));
    grossini->setPhysicsBody(body);
    addChild(grossini);
    
    // ø©±‚º≠∫Œ≈Õ¥¬ ø°¥œ∏ﬁ¿Ãº«¿ª ∏∏µÂ¥¬ ∞˙¡§
    
    // animation¿ª ∏∏µÈ ∞¢∞¢¿« ¿ÃπÃ¡ˆ∏¶ ¥„¿ª ∞¯∞£¿ª ∏∏µÈæÓ µŒ¿⁄.
    /*Vector<SpriteFrame*> animFrames(15);
    char str[100] = { 0 };
    for (int i = 1; i < 15; i++)
    {
        sprintf(str, "grossini_dance_%02d.png", i);
        auto frame = SpriteFrame::create(str, Rect(0, 0, 80, 115));
        animFrames.pushBack(frame);
    }
    
    auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    auto animate = Animate::create(animation);
    auto actionStar = RepeatForever::create(animate);
    grossini->runAction(animate);*/
    grossini->setTag(11);
    
    //addChild(makeGrossini(Point(240, 160)));
    
    return true;
}

void Stage::jump_scheduler(float time) {
    auto sp = (Sprite*)getChildByTag(11);
    if(sp->getPosition().y >=visibleSize.height/2) {
        this->setPosition(Vec2(0,-sp->getPosition().y+visibleSize.height/2));
    }
    else {
        this->setPosition(0,0);
    }
}

bool Stage::onTouchBegan(Touch *touch, Event * event)
{
    return true;
}

void Stage::onTouchEnded(Touch *touch, Event * event)
{
    auto location = touch->getLocation();
    doAction(this);
}

Sprite* Stage::makeGrossini(Vec2 point)
{
    auto sprite = Sprite::create("grossini_dance_10.png");
    auto material = PhysicsMaterial(0.1f, 1.0f, 0.5f);
    auto body = PhysicsBody::createBox(sprite->getContentSize(), material);
    
    sprite->setPhysicsBody(body);
    sprite->setPosition(Vec2(point.x, point.y));
    sprite->setTag(11);
    
    return sprite;
}

void Stage::doAction(Ref* sender)
{
    auto act1 = JumpBy::create(2, Vec2(0, 100), 200, 1);
    //auto act2 = MoveBy::create(2, Vec2(100, 0));
    //auto act3 = RotateBy::create(2, 720);
    auto action = Sequence::create(act1, NULL);
    
    auto sp = (Sprite*)getChildByTag(11);
    
    sp->runAction(action);
}

void Stage::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
    
    switch (keyCode){
            
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        {
            //auto act = MoveBy::create(1, Vec2(-100, 0));
            auto sp = (Sprite*)getChildByTag(11);
            sp->setPosition(sp->getPosition().x-visibleSize.width/3,sp->getPosition().y);
            break;
        }
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        {
            //auto act = MoveBy::create(1, Vec2(100, 0));
            auto sp = (Sprite*)getChildByTag(11);
            sp->setPosition(sp->getPosition().x+visibleSize.width/3,sp->getPosition().y);
            break;
        }
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        {
            auto act = JumpBy::create(1, Vec2(0, 300), 300, 1);
            auto sp = (Sprite*)getChildByTag(11);
            sp->runAction(act);
            schedule(schedule_selector(Stage::jump_scheduler));
            break;
        }
        case EventKeyboard::KeyCode::KEY_X: {
            auto sp = (Sprite*)getChildByTag(11);
            
            Vector<SpriteFrame*> animFrames(15);
            char str[100] = { 0 };
            for (int i = 1; i < 15; i++)
            {
                sprintf(str, "grossini_dance_%02d.png", i);
                auto frame = SpriteFrame::create(str, Rect(0, 0, 80, 115));
                animFrames.pushBack(frame);
            }
            
            auto animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
            auto animate = Animate::create(animation);
            
            sp->runAction(animate);
        }
    }
}

void Stage::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    
}


/*
 /////////////////////////////
 // 2. add a menu item with "X" image, which is clicked to quit the program
 //    you may modify it.
 
 // add a "close" icon to exit the progress. it's an autorelease object
 auto closeItem = MenuItemImage::create(
 "CloseNormal.png",
 "CloseSelected.png",
 CC_CALLBACK_1(Stage::menuCloseCallback, this));
 
 closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 origin.y + closeItem->getContentSize().height/2));
 
 // create menu, it's an autorelease object
 auto menu = Menu::create(closeItem, NULL);
 menu->setPosition(Vec2::ZERO);
 this->addChild(menu, 1);
 
 /////////////////////////////
 // 3. add your codes below...
 
 // add a label shows "Hello World"
 // create and initialize a label
 
 auto label = LabelTTF::create("Hello World", "Arial", 24);
 
 // position the label on the center of the screen
 label->setPosition(Vec2(origin.x + visibleSize.width/2,
 origin.y + visibleSize.height - label->getContentSize().height));
 
 // add the label as a child to this layer
 this->addChild(label, 1);
 
 // add "Stage" splash screen"
 auto sprite = Sprite::create("HelloWorld.png");
 
 // position the sprite on the center of the screen
 sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
 
 // add the sprite as a child to this layer
 this->addChild(sprite, 0);
 */



/*
void Stage::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
 
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}*/
