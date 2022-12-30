#pragma once
#include "MovingObjectPosition.h"

MovingObjectPosition::MovingObjectPosition(Core* core, jobject objectPosition) : ImplClass(core, "net.minecraft.util.MovingObjectPosition") {
    this->objectPosition = objectPosition;
    this->fdBlockPos = getFieldID("blockPos");
}

BlockPos* MovingObjectPosition::getBlockPos() {
    jobject blockPos = getObject(this->objectPosition, this->fdBlockPos);
    return new BlockPos(this->core, blockPos);
}

jobject MovingObjectPosition::getObjectPosition() {
    return this->objectPosition;
}