#ifndef PURP3D_H
#define PURP3D_H

//////////////////////////////////
///// PURP3D ENGINE INCLUDES /////
//////////////////////////////////
#include "purp3d/core/core.h"
#include "purp3d/core/application.h"
#include "purp3d/core/applicationspecification.h"
#include "purp3d/core/window.h"
#include "purp3d/core/windowspecification.h"
#include "purp3d/core/events/event.h"
#include "purp3d/core/events/eventdispatcher.h"
#include "purp3d/core/events/eventqueue.h"
#include "purp3d/core/events/windowevents.h"
#include "purp3d/core/events/keyevents.h"
#include "purp3d/core/events/mouseevents.h"
#include "purp3d/core/layer/layer.h"

///////////////////////////////////
//////////// RENDERER ////////////
//////////////////////////////////
#include "purp3d/renderer/glutils.h"
#include "purp3d/renderer/renderer.h"
#include "purp3d/renderer/shader.h"

#ifdef INCLUDE_ENTRY_POINT
///////////////////////////////////
/////////// ENTRY POINT ///////////
//////////////////////////////////
#include "purp3d/core/entrypoint.h"
#endif

///////////////////////////////////
/////// THIRDPARTY INCLUDES ///////
//////////////////////////////////
#include <glm/glm.hpp>

#endif