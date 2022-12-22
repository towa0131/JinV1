#pragma once

#include "JNI/jni.h"
#include "mapping/MapTranslator.h"
#include <iostream>
#include <windows.h>

class ModuleManager;

class Core {
public:
    JavaVM* vm;
    JNIEnv* env;
    JavaVMInitArgs vm_args;

    boolean running;
    ModuleManager* moduleManager;
    MapTranslator* mapping;

    void run();

    void shutdown();

    void setRunning(boolean);

    ModuleManager* getModuleManager();

    MapTranslator* getMapping();

    JNIEnv* getEnv();
};

__declspec(selectany) Core core = Core();