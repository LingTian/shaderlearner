#include "HelloWorldScene.h"
#include "startScene.h"

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
    Point origin = Director::getInstance()->getVisibleOrigin();
    if(Constant::getInstance()->machineID==0){
        machineScale=1.0;
    }else if(Constant::getInstance()->machineID==3){
        machineScale=0.5;
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
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    
/*    Label *designInfoLabel;
    designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest;
    shadertest->setFontSize(48);
    
    shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(HelloWorld::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/12));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Static Shader", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    
    /*auto upDirector = MenuItemImage::create(
                                           "HelloWorld.png",
                                           "HelloWorld.png",
                                           CC_CALLBACK_1(HelloWorld::menuSingle, this));
    upDirector->setVisible(true);
    //setShader(upDirector,"gray.vsh","HorizontalColor.fsh");
    upDirector->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4*3 + origin.y));
    
    menu = Menu::create(upDirector, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);*/
    
    auto topleftsprite = Sprite::create("HelloWorld.png");
    topleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/4*3 + origin.y));
    topleftsprite->setScale(machineScale, machineScale);
    this->addChild(topleftsprite, 0);
//     BlurSprite* sprite = BlurSprite::createSprite
    
    float scale1;float scale2;
    
   /*top mid sprite */
    auto topmidsprite = MenuItemImage::create(
                                              "2.png",
                                              "2.png",
                                              CC_CALLBACK_1(HelloWorld::menuSingle, this));
    topmidsprite->setTag(2);
    // position the sprite on the center of the screen
    topmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4*3 + origin.y));
    scale1=visibleSize.width/topmidsprite->getContentSize().width;
    scale2=visibleSize.height/topmidsprite->getContentSize().height;
    topmidsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    //topmidsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale1/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    MenuItemFont * newFont;
    newFont->setFontSize(48*machineScale);
    menu = Menu::create(topmidsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    /*CCLOG("width:%f, height:%f",visibleSize.width,visibleSize.height);
    CCLOG("spritewidth:%f, spriteheight:%f",topmidsprite->getContentSize().width,topmidsprite->getContentSize().height);
    CCLOG("scale1:%f,scale2:%f",scale1,scale2);
    
    CCLOG("spritewidth:%f, spriteheight:%f",topmidsprite->getContentSize().width,topmidsprite->getContentSize().height);*/
    // add the sprite as a child to this layer
    
    float posscale;
    if(Constant::getInstance()->machineID==0 || Constant::getInstance()->machineID==3){
        posscale=machineScale*scale1/(visibleSize.width/topleftsprite->getContentSize().width);
    }else{
        posscale=machineScale*scale1/(visibleSize.width/topleftsprite->getContentSize().width);
        posscale=posscale*4;
    }
    CCLOG("%f :", posscale);
    MenuItemFont * Gray=MenuItemFont::create("Gray",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    Gray->setFontSize(48*machineScale);
    Gray->setTag(2);
    CCLOG("width:%f height:%f",visibleSize.width,visibleSize.height);
    Gray->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4*3 -topmidsprite->getContentSize().height*posscale/2));
    menu = Menu::create(Gray, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /*top right sprite*/
    auto upRsprite = MenuItemImage::create(
                                              "3.png",
                                              "3.png",
                                              CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    upRsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4*3 + origin.y));
    
    upRsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    upRsprite->setTag(3);
    menu = Menu::create(upRsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    MenuItemFont * horizontal=MenuItemFont::create("HorizontalBar",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(horizontal, NULL);
    horizontal->setPosition(Point(visibleSize.width/4*3,visibleSize.height/4*3-upRsprite->getContentSize().height*posscale/2));
    horizontal->setTag(3);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /*mid left sprite*/
    auto midleftsprite = MenuItemImage::create(
                                           "4.png",
                                           "4.png",
                                           CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    midleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    
    midleftsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    midleftsprite->setTag(4);
    menu = Menu::create(midleftsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * bloom=MenuItemFont::create("Bloom",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(bloom, NULL);
    bloom->setPosition(Point(visibleSize.width/4,visibleSize.height/2-midleftsprite->getContentSize().height*posscale/2));
    bloom->setTag(4);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*mid mid sprite*/
    auto midmidsprite = MenuItemImage::create(
                                               "5.png",
                                               "5.png",
                                               CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    midmidsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    midmidsprite->setTag(5);
    menu = Menu::create(midmidsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * edgeDetection=MenuItemFont::create("Edge Detection",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(edgeDetection, NULL);
    edgeDetection->setPosition(Point(visibleSize.width/2,visibleSize.height/2-midleftsprite->getContentSize().height*posscale/2));
    edgeDetection->setTag(5);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

  
    
    /*mid right sprite*/
    auto midrightsprite = MenuItemImage::create(
                                              "6.png",
                                              "6.png",
                                              CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    midrightsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
    
    midrightsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    midrightsprite->setTag(6);
    menu = Menu::create(midrightsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * randBlur=MenuItemFont::create("Frost Blur",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(randBlur, NULL);
    randBlur->setPosition(Point(visibleSize.width/4*3,visibleSize.height/2-midleftsprite->getContentSize().height*posscale/2));
    randBlur->setTag(6);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*down left sprite*/
    auto downleftsprite = MenuItemImage::create(
                                                "7.png",
                                                "7.png",
                                                CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    downleftsprite->setPosition(Point(visibleSize.width/4 + origin.x, visibleSize.height/4 + origin.y));
    
    downleftsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    downleftsprite->setTag(7);
    menu = Menu::create(downleftsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * celShading=MenuItemFont::create("Toon Shading",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(celShading, NULL);
    celShading->setPosition(Point(visibleSize.width/4,visibleSize.height/4-downleftsprite->getContentSize().height*posscale/2));
    celShading->setTag(7);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    
    /*down mid sprite*/
    auto downmidsprite = MenuItemImage::create(
                                                "8.png",
                                                "8.png",
                                                CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    downmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y));
    
    downmidsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    downmidsprite->setTag(8);
    menu = Menu::create(downmidsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * emboss=MenuItemFont::create("Embossed",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(emboss, NULL);
    emboss->setPosition(Point(visibleSize.width/2,visibleSize.height/4-downmidsprite->getContentSize().height*posscale/2));
    emboss->setTag(8);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    
    /*down right sprite*/
    auto downrightsprite = MenuItemImage::create(
                                               "9.png",
                                               "9.png",
                                               CC_CALLBACK_1(HelloWorld::menuSingle, this));
    // position the sprite on the center of the screen
    downrightsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/4 + origin.y));
    
    downrightsprite->setScale(scale1/(visibleSize.width/topleftsprite->getContentSize().width*(1/machineScale)),scale2/(visibleSize.height/topleftsprite->getContentSize().height*(1/machineScale)));
    downrightsprite->setTag(9);
    menu = Menu::create(downrightsprite, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * gaussianBlur=MenuItemFont::create("Gaussian Blur",CC_CALLBACK_1(HelloWorld::menuSingle,this));
    menu = Menu::create(gaussianBlur, NULL);
    gaussianBlur->setPosition(Point(visibleSize.width/4*3,visibleSize.height/4-downrightsprite->getContentSize().height*posscale/2));
    gaussianBlur->setTag(9);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    

    
    
    
    
    
    
//   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(HelloWorld::languageCallback));

 //   this->addChild(menu, 1);

/*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(HelloWorld::menuBackCallback));
    change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
    //  setup("example_Blur.fsh");
    CCMenu* pMenu = CCMenu::create(change, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);*/

    return true;
}
/*
void HelloWorld::buildCustomUniforms()
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
void HelloWorld::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
void HelloWorld::setShaderwithccPosition(Sprite * sprite,GLProgram* shader)
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

/*void HelloWorld::setBlur(Sprite * sprite)
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
void HelloWorld::setShader(Sprite * sprite,const char* vert,const char* frag)
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
void HelloWorld::menuSingle(cocos2d::Ref *pSender){
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
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));

}
void HelloWorld::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();

    startScene *layer = startScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipAngular::create(0.5,scene,TransitionScene::Orientation::LEFT_OVER));
    
}
void HelloWorld::menuCloseCallback(Ref* pSender)
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
