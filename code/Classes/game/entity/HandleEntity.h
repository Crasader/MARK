#ifndef __HANDLE_ENTITY_H__
#define __HANDLE_ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "IEntity.h"
#include "ModelEntity.h"

NS_BEGIN_GAME_ENTITY

class HandleEntity : public cocos2d::Ref
{
public:
	CREATE_FUNC(HandleEntity);

	HandleEntity();
	~HandleEntity();

	virtual bool init();

	void update(float delta);

	virtual IEntity* getEntity() const { return _entity; }
	virtual void setEntity(IEntity* val) { _entity = val; }

	virtual ModelEntity* getModel() const { return _model; }

protected:
	virtual ModelEntity* createModel();

private:
	void createSkin();
	void creatingSkin();
	void createdSkin();

	IEntity* _entity;
	
	ModelEntity* _model;

};

NS_END_END

#endif