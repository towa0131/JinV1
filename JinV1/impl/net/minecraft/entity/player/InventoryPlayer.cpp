#pragma once
#include "InventoryPlayer.h"

InventoryPlayer::InventoryPlayer(Core* core, jobject inventory) : ImplClass(core, "net.minecraft.entity.player.InventoryPlayer") {
    this->inventory = inventory;
    this->fdCurrentItem = getFieldID("currentItem");
    this->fdMainInventory = getFieldID("mainInventory");
}

void InventoryPlayer::setCurrentItem(jint currentItem) {
    setInt(this->inventory, fdCurrentItem, currentItem);
}

ItemStack* InventoryPlayer::getItemStack(jint index) {
    jobject mainInventory = getObject(this->inventory, this->fdMainInventory);
    jobject itemstack = this->core->getEnv()->GetObjectArrayElement((jobjectArray)mainInventory, index);
    if (itemstack == NULL) return NULL;
    else return new ItemStack(this->core, itemstack);
}