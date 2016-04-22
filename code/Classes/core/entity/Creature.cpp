#include "Creature.h"

USING_NS_CC;
USING_NS_CORE_ENTITY;

Creature::Creature()
{
}

Creature::~Creature()
{
}

bool Creature::init()
{
	auto isInit = false;

	do
	{
		CC_BREAK_IF(!Unit::init());

		isInit = true;
	} while (0);

	return isInit;
}

void core::entity::Creature::createSkin()
{
	auto spriteFrameName = "images/creature/creature.png";
	_skin = Sprite::createWithSpriteFrameName(spriteFrameName);

	if (_id == 1000)
	{
		this->setPosition(Vec2(320.0f, 480.0f));
	}
	else
	{
		this->setPosition(Vec2(320.0f, 480.0f + 200.0f));
	}

	Entity::createSkin();
}
