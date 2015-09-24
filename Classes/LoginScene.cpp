//
//  LoginScene.cpp
//  pomelo-cocos2dxchat-v3
//
//  Created by wangbin on 15/9/24.
//
//

#include "LoginScene.h"

USING_NS_CC;

Scene* Login::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Login::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Login::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    
    auto glview = Director::getInstance()->getOpenGLView();
    Point visibleOrigin = glview->getVisibleOrigin();
    Size visibleSize = glview->getVisibleSize();
    Size editBoxSize = Size(visibleSize.width - 100, 60);
    m_pEditBoxName = cocos2d::ui::EditBox::create(editBoxSize, cocos2d::ui::Scale9Sprite::create("green_edit.png"));
    m_pEditBoxName->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height * 3 / 4));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pEditBoxName->setFont("Paint Boy", 25);
#else
    m_pEditBoxName->setFont("Arial", 25);
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
    m_pEditBoxChannel->setFont("Paint Boy", 25);
#else
    m_pEditBoxChannel->setFont("Arial", 25);
#endif
    m_pEditBoxChannel->setFontColor(Color3B::BLACK);
    m_pEditBoxChannel->setPlaceHolder("Channel:");
    m_pEditBoxChannel->setPlaceholderFontColor(Color3B::WHITE);
    m_pEditBoxChannel->setMaxLength(8);
    m_pEditBoxChannel->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    m_pEditBoxChannel->setDelegate(this);
    this->addChild(m_pEditBoxChannel, 2);
    
    Label *label = Label::createWithSystemFont("Login", "Arial", 50);

    void (*onloginCB)(Ref *ref) = &Login::onLogin;
    
    MenuItemLabel *pMenuItem = MenuItemLabel::create(label, onloginCB);// const ccMenuCallback &callback
    Menu *pMenu = Menu::create(pMenuItem, NULL);
    pMenu->setPosition(Vec2(0,0));
    pMenuItem->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, visibleOrigin.y + visibleSize.height / 4));
    this->addChild(pMenu, 1);
    
    Label *pLabel = Label::createWithSystemFont("pomelo-cocos2dchat", "Arial", 30);
    Size size = Director::getInstance()->getWinSize();
    pLabel->setPosition(Vec2(size.width / 2, size.height - 30));
    this->addChild(pLabel, 1);
        
    return true;
}


void Login::onLogin(Ref *pSender)
{
    CCLOG(">>>>>>on login\n");

}