<<<<<<< HEAD
//
//  Building.h
//  BreakGongDae
//
//  Created by À¯Á¤¹Î on 2014. 11. 1..
//
//

#ifndef __BreakGongDae__Building__
#define __BreakGongDae__Building__

#include "cocos2d.h"
#include <queue>
USING_NS_CC;

class Block : Sprite {
private:
    int durability;
public:
    Block(int _durability=10) : durability(_durability) {}
    void attack();
    virtual bool init();
    CREATE_FUNC(Block);
};

using namespace std;
class Building : Layer {
private:
    queue<Block> blocks;
public:
    //Constructor(¿¡¼­ Layer::init È£Ãâ)
    static Building* create(/*³Ö¾î¾ßÇÔ*/);
    void setPositionOfBottom();
    Point getPositionOfTop();
    void attack();
    void destroyAll();
};



#endif /* defined(__BreakGongDae__Building__) */
=======
//
//  Building.h
//  BreakGongDae
//
//  Created by ìœ ì •ë¯¼ on 2014. 11. 1..
//
//

#ifndef __BreakGongDae__Building__
#define __BreakGongDae__Building__

#include "cocos2d.h"
#include <queue>
USING_NS_CC;

class Block : Sprite {
private:
    int durability;
public:
    Block(int _durability=10) : durability(_durability) {}
    void attack();
    virtual bool init();
    CREATE_FUNC(Block);
};

using namespace std;
class Building : Layer {
private:
    queue<Block> blocks;
public:
    //Constructor(ì—ì„œ Layer::init í˜¸ì¶œ)
    static Building* create(/*ë„£ì–´ì•¼í•¨*/);
    void setPositionOfBottom();
    Point getPositionOfTop();
    void attack();
    void destroyAll();
};



#endif /* defined(__BreakGongDae__Building__) */
>>>>>>> 03a735b2bd71b7ff773cefb96ae1085319b33fc4
