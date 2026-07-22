#include "Application.h"
#include "Logger.h"
#include "../../Platform/Windows/WindowsWindow.h"
#include "../../Platform/Window.h"

#include <iostream>

Application::Application()
{
    Logger::Info("Application initialized.");
}

void Application::Run()
{
    Logger::Info("Starting Muyti Engine...");
    Window* window = new WindowsWindow();

    window->Create();
    window->Update();   
    window->Destroy();

    delete window;
}

