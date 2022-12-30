#pragma once
#include "../../../../ImplClass.h"
#include "../../block/Block.h"

class Chunk : public ImplClass {
public:
    Chunk(Core* core, jobject chunk);

    Block* getBlock(jint x, jint y, jint z);

private:
    jobject chunk;
    jmethodID GetBlock;
};