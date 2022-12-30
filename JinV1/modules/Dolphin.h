#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class Dolphin : public Module {
public:
    Dolphin(Core* core, const char* name, int key);

    Dolphin(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    double speed;
};