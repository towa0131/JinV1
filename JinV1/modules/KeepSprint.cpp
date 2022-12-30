#pragma once
#include "KeepSprint.h"
#include "ModuleId.h"


KeepSprint::KeepSprint(Core* core, const char* name, int key) : KeepSprint(core, name, key, false) {

}

KeepSprint::KeepSprint(Core* core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_KEEPSPRINT, key, state) {
    this->mc = new Minecraft(core);
}

void KeepSprint::onUpdate() {
    EntityPlayerSP player = this->mc->getPlayer();

    Vector3 vec = player.getVector3();

    if (player.getMoveForward() > 0.0) {
        player.setSprinting(true);
    } else {
        player.setSprinting(false);
    }
}