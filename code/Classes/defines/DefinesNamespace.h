#ifndef __DEFINES_NAMESPACE_H__
#define __DEFINES_NAMESPACE_H__

#define NS_BEGIN_MODEL_DEFINE namespace model { namespace define { 
#define USING_NS_MODEL_DEFINE using namespace model::define

#define NS_BEGIN_UI_COMMON namespace userInerface { namespace common { 
#define NS_UI_COMMON(CLASS) userInerface::common::##CLASS
#define USING_NS_UI_COMMON using namespace userInerface::common

#define NS_BEGIN_GAME_ENTITY namespace game { namespace entity { 
#define NS_GAME_ENTITY(CLASS) game::entity::##CLASS
#define USING_NS_GAME_ENTITY using namespace game::entity

#define NS_END_END } }

#endif