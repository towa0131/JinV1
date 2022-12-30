#pragma once
#include "ItemStack.h"

ItemStack::ItemStack(Core* core, jobject itemstack) : ImplClass(core, "net.minecraft.item.ItemStack") {
    this->itemstack = itemstack;
    this->fdItem = getFieldID("item");
    this->fdStackSize = getFieldID("stackSize");
}

Item ItemStack::getItem() {
    jobject item = getObject(this->itemstack, this->fdItem);
    return Item(this->core, item);
}

jint ItemStack::getStackSize() {
    return getInt(this->itemstack, this->fdStackSize);
}

boolean ItemStack::isNull() {
    return this->itemstack == NULL;
}