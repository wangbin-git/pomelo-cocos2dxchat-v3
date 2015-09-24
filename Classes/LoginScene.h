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

class MLogin : public cocos2d::Layer, public cocos2d::ui::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    static void onLogin(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MLogin);
    
    
    virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);
    
private:
    cocos2d::ui::EditBox *m_pEditBoxName;
    cocos2d::ui::EditBox *m_pEditBoxChannel;
};

#endif
