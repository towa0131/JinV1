#pragma once
#include <map>
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

class InventoryWalk : public Module {
public:
    InventoryWalk(Core* core, const char* name, int key);

    InventoryWalk(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    std::map<int, KeyBinding*> keys;
};