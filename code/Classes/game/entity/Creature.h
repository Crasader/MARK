#ifndef __CORE_ENTITY_CREATURE_H__
#define __CORE_ENTITY_CREATURE_H__

#include "Unit.h"
#include "common/define/DefinesNamespace.h"

NS_BEGIN_GAME_ENTITY

class Creature : public Unit
{
public:
	CREATE_FUNC(Creature);

	Creature();
	~Creature();

	virtual bool init();

protected:
	virtual void createSkin();

private:

};

NS_END_END

#endif