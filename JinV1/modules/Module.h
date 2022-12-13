#pragma once
#include "../Core.h"
#include "ModuleId.h"

class Module {
public:
    Module(Core *core, const char* name, ModuleId moduleId);

    Module(Core *core, const char* name, ModuleId moduleId, int key);

    Core* getCore();

    const char* getName();

    int getKeyBind();

    ModuleId getModuleId();

    virtual void onUpdate();

private:
    Core* core;

    const char* name;

    ModuleId moduleId;

    int key;
};