#ifndef __LAYER_ENTITY_H__
#define __LAYER_ENTITY_H__

#include "cocos2d.h"
#include "defines/DefinesNamespace.h"
#include "common/basic/StateCallback.h"
#include "common/util/BitData.h"
#include "common/basic/Observer.h"
#include "Entity.h"

NS_BEGIN_GAME_ENTITY

enum class StateLayerEntity
{
	DEFAULT,
	ATTACH_OBSERVER,
	UNCREATE_WORLD,
	CREATING_WORLD,
	CREATED_WORLD
};

class LayerEntityModel : public cocos2d::Ref
{
public:
	CREATE_FUNC(LayerEntityModel);

	LayerEntityModel();
	~LayerEntityModel();

	virtual bool init();

public://state
	const StateLayerEntity & getState() const { return _stateCallback.getState(); }
	void setState(const StateLayerEntity& val) { _stateCallback.setState(val); }
	StateCallback<StateLayerEntity>& getStateCallback() { return _stateCallback; }
private:
	StateCallback<StateLayerEntity> _stateCallback;

public://entity
	Entity* getEntity(const NS_GAME_ENTITY(TypeEntity)& type, const int& id);
	const cocos2d::Vec2& getEntityPostion(const NS_GAME_ENTITY(TypeEntity)& type, const int& id);
	CC_SYNTHESIZE(BitData*, _dataEntityCreate, DataEntityCreated);
private:
	const cocos2d::Map<int, Entity*>& getDicByTypeEntity(const NS_GAME_ENTITY(TypeEntity)& type);
	Entity* createEntityByType(const NS_GAME_ENTITY(TypeEntity)& type);

	cocos2d::Map<int, Entity*> _dicNone;
	cocos2d::Map<int, Entity*> _dicRegion;
	cocos2d::Map<int, Entity*> _dicCreature;
	cocos2d::Map<int, Entity*> _dicRune;

};

class ILayerEntity
{
public:
	virtual void addEntity(Entity* entity) {}
	virtual void addEntity(Entity* entity, const cocos2d::Vec2& postion) {}
	virtual void removeEntity(Entity* entity) {}

};

class LayerEntityHandle : public cocos2d::Ref, Observer
{
public:
	CREATE_FUNC(LayerEntityHandle);

	LayerEntityHandle();
	~LayerEntityHandle();

	virtual bool init();

	void attachStateCallback();

	void update(float delta);

private://attach obverver
	void attachObserver();

private://uncreate entity
	void doAddEntity();
	void addEntityByTypeNum(const NS_GAME_ENTITY(TypeEntity)& type, const int& num);
	void setEntityPostion(Entity* entity);
	void setEntityBitIndex(Entity* entity);

private://creating entity
	bool creatingEntityCheck(float delta);
	void creatingEntity();

public://update obverver
	virtual void updateBySubject(va_list values);
private:
	void setDataEntityCreatedBit(va_list values);

public://view
	CC_SYNTHESIZE(ILayerEntity*, _view, View);
	
public://model
	CC_SYNTHESIZE_READONLY(LayerEntityModel*, _model, Model);

};

class LayerEntity : public cocos2d::Layer, ILayerEntity
{
public:
	CREATE_FUNC(LayerEntity);

	LayerEntity();
	~LayerEntity();

	virtual bool init();
	virtual void update(float delta);

	virtual void addEntity(Entity* entity);
	virtual void addEntity(Entity* entity, const cocos2d::Vec2& postion);
	virtual void removeEntity(Entity* entity);

private:
	LayerEntityHandle* _handle;

};

NS_END_END

#endif