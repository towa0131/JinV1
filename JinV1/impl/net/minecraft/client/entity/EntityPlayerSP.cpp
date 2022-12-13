#pragma once
#include "EntityPlayerSP.h"

EntityPlayerSP::EntityPlayerSP(Core* core, jobject player) : ImplClass(core, "net.minecraft.client.entity.EntityPlayerSP") {
    this->player = player;
    this->fdPosX = getFieldID("field_70165_t", "D");
    this->fdPosY = getFieldID("field_70163_u", "D");
    this->fdPosZ = getFieldID("field_70161_v", "D");
    this->fdMoveForward = getFieldID("field_70701_bs", "F");
    this->fdSetSprinting = getMethodID("func_70031_b", "(Z)V");
    this->fdSwingItem = getMethodID("func_71038_i", "()V");
}

Vector3 EntityPlayerSP::getVector3() {
    jdouble x = getDouble(this->player, this->fdPosX);
    jdouble y = getDouble(this->player, this->fdPosY);
    jdouble z = getDouble(this->player, this->fdPosZ);

    return Vector3(x, y, z);
}

void EntityPlayerSP::swingItem() {
    getObject(this->player, this->fdSwingItem);
}

void EntityPlayerSP::setSprinting(jboolean sprinting) {
    getObject(this->player, this->fdSetSprinting, sprinting);
}

jfloat EntityPlayerSP::getMoveForward() {
    return getFloat(this->player, this->fdMoveForward);
}