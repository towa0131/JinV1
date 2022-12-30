#pragma once
#include "Chunk.h"

Chunk::Chunk(Core* core, jobject chunk) : ImplClass(core, "net.minecraft.world.chunk.Chunk") {
    this->chunk = chunk;
    this->GetBlock = getMethodID("getBlock");
}

Block Chunk::getBlock(jint x, jint y, jint z) {
    jobject block = getObject(this->chunk, this->GetBlock, x, y, z);
    return Block(this->core, block);
}