#ifndef __CORE_ENTITY_REGION_H__
#define __CORE_ENTITY_REGION_H__

#include "Unit.h"

NS_BEGIN_GAME_ENTITY

class RegionModel : public UnitModel
{
public:
	CREATE_FUNC(RegionModel);

	RegionModel();
	~RegionModel();

	virtual bool init();

protected:
	virtual cocos2d::Sprite* createSprite();//具体创建Sprite的方法，子类实现

private:

};

class IRegion : public IUnit
{
public:

};

class RegionHandle : public UnitHandle
{
public:
	CREATE_FUNC(RegionHandle);

	RegionHandle();
	~RegionHandle();

	virtual bool init();

	virtual IRegion* getView() const { return dynamic_cast<IRegion*>(UnitHandle::getView()); }
	virtual void setView(IRegion* val) { UnitHandle::setView(dynamic_cast<IUnit*>(val)); }

	virtual RegionModel* getModel() const { return dynamic_cast<RegionModel*>(UnitHandle::getModel()); }

protected:
	virtual RegionModel* createModel();

private:

};

class Region : public Unit, IRegion
{
public:
	CREATE_FUNC(Region);

	Region();
	~Region();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual RegionHandle* getHandle() const { return dynamic_cast<RegionHandle*>(Unit::getHandle()); }

protected:
	virtual RegionHandle* createHandle();

private:

};

NS_END_END

#endif