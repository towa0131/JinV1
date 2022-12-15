#pragma once
#include "../../../../ImplClass.h"
#include "../../../../../utils/Vector3.h"

class EntityPlayerSP : public ImplClass {
public:
    EntityPlayerSP(Core *core, jobject player);

    Vector3 getVector3();

    jfloat getMoveForward();

    jfloat getYaw();

    jfloat getPitch();

    jboolean isDead();

    void setSprinting(jboolean sprinting);

    void setMotion(Vector3 vec);

    Vector3 getMotion();

    void swingItem();

private:
    jobject player;
    jfieldID fdPosX;
    jfieldID fdPosY;
    jfieldID fdPosZ;
    jfieldID fdMotionX;
    jfieldID fdMotionY;
    jfieldID fdMotionZ;
    jfieldID fdYaw;
    jfieldID fdPitch;
    jfieldID fdIsDead;
    jfieldID fdMoveForward;
    jmethodID fdSetSprinting;
    jmethodID fdSwingItem;
};