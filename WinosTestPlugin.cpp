#include <windows.h>

// ----- 必须导出的 4 个接口 -----
extern "C"
{
    // 唯一指令 ID，建议 > 1000 避免和官方重复
    __declspec(dllexport) int __stdcall GetId()
    {
        return 9001;
    }

    // 插件分组名；控制端菜单会按 Group 分类
    __declspec(dllexport) const char* __stdcall GetGroup()
    {
        return "测试插件";      // UTF-8 字面量 OK
    }

    // 初始化：控制端加载 DLL 后立即调用
    // 可返回 TRUE/FALSE 表示是否加载成功
    __declspec(dllexport) BOOL __stdcall Init(HWND /*hParent*/)
    {
        MessageBoxA(nullptr, "WinosTestPlugin 已加载!", "TestPlugin", MB_OK);
        return TRUE;
    }

    // 收尾：控制端卸载插件时调用
    __declspec(dllexport) void __stdcall UnInit()
    {
        MessageBoxA(nullptr, "WinosTestPlugin 即将卸载!", "TestPlugin", MB_OK);
    }
}

// 可选：DLL 入口，仅做精简设置
BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID /*lpReserved*/)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);  // 省去多余通知
    }
    return TRUE;
}