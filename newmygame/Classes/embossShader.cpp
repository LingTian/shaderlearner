//
//  embossShader.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "embossShader.h"
#include "startScene.h"
USING_NS_CC;

Scene* embossShader::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = embossShader::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool embossShader::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    struct  timeval start1,start2;
    struct  timeval end1,end2;
    gettimeofday(&start1,NULL);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(embossShader::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(embossShader::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
  /*  auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);*/
    
    // add "embossShader" splash screen"
    /*
     auto upRsprite = Sprite::create("HelloWorld.png");
     upRsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4*3 + origin.y));
     setShader(upRsprite,"gray.vsh","HorizontalColor.fsh");
     this->addChild(upRsprite, 0);
     
     
     auto topleftsprite = Sprite::create("HelloWorld.png");
     topleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/4*3 + origin.y));
     this->addChild(topleftsprite, 0);
     //     BlurSprite* sprite = BlurSprite::createSprite
     
     auto topmidsprite = Sprite::create("HelloWorld.png");
     //BlurSprite* topmidsprite = BlurSprite::createSprite("Images/powered.png");
     // BlurSprite* topmidsprite = BlurSprite::createSprite("Images/powered.png");
     //auto topmidsprite = Sprite::create("embossShader.png");
     topmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4*3 + origin.y));
     setShader(topmidsprite,"gray.vsh","Blur.fsh");
     this->addChild(topmidsprite, 0);
     */
    auto midleftsprite = Sprite::create("HelloWorld.png");
    midleftsprite->setScale(2.0,2.0);
    //loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "emboss.fsh",midleftsprite);
    midleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midleftsprite, 0);
     gettimeofday(&start2,NULL);
    auto midrightsprite = Sprite::create("HelloWorld.png");
    //midmidsprite->setScale(4.0,4.0);
    midrightsprite->setScale(2.0,2.0);
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "emboss.fsh",midrightsprite);
    midrightsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midrightsprite, 0);
    gettimeofday(&end2,NULL);
    double diff2 = (end2.tv_sec - start2.tv_sec) +
    ((end2.tv_usec - start2.tv_usec)/1000000.0);
    printf("Phase 2 Time:%lf\n",diff2);

    /*auto downsprite = Sprite::create("embossShader.png");
     downsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
     setShader(downsprite,"randBlur.vsh","randBlur.fsh");
     this->addChild(downsprite, 0);
     
     
     auto sprite = Sprite::create("embossShader.png");
     
     // position the sprite on the center of the screen
     setShader(sprite,"gray.vsh","gray.fsh");
     
     // add the sprite as a child to this layer
     sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     this->addChild(sprite, 0);
     
     //   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(embossShader::languageCallback));
     
     //   this->addChild(menu, 1);
     */
    /*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(embossShader::menuBackCallback));
     change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
     //  setup("example_Blur.fsh");
     CCMenu* pMenu = CCMenu::create(change, NULL);
     pMenu->setPosition(CCPointZero);
     this->addChild(pMenu, 1);*/
    gettimeofday(&end1,NULL);
    double diff1 = (end1.tv_sec - start1.tv_sec) +
    ((end1.tv_usec - start1.tv_usec)/1000000.0);
    printf("Phase 1 Time:%lf\n",diff1);

    return true;
}
/*
 void embossShader::buildCustomUniforms()
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
/*void embossShader::setShaderwithccPosition(Sprite * sprite,const char* frag)
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

/*void embossShader::setBlur(Sprite * sprite)
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
void embossShader::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
void embossShader::setShader(Sprite * sprite,const char* vert,const char* frag)
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
void embossShader::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    startScene *layer = startScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene,TransitionScene::Orientation::LEFT_OVER));
    
    
}
void embossShader::menuCloseCallback(Ref* pSender)
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
