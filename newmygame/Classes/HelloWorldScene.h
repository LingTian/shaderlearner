#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "detailScene.h"
#include "embossShader.h"
#include "singlePresent.h"
#include "constantUtil.h"
class HelloWorld : public cocos2d::Layer
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
    void setShaderwithccPosition(cocos2d::Sprite * sprite,cocos2d::GLProgram* shader);
    void setShader(cocos2d::Sprite * sprite,const char* vert,const char* frag);
    void setBlur(cocos2d::Sprite * sprite);
    void setMenuItem(cocos2d::MenuItemImage * sprite,const char* vert,const char* frag);
    //void buildCustomUniforms();
    void menuBackCallback(cocos2d::Ref* pSender);
    void menuSingle(cocos2d::Ref* pSender);
    float machineScale;
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
