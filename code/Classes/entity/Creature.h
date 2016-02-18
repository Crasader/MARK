#ifndef _ENTITY_CREATURE_H_
#define _ENTITY_CREATURE_H_

#include "Unit.h"

class Creature : public Unit
{
public:
	CREATE_FUNC(Creature);

	Creature();
	~Creature();

	virtual bool init();

private:

};

#endif