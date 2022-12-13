#pragma once
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class FastPlace : public Module {
public:
    FastPlace(Core *core, const char* name, int key);

    void onUpdate() override;

private:
    Minecraft* mc;
};