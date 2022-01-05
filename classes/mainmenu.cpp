#include "mainmenu.h"
#include "cocos2d.h"

#include "HelloWorldScene.h" 
USING_NS_CC;


Scene* mainmenu::createScene()
{
    auto Scene = Scene::create();
    auto layer = mainmenu::create();
    Scene->addChild(layer);
    return Scene;

}
bool mainmenu::init() {
    if (!Layer::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("titre.png", "titre.png");
    auto playItem = MenuItemImage::create("play.png", "play.png", CC_CALLBACK_1(mainmenu::GotoHelloWorldScene, this));
    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 10);
    this->addChild(menu);
}

void mainmenu::GotoHelloWorldScene(cocos2d::Ref *pSender)
{
    auto scene = HelloWorldScene::createScene();
    Director::getInstance()->replaceScene(scene);
}