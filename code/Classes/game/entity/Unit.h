#ifndef __CORE_ENTITY_UNIT_H__
#define __CORE_ENTITY_UNIT_H__

#include "Entity.h"
#include "Attribute.h"
#include "IUnit.h"

NS_BEGIN_GAME_ENTITY

class UnitModel : public EntityModel
{
public:
	CREATE_FUNC(UnitModel);

	UnitModel();
	~UnitModel();

	virtual bool init();

	void insertAttribute(const int& id, const int& value, const int& min = 0, const int& max = INT_MAX);
	void deleteAttribute(const int& id);
	Attribute* getAttribute(const int& id) const;
	void modifyAttributeValue(const int& id, const int& val);
	void modifyAttributeMin(const int& id, const int& val);
	void modifyAttributeMax(const int& id, const int& val);

private:
	cocos2d::Map<int, Attribute*> _poolAttribute;// Ù–‘≥ÿ

};

class UnitHandle : public EntityHandle
{
public:
	CREATE_FUNC(UnitHandle);

	UnitHandle();
	~UnitHandle();

	virtual bool init();

	virtual IUnit* getView() const { return dynamic_cast<IUnit*>(EntityHandle::getView()); }
	virtual void setView(IUnit* val) { EntityHandle::setView(dynamic_cast<IEntity*>(val)); }

	virtual UnitModel* getModel() const { return dynamic_cast<UnitModel*>(EntityHandle::getModel()); }

protected:
	virtual UnitModel* createModel();

private:

};

class Unit : public Entity, IUnit
{
public:
	CREATE_FUNC(Unit);

	Unit();
	~Unit();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual UnitHandle* getHandle() const { return dynamic_cast<UnitHandle*>(Entity::getHandle()); }

protected:
	virtual UnitHandle* createHandle();

private:

};

NS_END_END

#endif