#ifndef __CORE_ENTITY_REGION_H__
#define __CORE_ENTITY_REGION_H__

#include "Unit.h"

NS_BEGIN_CORE_ENTITY

class Region : public core::entity::Unit
{
public:
	CREATE_FUNC(Region);

	Region();
	~Region();

	virtual bool init();

protected:
	virtual void createSkin();

private:

};

NS_END_END

#endif