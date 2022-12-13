#pragma once
#include "Module.h"
#include <set>
#include <vector>

class ModuleManager {
public:
    void registerModule(Module*);

    void registerModule(Module*, boolean);

    void activate(ModuleId);

    void deactivate(ModuleId);

    void update();

private:
    std::vector<Module*> modules;

    std::set<ModuleId> activatedModuleId;
};