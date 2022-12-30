#pragma once
#include "../../../../ImplClass.h"
#include "../../util/BlockPos.h"
#include "../../block/state/BlockState.h"
#include "../../world/chunk/Chunk.h"

class WorldClient : public ImplClass {
public:
    WorldClient(Core* core, jobject worldClient);

    BlockState* getBlockState(jobject pos);

    jlong getWorldTime();

    jboolean isValid(BlockPos* pos);

    Chunk* getChunkFromChunkCoords(jint chunkX, jint chunkZ);

private:
    jobject worldClient;
    jmethodID GetBlockState;
    jmethodID GetWorldTime;
    jmethodID IsValid;
    jmethodID GetChunkFromChunkCoords;
};