#pragma once
#include "HitDelayFix.h"
#include "ModuleId.h"


HitDelayFix::HitDelayFix(Core* core, const char* name, int key) : HitDelayFix(core, name, key, false) {

}

HitDelayFix::HitDelayFix(Core* core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_HITDELAYFIX, key, state) {
    this->mc = new Minecraft(this->getCore());
}

void HitDelayFix::onUpdate() {
    this->mc->setLeftClickCounter(0);
}