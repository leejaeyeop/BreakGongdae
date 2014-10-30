//
//  Stage.cpp
//  BreakGongDae
//
//  Created by 유정민 on 2014. 10. 24..
//
//

#include "Stage.h"
#define GROUND 100

Scene* Stage::createScene()
{
    visibleSize=Director::getInstance()->getVisibleSize();
    //origin=Director::getInstance()->getVisibleOrigin();
    posCharacter[0]=Stage::visibleSize.width/2-Stage::visibleSize.width/3;
    posCharacter[1]=Stage::visibleSize.width/2;
    posCharacter[2]=Stage::visibleSize.width/2+Stage::visibleSize.width/3;
    
    Vect gravity = Vect(0.0f, -400.0f);
    
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
}

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
    
    Sprite *character = Sprite::create("grossini_dance_05.png");
    character->setPosition(visibleSize.width/2, GROUND+character->getContentSize().height/2);
    auto material = PhysicsMaterial(0.1f, 0.0f, 0.1f);
    
    auto body = PhysicsBody::createBox(character->getContentSize(),material,Vec2(0,-GROUND));
    character->setPhysicsBody(body);
    addChild(character);
    character->setTag(11);
    
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

void Stage::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
    static int cntofPosCharacter=0;
    switch (keyCode){
            
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        {
            auto sp = (Sprite*)getChildByTag(11);
            if(cntofPosCharacter!=0)
                sp->setPosition(posCharacter[--cntofPosCharacter],sp->getPosition().y);
            break;
        }
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        {
            auto sp = (Sprite*)getChildByTag(11);
            if(cntofPosCharacter!=2)
                sp->setPosition(posCharacter[++cntofPosCharacter],sp->getPosition().y);
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
        default:
            break;
    }
}

void Stage::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    
}
