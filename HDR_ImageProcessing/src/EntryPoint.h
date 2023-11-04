#pragma once


#include <HDR_IP/System/CoreSystem/Application.h>
#include <HDR_IP/System/CoreSystem/Logger.h>



extern HDR_IP::Application* HDR_IP::CreateApplication();

int main(int argc, char** argv)
{
    // We first initialize the logger
    // this way, we can use logging macros
    HDR_IP::Logger::Init();
    HDR_IP_WARN("Logger has been initialized.");
    HDR_IP::Application* Application = HDR_IP::CreateApplication();
    Application->Run();

    delete Application;
    return 0;
}