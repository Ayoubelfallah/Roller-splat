#pragma once
#include "cocos2d.h"
#include "Menu.h"
#ifndef __main_menu_H__
#define __main_menu_H__
class mainmenu:public::cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(mainmenu);
    void GotoHelloWorldScene(Ref* pSender);

};

#endif // __main_menu_H__