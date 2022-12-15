#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class KeepSprint : public Module {
public:
    KeepSprint(Core* core, const char* name, int key);

    KeepSprint(Core* core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;
    EntityPlayerSP* player;
};