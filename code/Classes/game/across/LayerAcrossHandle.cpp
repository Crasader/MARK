#include "LayerAcross.h"

USING_NS_CC;

LayerAcrossHandle::LayerAcrossHandle() : _model(nullptr), _view(nullptr)
{
}

LayerAcrossHandle::~LayerAcrossHandle()
{
	CC_SAFE_RELEASE_NULL(_model);
	_view = nullptr;
}

bool LayerAcrossHandle::init()
{
	auto isInit = false;

	do
	{
		_model = LayerAcrossModel::create();
		_model->retain();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerAcrossHandle::update(float delta)
{
	auto state = _model->getState();
	if (StateLayerAcross::DEFAULT == state)
	{
		return;
	}

	if (StateLayerAcross::UNINITIALIZED == state)
	{
		addEvent();
		return;
	}

	if (StateLayerAcross::INITIALIZED == state)
	{
		initialized();
		return;
	}

	if (StateLayerAcross::CREATEING == state)
	{
		creating();
		return;
	}
}

void LayerAcrossHandle::addEvent()
{
	auto listener = _model->getListener();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(LayerAcrossHandle::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(LayerAcrossHandle::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(LayerAcrossHandle::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(LayerAcrossHandle::onTouchCancelled, this);
	_view->addEvent(listener);

	_model->setState(StateLayerAcross::INITIALIZED);
}

void LayerAcrossHandle::initialized()
{
	auto isNumSizeSet = _model->getIsNumSizeSet();
	if (isNumSizeSet)
	{
		_model->setState(StateLayerAcross::CREATEING);
	}
}

void LayerAcrossHandle::creating()
{
	_model->createAcorssObjects();
	auto vector = _model->getAcrossObjects();
	auto length = vector.size();

	auto column = _model->getNumColumnAcrossObject();
	auto row = _model->getNumRowAcrossObject();
	auto size = _model->getSizeAcrossObject();

	for (auto i = 0; i < length; i++)
	{
		auto postion = Vec2((0.5f + int(i % column)) * size.width, (0.5f + int(i / row)) * size.height);
		_view->addNodeTo(vector.at(i), postion);
	}

	_view->setContentSizeByAcrossObject(Size(column * size.width, row * size.height));

	_model->setState(StateLayerAcross::DEFAULT);
}

bool LayerAcrossHandle::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 获取事件所绑定的 target 
	auto target = static_cast<Node*>(event->getCurrentTarget());
	/*log("target... w = %f, h = %f", target->getContentSize().width, target->getContentSize().height);*/
	// 获取当前点击点所在相对按钮的位置坐标
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	/*Size s = Director::getInstance()->getWinSize();*/
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
		/*target->setOpacity(180);*/
		return true;
	}
	return false;
}

void LayerAcrossHandle::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto location = touch->getLocation();
	auto previousLocation = touch->getPreviousLocation();
	auto startLocation = touch->getStartLocation();
	log("location,X:%f Y:%f", location.x, location.y);
	log("previousLocation,X:%f Y:%f", previousLocation.x, previousLocation.y);
	log("startLocation,X:%f Y:%f", startLocation.x, startLocation.y);

	auto i = 0;
	auto vec = _model->getAcrossObjects();
	auto postionAcrossObject = vec.at(i)->getPosition();

	auto isAcross = true;
	if (isAcross)
	{
		_model->createCricleDotLine();
		auto cricleDotLine = _model->getCricleDotLine();
		_view->addNodeTo(cricleDotLine, postionAcrossObject);
	}
	else
	{

	}
	auto cricleDotLine = _model->getCricleDotLine();

	auto lineOriginalWidth = cricleDotLine->getLineOriginalWidth();
	auto postionDelta = location - postionAcrossObject;
	auto angleLast = postionDelta.getAngle();
	log("````````` angleLast:%s", Value(angleLast).asString().c_str());
	auto rotation = postionDelta.getAngle() * -180.0f / acos(-1.0);
	auto scaleX = postionDelta.getLength() / lineOriginalWidth;

	_view->refreshLine(cricleDotLine->getLine(), rotation, scaleX);
}

void LayerAcrossHandle::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{

}

void LayerAcrossHandle::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}
