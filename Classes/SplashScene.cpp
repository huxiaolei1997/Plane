#include "cocos2d.h"
#include "SplashScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "resource.h"

USING_NS_CC;
using namespace std;;

Scene * SplashScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

bool SplashScene::init()
{
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getWinSize();

	//TTFConfig config("fonts/Marker Felt.ttf", 100);

	auto GameName = Label::createWithTTF("椋炴満澶ф垬", FONT_TYPE, 50);
	GameName->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(GameName);

	auto GameAuthor = Label::createWithTTF("GAME BY XIAOLEIHU", FONT_TYPE, 50);
	GameAuthor->setPosition(Point(size.width / 2, size.height / 3));
	GameAuthor->setScale(0.3);
	this->addChild(GameAuthor);

	//start button
	//MenuItemImage *startBtn = MenuItemImage::create(START_BTN, START_BTN_PRESSED, CC_CALLBACK_1(SplashScene::jumpToGame, this));
	auto startBtn = MenuItemImage::create(START_BTN, START_BTN_PRESSED,
		CC_CALLBACK_1(SplashScene::jumpToGame, this));

	auto menu = Menu::create(startBtn, NULL);
	menu->setTag(TAG_START_BTN);
	menu->setPosition(Point(size.width / 2, size.height / 4));
	//this->addChild(menu, 1);
	//auto start = MenuItemImage::create("", "", CC_CALLBACK_1(SplashScene::jumpToGame, this));
	//auto menu = Menu::create(startBtn, NULL);
	this->addChild(menu);

	//this->scheduleOnce(schedule_selector(SplashScene::jumpToGame), 1);

	return true;
}

void SplashScene::jumpToGame(cocos2d::Ref* pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(CCTransitionFade::create(2, scene));
	this->getChildByTag(TAG_START_BTN)->setVisible(false);
}