//
//  LectureScene.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//
//
//  LectureScene.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "LectureScene.h"
#include "startScene.h"
#include "AboutUsScene.h"
USING_NS_CC;
 
Scene* LectureScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LectureScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LectureScene::init()
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
                                           CC_CALLBACK_1(LectureScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
    MenuItemFont * shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(LectureScene::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/9));
    
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    if(Constant::getInstance()->lecture>1){
        MenuItemFont * pretest=MenuItemFont::create("Previous",CC_CALLBACK_1(LectureScene::menuPreviousCallback,this));
        menu = Menu::create(pretest, NULL);
        pretest->setPosition(Point(visibleSize.width/4,visibleSize.height/9));
        
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
    }
    
    if(Constant::getInstance()->lecture<Constant::getInstance()->lectureNo){
        MenuItemFont * nexttest=MenuItemFont::create("Next",CC_CALLBACK_1(LectureScene::menuNextCallback,this));
        menu = Menu::create(nexttest, NULL);
        nexttest->setPosition(Point(visibleSize.width/4*3,visibleSize.height/9));
        
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
    }

    int level=Constant::getInstance()->level;
    int lecture=Constant::getInstance()->lecture;
    int lectureNo=Constant::getInstance()->lectureNo;
    CCLOG("lectureNo: %d\n",lectureNo);
    std::stringstream a;
    a << "Lecture" << level<<"_"<<lecture<< ".png";
    std::string ppt =a.str();
   
    CCLOG("ppt : %s",ppt.c_str());
    
    //ppt=ppt+level+"_"+lecture;
    /*const char * ppt;
    if (Constant::getInstance()->ppt==1){
        ppt="Intro1.png";
        
    }else if(Constant::getInstance()->ppt==2){
        ppt="Intro2.png";
        
    }else if(Constant::getInstance()->ppt==3){
        ppt="Intro3.png";
        
    }else if(Constant::getInstance()->ppt==4){
        ppt="Intro4.png";
        
    }else if(Constant::getInstance()->ppt==5){
        ppt="Intro5.png";
        
    }*/
    
    auto midmidsprite=Sprite::create(ppt.c_str());
   
    
    midmidsprite->setScale(2.0*machineScale,2.0*machineScale);
    midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(midmidsprite, 0);
    
    /*auto downsprite = Sprite::create("LectureScene.png");
     downsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
     setShader(downsprite,"randBlur.vsh","randBlur.fsh");
     this->addChild(downsprite, 0);
     
     
     auto sprite = Sprite::create("LectureScene.png");
     
     // position the sprite on the center of the screen
     setShader(sprite,"gray.vsh","gray.fsh");
     
     // add the sprite as a child to this layer
     sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     this->addChild(sprite, 0);
     
     //   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(LectureScene::languageCallback));
     
     //   this->addChild(menu, 1);
     */
    /*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(LectureScene::menuBackCallback));
     change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
     //  setup("example_Blur.fsh");
     CCMenu* pMenu = CCMenu::create(change, NULL);
     pMenu->setPosition(CCPointZero);
     this->addChild(pMenu, 1);*/
    
    return true;
}

void LectureScene::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
void LectureScene::setShader(Sprite * sprite,const char* vert,const char* frag)
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

void LectureScene::menuPreviousCallback(Ref *pSender){
    Scene *scene = Scene::create();
    int i=Constant::getInstance()->lecture;
    Constant::getInstance()->lecture=i-1;
    
    LectureScene *layer = LectureScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene,TransitionScene::Orientation::LEFT_OVER));
    
    
}

void LectureScene::menuNextCallback(Ref *pSender){
    Scene *scene = Scene::create();
    int i=Constant::getInstance()->lecture;
    Constant::getInstance()->lecture=i+1;
    
    LectureScene *layer = LectureScene::create();
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    scene->addChild(layer);
    Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
    
    
}
void LectureScene::menuBackCallback(Ref *pSender){
 
    if(Constant::getInstance()->level<10){
        Scene *scene = Scene::create();
        singlePresent *layer;
       layer = singlePresent::create();
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene,TransitionScene::Orientation::DOWN_OVER));
    }else if(Constant::getInstance()->level==21){
        Scene *scene = Scene::create();
        
        Julia *layer = Julia::create();
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene,TransitionScene::Orientation::DOWN_OVER));
    }else if(Constant::getInstance()->level==22){
        Scene *scene = Scene::create();
        
        detailScene *layer = detailScene::create();
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene,TransitionScene::Orientation::DOWN_OVER));
    }else if(Constant::getInstance()->level==23){
        Scene *scene = Scene::create();
        
        laserShader *layer = laserShader::create();
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene,TransitionScene::Orientation::DOWN_OVER));
    }else if(Constant::getInstance()->level==99){
        Scene *scene = Scene::create();
        AboutUsScene *layer = AboutUsScene::create();
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipY::create(0.5,scene,TransitionScene::Orientation::DOWN_OVER));

    
    }
    
    // add layer as a child to scene
    //graySprite(sprite);
    //setup("example_Blur.fsh",layer);
    
   
    
    
}
void LectureScene::menuCloseCallback(Ref* pSender)
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
