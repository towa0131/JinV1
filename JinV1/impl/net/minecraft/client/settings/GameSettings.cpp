#include "GameSettings.h"

GameSettings::GameSettings(Core* core, jobject gameSettings) : ImplClass(core, "net.minecraft.client.settings.GameSettings") {
    this->gameSettings = gameSettings;
    this->fdKeyBindAttack = getFieldID("field_74312_F", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindJump = getFieldID("field_74314_A", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindDrop = getFieldID("field_74316_C", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindForward = getFieldID("field_74351_w", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindBack = getFieldID("field_74368_y", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindRight = getFieldID("field_74366_z", "Lnet/minecraft/client/settings/KeyBinding;");
    this->fdKeyBindLeft = getFieldID("field_74370_x", "Lnet/minecraft/client/settings/KeyBinding;");
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