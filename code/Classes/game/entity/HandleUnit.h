#ifndef __HANDLE_UNIT_H__
#define __HANDLE_UNIT_H__

#include "HandleEntity.h"
#include "IUnit.h"
#include "ModelUnit.h"

NS_BEGIN_GAME_ENTITY

class HandleUnit : public HandleEntity
{
public:
	CREATE_FUNC(HandleUnit);

	HandleUnit();
	~HandleUnit();

	virtual bool init();

	virtual IUnit* getEntity() const { return dynamic_cast<IUnit*>(HandleEntity::getEntity()); }
	virtual void setEntity(IUnit* val) { HandleEntity::setEntity(dynamic_cast<IEntity*>(val)); }

	virtual ModelUnit* getModel() const { return dynamic_cast<ModelUnit*>(HandleEntity::getModel()); }

protected:
	virtual ModelUnit* createModel();

private:

};

NS_END_END

#endif