#ifndef _ENTITY_RUNE_H_
#define _ENTITY_RUNE_H_

#include "Entity.h"

class Rune : public Entity
{
public:
	CREATE_FUNC(Rune);

	Rune();
	~Rune();

	virtual bool init();

private:

};

#endif
