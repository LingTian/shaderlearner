//
//  singlePresent.h
//  mygame
//
//  Created by WU XIAO on 2014-12-06.
//
//

#ifndef __mygame__singlePresent__
#define __mygame__singlePresent__

#include <iostream>

#include <iostream>
#include "cocos2d.h"
#include "embossShader.h"
#include "HelloWorldScene.h"
#include "constantUtil.h"
#include "shaderScene.h"
class singlePresent : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    cocos2d::MenuItemFont * change;
    void ScreenShoot();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void setShaderwithccPosition(cocos2d::Sprite * sprite,const char* frag);
    void setShader(cocos2d::Sprite * sprite,const char* vert,const char* frag);
    void setBlur(cocos2d::Sprite * sprite);
    //void buildCustomUniforms();
    void menuLectureCallback(cocos2d::Ref* pSender);
    void menuCompareCallback(cocos2d::Ref* pSender);
    void menuExtensionCallback(cocos2d::Ref* pSender);
    void menuBackCallback(cocos2d::Ref* pSender);
    cocos2d::RenderTexture *_target;

    void loadShader(const GLchar* vertexShader, const char* frag,cocos2d::Sprite * sprite);
    // implement the "static create()" method manually
    CREATE_FUNC(singlePresent);
};


#endif /* defined(__mygame__singlePresent__) */
