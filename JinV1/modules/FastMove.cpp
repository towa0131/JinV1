#pragma once
#include <cmath>
#include "FastMove.h"
#include "ModuleId.h"

#ifndef M_PI
#define M_PI 3.141592
#endif
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

FastMove::FastMove(Core* core, const char* name, int key) : FastMove(core, name, key, false) {

}

FastMove::FastMove(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_FASTMOVE, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->speed = 0.5;
}

void FastMove::onUpdate() {
    EntityPlayerSP* player = this->mc->getPlayer();
    double x = 0;
    double y = 0;
    double z = 0;
    Vector3 vec3 = player->getVector3();
    float yaw = player->getYaw();

    if ((GetAsyncKeyState('W') & 0xff00) != 0) {
        x += -sin(degToRad(yaw)) * this->speed;
        z += cos(degToRad(yaw)) * this->speed;
    }

    if ((GetAsyncKeyState('S') & 0xff00) != 0) {
        x += sin(degToRad(yaw)) * this->speed;
        z += -cos(degToRad(yaw)) * this->speed;
    }

    if ((GetAsyncKeyState('D') & 0xff00) != 0) {
        x += -sin(degToRad(yaw + 90)) * this->speed;
        z += cos(degToRad(yaw + 90)) * this->speed;
    }

    if ((GetAsyncKeyState('A') & 0xff00) != 0) {
        x += sin(degToRad(yaw + 90)) * this->speed;
        z += -cos(degToRad(yaw + 90)) * this->speed;
    }

    if ((GetAsyncKeyState(VK_SPACE) & 0xff00) != 0) {
        y += this->speed;
    }

    if ((GetAsyncKeyState(VK_SHIFT) & 0xff00) != 0) {
        y -= this->speed;
    }

    player->setMotion(Vector3(x, y, z));

    delete player;
}