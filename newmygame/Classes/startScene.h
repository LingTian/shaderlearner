//
//  startScene.h
//  mygame
//
//  Created by WU XIAO on 2015-01-03.
//
//

#ifndef __mygame__startScene__
#define __mygame__startScene__

#include <iostream>
#include "cocos2d.h"
#include "detailScene.h"
#include "embossShader.h"
#include "singlePresent.h"
#include "constantUtil.h"
class startScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    cocos2d::MenuItemFont * change;
    void loadShader(const GLchar* vertexShader, const char* frag,cocos2d::Sprite * sprite);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuIntroCallback(cocos2d::Ref* pSender);
    void menuAboutUsCallback(cocos2d::Ref* pSender);
    void setShaderwithccPosition(cocos2d::Sprite * sprite,cocos2d::GLProgram* shader);
    void setShader(cocos2d::Sprite * sprite,const char* vert,const char* frag);
    void setBlur(cocos2d::Sprite * sprite);
    void setMenuItem(cocos2d::MenuItemImage * sprite,const char* vert,const char* frag);
    //void buildCustomUniforms();
    void menuStaticShaderCallback(cocos2d::Ref* pSender);
    void menuDynamicShaderCallback(cocos2d::Ref* pSender);
    void menuBackCallback(cocos2d::Ref* pSender);
    void menuSingle(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(startScene);
};

#endif // __startScene_SCENE_H__
