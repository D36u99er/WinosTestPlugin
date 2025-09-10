# WinosTestPlugin DLL 编译说明

## 文件列表
- `WinosTestPlugin.cpp` - 源代码文件
- `CMakeLists.txt` - CMake 构建配置
- `build.bat` - CMake 构建脚本
- `compile_direct.bat` - 直接编译脚本

## 编译方法

### 方法 1: 使用 CMake (推荐)
1. 确保安装了 Visual Studio 2019 或更新版本
2. 安装 CMake
3. 双击运行 `build.bat`
4. 生成的 DLL 位于 `build/Release/WinosTestPlugin.dll`

### 方法 2: 直接编译
1. 打开 "Developer Command Prompt for VS"
2. 导航到包含源代码的目录
3. 双击运行 `compile_direct.bat`
4. 生成的 DLL 位于当前目录

### 方法 3: 手动编译
在 Visual Studio 开发者命令提示符中运行:
```cmd
cl.exe /LD /Fe:WinosTestPlugin.dll WinosTestPlugin.cpp user32.lib
```

## 编译选项说明
- `/LD` - 生成 DLL
- `/Fe:` - 指定输出文件名
- `user32.lib` - 链接 Windows API 库 (MessageBox 需要)

## 注意事项
- 此代码必须在 Windows 系统上编译
- 需要 Visual Studio 或 Windows SDK
- 生成的 DLL 为 x64 架构 (可通过编译选项调整)