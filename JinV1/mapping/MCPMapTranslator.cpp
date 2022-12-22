#pragma once
#include "MCPMapTranslator.h"

MCPMapTranslator::MCPMapTranslator() {
    this->registerClass("net.minecraft.client.Minecraft", "net.minecraft.client.Minecraft");
    this->registerMethod("func_71410_x", "getMinecraft", "()Lnet/minecraft/client/Minecraft;");
    this->registerField("field_71467_ac", "rightClickDelayTimer", "I");
    this->registerField("field_71429_W", "leftClickCounter", "I");
    this->registerField("field_71439_g", "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
    this->registerField("field_71466_p", "fontRendererObj", "Lnet/minecraft/client/gui/FontRenderer;");
    this->registerField("field_71476_x", "objectMouseOver", "Lnet/minecraft/util/MovingObjectPosition;");
    this->registerField("field_71474_y", "gameSettings", "Lnet/minecraft/client/settings/GameSettings;");
    this->registerClass("net.minecraft.client.entity.EntityPlayerSP", "net.minecraft.client.entity.EntityPlayerSP");
    this->registerField("field_70165_t", "posX", "D");
    this->registerField("field_70163_u", "posY", "D");
    this->registerField("field_70161_v", "posZ", "D");
    this->registerField("field_70159_w", "motionX", "D");
    this->registerField("field_70181_x", "motionY", "D");
    this->registerField("field_70179_y", "motionZ", "D");
    this->registerField("field_70177_z", "rotationYaw", "F");
    this->registerField("field_70125_A", "rotationPitch", "F");
    this->registerField("field_70128_L", "isDead", "Z");
    this->registerField("field_70122_E", "onGround", "Z");
    this->registerField("field_70701_bs", "moveForward", "F");
    this->registerMethod("func_70031_b", "setSprinting", "(Z)V");
    this->registerMethod("func_71038_i", "swingItem", "()V");
    this->registerClass("net.minecraft.client.gui.FontRenderer", "net.minecraft.client.gui.FontRenderer");
    this->registerMethod("func_175065_a", "drawString", "(Ljava/lang/String;FFIZ)I");
    this->registerClass("net.minecraft.client.settings.GameSettings", "net.minecraft.client.settings.GameSettings");
    this->registerField("field_74312_F", "keyBindAttack", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74314_A", "keyBindJump", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74316_C", "keyBindDrop", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74351_w", "keyBindForward", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74368_y", "keyBindBack", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74366_z", "keyBindRight", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerField("field_74370_x", "keyBindLeft", "Lnet/minecraft/client/settings/KeyBinding;");
    this->registerClass("net.minecraft.client.settings.KeyBinding", "net.minecraft.client.settings.KeyBinding");
    this->registerMethod("func_151463_i", "getKeyCode", "()I");
    this->registerMethod("func_74510_a", "setKeyBindState", "(IZ)V");
    this->registerField("field_74513_e", "pressed", "Z");

}