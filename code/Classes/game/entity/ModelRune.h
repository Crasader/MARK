#ifndef __MODEL_RUNE_H__
#define __MODEL_RUNE_H__

#include "ModelUnit.h"

NS_BEGIN_GAME_ENTITY

class ModelRune : public ModelUnit
{
public:
	CREATE_FUNC(ModelRune);

	ModelRune();
	~ModelRune();

	virtual bool init();

protected:
	virtual cocos2d::Sprite* createSprite();//���崴��Sprite�ķ���������ʵ��

private:

};

NS_END_END

#endif