#pragma once
#include "../../../../ImplClass.h"
#include "../../item/ItemStack.h"

class InventoryPlayer : public ImplClass {
public:
    InventoryPlayer(Core* core, jobject inventory);

    void setCurrentItem(jint currentItem);

    ItemStack getItemStack(jint index);

private:
    jobject inventory;
    jfieldID fdCurrentItem;
    jfieldID fdMainInventory;
};