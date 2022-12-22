#pragma once
#include "../../../../ImplClass.h"

class BridgeManager : public ImplClass {
public:
    BridgeManager(Core* core);

    jobject getMinecraftBridge();

private:
    jmethodID GetMinecraftBridge;
};