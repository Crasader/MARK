#ifndef __HANDLE_CREATURE_H__
#define __HANDLE_CREATURE_H__

#include "HandleUnit.h"
#include "ICreature.h"
#include "ModelCreature.h"

NS_BEGIN_GAME_ENTITY

class HandleCreature : public HandleUnit
{
public:
	CREATE_FUNC(HandleCreature);

	HandleCreature();
	~HandleCreature();

	virtual bool init();

	virtual ICreature* getEntity() const { return dynamic_cast<ICreature*>(HandleUnit::getEntity()); }
	virtual void setEntity(ICreature* val) { HandleUnit::setEntity(dynamic_cast<IUnit*>(val)); }

	virtual ModelCreature* getModel() const { return dynamic_cast<ModelCreature*>(HandleUnit::getModel()); }

protected:
	virtual ModelCreature* createModel();

private:

};

NS_END_END

#endif
