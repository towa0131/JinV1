#include "C03PacketPlayer.h"

C03PacketPlayer::C03PacketPlayer(Core* core, jboolean onGround) : ImplClass(core, "net.minecraft.network.play.client.C03PacketPlayer") {
    //jclass packetClass = getClass("net.minecraft.network.play.client.C03PacketPlayer");
    //jmethodID initMethod = this->core->getEnv()->GetMethodID(packetClass, "<init>", "()V");
    //this->packet = this->core->getEnv()->NewObject(packetClass, initMethod, onGround);
    //this->fdOnGround = getFieldID("field_149474_g", "Z");
}

void C03PacketPlayer::setOnGround(jboolean onGround) {
    // setBoolean(this->fdOnGround, onGround);
}