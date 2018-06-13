#include "cocos2d.h"
#include "SplashScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "resource.h"
#include "extensions\cocos-ext.h"  
USING_NS_CC_EXT;

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

	auto GameName = Label::createWithTTF("飞机大战", FONT_TYPE, 50);
	GameName->setPosition(Point(size.width / 2, size.height / 2));
	this->addChild(GameName);

	auto GameAuthor = Label::createWithTTF("GAME BY XIAOLEIHU", FONT_TYPE, 50);
	GameAuthor->setPosition(Point(size.width / 2, size.height / 3));
	GameAuthor->setScale(0.3);
	this->addChild(GameAuthor);

	//璐﹀彿妗?璁剧疆杈撳叆8涓瓧绗? 
	auto editbox1 = EditBox::create(Size(200, 35), Scale9Sprite::create("editbox.png"));
	editbox1->setAnchorPoint(Point(0, 0));
	editbox1->setPosition(Point(size.width *0.3, size.height*0.55));
	editbox1->setPlaceHolder("name:");//鍗犱綅瀛楃  
	editbox1->setMaxLength(8);
	editbox1->setFontColor(Color3B::BLACK);//璁剧疆杈撳叆瀛椾綋鐨勯鑹? 
	editbox1->setTag(222);
	this->addChild(editbox1, 2);
	//瀵嗙爜妗?password  
	auto editbox2 = EditBox::create(Size(200, 35), Scale9Sprite::create("editbox.png"));
	editbox2->setAnchorPoint(Point(0, 0));
	editbox2->setPosition(Point(size.width *0.3, size.height*0.4));
	editbox2->setPlaceHolder("mima:");
	editbox2->setPlaceholderFontColor(Color3B::RED);//璁剧疆鍗犱綅瀛椾綋鐨勯鑹? 
	editbox2->setFontColor(Color3B::BLACK);
	editbox2->setInputMode(EditBox::InputMode::NUMERIC);//璁剧疆杈撳叆绫诲瀷 鏁板瓧鍙婄壒娈婄鍙疯緭鍏? 
	editbox2->setInputFlag(EditBox::InputFlag::PASSWORD);//璁剧疆杈撳叆鏍囧織 瀵嗙爜杈撳叆鏍囧織锛堟樉绀轰负*锛? 
	editbox2->setMaxLength(8);
	editbox2->setTag(333);
	this->addChild(editbox2, 2);

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