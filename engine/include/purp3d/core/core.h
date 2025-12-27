#ifndef CORE_H
#define CORE_H

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
#define PURP_PLATFORM_WINDOWS
#else
#error Purp3D only supports Windows for now
#endif

// Export macro
// Its a stub since the engine is built into the exe for now
#define PURP_API

#endif