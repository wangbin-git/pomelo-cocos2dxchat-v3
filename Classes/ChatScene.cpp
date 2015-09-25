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
//    CCLabelTTF *backLabel = CCLabelTTF::create("Back", "Arial", 25);
//    CCMenuItemLabel *pBackMenuItem = CCMenuItemLabel::create(backLabel, this, menu_selector(Chat::backCallback));
//    CCMenu *pBackMenu = CCMenu::create(pBackMenuItem, NULL);
//    pBackMenu->setAnchorPoint(CCPointZero);
//    pBackMenu->setPosition(ccp(VisibleRect::left().x + 35, VisibleRect::top().y - 20));
//    addChild(pBackMenu, 10);
//    
//    CCLabelTTF *userLabel = CCLabelTTF::create("Users", "Arial", 25);
//    CCMenuItemLabel *pUserMenuItem = CCMenuItemLabel::create(userLabel, this, menu_selector(Chat::userCallback));
//    CCMenu *pUserMenu = CCMenu::create(pUserMenuItem, NULL);
//    pUserMenu->setAnchorPoint(CCPointZero);
//    pUserMenu->setPosition(ccp(VisibleRect::right().x - 40, VisibleRect::top().y - 20));
//    addChild(pUserMenu, 10);
//    
//    CCLabelTTF *sendLabel = CCLabelTTF::create("Send", "Arial", 25);
//    CCMenuItemLabel *pSendMenuItem = CCMenuItemLabel::create(sendLabel, this, menu_selector(Chat::sendCallback));
//    CCMenu *pSendMenu = CCMenu::create(pSendMenuItem, NULL);
//    pSendMenu->setAnchorPoint(CCPointZero);
//    pSendMenu->setPosition(ccp(VisibleRect::right().x - 45, 25));
//    addChild(pSendMenu, 10);
//    
//    channelText = CCLabelTTF::create(s_channel.c_str(), "Arial", 25);
//    channelText->setPosition(ccp(VisibleRect::center().x, VisibleRect::top().y - 20));
//    addChild(channelText, 10);
//    
//    m_layer = CCLayer::create();
//    
//    for (int i = 0; i < visibleRect.size.height / LINE_SPACE; ++i)
//    {
//        CCLabelTTF *label;
//        if (i < TESTS_COUNT)
//        {
//            label = CCLabelTTF::create(global_text[i].c_str(), "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
//        }
//        else
//        {
//            label = CCLabelTTF::create("", "Arial", 23, CCSizeMake(visibleRect.size.width, 50), kCCTextAlignmentLeft);
//        }
//        label->setColor(ccc3(32, 32, 32));
//        label->setAnchorPoint(ccp(0, 0));
//        label->setPosition(ccp(VisibleRect::left().x + 10, (m_tBeginPos.y - (i + 1) * LINE_SPACE) ));
//        m_layer->addChild(label, 10, i);
//    }
//    
//    m_layer->setContentSize(CCSizeMake(VisibleRect::getVisibleRect().size.width - 30, (TESTS_COUNT + 1) * (LINE_SPACE)));
//    m_layer->setPosition(s_tCurPos);
//    addChild(m_layer, 2);
//    
//    setTouchEnabled(true);
//    
//    CCLayerColor *layer1 = CCLayerColor::create(ccc4(255, 255, 255, 255), visibleRect.size.width, visibleRect.size.height);
//    layer1->setCascadeColorEnabled(false);
//    layer1->setPosition(ccp(0, 0));
//    addChild(layer1, 1);
//    
//    CCLayerColor *layer2 = CCLayerColor::create(ccc4(0, 0, 0, 255), visibleRect.size.width, 40);
//    layer2->setCascadeColorEnabled(false);
//    layer2->setPosition(ccp(0, VisibleRect::top().y - 40));
//    addChild(layer2, 8);
//    
//    CCLayerColor *layer3 = CCLayerColor::create(ccc4(72, 72, 72, 255), visibleRect.size.width, 50);
//    layer3->setCascadeColorEnabled(false);
//    layer3->setPosition(ccp(0, 0));
//    addChild(layer3, 8);
//    
//    m_pTextField = CCTextFieldTTF::textFieldWithPlaceHolder("",
//                                                            FONT_NAME,
//                                                            FONT_SIZE);
//    m_pTextField->setAnchorPoint(CCPointZero);
//    m_pTextField->setPosition(ccp(VisibleRect::left().x + 10, 5));
//    addChild(m_pTextField, 12);
//    
//    m_pTextField->setDelegate(this);
    
    return true;
}

