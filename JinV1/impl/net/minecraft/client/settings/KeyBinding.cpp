#include "KeyBinding.h"

KeyBinding::KeyBinding(Core* core, jobject keyBinding) : ImplClass(core, "net.minecraft.client.settings.KeyBinding") {
    this->keyBinding = keyBinding;
    this->mdGetKeyCode = getMethodID("getKeyCode");
    this->mdSetKeyBindState = getStaticMethodID("setKeyBindState");
    this->fdPressed = getFieldID("pressed");
}

jint KeyBinding::getKeyCode() {
    return getInt(this->keyBinding, this->mdGetKeyCode);
}

jboolean KeyBinding::isPressed() {
    return getBoolean(this->keyBinding, this->fdPressed);
}

void KeyBinding::setKeyBindState(jint key, jboolean state) {
    setBoolean(this->keyBinding, this->fdPressed, state);
}