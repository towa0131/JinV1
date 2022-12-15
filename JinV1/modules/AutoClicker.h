#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class AutoClicker : public Module {
public:
    AutoClicker(Core* core, const char* name, int key);

    AutoClicker(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    time_t lastClickTime;

    HWND window;
};