#pragma once
#include "../../../ImplClass.h"
#include "BlockPos.h"

class MovingObjectPosition : public ImplClass {
public:
    MovingObjectPosition(Core* core, jobject objectPosition);

    BlockPos* getBlockPos();

    jobject getObjectPosition();

private:
    jobject objectPosition;
    jfieldID fdBlockPos;
};