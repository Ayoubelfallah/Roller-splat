#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"

class HelloWorldScene : public cocos2d::Layer
{
public:
    void update(float x);
    static cocos2d::Scene* createScene();
    float x, y;
    virtual bool init();

    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    bool Contact(cocos2d::PhysicsContact& contact);

  
  
    CREATE_FUNC(HelloWorldScene) ;

    cocos2d::Sprite* ball;
    cocos2d::Sprite* murgauche;
    cocos2d::Sprite* murdroit;
    cocos2d::Sprite* murhaut;
    cocos2d::Sprite* murbas;
    std::vector<cocos2d::Sprite*> surfacecomplet;
    cocos2d::Sprite* surfacecolor;    
    cocos2d::Sprite* Obstacledemap1;
    cocos2d::Sprite* Obstacledemap2;
    cocos2d::Sprite* Obstacledemap3;
    cocos2d::Sprite* Obstacledemap4;
    cocos2d::Sprite* Obsintern1;
    cocos2d::Sprite* Obsintern2;
    cocos2d::Sprite* Obsintern3;
    cocos2d::Sprite* Obsintern4;
};

#endif // __HELLOWORLD_SCENE_H__

















