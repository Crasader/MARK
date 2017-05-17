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

		attachStateCallback();

		isInit = true;
	} while (0);

	return isInit;
}

void LayerAcrossHandle::attachStateCallback()
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.insertCallback(StateLayerAcross::DEFAULT, nullptr);
	stateCallback.insertCallback(StateLayerAcross::UNINITIALIZED, CC_CALLBACK_0(LayerAcrossHandle::initialize, this));
	stateCallback.insertCallback(StateLayerAcross::INITIALIZED, CC_CALLBACK_0(LayerAcrossHandle::initialized, this), CC_CALLBACK_1(LayerAcrossHandle::initializedCheck, this));
	stateCallback.insertCallback(StateLayerAcross::CREATEING, CC_CALLBACK_0(LayerAcrossHandle::creating, this));
}

void LayerAcrossHandle::update(float delta)
{
	auto& stateCallback = _model->getStateCallback();
	stateCallback.doCallbackByCurrentState(delta);
}

void LayerAcrossHandle::initialize()
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

bool LayerAcrossHandle::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 获取事件所绑定的 target 
	auto target = static_cast<Node*>(event->getCurrentTarget());
	/*log("target... w = %f, h = %f", target->getContentSize().width, target->getContentSize().height);*/
	// 获取当前点击点所在相对按钮的位置坐标
	auto location = touch->getLocation();
	Point locationInView = target->convertToNodeSpace(location);
	log("locationInNode,x = %f, y = %f", locationInView.x, locationInView.y);
	
	/*Size s = Director::getInstance()->getWinSize();*/
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (!rect.containsPoint(locationInView))// 点击范围判断检测
	{
		return false;
	}

	auto index = _model->getIndexOfVecAcrossObjects(location);
	if (index == -1)
	{
		return false;
	}

	addCricleDotLine(index,location);
	return true;
}

void LayerAcrossHandle::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto location = touch->getLocation();
	/*auto previousLocation = touch->getPreviousLocation();
	auto startLocation = touch->getStartLocation();*/
	auto target = static_cast<Node*>(event->getCurrentTarget());
	Point locationInView = target->convertToNodeSpace(location);
	/*log("////////////////////////");
	log("location,X:%f Y:%f", location.x, location.y);
	/ *log("previousLocation,X:%f Y:%f", previousLocation.x, previousLocation.y);
	log("startLocation,X:%f Y:%f", startLocation.x, startLocation.y);* /
	log("locationInNode,X:%f Y:%f", locationInNode.x, locationInNode.y);
	log("////////////////////////");*/

	auto cricleDotLine = _model->getCricleDotLine();
	if (cricleDotLine == nullptr)
	{
		return;
	}
	cricleDotLine->setLineLocationTarget(location);

	auto locationInCDL = cricleDotLine->convertToNodeSpace(location);
	/*log("locationInCDL,X:%f Y:%f", locationInCDL.x, locationInCDL.y);*/
	Size s = _model->getSizeAcrossObject();
	Rect rect = Rect(s.width * -.5f, s.height * -0.5f, s.width, s.height);
	if (rect.containsPoint(locationInCDL))//滑出当前区域
	{
		return;
	}

	auto index = _model->getIndexOfVecAcrossObjects(location);
	if (index == -1)
	{
		return;
	}

	auto cricleDotLinePrevious = _model->getCricleDotLinePrevious();
	auto indexPrevious = cricleDotLinePrevious ? cricleDotLinePrevious->getIndexOfAcrossObject() : -1;
	log("LayerAcrossHandle::onTouchMoved | indexPrevious:%d", indexPrevious);
	if (indexPrevious == index)
	{
		removeCricleDotLine();
	}
	else
	{
		addCricleDotLine(index, location);
		setLineLocationOfPreviousCDL();
	}
}

void LayerAcrossHandle::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	removeCricleDotLine(true);
}

void LayerAcrossHandle::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
	removeCricleDotLine(true);
}

void LayerAcrossHandle::addCricleDotLine(const int& index, const cocos2d::Vec2& location)
{
	auto& vecIsAcrossed = _model->getIsAcrosseds();
	auto& isAcrossed = vecIsAcrossed.at(index);
	isAcrossed = true;

	auto& vec = _model->getAcrossObjects();
	auto acrossObject = vec.at(index);
	auto postionAcrossObject = acrossObject->getPosition();
	auto cricleDotLine = _model->createCricleDotLine();
	cricleDotLine->setIndexOfAcrossObject(index);
	cricleDotLine->setLineLocationTarget(location);
	_view->addNodeTo(cricleDotLine, postionAcrossObject);
}

void LayerAcrossHandle::removeCricleDotLine(const bool& isRemoveAll /*= false*/)
{
	auto& vecIsAcrossed = _model->getIsAcrosseds();
	do 
	{
		auto cricleDotLine = _model->getCricleDotLine();
		if (cricleDotLine == nullptr) break;
		
		auto index = cricleDotLine->getIndexOfAcrossObject();
		if (index != -1)
		{
			auto& isAcrossed = vecIsAcrossed.at(index);
			isAcrossed = false;
		}

		cricleDotLine->removeFromParent();
		_model->deleteCricleDotLine();
	} while (isRemoveAll);
}

void LayerAcrossHandle::setLineLocationOfPreviousCDL()
{
	auto cricleDotLinePrevious = _model->getCricleDotLinePrevious();
	if (cricleDotLinePrevious == nullptr)
	{
		return;
	}

	auto cricleDotLine = _model->getCricleDotLine();
	auto location = cricleDotLine->convertToWorldSpace(cricleDotLine->getAnchorPointInPoints());//转化全局坐标
	/*log("locationInCDl,X:%f Y:%f", locationInCDl.x, locationInCDl.y);
	location = target->convertToNodeSpace(location);*/
	cricleDotLinePrevious->setLineLocationTarget(location);
}

bool LayerAcrossHandle::getIsMoveToLast()
{
	auto cricleDotLine = _model->getCricleDotLine();
	if (cricleDotLine == nullptr)
	{
		return false;
	}

	auto cricleDotLineLast = _model->getCricleDotLinePrevious();
	if (cricleDotLineLast == nullptr)
	{
		return false;
	}

	auto rotation = cricleDotLine->getLine()->getRotation();
	auto rotationToLast = cricleDotLineLast->getLine()->getRotation();
	rotationToLast = rotationToLast > 0 ? rotationToLast - 180.0f : 180.0f + rotationToLast;
	/*log("////////////////////////");
	log("rotation:%f", rotation);
	log("rotationToLast:%f", rotationToLast);
	log("////////////////////////");*/
	auto rotationToLastMax = rotationToLast + 22.5f;
	auto rotationToLastMin = rotationToLast - 22.5f;

	auto rotationTrue = rotation;
	if (rotation < 0 && rotationToLast > 0)
	{
		rotationTrue = rotationTrue + 360.0f;
	}
	else if (rotation > 0 && rotationToLast < 0)
	{
		rotationTrue = rotationTrue - 360.0f;
	}
	if (rotationTrue < rotationToLastMax && rotationTrue > rotationToLastMin)
	{
		return true;
	}
	return false;
}

bool LayerAcrossHandle::initializedCheck(float delta)
{
	auto isNumSizeSet = _model->getIsNumSizeSet();
	return isNumSizeSet;
}

void LayerAcrossHandle::initialized()
{
	_model->setState(StateLayerAcross::CREATEING);
}

void LayerAcrossHandle::creating()
{
	_model->createAcorssObjects();
	auto& vector = _model->getAcrossObjects();
	auto length = vector.size();

	auto column = _model->getNumColumnAcrossObject();
	auto row = _model->getNumRowAcrossObject();
	auto size = _model->getSizeAcrossObject();
	auto columnInterval = _model->getColumnInterval();
	auto rowInterval = _model->getRowInterval();

	for (auto i = 0; i < length; i++)
	{
		auto postion = Vec2((0.5f + int(i % column)) * (size.width + columnInterval) , (0.5f + int(i / row)) * (size.height + rowInterval));
		_view->addNodeTo(vector.at(i), postion);
	}

	_view->setContentSizeByAcrossObject(Size(column * (size.width + columnInterval), row * (size.height + rowInterval)));

	_model->setState(StateLayerAcross::DEFAULT);
}
