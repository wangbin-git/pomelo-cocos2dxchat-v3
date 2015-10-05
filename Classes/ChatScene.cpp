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

#define LINE_SPACE          10
#define TESTS_COUNT         5
#define FONT_NAME           "Arial"
#define FONT_SIZE           10
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
    m_tBeginPos = Vec2(0, VisibleRect::top().y);
    
    //back button
    Label *backLabel = Label::createWithSystemFont("Back", "Arial", 10);
    void (*onBackCB)(Ref *ref) = &Chat::onBack;
    MenuItemLabel *pBackMenuItem = MenuItemLabel::create(backLabel, onBackCB);// const ccMenuCallback &callback
    Menu *pBackMenu = Menu::create(pBackMenuItem, NULL);
    pBackMenu->setAnchorPoint(Vec2(0, 0));
    pBackMenu->setPosition(Vec2(VisibleRect::left().x + 20, VisibleRect::top().y - 5));
    //addChild(pBackMenu, 10);
    
    Label *usersLabel = Label::createWithSystemFont("Users", "Arial", 10);
    MenuItemLabel *pUsersMenuItem = MenuItemLabel::create(usersLabel, Chat::onUsers);
    Menu *pUsersMenu = Menu::create(pUsersMenuItem, NULL);
    pUsersMenu->setAnchorPoint(Vec2(0, 0));
    pUsersMenu->setPosition(Vec2(VisibleRect::right().x - 20, VisibleRect::top().y - 5));
    //addChild(pUsersMenu, 10);
    
    Label *sendLabel = Label::createWithSystemFont("Send", "Arial", 10);
    MenuItemLabel *pSendMenuItem = MenuItemLabel::create(sendLabel, Chat::onSend);
    Menu *pSendMenu = Menu::create(pSendMenuItem, NULL);
    pSendMenu->setAnchorPoint(Vec2(0, 0));
    pSendMenu->setPosition(Vec2(VisibleRect::right().x - 20, 10));
    //addChild(pSendMenu, 10);
    
    channelText = Label::createWithSystemFont(s_channel.c_str(), "Arial", 10);
    channelText->setPosition(Vec2(VisibleRect::center().x, VisibleRect::top().y - 20));
    //addChild(channelText, 10);
    
    m_layer = Layer::create();
    
    for (int i = 0; i < visibleRect.size.height / LINE_SPACE; ++i)
    {
        Label *label;
        if (i < TESTS_COUNT)
        {
            //label = CCLabelTTF::create(global_text[i].c_str(), "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
            label = Label::createWithSystemFont(global_text[i].c_str(), "Arial", 5);
        }
        else
        {
            //label = CCLabelTTF::create("", "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
            label = Label::createWithSystemFont("", "Arial", 5);
        }
        label->setColor(Color3B(32, 32, 32));
        label->setAnchorPoint(Vec2(0, 0));
        label->setPosition(Vec2(VisibleRect::left().x + 2, (m_tBeginPos.y - (i + 1) * LINE_SPACE)));
        //m_layer->addChild(label, 10, i);
    }
    
    m_layer->setContentSize(Size(VisibleRect::getVisibleRect().size.width, (TESTS_COUNT + 1) * (LINE_SPACE)));
    m_layer->setPosition(s_tCurPos);
    addChild(m_layer, 2);
    
    setTouchEnabled(true);
    
    LayerColor *layer1 = LayerColor::create(Color4B(255, 255, 0, 255), visibleRect.size.width, visibleRect.size.height);
    layer1->setCascadeColorEnabled(false);
    layer1->setPosition(Vec2(0, 0));
    addChild(layer1, 1);
//
//    LayerColor *layer2 = LayerColor::create(Color4B(255, 0, 0, 255), visibleRect.size.width, 40);
//    layer2->setCascadeColorEnabled(false);
//    layer2->setPosition(Vec2(0, VisibleRect::top().y - 40));
//    addChild(layer2, 8);
//    
//    LayerColor *layer3 = LayerColor::create(Color4B(72, 255, 72, 255), visibleRect.size.width, 50);
//    layer3->setCascadeColorEnabled(false);
//    layer3->setPosition(Vec2(0, 0));
//    addChild(layer3, 8);
    
    m_pTextField = TextFieldTTF::textFieldWithPlaceHolder("input message", FONT_NAME, FONT_SIZE);
    m_pTextField->setAnchorPoint(Vec2(0, 0));
    m_pTextField->setPosition(Vec2(VisibleRect::left().x, 5));
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



bool Chat::onTextFieldAttachWithIME(TextFieldTTF *pSender)
{
    CCLOG("onTextFieldAttachWithIME");
    return false;
}

bool Chat::onTextFieldDetachWithIME(TextFieldTTF *pSender)
{
    CCLOG("onTextFieldDetachWithIME");
    return false;
}

bool Chat::onTextFieldInsertText(TextFieldTTF *pSender, const char *text, int nLen)
{
    // if insert enter, treat as default to detach with ime
    if ('\n' == *text)
    {
        //this->sendCallback(NULL);
        return false;
    }
    
    // if the textfield's char count more than m_nCharLimit, doesn't insert text anymore.
    if (pSender->getCharCount() >= CHAT_LIMIT)
    {
        return true;
    }
    
    return false;
}

bool Chat::onTextFieldDeleteBackward(TextFieldTTF *pSender, const char *delText, int nLen)
{
    return false;
}
