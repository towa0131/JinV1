#pragma once
#include "AutoClicker.h"
#include "ModuleId.h"
#include "../utils/ProcessUtils.h"
#include "../impl/ImplClass.h"
#include "../impl/net/minecraft/util/MovingObjectPosition.h"
#include <random>

AutoClicker::AutoClicker(Core* core, const char* name, int key) : AutoClicker(core, name, key, false) {

}

AutoClicker::AutoClicker(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_AUTOCLICKER, key, state) {
    ProcessUtils pu = ProcessUtils();
    this->mc = new Minecraft(this->getCore());
    this->lastClickTime = GetTickCount();
    int pid = GetCurrentProcessId();
    this->window = pu.GetWindowHandle(pid);
}

void AutoClicker::onUpdate() {
    if (GetAsyncKeyState(VK_LBUTTON) && GetTickCount() - this->lastClickTime >= 55 && this->mc->getCurrentScreen() == NULL) {
        MovingObjectPosition* mouseOver = this->mc->getObjectMouseOver();
        if (mouseOver->getObjectPosition() != NULL) {
            jclass cls = ImplClass(this->getCore(), "net.minecraft.util.MovingObjectPosition").getClass("net.minecraft.util.MovingObjectPosition");
            jclass enum_cls = ImplClass(this->getCore(), "net.minecraft.util.MovingObjectPosition$MovingObjectType").getClass("net.minecraft.util.MovingObjectPosition$MovingObjectType");
            jmethodID equals_method = this->getCore()->getEnv()->GetMethodID(enum_cls, "equals", "(Ljava/lang/Object;)Z");
            jfieldID block_field = this->getCore()->getEnv()->GetStaticFieldID(enum_cls, "BLOCK", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            jobject block_object = this->getCore()->getEnv()->GetStaticObjectField(enum_cls, block_field);
            jfieldID typeOfHit = this->getCore()->getEnv()->GetFieldID(cls, "field_72313_a", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            jobject res = this->getCore()->getEnv()->GetObjectField(mouseOver->getObjectPosition(), typeOfHit);
            if (res != NULL) {
                if (this->getCore()->getEnv()->CallBooleanMethod(block_object, equals_method, res) == JNI_TRUE) {
                    BlockPos* pos = mouseOver->getBlockPos();
                    Vector3 vec = pos->getVector3();
                    this->mc->setLeftClickCounter(0);
                } else {
                    this->lastClickTime = GetTickCount();
                    POINT pos{};
                    if (GetCursorPos(&pos)) {
                        PostMessage(this->window, (DWORD)WM_LBUTTONDOWN, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
                        PostMessage(this->window, (DWORD)WM_LBUTTONUP, (DWORD)MK_LBUTTON, MAKELPARAM(pos.x, pos.y));
                    } else {
                        std::cout << "[Error] GetCursorPos Failed" << std::endl;
                    }
                }
            }
        }

        delete mouseOver;
    }
}