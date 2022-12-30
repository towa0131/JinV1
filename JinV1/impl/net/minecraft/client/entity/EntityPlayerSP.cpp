#pragma once
#include "EntityPlayerSP.h"

EntityPlayerSP::EntityPlayerSP(Core* core, jobject player) : ImplClass(core, "net.minecraft.client.entity.EntityPlayerSP") {
    this->player = player;
    this->fdPosX = getFieldID("posX");
    this->fdPosY = getFieldID("posY");
    this->fdPosZ = getFieldID("posZ");
    this->fdMotionX = getFieldID("motionX");
    this->fdMotionY = getFieldID("motionY");
    this->fdMotionZ = getFieldID("motionZ");
    this->fdYaw = getFieldID("rotationYaw");
    this->fdPitch = getFieldID("rotationPitch");
    this->fdIsDead = getFieldID("isDead");
    this->fdOnGround = getFieldID("onGround");
    this->fdMoveForward = getFieldID("moveForward");
    this->fdInventory = getFieldID("inventory");
    this->fdSetSprinting = getMethodID("setSprinting");
    this->fdSwingItem = getMethodID("swingItem");
    this->fdIsInWater = getMethodID("isInWater");
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

jboolean EntityPlayerSP::onGround() {
    return getBoolean(this->player, this->fdOnGround);
}

jboolean EntityPlayerSP::isInWater() {
    return getBoolean(this->player, this->fdIsInWater);
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

InventoryPlayer* EntityPlayerSP::getInventory() {
    jobject inventory = getObject(this->player, fdInventory);
    return new InventoryPlayer(this->core, inventory);
}