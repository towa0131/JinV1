#pragma once
#include "../../../ImplClass.h"

class Block : public ImplClass {
public:
    Block(Core* core, jobject block);

    jint getId();

    //const char* getUnlocalizedName();

    jobject getMaterial();

private:
    jobject block;
    jmethodID GetIdFromBlock;
    jmethodID GetMaterial;
    jfieldID fdUnlocalizedName;
};