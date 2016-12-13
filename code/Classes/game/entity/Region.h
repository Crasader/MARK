#ifndef __CORE_ENTITY_REGION_H__
#define __CORE_ENTITY_REGION_H__

#include "Unit.h"
#include "IRegion.h"
#include "HandleRegion.h"

NS_BEGIN_GAME_ENTITY

class Region : public Unit, IRegion
{
public:
	CREATE_FUNC(Region);

	Region();
	~Region();

	virtual bool init();

	virtual void addSkin(cocos2d::Sprite* skin);

	virtual HandleRegion* getHandle() const { return dynamic_cast<HandleRegion*>(Unit::getHandle()); }

protected:
	virtual HandleRegion* createHandle();

private:

};

NS_END_END

#endif