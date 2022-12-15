#pragma once
#include "InventoryWalk.h"
#include "ModuleId.h"

InventoryWalk::InventoryWalk(Core* core, const char* name, int key) : InventoryWalk(core, name, key, false) {

}

InventoryWalk::InventoryWalk(Core *core, const char* name, int key, boolean state) : Module(core, name, ModuleId::MODULE_INVENTORY_WALK, key, state) {
    this->mc = new Minecraft(this->getCore());
    this->keys['W'] = this->mc->getGameSettings()->getKeyBindForward();
    this->keys['S'] = mc->getGameSettings()->getKeyBindBack();
    this->keys['D'] = mc->getGameSettings()->getKeyBindRight();
    this->keys['A'] = mc->getGameSettings()->getKeyBindLeft();
    this->keys[VK_SPACE] = mc->getGameSettings()->getKeyBindJump();
}

void InventoryWalk::onUpdate() {
    auto iter = this->keys.begin();
    while (iter != this->keys.end()) {
        if ((GetAsyncKeyState(iter->first) & 0xff00) != 0) {
            iter->second->setKeyBindState(iter->second->getKeyCode(), true);
        } else {
            iter->second->setKeyBindState(iter->second->getKeyCode(), false);
        }
        iter++;
    }
}