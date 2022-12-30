#pragma once
#include <unordered_map>
#include "Module.h"
#include "../impl/net/minecraft/client/Minecraft.h"

enum class Tool
{
    Sword,
    Pickaxe,
    Axe,
    Shovel,
    Shears
};

class AutoTool : public Module {
public:
    AutoTool(Core* core, const char* name, int key);

    AutoTool(Core *core, const char* name, int key, boolean state);

    void onUpdate() override;

private:
    Minecraft* mc;

    std::unordered_map<int, Tool> toolMap;

    std::map<const char*, Tool> materialMap;

    int getIndex(Tool tool);

    bool locked;
};