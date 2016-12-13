#ifndef __HANDLE_RUNE_H__
#define __HANDLE_RUNE_H__

#include "HandleUnit.h"
#include "IRune.h"
#include "ModelCreature.h"

NS_BEGIN_GAME_ENTITY

class HandleRune : public HandleUnit
{
public:
	CREATE_FUNC(HandleRune);

	HandleRune();
	~HandleRune();

	virtual bool init();

	virtual IRune* getEntity() const { return dynamic_cast<IRune*>(HandleUnit::getEntity()); }
	virtual void setEntity(IRune* val) { HandleUnit::setEntity(dynamic_cast<IUnit*>(val)); }

	virtual ModelCreature* getModel() const { return dynamic_cast<ModelCreature*>(HandleUnit::getModel()); }

protected:
	virtual ModelCreature* createModel();

private:

};

NS_END_END

#endif
