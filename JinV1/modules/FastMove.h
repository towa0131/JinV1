#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class FastMove : public Module {
public:
    FastMove(Core* core, const char* name, int key);

    FastMove(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    EntityPlayerSP* player;

    double speed;
};