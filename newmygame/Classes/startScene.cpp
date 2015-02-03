//
//  startScene.cpp
//  mygame
//
//  Created by WU XIAO on 2015-01-03.
//
//

#include "startScene.h"
#include "HelloWorldScene.h"
#include "IntroductionScene.h"
#include "AboutUsScene.h"
#include "constantUtil.h"
USING_NS_CC;

Scene* startScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = startScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool startScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    if(visibleSize.width==1136 && visibleSize.height==640){
        Constant::getInstance()->machineID=1;
    }else if(visibleSize.width==960 && visibleSize.height==640)
    {
        Constant::getInstance()->machineID=2;
        
    }else if(visibleSize.width==1024 && visibleSize.height==768)
    {
        Constant::getInstance()->machineID=3;
        
    }else{
        Constant::getInstance()->machineID=0;
        
    
    }
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(startScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    //this->setFontSize(48);
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    /*This is the Introduction*/
    MenuItemFont * introduction;
    introduction->setFontSize(48);
    introduction=MenuItemFont::create("Introduction",CC_CALLBACK_1(startScene::menuIntroCallback,this));
    menu = Menu::create(introduction, NULL);
    introduction->setPosition(Point(visibleSize.width/4*2,visibleSize.height/5*4));
   
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    /*This is the Static Shader effect*/
    MenuItemFont * staticshader=MenuItemFont::create("Static Shader",CC_CALLBACK_1(startScene::menuStaticShaderCallback,this));
    menu = Menu::create(staticshader, NULL);
    staticshader->setPosition(Point(visibleSize.width/4*2,visibleSize.height/5*3));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /*This is the Dynamic Shader effect*/
    MenuItemFont * dynamicshader=MenuItemFont::create("Dynamic Shader",CC_CALLBACK_1(startScene::menuDynamicShaderCallback,this));
    menu = Menu::create(dynamicshader, NULL);
    dynamicshader->setPosition(Point(visibleSize.width/4*2,visibleSize.height/5*2));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    /*This is the About us*/
    MenuItemFont * aboutus=MenuItemFont::create("About Us",CC_CALLBACK_1(startScene::menuAboutUsCallback,this));
   
    //aboutus->setFontName("Zapfino");
    
    menu = Menu::create(aboutus, NULL);
    aboutus->setPosition(Point(visibleSize.width/4*2,visibleSize.height/5));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto midmidsprite = Sprite::create("HelloWorld.png");
    float winwidthSize = Director::getInstance()->getWinSize().width;
    float  contentwidthSize  = midmidsprite->getContentSize().width;
    float scalewidth=winwidthSize/contentwidthSize;
    
    float winheightSize = Director::getInstance()->getWinSize().height;
    float  contentheightSize  = midmidsprite->getContentSize().height;
    float scaleheight=winheightSize/contentheightSize;

    midmidsprite->setScale(scaleheight,scaleheight);
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "kaichang.fsh",midmidsprite);
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    

    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
  
    // add "startScene" splash screen"
    
    /*auto upRsprite = Sprite::create("startScene.png");
    upRsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4*3 + origin.y));
    setShader(upRsprite,"gray.vsh","HorizontalColor.fsh");
    this->addChild(upRsprite, 0);
    MenuItemFont * horizontal=MenuItemFont::create("HorizontalBar",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(horizontal, NULL);
    horizontal->setPosition(Point(visibleSize.width/4*3,visibleSize.height/4*3-upRsprite->getContentSize().height/2));
    horizontal->setTag(3);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    auto topleftsprite = Sprite::create("startScene.png");
    topleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/4*3 + origin.y));
    this->addChild(topleftsprite, 0);
    //     BlurSprite* sprite = BlurSprite::createSprite
    
    auto topmidsprite = Sprite::create("startScene.png");
    setShader(topmidsprite,"gray.vsh","gray.fsh");
    topmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4*3 + origin.y));
    this->addChild(topmidsprite, 0);
    MenuItemFont * grayeffect=MenuItemFont::create("Gray",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(grayeffect, NULL);
    grayeffect->setPosition(Point(visibleSize.width/2,visibleSize.height/4*3-topmidsprite->getContentSize().height/2));
    grayeffect->setTag(2);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto midleftsprite = Sprite::create("startScene.png");
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "bloom.fsh",midleftsprite);
    midleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midleftsprite, 0);
    MenuItemFont * bloom=MenuItemFont::create("Bloom",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(bloom, NULL);
    bloom->setPosition(Point(visibleSize.width/4,visibleSize.height/2-midleftsprite->getContentSize().height/2));
    bloom->setTag(4);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    auto midrightsprite = Sprite::create("startScene.png");
    midrightsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
    setShader(midrightsprite,"randBlur.vsh","randBlur.fsh");
    this->addChild(midrightsprite, 0);
    MenuItemFont * randBlur=MenuItemFont::create("Random Blur",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(randBlur, NULL);
    randBlur->setPosition(Point(visibleSize.width/4*3,visibleSize.height/2-midrightsprite->getContentSize().height/2));
    randBlur->setTag(6);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    auto midmidsprite = Sprite::create("startScene.png");
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "edgeDetection.fsh",midmidsprite);
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    MenuItemFont * edgeDetection=MenuItemFont::create("Edge Detection",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(edgeDetection, NULL);
    edgeDetection->setPosition(Point(visibleSize.width/2,visibleSize.height/2-midmidsprite->getContentSize().height/2));
    edgeDetection->setTag(5);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    
    auto downleftsprite = Sprite::create("startScene.png");
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "celShading.fsh",downleftsprite);
    downleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/4 + origin.y));
    this->addChild(downleftsprite, 0);
    MenuItemFont * celShading=MenuItemFont::create("Toon Shading",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(celShading, NULL);
    celShading->setPosition(Point(visibleSize.width/4,visibleSize.height/4-downleftsprite->getContentSize().height/2));
    celShading->setTag(7);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    auto downmidsprite = Sprite::create("startScene.png");
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Noisy.fsh",downmidsprite);
    downmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));
    this->addChild(downmidsprite, 0);
    MenuItemFont * noisy=MenuItemFont::create("Noisy",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(noisy, NULL);
    noisy->setPosition(Point(visibleSize.width/2,visibleSize.height/4-downmidsprite->getContentSize().height/2));
    noisy->setTag(8);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    
    auto downrightsprite = Sprite::create("startScene.png");
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "example_Blur.fsh",downrightsprite);
    downrightsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4 + origin.y));
    this->addChild(downrightsprite, 0);
    MenuItemFont * gaussianBlur=MenuItemFont::create("Gaussian Blur",CC_CALLBACK_1(startScene::menuSingle,this));
    menu = Menu::create(gaussianBlur, NULL);
    gaussianBlur->setPosition(Point(visibleSize.width/4*3,visibleSize.height/4-downrightsprite->getContentSize().height/2));
    gaussianBlur->setTag(9);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    */
    
    
    //   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(startScene::languageCallback));
    
    //   this->addChild(menu, 1);
    
    /*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(startScene::menuBackCallback));
     change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
     //  setup("example_Blur.fsh");
     CCMenu* pMenu = CCMenu::create(change, NULL);
     pMenu->setPosition(CCPointZero);
     this->addChild(pMenu, 1);*/
    
    return true;
}
/*
 void startScene::buildCustomUniforms()
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
void startScene::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
{
    // auto shader = ShaderCache::getInstance()->getGLProgram(fragmentShader);
    std::cout<<frag<<" successfully loaded!"<<"\n";
    GLchar * fragSource = (GLchar*) String::createWithContentsOfFile(
                                                                     FileUtils::getInstance()->fullPathForFilename(frag).c_str())->getCString();
    auto shader = new GLProgram();
    shader->initWithByteArrays(vertexShader, fragSource);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    shader->link();
    shader->updateUniforms();
    shader->use();
    sprite->setShaderProgram(shader);
    
}
void startScene::setShaderwithccPosition(Sprite * sprite,GLProgram* shader)
{
    /*  GLchar * fragSource = (GLchar*) String::createWithContentsOfFile(
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
     
     CHECK_GL_ERROR_DEBUG();*/
    sprite->setShaderProgram(shader);
}

/*void startScene::setBlur(Sprite * sprite)
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
void startScene::setShader(Sprite * sprite,const char* vert,const char* frag)
{
    // Size visibleSize = Director::getInstance()->getVisibleSize();
    // Point origin = Director::getInstance()->getVisibleOrigin();
    std::cout<<frag<<" successfully loaded!"<<"\n";
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
void startScene::menuSingle(cocos2d::Ref *pSender){
    Scene *scene = Scene::create();
    auto button = (MenuItemFont*)pSender;
    if(button->getTag()==2){
        Constant::getInstance()->level=2;
        
    }else if(button->getTag()==3){
        Constant::getInstance()->level=3;
    }else if(button->getTag()==4){
        Constant::getInstance()->level=4;
    }else if(button->getTag()==5){
        Constant::getInstance()->level=5;
    }else if(button->getTag()==6){
        Constant::getInstance()->level=6;
    }else if(button->getTag()==7){
        Constant::getInstance()->level=7;
    }else if(button->getTag()==8){
        Constant::getInstance()->level=8;
    }else if(button->getTag()==9){
        Constant::getInstance()->level=9;
    }
    singlePresent *layer = singlePresent::create();
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFade::create(1,scene));
    
}
void startScene::menuIntroCallback(Ref *pSender){
    Scene *scene = Scene::create();
    Constant::getInstance()->ppt=1;
    IntroductionScene *layer = IntroductionScene::create();
    scene->addChild(layer);
    //Director::getInstance()->replaceScene(CCTransitionFade::create(1,scene));
    //Director::getInstance()->replaceScene(CCTransitionSlideInB::create(1,scene));
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene));
    
}

void startScene::menuAboutUsCallback(Ref *pSender){
    Scene *scene = Scene::create();
    
    AboutUsScene *layer = AboutUsScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene));
    
}

void startScene::menuStaticShaderCallback(Ref *pSender){
    Scene *scene = Scene::create();
    Constant::getInstance()->level=1;
    HelloWorld *layer = HelloWorld::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene));
    
}

void startScene::menuDynamicShaderCallback(Ref *pSender){
    Scene *scene = Scene::create();
    Constant::getInstance()->level=21;
    Julia *layer = Julia::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene));
    
}
void startScene::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    
    HelloWorld *layer = HelloWorld::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFade::create(1,scene));
    
    
}
void startScene::menuCloseCallback(Ref* pSender)
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
