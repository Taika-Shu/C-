# Home Automation System - README

## Development Environment Configuration

### Platform Setup

#### **macOS**
| Tool | Installation Command |
|------|---------------------|
| Homebrew | `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` |
| cpprestsdk | `brew install cpprestsdk openssl` |
| CMake | `brew install cmake` |
| Node.js | `brew install node` |

#### **Windows**
| Tool | Installation Command |
|------|---------------------|
| vcpkg | `git clone https://github.com/microsoft/vcpkg` → `.\vcpkg\bootstrap-vcpkg.bat` |
| cpprestsdk | `.\vcpkg install cpprestsdk:x64-windows` |

### Toolchain Overview

| Tool | Purpose |
|------|---------|
| **CMake** | Cross-platform build system (generates Makefile / Visual Studio projects) |
| **cpprestsdk** | Microsoft C++ REST SDK (provides HTTP/JSON/WebSocket functionality) |
| **SQLite3** | Lightweight embedded database (no separate server required) |
| **React** | Frontend framework (real-time data display) |
| **Discord Webhook** | Message notifications |

## C++ Core Concepts

### String Handling
```cpp
#define USTRING_STD_STRING  // Force cpprestsdk to use std::string instead of std::wstring
utility::conversions::to_utf8string()  // Convert cpprest string to std::string
```

### Lambda Expressions
```cpp
auto func = [](int x) { return x * 2; };
```

### SQLite3 C API
```cpp
sqlite3_open("database.db", &db);  // Open database connection
```

### Common Syntax Reference

| Syntax | Description |
|--------|-------------|
| `auto x = ...` | Automatic type deduction |
| `std::map<std::string, double>` | Key-value pair container |
| `std::thread([]() { ... }).detach()` | Background thread execution |
| `#ifdef VIRTUAL_MODE` | Conditional compilation |

## Learning Path Recommendation

### Step-by-Step Guide

1. **Start with Virtual Mode**
   - Enable `VIRTUAL_MODE` in `CMakeLists.txt`
   - Observe `home_automation.db` and Discord notifications
   - Understand the system flow without hardware

2. **Launch React Dashboard**
   ```bash
   cd dashboard && npm start
   ```
   - Monitor real-time data visualization
   - Familiarize with the UI components

3. **Switch to Real Mode**
   - Comment out `VIRTUAL_MODE` definition
   - Use `curl` to send actual sensor data:
   ```bash
   curl -X POST http://localhost:8080/api/data \
        -H "Content-Type: application/json" \
        -d '{"temperature": 25.5, "humidity": 60}'
   ```

4. **Experiment with Extensions**
   - Modify notification logic
   - Add new sensor types
   - Customize database schema

## 🚀 Final Notes

- All code has been tested and verified on **macOS with cpprestsdk 2.10.18**
- Seamless switching between virtual and real modes
- Complete learning path included for gradual progression
- The system is modular and easily extensible

### Quick Start Commands
```bash
# Build the project
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make

# Run the server
./home_automation

# Start the dashboard (in separate terminal)
cd dashboard
npm install
npm start
```

### Troubleshooting
- Ensure all dependencies are correctly installed
- Check port availability (8080 for server, 3000 for dashboard)
- Verify database file permissions
- Monitor system logs for detailed error information

---
