#pragma once
#include "Module.h"

Module::Module(Core* core, const char* name, ModuleId moduleId) : Module(core, name, moduleId, 0) {
}

Module::Module(Core* core, const char* name, ModuleId moduleId, int key) {
    this->core = core;
    this->name = name;
    this->moduleId = moduleId;
    this->key = key;
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

void Module::onUpdate() {

}