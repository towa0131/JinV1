#pragma once
#include "Module.h"

Module::Module(Core* core, const char* name, ModuleId moduleId) : Module(core, name, moduleId, 0) {

}

Module::Module(Core* core, const char* name, ModuleId moduleId, int key) : Module(core, name, moduleId, 0, false) {

}

Module::Module(Core* core, const char* name, ModuleId moduleId, int key, boolean state) {
    this->core = core;
    this->name = name;
    this->moduleId = moduleId;
    this->key = key;
    this->state = state;
}

Core* Module::getCore() {
    return this->core;
}

const char* Module::getName() {
    return this->name;
}

int Module::getKeyBind() {
    return this->key;
}

ModuleId Module::getModuleId() {
    return this->moduleId;
}

void Module::keyCheck() {
    if ((GetAsyncKeyState(this->getKeyBind()) & 1) && ((GetAsyncKeyState(VK_CONTROL) & 0xff00) != 0)) {
        this->toggle();
        std::cout << "[Debug] " << this->getName() << " " <<  (this->getState() ? "Enabled" : "Disabled") << std::endl;
    }
}

void Module::toggle() {
    this->setState(!this->state);
}

void Module::setState(boolean state) {
    if (state) this->onEnable();
    else this->onDisable();
    this->state = state;
}

boolean Module::getState() {
    return this->state;
}

void Module::onUpdate() {

}

void Module::onEnable() {

}

void Module::onDisable() {

}