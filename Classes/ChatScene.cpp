//
//  ChatScene.cpp
//  pomelo-cocos2dxchat-v3
//
//  Created by wangbin on 15/9/25.
//
//

#include "ChatScene.h"
#include "VisibleRect.h"

USING_NS_CC;

#define LINE_SPACE          50
#define TESTS_COUNT         5
#define FONT_NAME           "Thonburi"
#define FONT_SIZE           36
#define CHAT_LIMIT			20

std::string global_text[] =
{
    "Welcome To Pomelo Cocos2d-x Chat Demo",
    "This is a simple chat demo based on libpomelo and cocos2d-x",
    "You can send broadcast messages directly",
    "You can also send private message by @user at the head of your messages",
    "Enjoy with it"
};

static Point s_tCurPos = Vec2(0,0);
static int cur = 0;

Scene* Chat::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Chat::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chat::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Rect visibleRect = VisibleRect::getVisibleRect();
    m_tBeginPos = Vec2(0, VisibleRect::top().y - 50);
    
    //back button
    Label *backLabel = Label::createWithSystemFont("Back", "Arial", 15);
    void (*onBackCB)(Ref *ref) = &Chat::onBack;
    MenuItemLabel *pBackMenuItem = MenuItemLabel::create(backLabel, onBackCB);// const ccMenuCallback &callback
    Menu *pBackMenu = Menu::create(pBackMenuItem, NULL);
    pBackMenu->setAnchorPoint(Vec2(0,0));
    pBackMenu->setPosition(Vec2(VisibleRect::left().x + 35, VisibleRect::top().y - 20));
    addChild(pBackMenu, 10);
    
    Label *usersLabel = Label::createWithSystemFont("Users", "Arial", 15);
    MenuItemLabel *pUsersMenuItem = MenuItemLabel::create(usersLabel, Chat::onUsers);
    Menu *pUsersMenu = Menu::create(pUsersMenuItem, NULL);
    pUsersMenu->setAnchorPoint(Vec2(0,0));
    pUsersMenu->setPosition(Vec2(VisibleRect::right().x - 40, VisibleRect::top().y - 20));
    addChild(pUsersMenu, 10);
    
    Label *sendLabel = Label::createWithSystemFont("Send", "Arial", 15);
    MenuItemLabel *pSendMenuItem = MenuItemLabel::create(sendLabel, Chat::onSend);
    Menu *pSendMenu = Menu::create(pSendMenuItem, NULL);
    pSendMenu->setAnchorPoint(Vec2(0,0));
    pSendMenu->setPosition(Vec2(VisibleRect::right().x - 45, 25));
    addChild(pSendMenu, 10);
    
    channelText = Label::createWithSystemFont(s_channel.c_str(), "Arial", 25);
    channelText->setPosition(Vec2(VisibleRect::center().x, VisibleRect::top().y - 20));
    addChild(channelText, 10);
    
    m_layer = Layer::create();
    
    for (int i = 0; i < visibleRect.size.height / LINE_SPACE; ++i)
    {
        CCLabelTTF *label;
        if (i < TESTS_COUNT)
        {
            label = CCLabelTTF::create(global_text[i].c_str(), "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
        }
        else
        {
            label = CCLabelTTF::create("", "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
        }
        label->setColor(ccc3(32, 32, 32));
        label->setAnchorPoint(ccp(0, 0));
        label->setPosition(ccp(VisibleRect::left().x + 10, (m_tBeginPos.y - (i + 1) * LINE_SPACE) ));
        m_layer->addChild(label, 10, i);
    }
    
    m_layer->setContentSize(CCSizeMake(VisibleRect::getVisibleRect().size.width - 30, (TESTS_COUNT + 1) * (LINE_SPACE)));
    m_layer->setPosition(s_tCurPos);
    addChild(m_layer, 2);
    
    setTouchEnabled(true);
    
    CCLayerColor *layer1 = CCLayerColor::create(ccc4(255, 255, 255, 255), visibleRect.size.width, visibleRect.size.height);
    layer1->setCascadeColorEnabled(false);
    layer1->setPosition(ccp(0, 0));
    addChild(layer1, 1);
    
    CCLayerColor *layer2 = CCLayerColor::create(ccc4(0, 0, 0, 255), visibleRect.size.width, 40);
    layer2->setCascadeColorEnabled(false);
    layer2->setPosition(ccp(0, VisibleRect::top().y - 40));
    addChild(layer2, 8);
    
    CCLayerColor *layer3 = CCLayerColor::create(ccc4(72, 72, 72, 255), visibleRect.size.width, 50);
    layer3->setCascadeColorEnabled(false);
    layer3->setPosition(ccp(0, 0));
    addChild(layer3, 8);
    
    m_pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("",
                                                            FONT_NAME,
                                                            FONT_SIZE);
    m_pTextField->setAnchorPoint(CCPointZero);
    m_pTextField->setPosition(ccp(VisibleRect::left().x + 10, 5));
    addChild(m_pTextField, 12);
    
    m_pTextField->setDelegate(this);
    
    return true;
}

void Chat::onBack(Ref *pSender) {
    CCLOG(">>>>>>on back callback");
}

void Chat::onUsers(Ref *pSender) {
    CCLOG(">>>>>>on users callback");
}

void Chat::onSend(Ref *pSender) {
    CCLOG(">>>>>>on send callback");
}

