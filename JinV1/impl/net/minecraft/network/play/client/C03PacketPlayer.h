#pragma once
#include "../../../../../ImplClass.h"

class C03PacketPlayer : public ImplClass {
public:
    C03PacketPlayer(Core* core, jboolean onGround);

    void setOnGround(jboolean onGround);

private:
    jobject packet;

    jfieldID fdOnGround;
};