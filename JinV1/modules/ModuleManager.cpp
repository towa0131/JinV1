#pragma once
#include "ModuleManager.h"

void ModuleManager::registerModule(Module *m) {
    this->registerModule(m, false);
}

void ModuleManager::registerModule(Module *m, boolean activate) {
    this->modules.push_back(m);
    std::cout << "[Debug] Module Registerd : " << m->getName() << std::endl;
    if (activate) this->activate(m->getModuleId());
}

void ModuleManager::activate(ModuleId id) {
    this->activatedModuleId.insert(id);
}

void ModuleManager::deactivate(ModuleId id) {
    this->activatedModuleId.erase(id);
}

void ModuleManager::update() {
    for (Module *m : this->modules) {
        m->onUpdate();
    }
}