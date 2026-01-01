# Purp3D

Purp3D is a lightweight C++20 game engine focused on fast iteration and Lua-driven gameplay.  
The engine is designed to keep core systems minimal while exposing a clean, high-level scripting API for game logic.  
Lua scripting is integrated as a first-class system, allowing most gameplay code to live outside of C++.

## Features

- Modern C++20 codebase
- Layer-based application architecture
- Deferred event system
- Lua scripting via **Lua + sol2**
- Clean scripting API (`purp.*`)
- OpenGL renderer
- ImGui integration
- Currently only tested on windows

## Building

### Requirements

- CMake 3.10+
- C++20 compatible compiler
- Git

### Build Options

Purp3D can be built using **CMake GUI**, **CMake CLI**, or any IDE with integrated CMake support.

**NOTE:** Make sure to clone the repo recursively, as most third-party libraries are submodules!

**Using CMake GUI:**
```bash
git clone --recursive https://github.com/CallMeTerry-ZED/Purp3D.git
cd Purp3D
cmake-gui
```

Then:
1. Set the source path to the Purp3D repo
2. Set the build path (e.g., `project-build/vs2022` for Visual Studio 2022)
3. Configure the project and select your generator (e.g., Visual Studio, Ninja)
4. Generate and open the project in your IDE

**Using CMake CLI:**
```bash
git clone --recursive https://github.com/CallMeTerry-ZED/Purp3D.git
cd Purp3D
cmake -S . -B build
cmake --build build
```

You can replace `build` with any preferred folder, and choose the generator as needed.  
The output executable will be generated in the specified build directory.

## Scripting

Lua scripting provides a first-class interface for gameplay logic.  
The scripting system exposes engine features in a clean `purp.*` namespace without requiring C++ knowledge.

### Example
```lua
function purp.start()
    purp.clientlog.info("Lua started")
end

function purp.update(dt)
    purp.clientlog.trace("dt = " .. dt)
end

function purp.onevent(e)
    if e.type == purp.event.WindowResize then
        purp.clientlog.info("Window resized")
        e.handled = true
    end
end
```

### API Overview

- `purp.clientlog` – logging (trace/info/warn/error)
- `purp.serverlog` – logging (trace/info/warn/error)
- `purp.event` – event utilities (e.g., mark_handled)
- `purp.quit()` – stop the application

The Lua scripting system is fully integrated with the engine's deferred event queue and update loop.  
Scripts are executed on start, update, and event dispatch automatically.

### Lua Development Setup

For the best Lua scripting experience, we recommend using **Visual Studio Code** or any VS Code-based IDE (VSCodium, Cursor, etc.).

**Install our official VS Code extension for IntelliSense support:**

🔗 [Purp3D VS Code Snippets Extension](https://github.com/CallMeTerry-ZED/Purp3DVSCodeSnipets)

This extension provides:
- Autocomplete for all `purp.*` API functions
- IntelliSense tooltips with function signatures
- Code snippets for common patterns
- Syntax highlighting for Purp3D-specific Lua code

**Installation:**
1. Clone or download the extension repository
2. Open the extension folder in VS Code
3. Press `F5` to launch a new VS Code window with the extension loaded
4. Or package it as a `.vsix` and install it manually

This significantly improves the Lua scripting workflow and helps avoid typos in API calls.

## Planned

Purp3D is under active development. Future plans include:

- **ECS (Entity Component System)** – for more flexible game object management
- **Additional scripting languages** – Python, C#, TypeScript, etc.
- **Platform support expansion** – MacOS, Linux, and consoles including Nintendo Switch, Switch 2, PS5, Xbox Series X/S, and more
- **Asset pipeline and hot-reloading improvements**

The engine is designed to allow future expansion without breaking existing Lua workflows.  
Lua is the main scripting language and will be supported long term.

## Contributing

Contributions are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) before submitting pull requests.

## License

This project is licensed under the MIT License – see [LICENSE](LICENSE)
