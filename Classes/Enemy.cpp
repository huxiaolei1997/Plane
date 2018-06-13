#include "Enemy.h"
#include "resource.h"

USING_NS_CC;

Enemy* Enemy::create()
{
	Enemy* pRet = new Enemy();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool Enemy::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Sprite* sprite;

	// n为0到9之间的一个数
	int n = rand() % 10;
	if (n >= 6)
	{
		sprite = Sprite::create(ENEMY_PLANE_1);
		m_hitScore = 50;
		// 打中之后马上死亡
		m_isSoonDie = 1;
	}
	else if(n >= 2) {
		sprite = Sprite::create(ENEMY_PLANE_2);
		m_hitScore = 100;
		// 打中之后马上死亡
		m_isSoonDie = 1;

	}
	else 
	{
		sprite = Sprite::create(ENEMY_PLANE_3);
		m_hitScore = 200;
		m_isSoonDie = 0;
	}	
	
	this->addChild(sprite);

	m_hitNum = 0;

	return true;
}

void Enemy::setPositionRC(int row, int col)
{
	m_x = row;
	m_y = col;
	this->setPosition(Point(row, col));
}