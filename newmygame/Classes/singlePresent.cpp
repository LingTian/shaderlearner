//
//  singlePresent.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//
//
//  singlePresent.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "singlePresent.h"
#include "HelloWorldScene.h"
#include "CompareScene.h"
#include "LectureScene.h"
USING_NS_CC;
using namespace cocos2d;
Scene* singlePresent::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = singlePresent::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool singlePresent::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
   const char * frag;
    int flag=0;
    if (Constant::getInstance()->level==2){
        flag=1;
        frag="2.png";

    }else if(Constant::getInstance()->level==3){
        flag=1;
        frag="3.png";
    
    }else if(Constant::getInstance()->level==4){
        flag=2;
        frag="4.png";
    
    }else if(Constant::getInstance()->level==5){
        frag="5.png";
        flag=2;
    }else if(Constant::getInstance()->level==6){
        flag=1;
        frag="6.png";
    
    }else if(Constant::getInstance()->level==7){
        flag=2;
        frag="7.png";
    
    }else if(Constant::getInstance()->level==8){
        frag="8.png";
        flag=2;
        
        
    }else if(Constant::getInstance()->level==9){
        frag="9.png";
        flag=2;
        
        
    }else{
    
    
    }
    struct  timeval start1,start2;
    struct  timeval end1,end2;
    gettimeofday(&start1,NULL);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(singlePresent::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    MenuItemFont * shadertest;
    shadertest->setFontSize(48);

    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(singlePresent::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
      MenuItemFont * comparetest=MenuItemFont::create("Compare",CC_CALLBACK_1(singlePresent::menuCompareCallback,this));
    menu = Menu::create(comparetest, NULL);
    comparetest->setPosition(Point(visibleSize.width/4*3,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
   
    

    MenuItemFont * lecture=MenuItemFont::create("Lecture",CC_CALLBACK_1(singlePresent::menuLectureCallback,this));
    menu = Menu::create(lecture, NULL);
    lecture->setPosition(Point(visibleSize.width/4,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    /*MenuItemFont * savefile=MenuItemFont::create("Save",CC_CALLBACK_1(singlePresent::menuSaveCallback,this));
    menu = Menu::create(savefile, NULL);
    savefile->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6*5));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);*/
    auto s = Director::getInstance()->getWinSize();
    
    // create a render texture, this is what we are going to draw into
    _target = RenderTexture::create(s.width, s.height, Texture2D::PixelFormat::RGBA8888);
    _target->retain();
    _target->setPosition(Point(s.width / 2, s.height / 2));
    this->addChild(_target, -1);
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    /*auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);*/
    
    
    auto midmidsprite = Sprite::create(frag);
   
    float winheightSize = Director::getInstance()->getWinSize().height;
    float  contentheightSize  = midmidsprite->getContentSize().height;
    float scaleheight=winheightSize/contentheightSize;
     midmidsprite->setScale(scaleheight,scaleheight);
    //if(flag==1){
     //   setShader(midmidsprite,"gray.vsh",frag);
    //}else if(flag==2){
     //loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, frag,midmidsprite);
    //}else if(flag==3){
    
    //}else{
    
    //}
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    this->addChild(midmidsprite, 0);
    gettimeofday(&end1,NULL);
    double diff1 = (end1.tv_sec - start1.tv_sec) +
    ((end1.tv_usec - start1.tv_usec)/1000000.0);
    printf("Phase 1 Time:%lf\n",diff1);
    
   /*
    auto midmidsprite = Sprite::create("HelloWorld.png");
    midmidsprite->setScale(4.0,4.0);
    loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian.fsh",midmidsprite);
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
   */
    
    return true;
}
void singlePresent::menuCompareCallback(Ref *pSender){
    Scene *scene = Scene::create();
    CompareScene *layer = CompareScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene));
    //this->ScreenShoot();
    
}




void singlePresent::ScreenShoot()
{
    
    static int counter = 0;
    
    char png[20];
    sprintf(png, "image-%d.png", counter);
    char jpg[20];
    sprintf(jpg, "image-%d.jpg", counter);
    
    _target->saveToFile(png, Image::Format::PNG);
    _target->saveToFile(jpg, Image::Format::JPG);
    
    std::string fileName = FileUtils::getInstance()->getWritablePath() + jpg;
    CCLOG("%s",fileName.c_str());
    /*auto action1 = DelayTime::create(1);
    auto func = [&,fileName]()
    {
        auto sprite = Sprite::create(fileName);
        addChild(sprite);
        sprite->setScale(0.3f);
        sprite->setPosition(Point(40, 40));
        sprite->setRotation(counter * 3);
    };
    runAction(Sequence::create(action1, CallFunc::create(func), NULL));
    */
    CCLOG("Image saved %s and %s", png, jpg);
    
    counter++;
}

void singlePresent::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
    //   shader->setUniformLocationWith2fv( shader->getUniformLocation("resolution"),sprite->getTexture()->getContentSizeInPixels().height, 1);
    shader->link();
    shader->updateUniforms();
    shader->use();
    sprite->setShaderProgram(shader);
    
}
void singlePresent::setShader(Sprite * sprite,const char* vert,const char* frag)
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
void singlePresent::menuLectureCallback(Ref *pSender){
    if(Constant::getInstance()->level==2){
        Constant::getInstance()->lecture=1;
        Constant::getInstance()->lectureNo=5;
        
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
        Constant::getInstance()->lectureNo=8;
        
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
void singlePresent::menuBackCallback(Ref *pSender){
    Scene *scene = Scene::create();
    HelloWorld *layer = HelloWorld::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene,TransitionScene::Orientation::LEFT_OVER));
    
    
}

void singlePresent::menuCloseCallback(Ref* pSender)
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
