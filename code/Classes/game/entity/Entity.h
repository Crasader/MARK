#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"
#include "common/define/DefinesNamespace.h"
#include "common/basic/StateCallback.h"

NS_BEGIN_GAME_ENTITY

enum class StateEntity
{
	DEFAULT,
	UNCREATE_SKIN,
	CREATING_SKIN,
	CREATED_SKIN,
	UNINIT,
	STANDBY
};

enum class TypeEntity
{
	REGION,
	CREATURE,
	RUNE
};

class EntityModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(EntityModel);

	EntityModel();
	~EntityModel();

	virtual bool init();

public://state
	const StateEntity & getState() const { return _stateCallback.getState(); }
	void setState(const StateEntity& val) { _stateCallback.setState(val); }
	StateCallback<StateEntity>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateEntity> _stateCallback;

public://type
	CC_SYNTHESIZE_PASS_BY_REF(TypeEntity, _type, Type);
	
public://id
	CC_SYNTHESIZE(int, _id, Id);
	
public://bitindex
	CC_SYNTHESIZE(int, _bitIndex, BitIndex);

public://skin
	cocos2d::Sprite* getSkin();
protected:
	virtual cocos2d::Sprite* createSprite() { return nullptr; }//具体创建Sprite的方法，子类实现
private:
	cocos2d::Sprite* _skin;

};

class IEntity
{
public:
	virtual void addSkin(cocos2d::Sprite* skin) {}
	virtual void doSomething() {}

};

class EntityHandle : public cocos2d::Ref
{
public:
	CREATE_FUNC(EntityHandle);

	EntityHandle();
	~EntityHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

private:
	void createSkin();
	void creatingSkin();
	void createdSkin();

public://view
	CC_SYNTHESIZE(IEntity*, _view, View);

public://model
	CC_SYNTHESIZE_READONLY(EntityModel*, _model, Model);
protected:
	virtual EntityModel* createModel();

};

class Entity : public cocos2d::Node, IEntity
{
public:
	CREATE_FUNC(Entity);

	Entity();
	~Entity();

	virtual bool init();
	virtual void update(float delta);
	
	virtual void addSkin(cocos2d::Sprite* skin);

public://handle
	CC_SYNTHESIZE_READONLY(EntityHandle*, _handle, Handle);
protected:
	virtual EntityHandle* createHandle();

};

NS_END_END

#endif
