#pragma once
#include "Module.h"
#include <set>
#include <vector>

class ModuleManager {
public:
    void registerModule(Module*);

    boolean activate(ModuleId);

    boolean deactivate(ModuleId);

    void update();

private:
    std::vector<Module*> modules;

    std::set<ModuleId> activatedModuleId;

    time_t lastUpdate;
};