#pragma once
#include "../../../../ImplClass.h"
#include "KeyBinding.h"

class GameSettings : public ImplClass {
public:
    GameSettings(Core* core, jobject gameSettings);

    KeyBinding* getKeyBindAttack();

    KeyBinding* getKeyBindJump();

    KeyBinding* getKeyBindDrop();

    KeyBinding* getKeyBindForward();

    KeyBinding* getKeyBindBack();

    KeyBinding* getKeyBindRight();

    KeyBinding* getKeyBindLeft();

private:
    jobject gameSettings;

    jfieldID fdKeyBindAttack;
    jfieldID fdKeyBindJump;
    jfieldID fdKeyBindDrop;
    jfieldID fdKeyBindForward;
    jfieldID fdKeyBindBack;
    jfieldID fdKeyBindRight;
    jfieldID fdKeyBindLeft;
};