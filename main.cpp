#include <iostream>
#include "Engine.h"
using namespace std;
#include "Logger.h"
#include "raylib/src/raylib.h"
void CustomLog(int msgType, const char *text, va_list args)
{
    char timeStr[64] = { 0 };
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("[%s] ", timeStr);

    switch (msgType)
    {
        case LOG_INFO: printf("[INFOs] : "); break;
        case LOG_ERROR: printf("[ERROR]: "); break;
        case LOG_WARNING: printf("[WARN] : "); break;
        case LOG_DEBUG: printf("[DEBUG]: "); break;
        default: break;
    }

    vprintf(text, args);
    printf("\n");
}

int main(void)
{
    //SetTraceLogCallback(Logger::SetMessage);
        Engine engine;
        while (engine.running())  // main game loop
        {
            engine.Update();
            engine.render();
        }

        return 0;



}