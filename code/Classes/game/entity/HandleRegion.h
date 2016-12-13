#ifndef __HANDLE_REGION_H__
#define __HANDLE_REGION_H__

#include "HandleUnit.h"
#include "IRegion.h"
#include "ModelRegion.h"

NS_BEGIN_GAME_ENTITY

class HandleRegion : public HandleUnit
{
public:
	CREATE_FUNC(HandleRegion);

	HandleRegion();
	~HandleRegion();

	virtual bool init();

	virtual IRegion* getEntity() const { return dynamic_cast<IRegion*>(HandleUnit::getEntity()); }
	virtual void setEntity(IRegion* val) { HandleUnit::setEntity(dynamic_cast<IUnit*>(val)); }

	virtual ModelRegion* getModel() const { return dynamic_cast<ModelRegion*>(HandleUnit::getModel()); }

protected:
	virtual ModelRegion* createModel();

private:

};

NS_END_END

#endif