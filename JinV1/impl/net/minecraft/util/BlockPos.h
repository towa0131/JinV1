#pragma once
#include "../../../ImplClass.h"
#include "../../../../utils/Vector3.h"

class BlockPos : public ImplClass {
public:
    BlockPos(Core* core, jobject blockPos);

    jobject getBlockPos();

    Vector3 getVector3();

private:
    jobject blockPos;
    jfieldID fdX;
    jfieldID fdY;
    jfieldID fdZ;
};