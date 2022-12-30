#pragma once
#include "../../../ImplClass.h"
#include "entity/EntityPlayerSP.h"
#include "gui/FontRenderer.h"
#include "settings/GameSettings.h"
#include "../util/MovingObjectPosition.h"
#include "multiplayer/WorldClient.h"

class Minecraft : public ImplClass {
public:
    Minecraft(Core *core);

    jobject getMinecraft();

    WorldClient getWorld();

    EntityPlayerSP getPlayer();

    FontRenderer getFontRenderer();

    GameSettings getGameSettings();

    void setRightClickDelayTimer(jint);

    void setLeftClickCounter(jint);

    MovingObjectPosition getObjectMouseOver();

    jobject getCurrentScreen();

    bool isInWorld();

private:
    jmethodID GetMinecraft;
    jfieldID fdRightClickDelayTimer;
    jfieldID fdLeftClickCounter;
    jfieldID fdWorld;
    jfieldID fdPlayer;
    jfieldID fdFontRendererObj;
    jfieldID fdObjectMouseOver;
    jfieldID fdGameSettings;
    jfieldID fdCurrentScreen;
};