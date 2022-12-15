#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class Speed : public Module {
public:
    Speed(Core* core, const char* name, int key);

    Speed(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    EntityPlayerSP* player;

    double speed;
};