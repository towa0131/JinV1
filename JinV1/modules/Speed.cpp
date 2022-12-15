#pragma once
#include "Speed.h"
#include "ModuleId.h"

Speed::Speed(Core* core, const char* name, int key) : Speed(core, name, key, false) {

}

Speed::Speed(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_SPEED, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->player = this->mc->getPlayer();
    this->speed = 1.05;
}

void Speed::onUpdate() {
    if (this->player->isDead()) this->player = this->mc->getPlayer();
    if (this->player->onGround()) {
        Vector3 motion = this->player->getMotion();
        Vector3 speedMotion = Vector3(motion.getX() * this->speed, motion.getY(), motion.getZ() * this->speed);
        double currentSpeed = sqrt(pow(motion.getX(), 2) + pow(motion.getY(), 2));
        double maxSpeed = 0.66;

        if (currentSpeed > maxSpeed) {
            speedMotion.setX(speedMotion.getX() * maxSpeed / currentSpeed);
            speedMotion.setZ(speedMotion.getZ() * maxSpeed / currentSpeed);
        }

        this->player->setMotion(speedMotion);
    }
}