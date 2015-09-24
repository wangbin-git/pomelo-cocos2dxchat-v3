//
//  LoginScene.hpp
//  pomelo-cocos2dxchat-v3
//
//  Created by wangbin on 15/9/24.
//
//

#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class Login : public cocos2d::Layer, public cocos2d::ui::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    static void onLogin(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Login);
    
private:
    cocos2d::ui::EditBox *m_pEditBoxName;
    cocos2d::ui::EditBox *m_pEditBoxChannel;
};

#endif
