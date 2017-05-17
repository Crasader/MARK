#ifndef __CRICLE_DOT_LINE_H__
#define __CRICLE_DOT_LINE_H__

#include "cocos2d.h"

class CricleDotLine : public cocos2d::Node
{
public:
	CREATE_FUNC(CricleDotLine);

	CricleDotLine();
	~CricleDotLine();

	virtual bool init();
	virtual void update(float delta);

	int getIndexOfAcrossObject() const { return _indexOfAcrossObject; }
	void setIndexOfAcrossObject(int val) { _indexOfAcrossObject = val; }

public://init cricle dot line
	cocos2d::Sprite* getCricle();
	cocos2d::Sprite* getDot();
	cocos2d::Sprite* getLine();
private:
	void initCDl();
	cocos2d::Sprite* createSprite(const std::string& spriteFrameName);

	bool _isInitedCDL;
	cocos2d::Sprite* _cricle;
	cocos2d::Sprite* _dot;
	cocos2d::Sprite* _line;

public://line refresh
	void setLineLocationTarget(const cocos2d::Vec2& location);
private:
	void refreshLine();

	float _lineOriginalWidth;
	cocos2d::Vec2 _locationTarget;
	bool _isLoactionTargetSet;

	int _indexOfAcrossObject;
};

#endif