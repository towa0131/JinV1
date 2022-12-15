#include "KeyBinding.h"

KeyBinding::KeyBinding(Core* core) : ImplClass(core, "net.minecraft.client.settings.KeyBinding") {
}

void KeyBinding::test() {
    jfieldID keyArray = getStaticFieldID("field_74516_a", "Ljava/util/List;");
    jfieldID pressed = getFieldID("field_74513_e", "Z");
    jfieldID pressTime = getFieldID("field_151474_i", "I");
    jfieldID keyCode = getFieldID("field_74512_d", "I");
    jobject list = getObject(keyArray);
    jclass clsList = this->core->getEnv()->GetObjectClass(list);
    int listSize = this->core->getEnv()->GetArrayLength((jarray)list);

    if ((GetAsyncKeyState('W') & 0xff00) != 0) {
        std::cout << "Key Pressed : W" << std::endl;
    }

    for (int i = 0; i < listSize; i++) {
        jmethodID midGet = this->core->getEnv()->GetMethodID(clsList, "get", "(I)Ljava/lang/Object;");
        jobject obj = this->core->getEnv()->CallObjectMethod(list, midGet, i);
        int pTime = getInt(obj, pressTime);
        int kc = getInt(obj, keyCode);
        if (pTime == 0) {

        }
    }
}