#pragma once
#include "Speed.h"
#include "ModuleId.h"

Speed::Speed(Core* core, const char* name, int key) : Speed(core, name, key, false) {

}

Speed::Speed(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_SPEED, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->player = this->mc->getPlayer();
    this->speed = 1.1;
}

void Speed::onUpdate() {
    if (this->player->isDead()) this->player = this->mc->getPlayer();
    Vector3 motion = this->player->getMotion();
    Vector3 speedMotion = Vector3(motion.getX() * this->speed, motion.getY() * this->speed, motion.getZ() * this->speed);
    this->player->setMotion(speedMotion);
}