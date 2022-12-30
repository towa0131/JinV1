#pragma once
#include "BlockState.h"

BlockState::BlockState(Core* core, jobject blockState) : ImplClass(core, "net.minecraft.block.state.BlockState") {
    this->blockState = blockState;
}