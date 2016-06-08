#ifndef __CORE_ENTITY_UNIT_H__
#define __CORE_ENTITY_UNIT_H__

#include "Entity.h"
#include "Attribute.h"

NS_BEGIN_GAME_ENTITY

class Unit : public Entity
{
public:
	CREATE_FUNC(Unit);

	Unit();
	~Unit();

	virtual bool init();

	void insertAttribute(const int& id, const int& value, const int& min = 0, const int& max = INT_MAX);
	void deleteAttribute(const int& id);
	Attribute* getAttribute(const int& id) const;
	void modifyAttributeValue(const int& id, const int& val);
	void modifyAttributeMin(const int& id, const int& val);
	void modifyAttributeMax(const int& id, const int& val);

private:
	cocos2d::Map<int, Attribute*> _poolAttribute;// Ù–‘≥ÿ

};

NS_END_END

#endif