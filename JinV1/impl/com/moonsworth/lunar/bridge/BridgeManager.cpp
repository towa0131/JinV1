#pragma once
#include "BridgeManager.h"

BridgeManager::BridgeManager(Core* core) : ImplClass(core, "com.moonsworth.lunar.bridge.BridgeManager") {
    this->GetMinecraftBridge = getStaticMethodID("getMinecraftBridge");
    if (this->GetMinecraftBridge == NULL) {
        std::cout << "GetMinecraftBridge is NULL" << std::endl;
    }
}

jobject BridgeManager::getMinecraftBridge() {
    return getObject(this->GetMinecraftBridge);
}