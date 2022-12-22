#pragma once
#include "Minecraft.h"

Minecraft::Minecraft(Core* core) : ImplClass(core, "net.minecraft.client.Minecraft") {
    GetMinecraft = getStaticMethodID("getMinecraft");
    fdRightClickDelayTimer = getFieldID("rightClickDelayTimer");
    fdLeftClickCounter = getFieldID("leftClickCounter");
    fdPlayer = getFieldID("thePlayer");
    fdFontRendererObj = getFieldID("fontRendererObj");
    fdObjectMouseOver = getFieldID("objectMouseOver");
    fdGameSettings = getFieldID("gameSettings");
}

jobject Minecraft::getMinecraft() {
    return getObject(GetMinecraft);
}

EntityPlayerSP* Minecraft::getPlayer() {
    jobject player = getObject(getMinecraft(), fdPlayer);
    if (player == NULL) std::cout << "[Error] Player is NULL!" << std::endl;
    return new EntityPlayerSP(this->core, player);
}

FontRenderer* Minecraft::getFontRenderer() {
    jobject fontRenderer = getObject(getMinecraft(), fdFontRendererObj);
    return new FontRenderer(this->core, fontRenderer);
}

GameSettings* Minecraft::getGameSettings() {
    jobject gameSettings = getObject(getMinecraft(), fdGameSettings);
    return new GameSettings(this->core, gameSettings);
}

jobject Minecraft::getObjectMouseOver() {
    return getObject(getMinecraft(), fdObjectMouseOver);
}

void Minecraft::setRightClickDelayTimer(jint rightClickDelayTimer) {
    setInt(getMinecraft(), fdRightClickDelayTimer, rightClickDelayTimer);
}

void Minecraft::setLeftClickCounter(jint leftClickCounter) {
    setInt(getMinecraft(), fdLeftClickCounter, leftClickCounter);
}