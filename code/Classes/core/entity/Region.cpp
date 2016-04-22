#include "Region.h"
#include <vector>

USING_NS_CC;
USING_NS_CORE_ENTITY;

Region::Region()
{

}

Region::~Region()
{

}

bool Region::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());
		isInit = true;
	} while (0);

	return isInit;
}

void core::entity::Region::createSkin()
{
	auto spriteFrameName = "images/map/unit_ground.jpg";
	_skin = Sprite::createWithSpriteFrameName(spriteFrameName);
	
	std::vector<Vec2> vecPostion = { 
		Vec2(320.0f, 480.0f), 
		Vec2(320.0f, 380.0f), Vec2(320.0f, 580.0f), 
		Vec2(220.0f, 480.0f), Vec2(420.0f, 480.0f), 
		Vec2(220.0f, 380.0f), Vec2(420.0f, 580.0f), 
		Vec2(220.0f, 580.0f), Vec2(420.0f, 380.0f) };

	this->setPosition(vecPostion[(_id - 1000)]);

	Entity::createSkin();
}
