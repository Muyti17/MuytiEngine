#include "Application.h"
#include "Logger.h"

#include <iostream>

Application::Application()
{
    Logger::Info("Application initialized.");
}

void Application::Run()
{
    Logger::Info("Starting Muyti Engine...");
}