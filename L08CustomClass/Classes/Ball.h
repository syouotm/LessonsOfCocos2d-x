//
//  Ball.h
//  L08CustomClass
//
//  Created by 张翔 on 15/8/28.
//
//

#ifndef __L08CustomClass__Ball__
#define __L08CustomClass__Ball__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Ball:public Sprite
{
public:
    virtual bool init();
    
    /*static Ball *create(){
        Ball *b = new Ball;
        b->init();
        b->autorelease();
        return b;
    }*/
    CREATE_FUNC(Ball);
    
};

#endif /* defined(__L08CustomClass__Ball__) */
