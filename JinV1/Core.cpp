#pragma once

#include "Core.h"
#include "modules/ModuleManager.h"
#include "modules/FastPlace.h"
#include "utils/ProcessUtils.h"
#include "impl/net/minecraft/client/Minecraft.h"

void Core::run() {
    this->running = true;
    this->autoclicker = false;
    this->lastClickTime = GetTickCount();
    this->moduleManager = new ModuleManager();

    this->getModuleManager()->registerModule(new FastPlace(this, "FastPlace", 'P'), true);

    ProcessUtils pu = ProcessUtils();
	Minecraft* mc = new Minecraft(this);
    EntityPlayerSP player = mc->getPlayer();
    DWORD pid = GetCurrentProcessId();
    HWND window = pu.GetWindowHandle(pid);

    while (this->running) {
        this->getModuleManager()->update();
		// mc->setRightClickDelayTimer(0);
        mc->setLeftClickCounter(0);
        Vector3 vec = player.getVector3();

        if (player.getMoveForward() > 0.0) {
            player.setSprinting(true);
        } else {
            player.setSprinting(false);
        }

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

        if (GetAsyncKeyState(0x42) & 1) {
            this->autoclicker = !this->autoclicker;
            std::cout << "[Debug] AutoClicker " << (this->autoclicker ? "Enabled" : "Disabled") << std::endl;
        }

        if (this->autoclicker && GetAsyncKeyState(VK_LBUTTON) && GetTickCount() - this->lastClickTime >= 55) {
            this->lastClickTime = GetTickCount();
            POINT pos{};
            if (!GetCursorPos(&pos)) std::cout << "[Error] GetCursorPos Failed" << std::endl;
            PostMessage(window, (DWORD)WM_LBUTTONDOWN, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
            PostMessage(window, (DWORD)WM_LBUTTONUP, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
        }

        // printf("(%f, %f, %f)\n", vec.getX(), vec.getY(), vec.getZ());

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