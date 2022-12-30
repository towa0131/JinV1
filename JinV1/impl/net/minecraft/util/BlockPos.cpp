#pragma once
#include "BlockPos.h"

BlockPos::BlockPos(Core* core, jobject blockPos) : ImplClass(core, "net.minecraft.util.BlockPos") {
    this->blockPos = blockPos;
    this->fdX = getFieldID("x");
    this->fdY = getFieldID("y");
    this->fdZ = getFieldID("z");
}

jobject BlockPos::getBlockPos() {
    return this->blockPos;
}

Vector3 BlockPos::getVector3() {
    jint x = getInt(this->blockPos, this->fdX);
    jint y = getInt(this->blockPos, this->fdY);
    jint z = getInt(this->blockPos, this->fdZ);

    return Vector3(x, y, z);
}