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

class Chat: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Chat);
    
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
