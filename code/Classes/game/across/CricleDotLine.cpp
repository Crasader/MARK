#include "CricleDotLine.h"

USING_NS_CC;

CricleDotLine::CricleDotLine() : 
	_isInitedCDL(false), 
	_cricle(nullptr), 
	_dot(nullptr), 
	_line(nullptr),
	_indexOfAcrossObject(-1)
{
}

CricleDotLine::~CricleDotLine()
{
	unscheduleUpdate();
	_line->removeFromParent();
	_line = nullptr;
	_dot->removeFromParent();
	_dot = nullptr;
	_cricle->removeFromParent();
	_cricle = nullptr;
	
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
	refreshLine();
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

void CricleDotLine::setLineLocationTarget(const cocos2d::Vec2& location)
{
	_locationTarget = location;
	_isLoactionTargetSet = true;
}

void CricleDotLine::initCDl()
{
	if (_isInitedCDL)
	{
		return;
	}
	_isInitedCDL = true;

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

void CricleDotLine::refreshLine()
{
	if (!_isInitedCDL)
	{
		return;
	}
	if (!_isLoactionTargetSet)
	{
		return;
	}
	_isLoactionTargetSet = false;

	/*log("_locationTarget,x = %f, y = %f", _locationTarget.x, _locationTarget.y);*/
	auto locationInCDlParent = getParent()->convertToNodeSpace(_locationTarget);
	/*log("locationInCDlParent,x = %f, y = %f", locationInCDlParent.x, locationInCDlParent.y);*/
	auto locationDelta = locationInCDlParent - getPosition();
	auto angleLast = locationDelta.getAngle();
	/*log("angleLast:%s", Value(angleLast).asString().c_str());*/
	auto rotation = locationDelta.getAngle() * -180.0f / acos(-1.0);
	/*log("rotationOfCDl:%f", rotation);*/
	auto scaleX = locationDelta.getLength() / _lineOriginalWidth;
	_line->setRotation(rotation);
	_line->setScaleX(scaleX);
}

cocos2d::Sprite* CricleDotLine::createSprite(const std::string& spriteFrameName)
{
	auto sprite = Sprite::createWithSpriteFrameName(spriteFrameName);
	return sprite;
}
