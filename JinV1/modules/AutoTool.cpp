#pragma once
#include "AutoTool.h"
#include "ModuleId.h"
#include "../utils/ProcessUtils.h"
#include "../impl/ImplClass.h"
#include "../impl/net/minecraft/util/MovingObjectPosition.h"
#include <vector>
#include <thread>
#include <chrono>

AutoTool::AutoTool(Core* core, const char* name, int key) : AutoTool(core, name, key, false) {

}

AutoTool::AutoTool(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_AUTOTOOL, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->locked = false;

    this->materialMap.insert(std::make_pair("field_151575_d", Tool::Axe));
    this->materialMap.insert(std::make_pair("field_151577_b", Tool::Shovel));
    this->materialMap.insert(std::make_pair("field_151576_e", Tool::Pickaxe));

    this->toolMap.insert(std::make_pair(359, Tool::Shears));

    this->toolMap.insert(std::make_pair(276, Tool::Sword));
    this->toolMap.insert(std::make_pair(272, Tool::Sword));
    this->toolMap.insert(std::make_pair(283, Tool::Sword));
    this->toolMap.insert(std::make_pair(268, Tool::Sword));

    this->toolMap.insert(std::make_pair(278, Tool::Pickaxe));
    this->toolMap.insert(std::make_pair(285, Tool::Pickaxe));
    this->toolMap.insert(std::make_pair(257, Tool::Pickaxe));
    this->toolMap.insert(std::make_pair(274, Tool::Pickaxe));
    this->toolMap.insert(std::make_pair(270, Tool::Pickaxe));

    this->toolMap.insert(std::make_pair(279, Tool::Axe));
    this->toolMap.insert(std::make_pair(286, Tool::Axe));
    this->toolMap.insert(std::make_pair(258, Tool::Axe));
    this->toolMap.insert(std::make_pair(275, Tool::Axe));
    this->toolMap.insert(std::make_pair(271, Tool::Axe));

    this->toolMap.insert(std::make_pair(277, Tool::Shovel));
    this->toolMap.insert(std::make_pair(284, Tool::Shovel));
    this->toolMap.insert(std::make_pair(256, Tool::Shovel));
    this->toolMap.insert(std::make_pair(273, Tool::Shovel));
    this->toolMap.insert(std::make_pair(269, Tool::Shovel));
}

void AutoTool::onUpdate() {
    if (GetAsyncKeyState(VK_LBUTTON) && this->mc->getCurrentScreen() == NULL) {
        MovingObjectPosition mouseOver = this->mc->getObjectMouseOver();
        if (mouseOver.getObjectPosition() != NULL) {
            jclass cls = ImplClass(this->getCore(), "net.minecraft.util.MovingObjectPosition").getClass("net.minecraft.util.MovingObjectPosition");
            jclass enum_cls = ImplClass(this->getCore(), "net.minecraft.util.MovingObjectPosition$MovingObjectType").getClass("net.minecraft.util.MovingObjectPosition$MovingObjectType");
            jmethodID equals_method = this->getCore()->getEnv()->GetMethodID(enum_cls, "equals", "(Ljava/lang/Object;)Z");
            jfieldID block_field = this->getCore()->getEnv()->GetStaticFieldID(enum_cls, "BLOCK", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            jobject block_object = this->getCore()->getEnv()->GetStaticObjectField(enum_cls, block_field);
            jfieldID entity_field = this->getCore()->getEnv()->GetStaticFieldID(enum_cls, "ENTITY", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            jobject entity_object = this->getCore()->getEnv()->GetStaticObjectField(enum_cls, entity_field);
            jfieldID typeOfHit = this->getCore()->getEnv()->GetFieldID(cls, "field_72313_a", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;");
            jobject res = this->getCore()->getEnv()->GetObjectField(mouseOver.getObjectPosition(), typeOfHit);
            if (res != NULL) {
                if (this->getCore()->getEnv()->CallBooleanMethod(block_object, equals_method, res) == JNI_TRUE && !this->locked) {
                    this->locked = true;
                    BlockPos pos = mouseOver.getBlockPos();
                    Vector3 vec = pos.getVector3();
                    if (pos.getBlockPos() != NULL) {
                        Chunk chunk = this->mc->getWorld().getChunkFromChunkCoords((int)vec.getX() >> 4, (int)vec.getZ() >> 4);
                        Block block = chunk.getBlock(vec.getX(), vec.getY(), vec.getZ());
                        int blockId = block.getId();
                        jobject material = block.getMaterial();
                        jclass materialClass = ImplClass(this->getCore(), "net.minecraft.block.material.Material").getClass("net.minecraft.block.material.Material");

                        for (const auto& mp : this->materialMap) {
                            jfieldID targetMaterialField = this->getCore()->getEnv()->GetStaticFieldID(materialClass, mp.first, "Lnet/minecraft/block/material/Material;");
                            jobject targetMaterial = this->getCore()->getEnv()->GetStaticObjectField(materialClass, targetMaterialField);
                            if (this->getCore()->getEnv()->IsSameObject(material, targetMaterial)) {
                                clock_t start = clock();
                                int index = this->getIndex(mp.second);
                                clock_t end = clock();
                                printf("[Debug] time : %0.8f\n", ((float)end - start) / CLOCKS_PER_SEC);
                                if (index != -1) {
                                    this->mc->getPlayer().getInventory().setCurrentItem(index);
                                    this->locked = false;
                                    break;
                                }
                            }
                        }

                        // Wool
                        if (blockId == 35) {
                            int index = this->getIndex(Tool::Shears);
                            if (index != -1) {
                                this->mc->getPlayer().getInventory().setCurrentItem(index);
                            }
                        }
                    }
                    this->locked = false;
                } else if (this->getCore()->getEnv()->CallBooleanMethod(entity_object, equals_method, res) == JNI_TRUE) {
                    int index = this->getIndex(Tool::Sword);
                    if (index != -1) {
                        this->mc->getPlayer().getInventory().setCurrentItem(index);
                    }
                }
            }
        }
    }
}

int AutoTool::getIndex(Tool tool) {
    InventoryPlayer inv = this->mc->getPlayer().getInventory();
    for (const auto& mp : this->toolMap) {
        for (int i = 0; i < 9; i++) {
            ItemStack itemstack = inv.getItemStack(i);
            if (!itemstack.isNull()) {
                int id = itemstack.getItem().getId();
                if (mp.first == id && mp.second == tool) {
                    return i;
                }
            }
        }
    }

    return -1;
}