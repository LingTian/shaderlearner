//
//  AboutUsScene.cpp
//  mygame
//
//  Created by WU XIAO on 2015-01-03.
//
//

#include "AboutUsScene.h"
#include "startScene.h"
#include "constantUtil.h"
USING_NS_CC;

Scene* AboutUsScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AboutUsScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AboutUsScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
    cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(AboutUsScene::menuCloseCallback, this));
    
	closeItem->setPosition(cocos2d::Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu, 1);
    if(Constant::getInstance()->machineID==0){
        machineScale=1.0;
    }else{
        machineScale=0.5;
    }

    Constant::getInstance()->level=99;
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(AboutUsScene::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(cocos2d::Point(visibleSize.width/4*2,visibleSize.height/9));
    
    menu->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu, 1);
      
    auto midmidsprite=Sprite::create("AboutUs.jpg");
    midmidsprite->setScale(2.0*machineScale,2.0*machineScale);
    midmidsprite->setPosition(cocos2d::Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    
    
    
    MenuItemFont * comparetest=MenuItemFont::create("Reference",CC_CALLBACK_1(AboutUsScene::menuReferenceCallback,this));
    menu = Menu::create(comparetest, NULL);
    comparetest->setPosition(cocos2d::Point(visibleSize.width/4,visibleSize.height/9));
    menu->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu, 1);
    
    
    MenuItemFont * more=MenuItemFont::create("More",CC_CALLBACK_1(AboutUsScene::menuMoreCallback,this));
    more->setColor(cocos2d::ccc3(255,215,0));
    menu = Menu::create(more, NULL);
    more->setPosition(cocos2d::Point(visibleSize.width/4*3,visibleSize.height/9));
    menu->setPosition(cocos2d::Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void AboutUsScene::menuMoreCallback(Ref *pSender){
    NSString* str;
    str = [NSString stringWithFormat:@"itms-apps://itunes.apple.com/artist/gamecloud-ltd./id838672001"];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:str]];
    
}

void AboutUsScene::menuReferenceCallback(Ref *pSender){
    Scene *scene = Scene::create();
    
    Constant::getInstance()->lecture=1;
    Constant::getInstance()->lectureNo=5;
    
    
    LectureScene *layer = LectureScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene));
    
    
}
void AboutUsScene::menuPreviousCallback(Ref *pSender){
    Scene *scene = Scene::create();
    int i=Constant::getInstance()->ppt;
    Constant::getInstance()->ppt=i-1;
    
    AboutUsScene *layer = AboutUsScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.5,scene));
    
    
}

void AboutUsScene::menuNextCallback(Ref *pSender){
    Scene *scene = Scene::create();
    int i=Constant::getInstance()->ppt;
    Constant::getInstance()->ppt=i+1;
    
    AboutUsScene *layer = AboutUsScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionSlideInR::create(0.5,scene));
    
    
}
void AboutUsScene::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    startScene *layer = startScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene,TransitionScene::Orientation::LEFT_OVER));
    
    
}
void AboutUsScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
