#pragma once
#include "ModuleManager.h"

void ModuleManager::registerModule(Module *m) {
    this->modules.push_back(m);
    std::cout << "[Debug] Module Registered: " << m->getName() << std::endl;
}

boolean ModuleManager::activate(ModuleId id) {
    for (Module* m : this->modules) {
        if (m->getModuleId() == id) {
            m->setState(true);
            return true;
        }
    }
    return false;
}

boolean ModuleManager::deactivate(ModuleId id) {
    for (Module* m : this->modules) {
        if (m->getModuleId() == id) {
            m->setState(false);
            return true;
        }
    }
    return false;
}

void ModuleManager::update() {
    for (Module *m : this->modules) {
        m->keyCheck();
        if (m->getState()) m->onUpdate();
    }
}