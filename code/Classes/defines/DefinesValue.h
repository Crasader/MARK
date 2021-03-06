#pragma execution_character_set("utf-8")

#ifndef __COMMON_DEFINE_DEFINES_VALUE_H__
#define __COMMON_DEFINE_DEFINES_VALUE_H__

#define TIME_LAST_SAVE_INTERVAL 300
#define TIME_OFF_LINE_MAX 172800
#define TRAINING_NUM_RST_INTERVAL 3600
#define TRAINING_NUM_RST_VALUE 1

#define DATA_UNLOCK_INIT_MAID 1000//初始化时默认解锁的女仆
#define DATA_UNLOCK_INIT_LEVEL 1000//初始化时默认解锁的关卡

#define ID_GRADE_FIRST 1000//第一个等级id

#define GRID_SELECT_MAX 9
#define GRID_SELECTED_MAX 3
#define ENTITY_BATTLE_MAX 3

#define ENERGY_SWITCH_ENTITY 8

#define BREAK_DAMAGE_TAKES 5

#define LENGTH_INFO_THING 2
#define LENGTH_INFO_CATCH_MST 4

#define TRAINING_NUM_MAX 3

#define vecPostionGridBattle \
{ \
	Vec2(160.0f, 620.0f), Vec2(480.0f, 340.0f), Vec2(320.0f, 480.0f) \
}

#define dicAnchorPoint2BubbleAnchorPoint \
{ \
	{ Vec2::ANCHOR_BOTTOM_LEFT, Vec2(1.0f, 1.0f) }, { Vec2::ANCHOR_BOTTOM_RIGHT, Vec2(0.0f, 1.0f) }, { Vec2::ANCHOR_TOP_RIGHT, Vec2(0.0f, 0.0f) }, { Vec2::ANCHOR_TOP_LEFT, Vec2(1.0f, 0.0f) } \
}

#define dicAnchorPoint2BubbleBgScale \
{ \
	{ Vec2::ANCHOR_BOTTOM_LEFT, Vec2(1.0f, 1.0f) }, { Vec2::ANCHOR_BOTTOM_RIGHT, Vec2(-1.0f, 1.0f) }, { Vec2::ANCHOR_TOP_RIGHT, Vec2(-1.0f, -1.0f) }, { Vec2::ANCHOR_TOP_LEFT, Vec2(1.0f, -1.0f) } \
}

#define sizeSkillIcon Size(100.0f, 100.0f)
#define sizeSkillAttribute Size(55.0f, 55.0f)
#define sizeStarLevels Size(20.0f, 20.0f)
#define sizeStarTrainingLv Size(50.0f, 50.0f)
#define sizeStarBattleResult Size(114.0f, 110.0f)

#define moveDistanceVictoryDefeat Vec2(0.0f, 345.0f)
#define vecMoveDistanceSpriteMaid \
{ \
	Vec2(470.0f, 0.0f), Vec2(280.0f, 0.0f), Vec2(-240.0f, 0.0f) \
}
#define moveDistanceGradeUp Vec2(0.0f, 255.0f)

enum class TypeLoadState
{
	UNLOAD,//未加载
	LOADING,//加载中
	LOADED//加载完成
};

enum class IdAttribute
{
	ATTRIBUTE_NONE,

	ENTITY_HP = 100,//血量
	ENTITY_HP_MAX,//血量上限
	ENTITY_ENERGY,//能量
	ENTITY_ENERGY_MAX,//能量上限
	ENTITY_PHYSICAL_ATTACK,//物理攻击
	ENTITY_MAGIC_ATTACK,//魔法攻击
	ENTITY_GOLD_GENERATE,//生成宝箱
	ENTITY_GOLD_INCOME,//金币收益
	ENTITY_STONE_GENERATE,//生成石头
	ENTITY_STONE_CRUSHED,//击碎石头
	ENTITY_ICE_GENERATE,//生成冰块
	ENTITY_ICE_MELTING,//融化冰块
	ENTITY_TRAP_GENERATE,//生成陷阱
	ENTITY_TRAP_DISARM,//解除陷阱
	ENTITY_SWITCH,//切换角色
	ENTITY_KILL_NUM,//击杀
	ENTITY_BREAK_CASE_NUM,//造成破衣次数
	ENTITY_BREAK_TAKES_NUM,//受到破衣次数
	ENTITY_GOLD_INCOME_NUM,//金币收益次数
	ENTITY_STONE_CRUSHED_NUM,//击碎石头次数
	ENTITY_ICE_MELTING_NUM,//融化冰块次数
	ENTITY_TRAP_DISARM_NUM,//解除陷阱次数
	ENTITY_PHYSICAL_ATTACK_EXTRA,//额外物理攻击
	ENTITY_MAGIC_ATTACK_EXTRA,//额外魔法攻击

	ENTITY_QUICK = 150,//快速攻击
	ENTITY_DAMAGE_CASE,//造成伤害
	ENTITY_DAMAGE_TAKES,//受到伤害
	ENTITY_RESTORE_HP,//恢复生命
	ENTITY_COST_HP,//消耗生命
	ENTITY_RESTORE_ENERGY,//恢复能量
	ENTITY_COST_ENERGY,//消耗能量
	ENTITY_RESTORE_HP_ALL,//全体恢复生命
	ENTITY_COST_HP_ALL,//全体消耗生命
	ENTITY_DAMAGE_CASE_EXTRA,//额外造成伤害
	ENTITY_DAMAGE_TAKES_EXTRA,//额外受到伤害
	ENTITY_DAMAGE_BREAK_COUNT,//破衣伤害计数
	ENTITY_BREAK_TAKES,//受到破衣

	GRID_DAMAGE_PHYSICAL = 200,//物理伤害
	GRID_DAMAGE_MAGIC,//魔法伤害
	GRID_DAMAGE_ANY,//任意伤害
	GRID_BLOCK_PHYSICAL,//物理抵挡
	GRID_BLOCK_MAGIC,//魔法抵挡
	GRID_BLOCK_ANY,//任意抵挡
	GRID_UNBLOCKABLE,//不可抵挡
	GRID_QUICK,//快速攻击
	GRID_RESTORE_HP,//恢复生命
	GRID_COST_HP,//消耗生命
	GRID_RESTORE_HP_CANCEL,//取消恢复生命
	GRID_COST_HP_CANCEL,//取消消耗生命
	GRID_RESTORE_ENERGY,//恢复能量
	GRID_COST_ENERGY,//消耗能量
	GRID_RESTORE_ENERGY_CANCEL,//取消恢复能量
	GRID_COST_ENERGY_CANCEL,//取消消耗能量
	GRID_RESTORE_HP_ALL,//全体恢复生命
	GRID_COST_HP_ALL,//全体消耗生命
	GRID_BLOCK_ALL,//抵挡所有伤害
	GRID_DAMAGE_PHYSICAL_EXTRA,//额外物理伤害
	GRID_DAMAGE_MAGIC_EXTRA,//额外魔法伤害

	GRID_GOLD = 250,//宝箱
	GRID_STONE,//石头
	GRID_ICE,//冰块
	GRID_TRAP,//陷阱
	GRID_GOLD_GET,//宝箱获得
	GRID_STONE_CRUSHED,//石头击碎
	GRID_ICE_MELTING,//冰块融化
	GRID_TRAP_TRIGGER,//陷阱触发
	GRID_TRAP_DISARM,//陷阱解除

	GRID_PHYSICAL_DAMAGE_SUCCESS = 300,//物理伤害成功
	GRID_PHYSICAL_DAMAGE_FAILED,//物理伤害失败
	GRID_PHYSICAL_BLOCK_SUCCESS,//物理抵挡成功
	GRID_PHYSICAL_BLOCK_FAILED,//物理抵挡失败
	GRID_MAGIC_DAMAGE_SUCCESS,//魔法伤害成功
	GRID_MAGIC_DAMAGE_FAILED,//魔法伤害失败
	GRID_MAGIC_BLOCK_SUCCESS,//魔法抵挡成功
	GRID_MAGIC_BLOCK_FAILED,//魔法抵挡失败
	GRID_ANY_DAMAGE_SUCCESS,//任意伤害成功
	GRID_ANY_DAMAGE_FAILED,//任意伤害失败
	GRID_ANY_BLOCK_SUCCESS,//任意抵挡成功
	GRID_ANY_BLOCK_FAILED,//任意抵挡失败
	GRID_N_PHYSICAL_DAMAGE,//造成n点物理伤害//n为0表示每点
	GRID_N_PHYSICAL_TAKES,//受到n点物理伤害//n为0表示每点
	GRID_N_PHYSICAL_BLOCK,//抵挡n点物理伤害//n为0表示每点
	GRID_N_MAGIC_DAMAGE,//造成n点魔法伤害//n为0表示每点
	GRID_N_MAGIC_TAKES,//受到n点魔法伤害//n为0表示每点
	GRID_N_MAGIC_BLOCK,//抵挡n点魔法抵挡//n为0表示每点
	GRID_N_ANY_DAMAGE,//造成n点任意伤害//n为0表示每点
	GRID_N_ANY_TAKES,//受到n点任意伤害//n为0表示每点
	GRID_N_ANY_BLOCK,//抵挡n点任意伤害//n为0表示每点
	GRID_OWN_UNBLOCKABLE,//拥有不可抵挡
	GRID_TAKEN_UNBLOCKABLE,//受到不可抵挡
	GRID_OWN_QUICK,//拥有快速攻击
	GRID_TAKEN_QUICK,//受到快速攻击
	GRID_CERTAINLY,//一定触发
	GRID_UNOWN_UNBLOCKABLE,//不拥有不可抵挡
	GRID_UNTAKEN_UNBLOCKABLE,//不受到不可抵挡
	GRID_UNOWN_QUICK,//不拥有快速攻击
	GRID_UNTAKEN_QUICK,//不受到快速攻击
	GRID_OWN_RESTORE_HP,//拥有恢复生命
	GRID_OWN_COST_HP,//拥有消耗生命

	GRID_EFFECTIVE_ROUND = 400,//第n轮生效//n为0表示当前回合
	GRID_EFFECTIVE_ROUND_COUNT,//持续n个轮
	GIRD_EFFECTIVE_TO_OTHER,//对对方
	GRID_EFFECTIVE_EACH//每点
};

enum class TypeAttribute
{
	NONE,
	ENTITY,//实体属性
	GRID_BASE,//格子基本属性
	GRID_IF,//格子条件属性
	GRID_COMPLEX,//格子复合属性
};

enum class TypeEntity
{
	NONE,
	MAID,//女仆
	MONSTER//怪物
};

enum class TypeJob
{
	NONE,
	ROGUE,//盗贼
	WARRIOR,//战士
	MAGE,//法师
	TREAT,//治疗
	TANK,//坦克
	ARCHER//弓手
};

enum class TypeSkill
{
	NONE,
	BASE,
	SPECIAL,
	ENERGY,
	PASSIVE,//被动
	RANDOM//随机
};

enum class TypeSkillGroup
{
	NONE,
	HP_PERCENT,//血量百分比
	ENERGY_VALUE,//能量值
	ROUND_TOTAL,//总回合
	ROUND,//回合
};

enum class TypeLevelState
{
	NONE,
	PASSED,//已通过
	CURRENT,//当前
	LOCK//未开启
};

enum class TypeLevelTarget
{
	NONE,
	HP_MST,//血量怪物 正数大于，负数小于
	HP_MAID,//血量女仆 正数大于，负数小于
	PASS,//通关
	KILL,//击杀
	BREAK,//破衣
	GOLD,//获得金币
	STONE,//击碎石头
	ICE,//融化冰块
	TRAP//解除陷阱
};

enum class TypeUnlock
{
	LAST_NEXT
};

enum class TypeNodeHead
{
	NONE,
	LARGE,
	MIDDLE,
	SMALL
};

enum class TypeSRP
{
	NONE,
	SCISSORS,
	ROCK,
	PAPER
};

enum class TypeTrianing
{
	NONE,
	WAY0,//挠痒
	WAY1,//牙刷
	WAY2,//换装
};

enum class IdThing
{
	THING_NONE,

	GOLD = 100,//金币
	DIAMOND,//钻石
	EXP,//经验
	TRAINING,//调教
	DATING,//约会

	TOOTHBRUSH = 200,//牙刷

	CLOTH = 300,//时装
};

enum class TypeConfirms
{
	MAP_TRANSFER,
	OFF_LINE_DROP,
	BUY_ACTION_POINT,
	BUY_CARRIAGE,
	BUY_MAID_CLOTHS
};

enum class TypeTips
{
	ERRORS,
	THING_UNLOCK,
	MONSTER,
	THING,
	SKILL,
	TARGET_AWARD
};

enum class TypeScene
{
	WELCOME,
	PLOT,
	MAIN,
};

enum class ID_OBSERVER
{
	HANDLE_SCENE_GAME,
	HANDLE_LAYER_ENTITY
};

enum class TO_HANDLE_SCENE_GAME
{
	LAYER_RES_LOAD_ADD,
	LAYER_RES_LOAD_REMOVE,
	LAYER_ENTITY_ADD,
	LAYER_ENTITY_REMOVE,
	LAYER_MENU_SET_ADD,
	LAYER_MENU_SET_REMOVE,
	LAYER_MENU_SET_SWITCH,
	LAYER_MENU_SYSTEM_ADD,
	LAYER_MENU_SYSTEM_REMOVE,
	LAYER_ACROSS_ADD,
	LAYER_ACROSS_REMOVE,
};

enum class TO_HANDLE_LAYER_ENTITY
{
	ENTITY_CREATED,
	GAME_START,
	GAME_STOP
};

enum class TYPE_OBSERVER_SCENE_MAIN
{
	UPDATE_LAYOUT_TOP,
	SWITCH_LAYER,

	SHOW_NONE = 10,
	SHOW_GUILD,
	SHOW_SKILLS,
	SHOW_SHOP,
	SHOW_TRAINING,
	SHOW_LEVELS,
	SHOW_BATTLE
};

enum class TYPE_OBSERVER_LAYER_BATTLE
{
	SHOW_APPEAR_GRID_SELECTED_MST,//显示怪物选中格子出现动画
	SHOW_LAYER_GRID_SELECT,//添加格子选择层，显示出现动画
	SHOW_APPEAR_GRID_SELECT_MAID,//显示女仆选择格子出现动画
	HIDE_LAYER_GRID_SELECT,//移除格子选择层，显示消失动画
	UPDATE_TXT_ROUND,
	SHOW_LAYER_CATCH,
	SHOW_LAYER_BATTLE_RESULT,
	SHOW_LAYER_GRADE_UP,
	RESET_SKIN
};

enum class TYPE_OBSERVER_LAYER_GRID_SELECT
{
	RUN_MAID_GRID_MOVE_FROM_ACTION_ONE_BACK,
	RUN_MAID_GRID_MOVE_FROM_ACTION_ALL_BACK,
	RUN_MAID_GRID_MOVE_FROM_ACTION_TAKE_BACK,
	RUN_MAID_GRID_PLAY_SPECIAL_STH_GENERATE,
	RUN_MAID_GRID_SCALE_BIG,
	RUN_MAID_GRID_SCALE_SMALL
};

enum class TYPE_OBSERVER_HANDLE_GRID
{
	RUN_ACTION_GRID_SELECTED_MOVE_FROM_SELECT,//显示女仆格子从选择格子移动到选中格子的动画
	RUN_GRID_MOVE_AND_THROW,//轮开始执行
	UPDATE_GRID
};

enum class TYPE_OBSERVER_HANDLE_HEAD
{
	UPDATE_HP,//参数：是否为怪物
	UPDATE_HP_ALL,//参数：是否为怪物
	SHOW_WORDS_DRIFT,//const bool &isMst, const int &indexNodeHead, const int &valueChange, const IdAttribute &idAttributeBeChange, const Color4B &color, const double &duration
	SHOW_WORDS_DRIFT_ALL,//const bool &isMst, const int &valueChange, const IdAttribute &idAttributeBeChange, const Color4B &color, const double &duration
	UPDATE_ENERGY,//参数：是否为怪物
	SWITCH_NODE_HEAD_TO,//参数：是否为怪物，切换目标index
	SWITCH_LAYOUT_HEAD_MAID_TOUCHABLE//参数：是否可触摸
};

enum class TYPE_OBSERVER_LAYER_GUILD
{
	SWITCH_LAYOUT,//切换显示内容

	LAYOUT_SELECT = 10,
	LAYOUT_DATING,
	LAYOUT_RESULT
};

enum class TYPE_OBSERVER_HANDLE_ENTITY
{
	RUN_ENTITY_APPEAR,
	RUN_ENTITY_ACTION,
	DEAL_ROUND_OVER,
	UPDATE_HP,
	UPDATE_ENERGY
};

#define  dicTypeLevelTarget2IdAttribute \
{ \
	{ TypeLevelTarget::KILL, IdAttribute::ENTITY_KILL_NUM }, \
	{ TypeLevelTarget::BREAK, IdAttribute::ENTITY_BREAK_CASE_NUM }, \
	{ TypeLevelTarget::GOLD, IdAttribute::ENTITY_GOLD_INCOME_NUM }, \
	{ TypeLevelTarget::STONE, IdAttribute::ENTITY_STONE_CRUSHED_NUM }, \
	{ TypeLevelTarget::ICE, IdAttribute::ENTITY_ICE_MELTING_NUM }, \
	{ TypeLevelTarget::TRAP, IdAttribute::ENTITY_TRAP_DISARM_NUM } \
}

#endif