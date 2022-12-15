#pragma once
#include "KeepSprint.h"
#include "ModuleId.h"


KeepSprint::KeepSprint(Core* core, const char* name, int key) : KeepSprint(core, name, key, false) {

}

KeepSprint::KeepSprint(Core* core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_KEEPSPRINT, key, state) {
    this->mc = new Minecraft(core);
    this->player = this->mc->getPlayer();
}

void KeepSprint::onUpdate() {
    if (this->player->isDead()) this->player = this->mc->getPlayer();

    Vector3 vec = this->player->getVector3();

    if (this->player->getMoveForward() > 0.0) {
        this->player->setSprinting(true);
    } else {
        this->player->setSprinting(false);
    }
}