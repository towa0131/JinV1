#pragma once
#include "../../../../ImplClass.h"
#include "../../../../../utils/Vector3.h"

class EntityPlayerSP : public ImplClass {
public:
    EntityPlayerSP(Core *core, jobject player);

    Vector3 getVector3();

    jfloat getMoveForward();

    void setSprinting(jboolean);

    void swingItem();

private:
    jobject player;
    jfieldID fdPosX;
    jfieldID fdPosY;
    jfieldID fdPosZ;
    jfieldID fdMoveForward;
    jmethodID fdSetSprinting;
    jmethodID fdSwingItem;
};