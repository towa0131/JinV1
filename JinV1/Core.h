#pragma once

#include "JNI/jni.h"
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

    void run();

    void shutdown();

    void setRunning(boolean);

    ModuleManager* getModuleManager();

    JNIEnv* getEnv();
};

__declspec(selectany) Core core = Core();