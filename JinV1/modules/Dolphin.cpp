#pragma once
#include <cmath>
#include "Dolphin.h"
#include "ModuleId.h"

Dolphin::Dolphin(Core* core, const char* name, int key) : Dolphin(core, name, key, false) {

}

Dolphin::Dolphin(Core* core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_DOLPHIN, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->speed = 1.01;
}

void Dolphin::onUpdate() {
    EntityPlayerSP* player = this->mc->getPlayer();

    if (player->isInWater()) {
        Vector3 motion = player->getMotion();
        if (((GetAsyncKeyState('W') & 0xff00) != 0) ||
            ((GetAsyncKeyState('A') & 0xff00) != 0) ||
            ((GetAsyncKeyState('S') & 0xff00) != 0) ||
            ((GetAsyncKeyState('D') & 0xff00) != 0)) {
            motion.multiply(Vector3(this->speed, 1.0, this->speed));
            Vector3 speedMotion = Vector3(motion.getX() * this->speed, motion.getY(), motion.getZ() * this->speed);
            double currentSpeed = sqrt(pow(motion.getX(), 2) + pow(motion.getZ(), 2));
            double maxSpeed = 0.66;
            if (currentSpeed > maxSpeed) {
                speedMotion.setX(speedMotion.getX() * maxSpeed / currentSpeed);
                speedMotion.setZ(speedMotion.getZ() * maxSpeed / currentSpeed);
            }
        }
        motion.add(Vector3(0, 0.01, 0));
        player->setMotion(motion);
    }

    delete player;
}