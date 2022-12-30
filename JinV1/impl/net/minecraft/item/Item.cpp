#pragma once
#include "Item.h"

Item::Item(Core* core, jobject item) : ImplClass(core, "net.minecraft.item.Item") {
    this->item = item;
    this->GetIdFromItem = getStaticMethodID("getIdFromItem");
}

int Item::getId() {
    return getInt(this->GetIdFromItem, this->item);
}