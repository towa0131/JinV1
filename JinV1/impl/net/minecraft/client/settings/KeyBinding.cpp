#include "KeyBinding.h"

KeyBinding::KeyBinding(Core* core, jobject keyBinding) : ImplClass(core, "net.minecraft.client.settings.KeyBinding") {
    this->keyBinding = keyBinding;
    this->mdGetKeyCode = getMethodID("func_151463_i", "()I");
    this->mdSetKeyBindState = getStaticMethodID("func_74510_a", "(IZ)V");
    this->fdPressed = getFieldID("field_74513_e", "Z");
}

jint KeyBinding::getKeyCode() {
    return getInt(this->keyBinding, this->mdGetKeyCode);
}

jboolean KeyBinding::isPressed() {
    return getBoolean(this->keyBinding, this->fdPressed);
}

void KeyBinding::setKeyBindState(jint key, jboolean state) {
    jfieldID pressed = getFieldID("field_74513_e", "Z");
    setBoolean(this->keyBinding, pressed, state);
}