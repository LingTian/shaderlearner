//
//  Julia.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//
//
//  Julia.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "Julia.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* Julia::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Julia::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Julia::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    struct  timeval start1,start2;
    struct  timeval end1,end2;
    gettimeofday(&start1,NULL);
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Julia::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest=MenuItemFont::create("Next",CC_CALLBACK_1(Julia::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("My White Bulb", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this la`yer
    this->addChild(label, 1);
    

    auto midmidsprite = Sprite::create("HelloWorld.png");
    float winheightSize = Director::getInstance()->getWinSize().height;
    float  contentheightSize  = midmidsprite->getContentSize().height;
    float scaleheight=winheightSize/contentheightSize;

    midmidsprite->setScale(scaleheight,scaleheight);
    
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "mywhite.fsh",midmidsprite);
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    gettimeofday(&end1,NULL);
    double diff1 = (end1.tv_sec - start1.tv_sec) +
    ((end1.tv_usec - start1.tv_usec)/1000000.0);
    printf("Phase 1 Time:%lf\n",diff1);

    MenuItemFont * comparetest=MenuItemFont::create("Extension",CC_CALLBACK_1(Julia::menuCompareCallback,this));
    menu = Menu::create(comparetest, NULL);
    comparetest->setPosition(Point(visibleSize.width/4*3,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * lecture=MenuItemFont::create("Lecture",CC_CALLBACK_1(Julia::menuLectureCallback,this));
    menu = Menu::create(lecture, NULL);
    lecture->setPosition(Point(visibleSize.width/4,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    return true;
}

void Julia::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
void Julia::setShader(Sprite * sprite,const char* vert,const char* frag)
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
void Julia::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    detailScene *layer = detailScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
    
    
}

void Julia::menuCompareCallback(Ref *pSender){
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
void Julia::menuLectureCallback(Ref *pSender){
    if(Constant::getInstance()->level==21){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=9;
        
    }else if(Constant::getInstance()->level==3){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=6;
        
    }else if(Constant::getInstance()->level==4){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=13;
        
    }else if(Constant::getInstance()->level==5){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=10;
        
    }else if(Constant::getInstance()->level==6){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=6;
        
    }else if(Constant::getInstance()->level==7){
        Constant::getInstance()->lecture=1;
        
    }else if(Constant::getInstance()->level==8){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=6;
        
    }else if(Constant::getInstance()->level==9){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=10;
        
    }
    
    
    Scene *scene = Scene::create();
    LectureScene *layer = LectureScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene));
    
    
}
void Julia::menuCloseCallback(Ref* pSender)
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
