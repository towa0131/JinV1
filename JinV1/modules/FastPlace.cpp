#pragma once
#include "FastPlace.h"
#include "ModuleId.h"

FastPlace::FastPlace(Core *core, const char* name, int key) : Module(core, name, ModuleId::MODULE_FASTPLACE, key) {
    this->mc = new Minecraft(this->getCore());
}

void FastPlace::onUpdate() {
    this->mc->setRightClickDelayTimer(0);
}