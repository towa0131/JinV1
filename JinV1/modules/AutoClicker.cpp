#pragma once
#include "AutoClicker.h"
#include "ModuleId.h"
#include "../utils/ProcessUtils.h"

AutoClicker::AutoClicker(Core* core, const char* name, int key) : AutoClicker(core, name, key, false) {

}

AutoClicker::AutoClicker(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_AUTOCLICKER, key, state) {
    ProcessUtils pu = ProcessUtils();
    this->mc = new Minecraft(this->getCore());
    this->lastClickTime = GetTickCount();
    int pid = GetCurrentProcessId();
    this->window = pu.GetWindowHandle(pid);
}

void AutoClicker::onUpdate() {
    if (GetAsyncKeyState(VK_LBUTTON) && GetTickCount() - this->lastClickTime >= 55) {
        this->lastClickTime = GetTickCount();
        POINT pos{};
        if (GetCursorPos(&pos)) {
            PostMessage(this->window, (DWORD)WM_LBUTTONDOWN, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
            PostMessage(this->window, (DWORD)WM_LBUTTONUP, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
        } else {
            std::cout << "[Error] GetCursorPos Failed" << std::endl;
        }
    }
}