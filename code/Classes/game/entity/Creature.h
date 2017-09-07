#ifndef __CORE_ENTITY_CREATURE_H__
#define __CORE_ENTITY_CREATURE_H__

#include "Unit.h"
#include "ICreature.h"

NS_BEGIN_GAME_ENTITY

class CreatureModel : public UnitModel
{
public:
	CREATE_FUNC(CreatureModel);

	CreatureModel();
	~CreatureModel();

	virtual bool init();

protected:
	virtual cocos2d::Sprite* createSprite();//具体创建Sprite的方法，子类实现

private:

};

class CreatureHandle : public UnitHandle
{
public:
	CREATE_FUNC(CreatureHandle);

	CreatureHandle();
	~CreatureHandle();

	virtual bool init();

	virtual ICreature* getView() const { return dynamic_cast<ICreature*>(UnitHandle::getView()); }
	virtual void setView(ICreature* val) { UnitHandle::setView(dynamic_cast<IUnit*>(val)); }

	virtual CreatureModel* getModel() const { return dynamic_cast<CreatureModel*>(UnitHandle::getModel()); }

protected:
	virtual CreatureModel* createModel();

private:

};

class Creature : public Unit, ICreature
{
public:
	CREATE_FUNC(Creature);

	Creature();
	~Creature();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual CreatureHandle* getHandle() const { return dynamic_cast<CreatureHandle*>(Unit::getHandle()); }
	
protected:
	virtual CreatureHandle* createHandle();

private:

};

NS_END_END

#endif