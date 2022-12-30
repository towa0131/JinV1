#pragma once
#include "Minecraft.h"

Minecraft::Minecraft(Core* core) : ImplClass(core, "net.minecraft.client.Minecraft") {
    GetMinecraft = getStaticMethodID("getMinecraft");
    fdRightClickDelayTimer = getFieldID("rightClickDelayTimer");
    fdLeftClickCounter = getFieldID("leftClickCounter");
    fdWorld = getFieldID("theWorld");
    fdPlayer = getFieldID("thePlayer");
    fdFontRendererObj = getFieldID("fontRendererObj");
    fdObjectMouseOver = getFieldID("objectMouseOver");
    fdGameSettings = getFieldID("gameSettings");
    fdCurrentScreen = getFieldID("currentScreen");
}

jobject Minecraft::getMinecraft() {
    return getObject(GetMinecraft);
}

WorldClient Minecraft::getWorld() {
    jobject world = getObject(getMinecraft(), fdWorld);
    if (world == NULL) std::cout << "[Error] World is NULL!" << std::endl;
    return WorldClient(this->core, world);
}

EntityPlayerSP Minecraft::getPlayer() {
    jobject player = getObject(getMinecraft(), fdPlayer);
    if (player == NULL) std::cout << "[Error] Player is NULL!" << std::endl;
    return EntityPlayerSP(this->core, player);
}

FontRenderer Minecraft::getFontRenderer() {
    jobject fontRenderer = getObject(getMinecraft(), fdFontRendererObj);
    return FontRenderer(this->core, fontRenderer);
}

GameSettings Minecraft::getGameSettings() {
    jobject gameSettings = getObject(getMinecraft(), fdGameSettings);
    return GameSettings(this->core, gameSettings);
}

MovingObjectPosition Minecraft::getObjectMouseOver() {
    jobject objectPosition = getObject(getMinecraft(), fdObjectMouseOver);
    return MovingObjectPosition(this->core, objectPosition);
}

jobject Minecraft::getCurrentScreen() {
    return getObject(getMinecraft(), fdCurrentScreen);
}

void Minecraft::setRightClickDelayTimer(jint rightClickDelayTimer) {
    setInt(getMinecraft(), fdRightClickDelayTimer, rightClickDelayTimer);
}

void Minecraft::setLeftClickCounter(jint leftClickCounter) {
    setInt(getMinecraft(), fdLeftClickCounter, leftClickCounter);
}

bool Minecraft::isInWorld() {
    jobject world = getObject(getMinecraft(), fdWorld);
    jobject player = getObject(getMinecraft(), fdPlayer);
    return world != NULL && player != NULL;
}