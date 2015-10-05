//
//  ChatScene.h
//  pomelo-cocos2dxchat-v3
//
//  Created by wangbin on 15/9/25.
//
//

#ifndef __CHAT_SCENE_H__
#define __CHAT_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class Chat: public cocos2d::Layer, public cocos2d::TextFieldDelegate
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    static void onBack(Ref *pSender);
    static void onUsers(Ref *pSender);
    static void onSend(Ref *pSender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(Chat);
    
    virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * pSender);
    virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * pSender);
    virtual bool onTextFieldInsertText(cocos2d::TextFieldTTF * pSender, const char * text, int nLen);
    virtual bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF * pSender, const char * delText, int nLen);
    
private:
    cocos2d::Point m_tBeginPos;
    cocos2d::Menu *m_pItemMenu;
    cocos2d::Layer* m_layer;
    cocos2d::TextFieldTTF* m_pTextField;
    cocos2d::Label* m_pTTFShowEditReturn;
    cocos2d::ui::EditBox* m_pEditName;
    cocos2d::Label* channelText;
    std::string s_text;
    std::string s_channel;
    std::string s_user;
};

#endif /* __CHATSCENE_H__ */
