//
//  Stage.cpp
//  BreakGongDae
//
//  Created by 유정민 on 2014. 10. 24..
//...
//

#include "Stage.h"


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
    
    auto body = PhysicsBody::createEdgeBox(Size(visibleSize.width,visibleSize.height*10-GROUND), PhysicsMaterial(0.,0.,0.),1);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height*5+GROUND/2));
    edgeNode->setPhysicsBody(body);
    scene->addChild(edgeNode);
    
    auto layer = Stage::create();
    //layer->setPhyWorld(scene->getPhysicsWorld());
    layer->setContentSize(Size(visibleSize.width,visibleSize.height*10));
    
    scene->addChild(layer);
    
    return scene;
}

bool Stage::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    //visibleSize=Director::getInstance()->getVisibleSize();
    auto keylistener = EventListenerKeyboard::create();
    keylistener->onKeyPressed = CC_CALLBACK_2(Stage::onKeyPressed, this);
    keylistener->onKeyReleased = CC_CALLBACK_2(Stage::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);
    
    auto *background=Sprite::create("stage_background.png");
    background->setContentSize(Size(visibleSize.width,visibleSize.height*10));
    background->setPosition(visibleSize.width/2,visibleSize.height*5);
    addChild(background);
    
    auto character = Sprite::create("grossini_dance_05.png");
    character->setPosition(visibleSize.width/2, GROUND+character->getContentSize().height/2);
    auto body = PhysicsBody::createBox(character->getContentSize(),PhysicsMaterial(0., 0., 0.),Vec2(0,0));
    body->setAngularVelocityLimit(0);
    character->setPhysicsBody(body);
    addChild(character);
    character->setTag(CHARACTER_TAG);
    
    return true;
}
/*Stage::~Stage() {
    
}*/

void Stage::jump_scheduler(float time) {
    auto character = (Sprite*)getChildByTag(CHARACTER_TAG);
    if(character->getPosition().y >=visibleSize.height/2) {
        //캐릭터가 화면의 절반 이상 높이로 올라가려하면 this를 내려서 캐릭터가 화면을 벗어나지 못하게 한다
        this->setPosition(Vec2(0,-character->getPosition().y+visibleSize.height/2));
    }
    else if(character->getPosition().y<=GROUND+character->getContentSize().height/2+1) {
        //바닥에 닿으면 캐릭터를 강제로 멈추게 함
        character->getPhysicsBody()->setAngularVelocity(0.);
        character->getPhysicsBody()->setVelocity(Vec2(0.,0.));
        character->setRotation(0);
        character->setPosition(Vec2(posCharacter[cntofPosCharacter],GROUND+character->getContentSize().height/2));
        
        //언스케줄
        unschedule(schedule_selector(Stage::jump_scheduler));
    }
    else {
        //캐릭터가 높이 올라가지 않으면 this 는 가만히 있음
        this->setPosition(0,0);
        //캐릭터가 흔들리지 않게 함
        character->setRotation(0);
        character->getPhysicsBody()->setAngularVelocity(0.);
    }
}

void Stage::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
    auto character = (Sprite*)getChildByTag(CHARACTER_TAG);
    
    switch (keyCode){
            
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        {
            if(cntofPosCharacter!=0)
                character->setPosition(posCharacter[--cntofPosCharacter],character->getPosition().y);
            break;
        }
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        {
            if(cntofPosCharacter!=2)
                character->setPosition(posCharacter[++cntofPosCharacter],character->getPosition().y);
            break;
        }
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        {
            auto act=JumpBy::create(1, Vec2(0, 1000), 1000, 1);
            character->runAction(act);
            
            //점프 스케줄러가 없으면 등록
            if(!isScheduled(schedule_selector(Stage::jump_scheduler)))
                schedule(schedule_selector(Stage::jump_scheduler));
            break;
        }
        case EventKeyboard::KeyCode::KEY_X: {
            //auto sp = (Sprite*)getChildByTag(CHARACTER_TAG);
            
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
            
            character->runAction(animate);
        }
        default:
            break;
    }
}

void Stage::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    
}
