#ifndef __CORE_ENTITY_RUNE_H__
#define __CORE_ENTITY_RUNE_H__

#include "Unit.h"

NS_BEGIN_CORE_ENTITY

class Rune : public core::entity::Unit
{
public:
	CREATE_FUNC(Rune);

	Rune();
	~Rune();

	virtual bool init();

private:
	
};

NS_END_END

#endif