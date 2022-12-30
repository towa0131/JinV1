#pragma once
#include "../../../ImplClass.h"

class Item : public ImplClass {
public:
    Item(Core* core, jobject item);

    int getId();

private:
    jobject item;
    jmethodID GetIdFromItem;
};