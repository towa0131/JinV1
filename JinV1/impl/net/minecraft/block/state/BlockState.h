#pragma once
#include "../../../../ImplClass.h"
#include "../Block.h"

class BlockState : public ImplClass {
public:
    BlockState(Core* core, jobject blockState);

private:
    jobject blockState;
};