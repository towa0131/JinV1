#pragma once
#include "../../../../ImplClass.h"
#include "../../../../../utils/Vector3.h"

class FontRenderer : public ImplClass {
public:
    FontRenderer(Core* core, jobject fontRenderer);

    int drawString(const char *, float, float, int);

private:
    jobject fontRenderer;
    jmethodID fdDrawString;
};