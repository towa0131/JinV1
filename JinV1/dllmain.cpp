#pragma once

#include "Core.h"
#include "rdi/ReflectiveDLLInjection.h"
#include "utils/ProcessUtils.h"
#include <thread>

extern HINSTANCE hAppInstance;
FILE* pFile = nullptr;

void initialize() {
    jsize count;
    if (JNI_GetCreatedJavaVMs(&core.vm, 1, &count) != JNI_OK || count == 0) {
        return;
    }

    jint res = core.vm->GetEnv((void**)&core.env, JNI_VERSION_1_6);

    if (res == JNI_EDETACHED) {
        if (core.vm->AttachCurrentThread((void**)&core.env, nullptr) != JNI_OK) {
            return;
        }
    }

    if (core.env != nullptr) {
        std::cout << "JinV1 by towa0131" << std::endl;
        core.run();
    } else {
        std::cout << "env = nullptr" << std::endl;
        Sleep(1000);
    }

    core.vm->DestroyJavaVM();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     ) {
    switch (ul_reason_for_call)
    {
    case DLL_QUERY_HMODULE:
        if (lpReserved != NULL)
            *(HMODULE*)lpReserved = hAppInstance;
        break;
    case DLL_PROCESS_ATTACH:
        hAppInstance = hModule;
        AllocConsole();
        freopen_s(&pFile, "CONOUT$", "w", stdout);
        std::thread(initialize).detach();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

