#pragma once
#include "EntityPlayerSP.h"

EntityPlayerSP::EntityPlayerSP(Core* core, jobject player) : ImplClass(core, "net.minecraft.client.entity.EntityPlayerSP") {
    this->player = player;
    this->fdPosX = getFieldID("field_70165_t", "D");
    this->fdPosY = getFieldID("field_70163_u", "D");
    this->fdPosZ = getFieldID("field_70161_v", "D");
    this->fdMotionX = getFieldID("field_70159_w", "D");
    this->fdMotionY = getFieldID("field_70181_x", "D");
    this->fdMotionZ = getFieldID("field_70179_y", "D");
    this->fdYaw = getFieldID("field_70177_z", "F");
    this->fdPitch = getFieldID("field_70125_A", "F");
    this->fdIsDead = getFieldID("field_70128_L", "Z");
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

jfloat EntityPlayerSP::getYaw() {
    return getFloat(this->player, this->fdYaw);
}

jfloat EntityPlayerSP::getPitch() {
    return getFloat(this->player, this->fdPitch);
}

jboolean EntityPlayerSP::isDead() {
    return getBoolean(this->player, this->fdIsDead);
}

void EntityPlayerSP::swingItem() {
    getObject(this->player, this->fdSwingItem);
}

void EntityPlayerSP::setSprinting(jboolean sprinting) {
    getObject(this->player, this->fdSetSprinting, sprinting);
}

void EntityPlayerSP::setMotion(Vector3 vec) {
    setDouble(this->player, this->fdMotionX, vec.getX());
    setDouble(this->player, this->fdMotionY, vec.getY());
    setDouble(this->player, this->fdMotionZ, vec.getZ());
}

Vector3 EntityPlayerSP::getMotion() {
    jdouble x = getDouble(this->player, this->fdMotionX);
    jdouble y = getDouble(this->player, this->fdMotionY);
    jdouble z = getDouble(this->player, this->fdMotionZ);

    return Vector3(x, y, z);
}

jfloat EntityPlayerSP::getMoveForward() {
    return getFloat(this->player, this->fdMoveForward);
}