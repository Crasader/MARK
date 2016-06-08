#ifndef __GAME_MODEL_GAME_H__
#define __GAME_MODEL_GAME_H__

#include "cocos2d.h"

class ModelGame : public cocos2d::Ref
{
public:
	CREATE_FUNC(ModelGame);

	ModelGame();
	~ModelGame();

	virtual bool init();

	void createDatabase();//构建数据库

private:

};

#endif