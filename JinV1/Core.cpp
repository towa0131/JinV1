#pragma once

#include <cmath>
#include "Core.h"
#include "modules/AutoClicker.h"
#include "modules/AutoTool.h"
#include "modules/InventoryWalk.h"
#include "modules/ModuleManager.h"
#include "modules/FastPlace.h"
#include "modules/FastMove.h"
#include "modules/Dolphin.h"
#include "modules/HitDelayFix.h"
#include "modules/KeepSprint.h"
#include "modules/Speed.h"
#include "utils/ProcessUtils.h"
#include "impl/net/minecraft/client/Minecraft.h"
#include "impl/net/minecraft/client/settings/KeyBinding.h"
#include "impl/com/moonsworth/lunar/bridge/BridgeManager.h"
#include "mapping/MCPMapTranslator.h"

//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_glfw.h"
//#include "imgui/imgui_impl_opengl3.h"
//#include "imgui/GLFW/glfw3.h"

void Core::run() {
    this->running = true;
    this->moduleManager = new ModuleManager();
    this->mapping = new MCPMapTranslator();

    this->getModuleManager()->registerModule(new FastPlace(this, "FastPlace", 'P', true));
    this->getModuleManager()->registerModule(new HitDelayFix(this, "HitDelayFix", 'H', true));
    this->getModuleManager()->registerModule(new KeepSprint(this, "KeepSprint", 'K', true));
    this->getModuleManager()->registerModule(new AutoClicker(this, "AutoClicker", 'B', false));
    this->getModuleManager()->registerModule(new InventoryWalk(this, "InventoryWalk", 'I', false));
    this->getModuleManager()->registerModule(new Speed(this, "Speed", 'N', false));
    this->getModuleManager()->registerModule(new FastMove(this, "FastMove", 'M', false));
    this->getModuleManager()->registerModule(new Dolphin(this, "Dolphin", 'D', false));
    this->getModuleManager()->registerModule(new AutoTool(this, "AutoTool", 'A', false));

    //if (!glfwInit()) {
    //    std::cout << "glfw initialize failed!" << std::endl;
    //}

    //GLFWwindow* window = glfwCreateWindow(800, 600, "sample2", NULL, NULL);

    //if (!window) {
    //    glfwTerminate();
    //    std::cout << "Window Create Failed!!!" << std::endl;
    //}

    //const char* glsl_version = "#version 130";

    //glfwMakeContextCurrent(window);
    //glfwSwapInterval(1);

    //IMGUI_CHECKVERSION();
    //ImGui::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;

    //ImGui::StyleColorsDark();

    //ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplOpenGL3_Init(glsl_version);

     Minecraft* mc = new Minecraft(this);

    //float x, y;

    while (this->running) {
        if (mc->isInWorld()) this->getModuleManager()->update();

        //ImGui_ImplOpenGL3_NewFrame();
        //ImGui_ImplGlfw_NewFrame();
        //ImGui::NewFrame();
        //ImGui::ShowDemoWindow();
        //ImGui::Render();

        //ImGui_ImplOpenGL3_NewFrame();
        //ImGui_ImplGlfw_NewFrame();
        //ImGui::NewFrame();
        //ImGui::Begin("Hello, world!");
        //ImGui::Text("This is some useful text.");
        //ImGui::DragFloat("x", &x);
        //ImGui::DragFloat("y", &y);
        //ImGui::End();

        //// Rendering
        // ImGui::Render();

        //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        //glfwSwapBuffers(window);

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

MapTranslator* Core::getMapping() {
    return this->mapping;
}