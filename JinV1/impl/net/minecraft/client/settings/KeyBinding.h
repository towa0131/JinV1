#pragma once
#include "../../../../ImplClass.h"

class KeyBinding : public ImplClass {
public:
    KeyBinding(Core* core, jobject keyBinding);

    jint getKeyCode();

    jboolean isPressed();

    void setKeyBindState(jint key, jboolean state);

private:
    jobject keyBinding;

    jfieldID fdPressed;

    jmethodID mdGetKeyCode;
    jmethodID mdSetKeyBindState;
};