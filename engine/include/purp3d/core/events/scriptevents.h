#ifndef SCRIPT_EVENTS_H
#define SCRIPT_EVENTS_H

#include "purp3d/core/core.h"

namespace Purp3D
{
    struct PURP_API ScriptEvent
    {
        int Type;
        bool Handled = false;

        // ---- Keyboard ----
        int KeyCode = -1;
        bool Repeat = false;

        // ---- Mouse buttons ----
        int MouseButton = -1;

        // ---- Mouse movement ----
        float MouseX = 0.0f;
        float MouseY = 0.0f;

        // ---- Mouse scroll ----
        float ScrollX = 0.0f;
        float ScrollY = 0.0f;

        // ---- Window ----
        int Width = 0;
        int Height = 0;
    };  
}

#endif