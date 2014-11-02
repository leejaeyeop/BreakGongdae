<<<<<<< HEAD
//
//  Building.cpp
//  BreakGongDae
//
//  Created by À¯Á¤¹Î on 2014. 11. 1..
//
//

#include "Building.h"

Building* Building::create(/*³Ö¾î¾ßÇÔ*/)
{
    Building *pRet = new Building(/*³Ö¾î¾ßÇÔ*/);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
=======
//
//  Building.cpp
//  BreakGongDae
//
//  Created by ìœ ì •ë¯¼ on 2014. 11. 1..
//
//

#include "Building.h"

Building* Building::create(/*ë„£ì–´ì•¼í•¨*/)
{
    Building *pRet = new Building(/*ë„£ì–´ì•¼í•¨*/);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
>>>>>>> 03a735b2bd71b7ff773cefb96ae1085319b33fc4
