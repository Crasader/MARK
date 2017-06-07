#include "LayerAcross.h"

USING_NS_CC;

LayerAcrossModel::LayerAcrossModel() :
	_stateCallback(StateLayerAcross::UNINITIALIZED),
	_listener(nullptr),
	_vecCricleDotLine(),
	_isTest(false),
	_isNumSizeSet(false),
	_vecAcrossObject(),
	_vecIsAcrossedAcrossObject()
{
}

LayerAcrossModel::~LayerAcrossModel()
{
	_vecIsAcrossedAcrossObject.clear();
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

CricleDotLine* LayerAcrossModel::getCricleDotLinePrevious()
{
	CricleDotLine* cdl = nullptr;
	auto length = _vecCricleDotLine.size();
	if (!_vecCricleDotLine.empty() && length != 1)
	{
		cdl = _vecCricleDotLine.at(length - 2);
	}
	return cdl;
}

CricleDotLine* LayerAcrossModel::createCricleDotLine()
{
	auto cdl = CricleDotLine::create();
	_vecCricleDotLine.pushBack(cdl);
	return cdl;
}

void LayerAcrossModel::deleteCricleDotLine()
{
	_vecCricleDotLine.popBack();
}

void LayerAcrossModel::clearCricleDotLine()
{
	_vecCricleDotLine.clear();
}

void LayerAcrossModel::setAcrossObjectNumSize(const int& numRow, const int& numColumn, const cocos2d::Size& size, const float& rowInterval, const float& columnInterval)
{
	_numRowAcrossObject = numRow;
	_numColumnAcrossObject = numColumn;
	_sizeAcrossObject = size;
	_rowInterval = rowInterval;
	_columnInterval = columnInterval;
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

			//»æÖÆ¿ÕÐÄ¶à±ßÐÎ
			//Ìî³äÑÕÉ«£ºColor4F(1, 0, 0, 0), Í¸Ã÷
			//ÂÖÀªÑÕÉ«£ºColor4F(0, 1, 0, 1), ÂÌÉ«
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
		_vecIsAcrossedAcrossObject.push_back(false);
	}
}

void LayerAcrossModel::clearAcrossObjects()
{
	_vecAcrossObject.clear();
}

cocos2d::Node* LayerAcrossModel::getAcrossObject(const int& index)
{
	auto acrossObject = _vecAcrossObject.at(index);
	return acrossObject;
}

int LayerAcrossModel::getIndexOfVecAcrossObjects(const cocos2d::Vec2& location)
{
	auto cricleDotLinePrevious = getCricleDotLinePrevious();
	auto indexPrevious = cricleDotLinePrevious ? cricleDotLinePrevious->getIndexOfAcrossObject() : -1;
	auto length = _vecAcrossObject.size();
	for (auto i = 0; i < length; i++)
	{
		auto isAcrossed = getIsAcrossed(i);
		if (i != indexPrevious && isAcrossed) continue;

		auto acrossObject = _vecAcrossObject.at(i);
		auto locationInAO = acrossObject->convertToNodeSpace(location);
		/*log("locationInAO,X:%f Y:%f", locationInAO.x, locationInAO.y);*/
		auto s = acrossObject->getContentSize();
		auto rect = Rect(0, 0, s.width, s.height);
		// µã»÷·¶Î§ÅÐ¶Ï¼ì²â
		if (rect.containsPoint(locationInAO))
		{
			return i;
		}
	}
	return -1;
}

bool LayerAcrossModel::getIsAcrossed(const int& index)
{
	return _vecIsAcrossedAcrossObject.at(index);
}

void LayerAcrossModel::setIsAcrossed(const int& index, const bool& val)
{
	auto& isAcrossed = _vecIsAcrossedAcrossObject.at(index);
	isAcrossed = val;
}

bool LayerAcrossModel::getIsResultConfirmed()
{
	return _numOfResult == _vecCricleDotLine.size();
}
