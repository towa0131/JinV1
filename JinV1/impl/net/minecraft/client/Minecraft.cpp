#pragma once
#include "Minecraft.h"

Minecraft::Minecraft(Core* core) : ImplClass(core, "net.minecraft.client.Minecraft") {
    GetMinecraft = getStaticMethodID("func_71410_x", "()Lnet/minecraft/client/Minecraft;");
    fdRightClickDelayTimer = getFieldID("field_71467_ac", "I");
    fdLeftClickCounter = getFieldID("field_71429_W", "I");
    fdPlayer = getFieldID("field_71439_g", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    fdFontRendererObj = getFieldID("field_71466_p", "Lnet/minecraft/client/gui/FontRenderer;");
    fdObjectMouseOver = getFieldID("field_71476_x", "Lnet/minecraft/util/MovingObjectPosition;");
    fdGameSettings = getFieldID("field_71474_y", "Lnet/minecraft/client/settings/GameSettings;");
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