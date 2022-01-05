#include "HelloWorldScene.h" 
#include "mainmenu.h"
#include "cocos2d.h"
#include "Menu.h"
USING_NS_CC;

Scene* HelloWorldScene::createScene()
{
    auto scene = Scene::createWithPhysics();//creation dy scene
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));// ajout de gravite 
    auto layer = HelloWorldScene::create(); //creation de layer
    scene->addChild(layer);
    return scene;
}


bool buttongauche = false;
bool buttondroit = false;
bool buttonhaut = false;
bool buttonbas = false;
bool ismoving = false;
bool HelloWorldScene::init()//
{
    
    if (!Layer::init())
    {
        return false;
    }
     // implementation des fonctions cocos pour recuperer la taille et l origine
    auto Size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();  
          
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++)
        {
            surfacecolor= Sprite::create("obs11.png");
            surfacecolor->setPosition(Vec2(2.82 * Size.width / 7 + j * 22.8, Size.height / 4.1 + i * 23.5));
            this->addChild(surfacecolor, 1);
            surfacecomplet.push_back(surfacecolor);
        
        }
    }
  
    ball = Sprite::create("hh.png");
    ball->setScale(0.1);
    auto static Ballon = PhysicsBody::createCircle(ball->getContentSize().width / 2.2);
    Ballon->setCollisionBitmask(1);
    Ballon->setContactTestBitmask(true);
    ball->setPhysicsBody(Ballon);
    this->addChild(ball, 1);
    
    murgauche= Sprite::create("hj.png");
    auto murgtouch = PhysicsBody::createBox(murgauche->getContentSize());
    murgtouch->setCollisionBitmask(2.2);
    murgtouch->setContactTestBitmask(true);
    murgauche->setPosition(Point((Size.width / 7) + origin.x, (Size.height / 2) + origin.y));
    this->addChild(murgauche, 1);
    if (murgtouch != nullptr)
    {
        murgtouch->setDynamic(false);
        murgauche->setPhysicsBody(murgtouch);
    }


    
    


   
   murdroit = Sprite::create("frame.png");
    auto murdtouch = PhysicsBody::createBox(murdroit->getContentSize());
    murdtouch->setCollisionBitmask(2);
    murdtouch->setContactTestBitmask(true);
    murdroit->setPosition(Point((3.28 * Size.width / 4.05) + origin.x, (Size.height / 2) + origin.y));
    this->addChild(murdroit, 1);
    if (murdtouch != nullptr)
    {
        murdtouch->setDynamic(false);
        murdroit->setPhysicsBody(murdtouch);
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    murhaut = Sprite::create("cv.png");
    auto murhtouch = PhysicsBody::createBox(murhaut->getContentSize());
    murhtouch->setCollisionBitmask(2);
    murhtouch->setContactTestBitmask(true);
    murhaut->setPosition(Point((Size.width / 2.1) + origin.x, (3.32 * Size.height / 4.1) + origin.y));
    this->addChild(murhaut, 1);
    if (murhtouch != nullptr)
    {
        murhtouch->setDynamic(false);
        murhaut->setPhysicsBody(murhtouch);
    }
    


    


    murbas = Sprite::create("xxx.png");
    auto murbastouch = PhysicsBody::createBox(murbas->getContentSize());
    murbastouch->setCollisionBitmask(2);
    murbastouch->setContactTestBitmask(true);
    if (murbastouch != nullptr)
    {
        murbastouch->setDynamic(false);
        murbas->setPhysicsBody(murbastouch);
    }
    murbas->setPosition(Point((Size.width / 2.1) + origin.x, (Size.height / 5.4) + origin.y));
    this->addChild(murbas, 1);
    
    Obstacledemap1 = Sprite::create("obss.png");
    auto  Obstacledemap1touch = PhysicsBody::createBox(Obstacledemap1->getContentSize());
    Obstacledemap1touch->setCollisionBitmask(2);
    Obstacledemap1touch->setContactTestBitmask(true);
    Obstacledemap1touch->setDynamic(false);
    Obstacledemap1->setPhysicsBody(Obstacledemap1touch);
    Obstacledemap1->setPosition(Point((Size.width / 5) + origin.x, (Size.height / 1.7) + origin.y));
    this->addChild(Obstacledemap1, 1);

    
    Obstacledemap2 = Sprite::create("obss.png");
    auto Obstacledemap2touch = PhysicsBody::createBox(Obstacledemap2->getContentSize());
    Obstacledemap2touch->setCollisionBitmask(2);
    Obstacledemap2touch->setContactTestBitmask(true);
    Obstacledemap2touch->setDynamic(false);
    Obstacledemap2->setPhysicsBody(Obstacledemap2touch);
    Obstacledemap2->setPosition(Point((Size.width / 1.5) + origin.x, (Size.height / 4.39) + origin.y));
    this->addChild(Obstacledemap2, 2);


  
    
    Obstacledemap3 = Sprite::create("obss.png");
    auto Obstacledemap3touch = PhysicsBody::createBox(Obstacledemap3->getContentSize());
    Obstacledemap3touch->setCollisionBitmask(2);
    Obstacledemap3touch->setContactTestBitmask(true);
    Obstacledemap3touch->setDynamic(false);
    Obstacledemap3->setPhysicsBody(Obstacledemap3touch);
    Obstacledemap3->setPosition(Point((Size.width / 2) + origin.x, (Size.height / 1.3) + origin.y));
    this->addChild(Obstacledemap3, 2);

  


 
    Obstacledemap4 = Sprite::create("obss.png");
    auto Obstacledemap4touch = PhysicsBody::createBox(Obstacledemap4->getContentSize());
    Obstacledemap4touch->setCollisionBitmask(2);
    Obstacledemap4touch->setContactTestBitmask(true);
    Obstacledemap4touch->setDynamic(false);
    Obstacledemap4->setPhysicsBody(Obstacledemap4touch);
    Obstacledemap4->setPosition(Point((Size.width / 1.3) + origin.x, (Size.height / 1.8) + origin.y));
    this->addChild(Obstacledemap4, 2);

   
    


    Obsintern1 = Sprite::create("obsintern.png");
    auto Obsintern1touch = PhysicsBody::createBox(Obsintern1 ->getContentSize());
    Obsintern1touch->setCollisionBitmask(2);
    Obsintern1touch->setContactTestBitmask(true);
    Obsintern1touch->setDynamic(false);
    Obsintern1 ->setPhysicsBody(Obsintern1touch);
    Obsintern1 ->setPosition(Point((Size.width / 1.5) + origin.x, (Size.height /2.6) + origin.y));
    this->addChild(Obsintern1, 1);


    

    
    Obsintern2 = Sprite::create("obsintern.png");
    auto Obsintern2touch = PhysicsBody::createBox(Obsintern2->getContentSize());
    Obsintern2touch->setCollisionBitmask(2);
    Obsintern2touch->setContactTestBitmask(true);
    Obsintern2touch->setDynamic(false);
    Obsintern2->setPhysicsBody(Obsintern2touch);
    Obsintern2->setPosition(Point((Size.width / 2.7) + origin.x, (Size.height / 1.5) + origin.y));
    this->addChild(Obsintern2, 1);
    
    
    Obsintern3 = Sprite::create("obsintern.png");
    auto Obsintern3touch = PhysicsBody::createBox(Obsintern3->getContentSize());
    Obsintern3touch->setCollisionBitmask(2);
    Obsintern3touch->setContactTestBitmask(true);
    Obsintern3touch->setDynamic(false);
    Obsintern3->setPhysicsBody(Obsintern3touch);
    Obsintern3->setPosition(Point((Size.width / 2.5) + origin.x, (Size.height / 2.6) + origin.y));
    this->addChild(Obsintern3, 1);

    
    
    Obsintern4 = Sprite::create("obsintern.png");
    auto Obsintern4touch = PhysicsBody::createBox(Obsintern4->getContentSize());
    Obsintern4touch->setCollisionBitmask(2);
    Obsintern4touch->setContactTestBitmask(true);
    Obsintern4touch->setDynamic(false);
    Obsintern4->setPhysicsBody(Obsintern4touch);
    Obsintern4->setPosition(Point((Size.width / 1.6) + origin.x, (Size.height / 1.5) + origin.y));
    this->addChild(Obsintern4, 1);

   
    
   
    for (auto i = 0; i < surfacecomplet.size(); i++)
    {
        auto static position = surfacecomplet[0]->getPosition();
        ball->setPosition(position);
    }

    this->scheduleUpdate();
   

   

  
 
    

  
   
   
   
    
 
  


    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = CC_CALLBACK_2(HelloWorldScene::keyPressed, this);
    eventListener->onKeyReleased = CC_CALLBACK_2(HelloWorldScene::keyReleased, this);

    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
        if (ismoving == false)
        {


            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
           
                while (buttongauche == false)
                {

                    Ballon->setVelocity(Vec2(-250, 0));
                    ismoving = true;                                                     
                    buttongauche = true;
                    buttondroit = false;
                    buttonhaut = false;
                    buttonbas = false;

                }
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
           
                while (buttondroit == false)
                {


                    Ballon->setVelocity(Vec2(250, 0));
                    ismoving = true;
                    buttondroit = true;


                    buttongauche = false;
                    buttonhaut = false;
                    buttonbas = false;

                }
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
          
                while (buttonhaut == false)
                {


                    Ballon->setVelocity(Vec2(0, 250));
                    ismoving = true;
                    buttonhaut = true;


                    buttondroit = false;
                    buttongauche = false;
                    buttonbas = false;
                 

                }
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
          
                while (buttonbas == false)
                {


                    Ballon->setVelocity(Vec2(0, -250));
                    ismoving = true;
                    buttonbas = true;


                    buttondroit = false;
                    buttongauche = false;
                   buttonhaut = false;
                  

                }
                break;

            }
        }


    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, ball);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorldScene::Contact, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
   
   
          
}



bool HelloWorldScene::Contact(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* x = contact.getShapeA()->getBody();
    PhysicsBody* y = contact.getShapeB()->getBody();
    
    
    if ((1 == x->getCollisionBitmask() && 2 == y->getCollisionBitmask()) || (2 == x->getCollisionBitmask() && 1 == y->getCollisionBitmask()))
    {
        ball->getPhysicsBody()->setVelocity(Vec2(0, 0));
        ismoving = false;

    }
   
    return true;
}

void HelloWorldScene::update(float x) {
       
    for (auto carre : surfacecomplet) {
        Rect rectangle1 = ball->getBoundingBox();
        Rect rectangle2 = carre->getBoundingBox();
        if (rectangle1.intersectsRect(rectangle2))
        {
            carre->setColor(Color3B(255, 255, 0));
        }
    }
  
}  
void HelloWorldScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {}

void HelloWorldScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {}
