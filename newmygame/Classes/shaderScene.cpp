//
//  shaderScene.cpp
//  mygame
//
//  Created by WU XIAO on 2014-12-05.
//
//

#include "shaderScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* shaderScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = shaderScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool shaderScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    if(Constant::getInstance()->machineID==1){
        machineScale=0.5;
    }else{
        machineScale=1.0;
        
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(shaderScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                 origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    
    /*    Label *designInfoLabel;
     designInfoLabel = Label::createWithTTF("App", "Helvetica.ttf", 15, Size(545, 32), TextHAlignment::CENTER);*/
     if(Constant::getInstance()->extendEffect<Constant::getInstance()->extendEffectNo){
    MenuItemFont * shadertest=MenuItemFont::create("Next",CC_CALLBACK_1(shaderScene::menuBackCallback,this));
    menu = Menu::create(shadertest, NULL);
    shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
     }else{
         MenuItemFont * shadertest=MenuItemFont::create("Back",CC_CALLBACK_1(shaderScene::menuBackCallback,this));
         menu = Menu::create(shadertest, NULL);
         shadertest->setPosition(Point(visibleSize.width/4*2,visibleSize.height/6));
         menu->setPosition(Point::ZERO);
         this->addChild(menu, 1);
     
     }
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
 
    auto label = LabelTTF::create("Extension Shaders", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "shaderScene" splash screen"
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
    //auto topmidsprite = Sprite::create("shaderScene.png");
    topmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/4*3 + origin.y));
    setShader(topmidsprite,"gray.vsh","Blur.fsh");
    this->addChild(topmidsprite, 0);
    */
    auto midmidsprite = Sprite::create("HelloWorld.png");
    float winheightSize = Director::getInstance()->getWinSize().height;
    float  contentheightSize  = midmidsprite->getContentSize().height;
    float presentScale=winheightSize/contentheightSize;

    
    CCLOG("now flag:%d",Constant::getInstance()->extendEffect);
     CCLOG("now flag:%d",Constant::getInstance()->level);
    if(Constant::getInstance()->level==21){
        if(Constant::getInstance()->extendEffect==1){
        
        midmidsprite->setScale(presentScale,presentScale);
        loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "myWhite1.fsh",midmidsprite);
        midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(midmidsprite, 0);
        }else if(Constant::getInstance()->extendEffect==2){
            
            midmidsprite->setScale(presentScale,presentScale);
            loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "myWhite2.fsh",midmidsprite);
            midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(midmidsprite, 0);
            
        }
    }else if(Constant::getInstance()->level==22){
        if(Constant::getInstance()->extendEffect==1){
            midmidsprite->setScale(presentScale,presentScale);
            if(Constant::getInstance()->machineID==0){
            
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower1.fsh",midmidsprite);
            
            }else if(Constant::getInstance()->machineID==1){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower5s_1.fsh",midmidsprite);
            
            }else if(Constant::getInstance()->machineID==2){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower4s_1.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==3){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower1024_1.fsh",midmidsprite);
                
            }

            midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(midmidsprite, 0);
        }else if(Constant::getInstance()->extendEffect==2){
            
            midmidsprite->setScale(presentScale,presentScale);
            
            if(Constant::getInstance()->machineID==0){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==1){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower5s_2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==2){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower4s_2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==3){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "Flower1024_2.fsh",midmidsprite);
                
            }

            midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(midmidsprite, 0);
            
        }
    
    }else if(Constant::getInstance()->level==23){
        if(Constant::getInstance()->extendEffect==1){
            midmidsprite->setScale(presentScale,presentScale);
            
            if(Constant::getInstance()->machineID==0){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian1.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==1){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian5s_1.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==2){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian4s_1.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==3){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian1024_1.fsh",midmidsprite);
                
            }

            midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(midmidsprite, 0);
        }else if(Constant::getInstance()->extendEffect==2){
            
            midmidsprite->setScale(presentScale,presentScale);
            
            if(Constant::getInstance()->machineID==0){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==1){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian5s_2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==2){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian4s_2.fsh",midmidsprite);
                
            }else if(Constant::getInstance()->machineID==3){
                
                loadShader(cocos2d::ccPositionTextureColor_noMVP_vert, "zhatian1024_2.fsh",midmidsprite);
                
            }

            
            midmidsprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            this->addChild(midmidsprite, 0);
            
        }
        
    }
    
    /*auto downsprite = Sprite::create("shaderScene.png");
     downsprite->setPosition(Point(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
     setShader(downsprite,"randBlur.vsh","randBlur.fsh");
     this->addChild(downsprite, 0);
     
     
     auto sprite = Sprite::create("shaderScene.png");
     
     // position the sprite on the center of the screen
     setShader(sprite,"gray.vsh","gray.fsh");
     
     // add the sprite as a child to this layer
     sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     this->addChild(sprite, 0);
     
     //   change=CCMenuItemFont::create("change",this,CC_CALLBACK_1(shaderScene::languageCallback));
     
     //   this->addChild(menu, 1);
     */
    /*    CCMenuItemFont *change=CCMenuItemFont::create("change",this,menu_selector(shaderScene::menuBackCallback));
     change->setPosition(ccp(visibleSize.width/4*2,visibleSize.height/6*2));
     //  setup("example_Blur.fsh");
     CCMenu* pMenu = CCMenu::create(change, NULL);
     pMenu->setPosition(CCPointZero);
     this->addChild(pMenu, 1);*/
    
    return true;
}
/*
 void shaderScene::buildCustomUniforms()
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
/*void shaderScene::setShaderwithccPosition(Sprite * sprite,const char* frag)
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

/*void shaderScene::setBlur(Sprite * sprite)
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
void shaderScene::loadShader(const GLchar* vertexShader, const char* frag,Sprite * sprite)
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
void shaderScene::setShader(Sprite * sprite,const char* vert,const char* frag)
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
void shaderScene::menuBackCallback(Ref *pSender){
    
    if(Constant::getInstance()->extendEffect<Constant::getInstance()->extendEffectNo){
        Constant::getInstance()->extendEffect++;
        Scene *scene = Scene::create();
        shaderScene *layer = shaderScene::create();
        // add layer as a child to scene
        //graySprite(sprite);
        //setup("example_Blur.fsh",layer);
        scene->addChild(layer);
        Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
        
    }else{
        if(Constant::getInstance()->level==21){
            Scene *scene = Scene::create();
            Julia *layer = Julia::create();
            // add layer as a child to scene
            //graySprite(sprite);
            //setup("example_Blur.fsh",layer);
            scene->addChild(layer);
            Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
        }else if(Constant::getInstance()->level==22){
            Scene *scene = Scene::create();
            detailScene *layer = detailScene::create();
            // add layer as a child to scene
            //graySprite(sprite);
            //setup("example_Blur.fsh",layer);
            scene->addChild(layer);
            Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
        }else if(Constant::getInstance()->level==23){
            Scene *scene = Scene::create();
            laserShader *layer = laserShader::create();
            // add layer as a child to scene
            //graySprite(sprite);
            //setup("example_Blur.fsh",layer);
            scene->addChild(layer);
            Director::getInstance()->replaceScene(CCTransitionFlipX::create(0.5,scene));
        }
        
  
        
    }
    
    
}
void shaderScene::menuCloseCallback(Ref* pSender)
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
