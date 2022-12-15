#pragma once
#include "../Core.h"
#include "ModuleId.h"

class Module {
public:
    Module(Core *core, const char* name, ModuleId moduleId);

    Module(Core *core, const char* name, ModuleId moduleId, int key);

    Module(Core* core, const char* name, ModuleId moduleId, int key, boolean state);

    Core* getCore();

    const char* getName();

    int getKeyBind();

    ModuleId getModuleId();

    void keyCheck();

    void toggle();

    void setState(boolean state);

    boolean getState();

    virtual void onUpdate();

    virtual void onEnable();

    virtual void onDisable();

private:
    Core* core;

    boolean state;

    const char* name;

    ModuleId moduleId;

    int key;
};