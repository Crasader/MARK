#include "CricleDotLine.h"

USING_NS_CC;

CricleDotLine::CricleDotLine() : _cricle(nullptr), _dot(nullptr), _line(nullptr)
{
}

CricleDotLine::~CricleDotLine()
{
	_cricle->removeFromParent();
	_cricle = nullptr;
	_dot->removeFromParent();
	_dot = nullptr;
	_line->removeFromParent();
	_line = nullptr;
}

bool CricleDotLine::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Node::init());

		scheduleUpdate();

		isInit = true;
	} while (0);

	return isInit;
}

void CricleDotLine::update(float delta)
{
	initCDl();
	unscheduleUpdate();
}

cocos2d::Sprite* CricleDotLine::getCricle()
{
	if (_cricle == nullptr)
	{
		auto spriteFrameName = "images/across/ring.png";
		_cricle = createSprite(spriteFrameName);
	}
	return _cricle;
}

cocos2d::Sprite* CricleDotLine::getDot()
{
	if (_dot == nullptr)
	{
		auto spriteFrameName = "images/across/dot.png";
		_dot = createSprite(spriteFrameName);
	}
	return _dot;
}

cocos2d::Sprite* CricleDotLine::getLine()
{
	if (_line == nullptr)
	{
		auto spriteFrameName = "images/across/line.png";
		_line = createSprite(spriteFrameName);
	}
	return _line;
}

void CricleDotLine::initCDl()
{
	auto cricle = getCricle();
	cricle->setAnchorPoint(Vec2(0.5f, 0.5f));
	addChild(cricle);

	auto dot = getDot();
	dot->setAnchorPoint(Vec2(0.5f, 0.5f));
	addChild(dot);
	
	auto line = getLine();
	line->setAnchorPoint(Vec2(0.0f, 0.5f));
	addChild(line);

	auto size = line->getContentSize();
	_lineOriginalWidth = size.width;
}

cocos2d::Sprite* CricleDotLine::createSprite(const std::string& spriteFrameName)
{
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
