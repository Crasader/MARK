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

	cocos2d::Sprite* getCricle();
	cocos2d::Sprite* getDot();
	cocos2d::Sprite* getLine();

	const float& getLineOriginalWidth() const { return _lineOriginalWidth; }

private:
	void initCDl();
	cocos2d::Sprite* createSprite(const std::string& spriteFrameName);

	cocos2d::Sprite* _cricle;
	cocos2d::Sprite* _dot;
	cocos2d::Sprite* _line;
	float _lineOriginalWidth;

};

#endif