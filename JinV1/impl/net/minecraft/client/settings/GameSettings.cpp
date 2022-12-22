#include "GameSettings.h"

GameSettings::GameSettings(Core* core, jobject gameSettings) : ImplClass(core, "net.minecraft.client.settings.GameSettings") {
    this->gameSettings = gameSettings;
    this->fdKeyBindAttack = getFieldID("keyBindAttack");
    this->fdKeyBindJump = getFieldID("keyBindJump");
    this->fdKeyBindDrop = getFieldID("keyBindDrop");
    this->fdKeyBindForward = getFieldID("keyBindForward");
    this->fdKeyBindBack = getFieldID("keyBindBack");
    this->fdKeyBindRight = getFieldID("keyBindRight");
    this->fdKeyBindLeft = getFieldID("keyBindLeft");
}

KeyBinding* GameSettings::getKeyBindAttack() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindAttack);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindJump() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindJump);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindDrop() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindDrop);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindForward() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindForward);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindBack() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindBack);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindRight() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindRight);
    return new KeyBinding(this->core, keyBinding);
}

KeyBinding* GameSettings::getKeyBindLeft() {
    jobject keyBinding = getObject(this->gameSettings, this->fdKeyBindLeft);
    return new KeyBinding(this->core, keyBinding);
}