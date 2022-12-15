#pragma once
#include "../../../ImplClass.h"
#include "entity/EntityPlayerSP.h"
#include "gui/FontRenderer.h"

class Minecraft : public ImplClass {
public:
    Minecraft(Core *core);

    jobject getMinecraft();

    EntityPlayerSP* getPlayer();

    FontRenderer* getFontRenderer();

    void setRightClickDelayTimer(jint);

    void setLeftClickCounter(jint);

    jobject getObjectMouseOver();

private:
    jmethodID GetMinecraft;
    jfieldID fdRightClickDelayTimer;
    jfieldID fdLeftClickCounter;
    jfieldID fdPlayer;
    jfieldID fdFontRendererObj;
    jfieldID fdObjectMouseOver;
};