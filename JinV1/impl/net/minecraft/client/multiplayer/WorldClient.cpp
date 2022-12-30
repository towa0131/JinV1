#pragma once
#include "WorldClient.h"

WorldClient::WorldClient(Core* core, jobject worldClient) : ImplClass(core, "net.minecraft.client.multiplayer.WorldClient") {
    this->worldClient = worldClient;
    this->GetBlockState = getMethodID("getBlockState");
    this->GetWorldTime = getMethodID("getWorldTime");
    this->IsValid = getMethodID("isValid");
    this->GetChunkFromChunkCoords = getMethodID("getChunkFromChunkCoords");
}

BlockState* WorldClient::getBlockState(jobject pos) {
    jobject blockState = getObject(this->worldClient, this->GetBlockState, pos);
    if (blockState == NULL) std::cout << "blockstate is null" << std::endl;
    return new BlockState(this->core, blockState);
}

jlong WorldClient::getWorldTime() {
    return getLong(this->worldClient, this->GetWorldTime);
}

jboolean WorldClient::isValid(BlockPos* pos) {
    return getBoolean(this->worldClient, this->IsValid, pos->getBlockPos());
}

Chunk* WorldClient::getChunkFromChunkCoords(jint chunkX, jint chunkZ) {
    jobject chunk = getObject(this->worldClient, this->GetChunkFromChunkCoords, chunkX, chunkZ);
    return new Chunk(this->core, chunk);
}