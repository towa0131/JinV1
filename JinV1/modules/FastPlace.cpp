#pragma once
#include "FastPlace.h"
#include "ModuleId.h"

FastPlace::FastPlace(Core* core, const char* name, int key) : FastPlace(core, name, key, false) {

}

FastPlace::FastPlace(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_FASTPLACE, key, state) {
    this->mc = new Minecraft(this->getCore());
}

void FastPlace::onUpdate() {
    this->mc->setRightClickDelayTimer(0);
}