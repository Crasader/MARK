#ifndef __MODEL_CREATURE_H__
#define __MODEL_CREATURE_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "ModelUnit.h"

NS_BEGIN_GAME_ENTITY

class ModelCreature : public ModelUnit
{
public:
	CREATE_FUNC(ModelCreature);

	ModelCreature();
	~ModelCreature();

	virtual bool init();

protected:
	virtual cocos2d::Sprite* createSprite();//���崴��Sprite�ķ���������ʵ��

private:

};

NS_END_END

#endif