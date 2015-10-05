//
//  LoginScene.cpp
//  pomelo-cocos2dxchat-v3
//
//  Created by wangbin on 15/9/24.
//
//

#include "LoginScene.h"
#include "ChatScene.h"
USING_NS_CC;

static std::string username = "";
static std::string channel = "";

Scene* MLogin::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MLogin::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MLogin::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    
    Point visibleOrigin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size editBoxSize = Size(visibleSize.width - 20, 20);
    m_pEditBoxName = cocos2d::ui::EditBox::create(editBoxSize, cocos2d::ui::Scale9Sprite::create("green_edit.png"));
    m_pEditBoxName->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height * 3 / 4));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pEditBoxName->setFont("Paint Boy", 15);
#else
    m_pEditBoxName->setFont("Arial", 15);
#endif
    m_pEditBoxName->setFontColor(Color3B::BLACK);
    m_pEditBoxName->setPlaceHolder("Name:");
    m_pEditBoxName->setPlaceholderFontColor(Color3B::WHITE);
    m_pEditBoxName->setMaxLength(8);
    m_pEditBoxName->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    m_pEditBoxName->setDelegate(this);
    this->addChild(m_pEditBoxName, 1);
    
    m_pEditBoxChannel = cocos2d::ui::EditBox::create(editBoxSize, cocos2d::ui::Scale9Sprite::create("green_edit.png"));
    m_pEditBoxChannel->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 2));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pEditBoxChannel->setFont("Paint Boy", 15);
#else
    m_pEditBoxChannel->setFont("Arial", 15);
#endif
    m_pEditBoxChannel->setFontColor(Color3B::BLACK);
    m_pEditBoxChannel->setPlaceHolder("Channel:");
    m_pEditBoxChannel->setPlaceholderFontColor(Color3B::WHITE);
    m_pEditBoxChannel->setMaxLength(8);
    m_pEditBoxChannel->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    m_pEditBoxChannel->setDelegate(this);
    this->addChild(m_pEditBoxChannel, 2);
    
    Label *label = Label::createWithSystemFont("Login", "Arial", 20);

    void (*onloginCB)(Ref *ref) = &MLogin::onLogin;
    
    MenuItemLabel *pMenuItem = MenuItemLabel::create(label, onloginCB);// const ccMenuCallback &callback
    Menu *pMenu = Menu::create(pMenuItem, NULL);
    pMenu->setPosition(Vec2(0,0));
    pMenuItem->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 4));
    this->addChild(pMenu, 1);
    
    Label *pLabel = Label::createWithSystemFont("pomelo-cocos2dchat", "Arial", 10);
    Size size = Director::getInstance()->getWinSize();
    pLabel->setPosition(Vec2(size.width / 2, size.height - 30));
    this->addChild(pLabel, 1);
        
    return true;
}


void MLogin::onEnter()
{
    Layer::onEnter();
    CCLOG("Login onEnter");
    
    Director::getInstance()->getScheduler()->schedule(schedule_selector(MLogin::dispatchLoginCallbacks), this, 0, false);
}

void MLogin::dispatchLoginCallbacks(float delta)
{
    
    //CCDirector::sharedDirector()->getScheduler()->pauseTarget(this);
    Director::getInstance()->getScheduler()->pauseTarget(this);
    //CCScene* pScene = CCScene::create();
    Scene *pScene = Scene::create();
    Chat* pLayer = new Chat();
//    pLayer->setChannel(channel);
//    pLayer->setUser(username);
//    pLayer->setClient(pomelo_client);
//    pLayer->setUserQueue(userQueue);
//    pLayer->setMessageQueue(messageQueue);
    
    CCLOG("init player");
    if(pLayer && pLayer->init()) {
        //pLayer->autorelease();
        pScene->addChild(pLayer);
        CCLOG("director replaceScene");
        Director::getInstance()->replaceScene(TransitionFade::create(1, pScene));
        //CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1, pScene));
    } else {
        delete pLayer;
        pLayer = NULL;
    }
}

void MLogin::onLogin(Ref *pSender)
{
    CCLOG(">>>>>>on login\n");
}


void MLogin::editBoxEditingDidBegin(cocos2d::ui::EditBox *editBox)
{
    CCLOG("editBox %p DidBegin !", editBox);
}

void MLogin::editBoxEditingDidEnd(cocos2d::ui::EditBox *editBox)
{
    CCLOG("editBox %p DidEnd !", editBox);
}

void MLogin::editBoxTextChanged(cocos2d::ui::EditBox *editBox, const std::string &text)
{
    if (editBox == m_pEditBoxName) {
        username = text;
        CCLOG("name editBox %p TextChanged, text: %s ", editBox, text.c_str());
    } else {
        channel = text;
        CCLOG("channel editBox %p TextChanged, text: %s ", editBox, text.c_str());
    }
}

void MLogin::editBoxReturn(cocos2d::ui::EditBox *editBox)
{
    CCLOG("editBox %p was returned !", editBox);
}