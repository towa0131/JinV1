#pragma once
#include "../../../ImplClass.h"
#include "Item.h"

class ItemStack : public ImplClass {
public:
    ItemStack(Core* core, jobject itemstack);

    Item* getItem();

    jint getStackSize();

private:
    jobject itemstack;
    jfieldID fdItem;
    jfieldID fdStackSize;
};