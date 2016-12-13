#ifndef __MODEL_UNIT_H__
#define __MODEL_UNIT_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "ModelEntity.h"
#include "Attribute.h"

NS_BEGIN_GAME_ENTITY

class ModelUnit : public ModelEntity
{
public:
	CREATE_FUNC(ModelUnit);

	ModelUnit();
	~ModelUnit();

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