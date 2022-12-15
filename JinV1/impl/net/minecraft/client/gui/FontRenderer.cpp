#include "FontRenderer.h"

FontRenderer::FontRenderer(Core* core, jobject fontRenderer) : ImplClass(core, "net.minecraft.client.gui.FontRenderer") {
    this->fontRenderer = fontRenderer;
    this->fdDrawString = getMethodID("func_175065_a", "(Ljava/lang/String;FFIZ)I");
}

int FontRenderer::drawString(const char *text, jfloat x, jfloat y, jint color) {
    jstring jtext = this->core->getEnv()->NewStringUTF(text);
    jint res = (jint)getObject(this->fontRenderer, this->fdDrawString, jtext, x, y, color, false);

    return res;
}