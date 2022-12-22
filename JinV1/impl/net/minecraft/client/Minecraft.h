#pragma once
#include "../../../ImplClass.h"
#include "entity/EntityPlayerSP.h"
#include "gui/FontRenderer.h"
#include "settings/GameSettings.h"

class Minecraft : public ImplClass {
public:
    Minecraft(Core *core);

    jobject getMinecraft();

    EntityPlayerSP* getPlayer();

    FontRenderer* getFontRenderer();

    GameSettings* getGameSettings();

    void setRightClickDelayTimer(jint);

    void setLeftClickCounter(jint);

    jobject getObjectMouseOver();

    jobject getCurrentScreen();

private:
    jmethodID GetMinecraft;
    jfieldID fdRightClickDelayTimer;
    jfieldID fdLeftClickCounter;
    jfieldID fdPlayer;
    jfieldID fdFontRendererObj;
    jfieldID fdObjectMouseOver;
    jfieldID fdGameSettings;
    jfieldID fdCurrentScreen;
};