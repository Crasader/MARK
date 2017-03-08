#ifndef __CORE_ENTITY_RUNE_H__
#define __CORE_ENTITY_RUNE_H__

#include "Unit.h"

NS_BEGIN_GAME_ENTITY

class RuneModel : public UnitModel
{
public:
	CREATE_FUNC(RuneModel);

	RuneModel();
	~RuneModel();

	virtual bool init();

protected:
	virtual cocos2d::Sprite* createSprite();//具体创建Sprite的方法，子类实现

private:

};

class IRune : public IUnit
{
public:

};

class RuneHandle : public UnitHandle
{
public:
	CREATE_FUNC(RuneHandle);

	RuneHandle();
	~RuneHandle();

	virtual bool init();

	virtual IRune* getView() const { return dynamic_cast<IRune*>(UnitHandle::getView()); }
	virtual void setView(IRune* val) { UnitHandle::setView(dynamic_cast<IUnit*>(val)); }

	virtual RuneModel* getModel() const { return dynamic_cast<RuneModel*>(UnitHandle::getModel()); }

protected:
	virtual RuneModel* createModel();

private:

};

class Rune : public Unit, IRune
{
public:
	CREATE_FUNC(Rune);

	Rune();
	~Rune();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual RuneHandle* getHandle() const { return dynamic_cast<RuneHandle*>(Entity::getHandle()); }

protected:
	virtual RuneHandle* createHandle();

private:
	
};

NS_END_END

#endif
