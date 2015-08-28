#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    TextFieldTTF *tf = TextFieldTTF::textFieldWithPlaceHolder("在这里输入", "arial.ttf", 20);
    tf->setPosition(visibleSize/2);
    addChild(tf);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [tf,this](Touch *t,Event *event){
        if (tf->getBoundingBox().containsPoint(t->getLocation())) {
            tf->attachWithIME();
        }else
        {
            tf->detachWithIME();
        }
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, tf);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
