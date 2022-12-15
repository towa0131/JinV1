#pragma once

#include <cmath>
#include "Core.h"
#include "modules/AutoClicker.h"
#include "modules/InventoryWalk.h"
#include "modules/ModuleManager.h"
#include "modules/FastPlace.h"
#include "modules/HitDelayFix.h"
#include "modules/KeepSprint.h"
#include "modules/Speed.h"
#include "utils/ProcessUtils.h"
#include "impl/net/minecraft/client/Minecraft.h"
#include "impl/net/minecraft/client/settings/KeyBinding.h"

#ifndef M_PI
#define M_PI 3.14159265358979
#define deg_to_rad(deg) (((deg)/360)*2*M_PI)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#endif

void Core::run() {
    this->running = true;
    this->moduleManager = new ModuleManager();

    this->getModuleManager()->registerModule(new FastPlace(this, "FastPlace", 'P', true));
    this->getModuleManager()->registerModule(new InventoryWalk(this, "InventoryWalk", 'I', true));
    this->getModuleManager()->registerModule(new HitDelayFix(this, "HitDelayFix", 'H', true));
    this->getModuleManager()->registerModule(new KeepSprint(this, "KeepSprint", 'K', true));
    this->getModuleManager()->registerModule(new AutoClicker(this, "AutoClicker", 'B', false));
    this->getModuleManager()->registerModule(new Speed(this, "Speed", 'N', false));


    Minecraft* mc = new Minecraft(this);
    EntityPlayerSP* player = mc->getPlayer();

    while (this->running) {
        this->getModuleManager()->update();

        //jobject mouseOver = mc->getObjectMouseOver();
        //if (mouseOver == NULL) {
        //    std::cout << "ObjectMouseOver is NULL" << std::endl;
        //} else {
        //    // "Ljava.lang.Enum" typeOfHit 
        //    // Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;
        //    jclass cls = ImplClass(this, "net.minecraft.util.MovingObjectPosition").getClass("net.minecraft.util.MovingObjectPosition");
        //    if (cls == NULL) {
        //        std::cout << "net.minecraft.util.MovingObjectPosition not found" << std::endl;
        //    } else {
        //        jfieldID typeOfHit = this->getEnv()->GetFieldID(cls, "field_72313_a", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
        //        if (typeOfHit == NULL) {
        //            std::cout << "typeOfHit(jfieldID) is NULL" << std::endl;
        //        } else {
        //            jobject res = this->getEnv()->GetObjectField(mouseOver, typeOfHit);
        //            if (res == NULL) {
        //                std::cout << "typeOfHit(Object) is NULL" << std::endl;
        //            } else {
        //                std::cout << (jstring)res << std::endl;
        //            }
        //        }
        //    }
        //}

        Sleep(20);
    }
}

void Core::shutdown() {
    this->setRunning(false);
}

void Core::setRunning(boolean running) {
    this->running = running;
}

JNIEnv* Core::getEnv() {
    return this->env;
}

ModuleManager* Core::getModuleManager() {
    return this->moduleManager;
}