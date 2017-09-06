#pragma execution_character_set("utf-8")

#ifndef __COMMON_CONFIG_MANAGER_CFG_DEFINES_H__
#define __COMMON_CONFIG_MANAGER_CFG_DEFINES_H__

#include <string>
#include <map>
#include "defines/DefinesValue.h"

struct CfgAttribute//属性
{
	int id;//标志
	std::string desc;//描述
	std::string urlPic;//图片路径
	TypeAttribute type;//类型
	std::string args;//参数
};
typedef std::map<int32_t, CfgAttribute> DicCfgAttribute;
//
struct CfgSkill//指令
{
	int id;//标志
	int index;//排序
	std::string name;//名称
	TypeSkill type;//类型
	std::string effect;//效果
	int buyCost;//购买花费
	std::string urlPic;//图片
	std::string desc;//描述
};
typedef std::map<int32_t, std::map<int32_t, CfgSkill>> DicDicCfgSkill;
//
struct DataSkillInfo
{
	int idSkill;
	int indexSkill;
	int num;
	int odds;
};
struct CfgSkillGroup//指令组
{
	int id;//标志
	std::string typeArgs;//条件 类型(1血量百分比2能量值3总回合4回合):参数
	int index;//排序
	std::vector<DataSkillInfo> skills;//技能标志
};
typedef std::map<int32_t, std::map<std::string, std::map<int32_t, CfgSkillGroup>>> DicDicDicCfgSkillGroup;
typedef std::map<int32_t, std::vector<std::string>> DicVecCfgSkillGroupTypeArgs;
//
struct CfgEntity
{
	int id;//标志
	std::string name;//名称
	TypeEntity type;//类型 1女仆2怪物
	TypeJob typeJob;//职业 1盗贼2战士3法师4治疗5坦克6弓手
	std::string attribute;//属性 101生命上限103能量上限104物理攻击105魔法攻击106金币收益
	int idSkillGroup;//技能组id
	int idTraining;//训练id
	int cost;//购买消耗
	int oddsCatch;//捕获几率
	std::string urlPicEntity;//实体图片
	std::string urlPicEntityBreak;//破衣图片
	int xPic;//图片x
	int yPic;//图片y
	std::string urlPicHeadLarge;//大头像图片
	std::string urlPicHeadMiddle;//中头像图片
	std::string urlPicHeadSmall;//小头像图片
	std::string urlPicName;//名称图片
};
typedef std::map<int32_t, CfgEntity> DicCfgEntity;
//
struct CfgLevel//关卡
{
	int id;//标志
	std::string name;//名称
	std::vector<std::string> vecUrlPic;//图片路径
	std::string msts;//怪物配置
	int roundLimit;//回合限制
	bool isRoundLimitWin;//是否回合限制获胜
	std::vector<int> targets;//目标
	std::vector<int> unlockLevels;//解锁关卡
	std::vector<std::vector<int>> unlockSkills;//解锁技能
	std::vector<int> unlockMaids;//解锁女仆
	std::map<IdThing, std::vector<int>> award;//奖励 类型:值:几率
};
typedef std::map<int32_t, CfgLevel> DicCfgLevels;
//
struct CfgLevelTarget
{
	int id;//标志
	std::string desc;//描述
	TypeLevelTarget type;//类型
	int args;//参数
	int roundLimitMst;//怪物回合限制
	int roundLimitMaid;//女仆回合限制
	int roundLimitTotal;//总回合限制
	std::map<IdThing, std::vector<int>> award;//奖励 类型:值:几率
};
typedef std::map<int32_t, CfgLevelTarget> DicCfgLevelTargets;
//
struct CfgGrade
{
	int id;//标志
	int index;//顺序(等级)
	int exp;//升级需要总经验
	std::string effect;//等级总属性
};
typedef std::map<int32_t, CfgGrade> DicCfgGrade;
//
struct CfgTraining
{
	int id;//标志
	int limitMax;//星数上限
	int valueLvBase;//基础价格
	int valueLvAdd;//每星加价
	int valueLvFull;//满星加价
	int valueOther;//换装加价
	int way0CostIdThing;//扰痒消耗物品id(金币)
	int way0CostValue;//扰痒消耗值
	int way0AddPrecent;//扰痒增加比例
	int way1CostIdThing;//刷牙消耗物品id(牙具)
	int way1CostValue;//刷牙消耗值
	int way1AddPrecent;//刷牙增加比例
	int way2CostIdThing;//换装消耗物品id(钻石)
	int way2CostValue;//换装消耗值
	int way2AddPrecent;//换装增加比例
	std::string urlPic;//换装图片
	int idPlot;//剧情id
};
typedef std::map<int32_t, CfgTraining> DicCfgTraining;
struct CfgThing
{
	int id;//标志
	std::string name;//名称
	std::string urlPic;//图片路径
	std::string desc;//描述
};
typedef std::map<int32_t, CfgThing> DicCfgThing;
//
struct CfgPlot
{
	int id;//标志
	int index;//排序
	std::string textPlot;//文字
	std::string urlPic;//图片
	float time;//单字时间（毫秒）
};
typedef std::map<int32_t, std::map<int32_t, CfgPlot>> DicDicCfgPlot;
//
struct CfgTargetAward 
{
	int id;//标志
	int target;//目标
	int award;//奖励
	int num;//数量
	std::string desc;//描述
	int idNext;//下一项标志
};
typedef std::map<int32_t, CfgTargetAward> DicCfgTargetAward;
//
//
struct CfgGuide
{
	int id;//标志
	std::string dirName;//目标（编辑器中节点名称）
	std::string desc;//描述
	int idRegion;//条件（region.cfg标志）
	int idNext;//下一项标志
};
typedef std::map<int32_t, CfgGuide> DicCfgGuide;
//
#endif