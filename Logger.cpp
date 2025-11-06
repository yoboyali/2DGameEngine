//
// Created by Ali Hamdy on 06/11/2025.
//

#include "Logger.h"
#include "raylib.h"
#define MSGSIZE 100

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::SetMessage(int type , const char *text , va_list args)
{
    switch (type)
    {
        case LOG_INFO: WriteLog(LOG_INFO , text , args); break;
        case LOG_ERROR: printf("[ERROR]: "); break;
        case LOG_WARNING: printf("[WARN] : "); break;
        case LOG_DEBUG: printf("[DEBUG]: "); break;
        default: break;
    }
}

void Logger::WriteLog(int type , const char *text , va_list args)
{

}

