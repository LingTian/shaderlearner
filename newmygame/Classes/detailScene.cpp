//
//  detailScene.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "detailScene.h"
#include "HelloWorldScene.h"
#include "shaderScene.h"
USING_NS_CC;

Scene* detailScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = detailScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool detailScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    if(Constant::getInstance()->machineID==0){
        machineScale=1.0;
    }else{
        machineScale=0.5;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(detailScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest=MenuItemFont::create("Next",CC_CALLBACK_1(detailScene::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    Constant::getInstance()->level=22;
    
    auto label = LabelTTF::create("Flower", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    

    MenuItemFont * comparetest=MenuItemFont::create("Extension",CC_CALLBACK_1(detailScene::menuExtensionCallback,this));
    menu = Menu::create(comparetest, NULL);
    comparetest->setPosition(Point(visibleSize.width/4*3,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    MenuItemFont * lecture=MenuItemFont::create("Lecture",CC_CALLBACK_1(detailScene::menuLectureCallback,this));
    menu = Menu::create(lecture, NULL);
    lecture->setPosition(Point(visibleSize.width/4,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto midmidsprite = Sprite::create("HelloWorld.png");
    //setShader(midmidsprite,"Flower.vsh","Flower.fsh");
    float winheightSize = Director::getInstance()->getWinSize().height;
    float  contentheightSize  = midmidsprite->getContentSize().height;
    float scaleheight=winheightSize/contentheightSize;
    
    midmidsprite->setScale(scaleheight,scaleheight);

    if(Constant::getInstance()->machineID==0){
    
        loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower.fsh",midmidsprite);
    
    }else if(Constant::getInstance()->machineID==1){
    
        loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower5s.fsh",midmidsprite);
        
    }else if(Constant::getInstance()->machineID==2){
        
        loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower4s.fsh",midmidsprite);
        
    }else if(Constant::getInstance()->machineID==3){
        
        loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower1024.fsh",midmidsprite);
        
    }
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    
    /*auto downsprite = Sprite::create("detailScene.png");
    downsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
    setShader(downsprite,"randBlur.vsh","randBlur.fsh");
    this->addChild(downsprite, 0);
    
    
    auto sprite = Sprite::create("detailScene.png");
    
    // position the sprite on the center of the screen
    setShader(sprite,"gray.vsh","gray.fsh");
    
    // add the sprite as a child to this layer
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(sprite, 0);
    
    //   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(detailScene::languageCallback));
    
    //   this->addChild(menu, 1);
    */
    /*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(detailScene::menuBackCallback));
     change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
     //  setup("example_Blur.fsh");
     CCMenu* pMenu = CCMenu::create(change, NULL);
     pMenu->setPosition(CCPointZero);
     this->addChild(pMenu, 1);*/
    
    return true;
}
void detailScene::menuLectureCallback(Ref *pSender){
    if(Constant::getInstance()->level==22){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=12;
        
    }
    Scene *scene = Scene::create();
    LectureScene *layer = LectureScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene));

}
/*
 void detailScene::buildCustomUniforms()
 {
 //  auto s = getTexture()->getContentSizeInPixels();
 //  _blurRadius = 0;
 //  _pixelSize = Point(1/s.width, 1/s.height);
 // _samplingRadius = 0;
 
 //  setBlurSize(3.0f);
 auto program = getShaderProgram();
 //  pixelSizeLocation = program->getUniformLocation("onePixelSize");
 // coefficientLocation = program->getUniformLocation("gaussianCoefficient");
 }
 */
/*void detailScene::setShaderwithccPosition(Sprite * sprite,const char* frag)
{
    GLchar * fragSource = (GLchar*) String::createWithContentsOfFile(
                                                                     FileUtils::getInstance()->fullPathForFilename(frag).c_str())->getCString();
    
    auto p = new GLProgram();
    p->initWithByteArrays(ccPositionTextureColor_vert, fragSource);
    setShaderProgram(p);
    p->release();
    
    CHECK_GL_ERROR_DEBUG();
    
    p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    
    CHECK_GL_ERROR_DEBUG();
    
    p->link();
    
    CHECK_GL_ERROR_DEBUG();
    
    p->updateUniforms();
    
    CHECK_GL_ERROR_DEBUG();
    
    //buildCustomUniforms();
    
    CHECK_GL_ERROR_DEBUG();
}*/

/*void detailScene::setBlur(Sprite * sprite)
 {
 if(sprite)
 {
 GLProgram * p = new GLProgram();
 p->initWithFilenames(vert, frag);
 p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
 p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
 p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
 p->link();
 p->updateUniforms();
 sprite->setShaderProgram(p);
 
 
 }
 
 }*/
void detailScene::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
{
    // auto shader = ShaderCache::getInstance()->getGLProgram(fragmentShader);
    std::cout<<frag<<" successfully loaded!"<<"\n";
    GLchar * fragSource = (GLchar*) String::createWithContentsOfFile(
                                                                     FileUtils::getInstance()->fullPathForFilename(frag).c_str())->getCString();
    auto shader = new GLProgram();
    // if (!shader) {
    //shader->initWithFilenames(vert, frag);
    shader->initWithByteArrays(vertexShader, fragSource);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    //   shader->setUniformLocationWith2fv( shader->getUniformLocation("resolution"),sprite->getTexture()->getContentSizeInPixels().height, 1);
    shader->link();
    shader->updateUniforms();
    shader->use();
    sprite->setShaderProgram(shader);
    
}

void detailScene::menuExtensionCallback(Ref *pSender){
    Scene *scene = Scene::create();
    
    Constant::getInstance()->extendEffect=1;
    Constant::getInstance()->extendEffectNo=2;
    
    shaderScene *layer = shaderScene::create();
    
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene));
    //this->ScreenShoot();
    
}
void detailScene::setShader(Sprite * sprite,const char* vert,const char* frag)
{
    // Size visibleSize = Director::getInstance()->getVisibleSize();
    // Point origin = Director::getInstance()->getVisibleOrigin();
    
    if(sprite)
    {
        GLProgram * p = new GLProgram();
        p->initWithFilenames(vert, frag);
        p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
        p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
        p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
        p->link();
        p->updateUniforms();
        sprite->setShaderProgram(p);
        
        
    }
}
void detailScene::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    laserShader *layer = laserShader::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
    
    
}
void detailScene::menuCloseCallback(Ref* pSender)
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
