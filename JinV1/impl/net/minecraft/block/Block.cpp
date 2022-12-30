#pragma once
#include "Block.h"

Block::Block(Core* core, jobject block) : ImplClass(core, "net.minecraft.block.Block") {
    this->block = block;
    this->GetIdFromBlock = getStaticMethodID("getIdFromBlock");
    this->GetMaterial = getMethodID("getMaterial");
    if (this->GetMaterial == NULL) std::cout << "material not found" << std::endl;
    //this->fdUnlocalizedName = getFieldID("unlocalizedName");
}

jint Block::getId() {
    return getInt(this->GetIdFromBlock, this->block);
}
//
//const char* Block::getUnlocalizedName() {
//    jstring name = (jstring)getObject(this->block, this->fdUnlocalizedName);
//    return this->core->getEnv()->GetStringUTFChars(name, NULL);
//}

jobject Block::getMaterial() {
    return getObject(this->block, this->GetMaterial);
}