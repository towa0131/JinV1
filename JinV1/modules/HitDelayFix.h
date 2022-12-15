#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class HitDelayFix : public Module {
public:
    HitDelayFix(Core* core, const char* name, int key);

    HitDelayFix(Core* core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;
};