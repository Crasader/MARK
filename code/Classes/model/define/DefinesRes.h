#pragma execution_character_set("utf-8")

#ifndef __DATA_DEFINE_DEFINES_RES_H__
#define __DATA_DEFINE_DEFINES_RES_H__

#define RES_FONTS_KTJT "fonts/ktjt.ttf" 

#define RES_CORE_ENTITY_PLIST_CREATURE_PLIST "core/entity/PlistCreature.plist"
#define RES_CORE_ENTITY_PLIST_MAP_PLIST "core/entity/PlistMap.plist"
#define RES_CORE_ENTITY_PLIST_RUNE_PLIST "core/entity/PlistRune.plist"

#define RES_UI_COMMON_PLIST_COMMON_PLIST "ui/common/PlistCommon.plist"

#define RES_UI_COMMON_LAYER_RES_LOAD_CSB "ui/common/LayerResLoad.csb"

#define RES_UI_MENU_LAYER_MENU_START_CSB "ui/menu/LayerMenuStart.csb"

#define RES_IMAGES_MAIN_CIRCLE_LINE_POINT_PNG "images/battle/lianxian_dian.png"
#define RES_IMAGES_MAIN_CIRCLE_LINE_CIRCLE_PNG "images/battle/lianxian_quan.png"
#define RES_IMAGES_MAIN_CIRCLE_LINE_LINE_PNG "images/battle/lianxian_xian.png"

#define RES_IMAGES_COMMON_TYPE_JOB_ROGUE_PNG "images/common/typeJobRogue.png"
#define RES_IMAGES_COMMON_TYPE_JOB_WARRIOR_PNG "images/common/typeJobWarrior.png"
#define RES_IMAGES_COMMON_TYPE_JOB_MAGE_PNG "images/common/typeJobMage.png"
#define RES_IMAGES_COMMON_TYPE_JOB_TREAT_PNG "images/common/typeJobTreat.png"
#define RES_IMAGES_COMMON_TYPE_JOB_TANK_PNG "images/common/typeJobTank.png"
#define RES_IMAGES_COMMON_TYPE_JOB_ARCHER_PNG "images/common/typeJobArcher.png"

#define SOUND_EFFECT_SYSTEM_BTN_0_MP3 "effect/systemBtn0.mp3"//音效系统按钮0
#define SOUND_EFFECT_SYSTEM_BTN_1_MP3 "effect/systemBtn1.mp3"//音效系统按钮1

#include "DefinesNamespace.h"
#include <string.h>

NS_BEGIN_MODEL_DEFINE

class DefinesRes
{
public:
	static std::string getResImagesCommonTypeJobPng(int val)
	{
		switch (val)
		{
		case 1:
			return RES_IMAGES_COMMON_TYPE_JOB_ROGUE_PNG;
		case 2:
			return RES_IMAGES_COMMON_TYPE_JOB_WARRIOR_PNG;
		case 3:
			return RES_IMAGES_COMMON_TYPE_JOB_MAGE_PNG;
		case 4:
			return RES_IMAGES_COMMON_TYPE_JOB_TREAT_PNG;
		case 5:
			return RES_IMAGES_COMMON_TYPE_JOB_TANK_PNG;
		case 6:
			return RES_IMAGES_COMMON_TYPE_JOB_ARCHER_PNG;
		default:
			return "";
		}
	}
};

NS_END_END

#endif