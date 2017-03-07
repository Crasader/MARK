#include "LayerAcross.h"

USING_NS_CC;

LayerAcrossModel::LayerAcrossModel() :
	_stateCallback(StateLayerAcross::UNINITIALIZED),
	_listener(nullptr),
	_vecCricleDotLine(),
	_isTest(false),
	_isNumSizeSet(false),
	_vecAcrossObject()
{
}

LayerAcrossModel::~LayerAcrossModel()
{
	clearAcrossObjects();
	clearCricleDotLine();
	setListenerNullptr();
	_stateCallback.clearDic();
}

bool LayerAcrossModel::init()
{
	auto isInit = false;

	do
	{

		isInit = true;
	} while (0);

	return isInit;
}

cocos2d::EventListenerTouchOneByOne* LayerAcrossModel::getListener()
{
	if (_listener == nullptr)
	{
		_listener = EventListenerTouchOneByOne::create();
	}
	return _listener;
}

void LayerAcrossModel::setListenerNullptr()
{
	_listener = nullptr;
}

CricleDotLine* LayerAcrossModel::getCricleDotLine()
{
	CricleDotLine* cdl = nullptr;
	if (!_vecCricleDotLine.empty())
	{
		cdl = _vecCricleDotLine.back();
	}
	return cdl;
}

void LayerAcrossModel::createCricleDotLine()
{
	auto cdl = CricleDotLine::create();
	_vecCricleDotLine.pushBack(cdl);
}

void LayerAcrossModel::deleteCricleDotLine()
{
	_vecCricleDotLine.popBack();
}

void LayerAcrossModel::clearCricleDotLine()
{
	_vecCricleDotLine.clear();
}

void LayerAcrossModel::setAcrossObjectNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size)
{
	_numRowAcrossObject = numRow;
	_numColumnAcrossObject = numColumn;
	_sizeAcrossObject = size;
	_isNumSizeSet = true;
}

void LayerAcrossModel::createAcorssObjects()
{
	auto total = _numRowAcrossObject * _numColumnAcrossObject;
	for (auto i = 0; i < total; i++)
	{
		Node* acrossObject = nullptr;
		if (_isTest)
		{
			auto drawNode = DrawNode::create();
			Vec2 point[4];
			point[0] = Vec2(0, 0);
			point[1] = Vec2(0, _sizeAcrossObject.height);
			point[2] = Vec2(_sizeAcrossObject.width, _sizeAcrossObject.height);
			point[3] = Vec2(_sizeAcrossObject.width, 0);

			//绘制空心多边形
			//填充颜色：Color4F(1, 0, 0, 0), 透明
			//轮廓颜色：Color4F(0, 1, 0, 1), 绿色
			drawNode->drawPolygon(point, 4, Color4F(1, 0, 0, 0), 1, Color4F(0, 1, 0, 1));
			acrossObject = drawNode;
		}
		else
		{
			auto node = Node::create();
			acrossObject = node;
		}
		acrossObject->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		acrossObject->setContentSize(_sizeAcrossObject);
		_vecAcrossObject.pushBack(acrossObject);
	}
}

void LayerAcrossModel::clearAcrossObjects()
{
	_vecAcrossObject.clear();
}
