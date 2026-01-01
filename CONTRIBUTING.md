# Contributing to Purp3D

Thank you for your interest in contributing to Purp3D! We welcome contributions from the community and appreciate your help in making this engine better.

## How to Contribute

### Reporting Bugs
- Use the GitHub Issues tab to report bugs
- Include clear reproduction steps
- Provide system information (OS, compiler, CMake version)

### Suggesting Features
- Open an issue with the proper label
- Describe the feature and its use case
- Explain how it fits with Purp3D's goals

### Submitting Code

1. **Fork the repository** and create a new branch for your feature/fix
2. **Write clean, documented code** following the existing style
3. **Test your changes** thoroughly
4. **Submit a pull request** with a clear description of your changes

## Code Attribution

**All contributors must add attribution headers to new files they create.**

For any new source file (`.cpp`, `.h`, `.lua`, etc.), add a header comment at the top:
```cpp
// Copyright (c) 2025-2026 [Your Name or GitHub Username]
// Copyright (c) 2025-2026 ZED Interactive
```

**For modifications to existing files:**
- You do not need to add your name to the file header
- Your contribution will be tracked via Git history
- Significant rewrites or major features will warrant adding your name

**Example for a new file:**
```cpp
// Copyright (c) 2025-2026 JohnDoe
// Copyright (c) 2025-2026 ZED Interactive

#ifndef FOO_BAR
#define FOO_BAR

namespace Purp
{
    // Your code here
}

#endif
```

## Code Style Guidelines

- Use **C++20** features where appropriate
- Follow existing naming conventions:
  - `PascalCase` for classes and namespaces
  - `camelCase` for functions and variables
  - `UPPER_CASE` for constants and macros
- Keep functions focused and readable
- Add comments for complex logic
- Use `auto` where type is obvious

## Lua Scripting Contributions

- Keep the `purp.*` API clean and intuitive
- Document new Lua functions in the README
- Test scripts with the engine before submitting

## Pull Request Process

1. Ensure your code builds without errors, warnings are ok depending on the warning
2. Update documentation if you're adding features
3. Reference any related issues in your PR description
4. Be responsive to feedback during code review

## Questions?

If you have questions about contributing, feel free to:
- Open a discussion in the GitHub Discussions tab
- Reach out via Issues

We appreciate your contributions and look forward to building Purp3D together!