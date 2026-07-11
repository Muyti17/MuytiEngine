#include "Logger.h"
#include <iostream>

LogLevel Logger::s_LogLevel = LogLevel::Info; // Default log level

void Logger::SetLogLevel(LogLevel level)
{
    // Set the log level for the logger
    s_LogLevel = level;
}
void Logger::Info(const std::string& message)
{
    if (s_LogLevel > LogLevel::Info)
    {
        return; // Skip logging if the current log level is higher than Info
    }
    // Log the message to the console or a file
    std::cout << "[INFO]: " << message << std::endl;
}

void Logger::Warning(const std::string& message)
{
    if (s_LogLevel > LogLevel::Warning)
    {
        return; // Skip logging if the current log level is higher than Warning
    }
    // Log the message to the console or a file
    std::cout << "[WARNING]: " << message << std::endl;
}

void Logger::Error(const std::string& message)
{
    if (s_LogLevel > LogLevel::Error)
    {
        return; // Skip logging if the current log level is higher than Error
    }
    // Log the message to the console or a file
    std::cerr << "[ERROR]: " << message << std::endl;
}