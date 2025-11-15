#include "Engine.h"
#include <fstream>
using namespace std;
#include "raylib/src/raylib.h"
void CustomLog(int msgType, const char *text, va_list args)
{   fstream LogFile("Log.txt" , std::ios::app);
    char timeStr[64] = { 0 };
    time_t now = time(nullptr);
    struct tm *tm_info = localtime(&now);

    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", tm_info);
    LogFile<<timeStr;
    const char* x = "";
    switch (msgType)
    {
        case LOG_INFO: x ="[INFO bitch] : "; break;
        case LOG_ERROR: x ="[ERROR]: "; break;
        case LOG_WARNING: x ="[WARN] : "; break;
        case LOG_DEBUG: x ="[DEBUG]:"; break;
        default: break;
    }
    LogFile<<x;
    char buffer[1024];
    vsnprintf(buffer , sizeof(buffer) , text , args);
    LogFile<<buffer<<"\n";
    LogFile.close();
}

int main(void)
{
        SetTraceLogCallback(CustomLog);
        Engine engine;
        while (engine.running())  // main game loop
        {
            engine.Update();
            engine.render();
        }

        return 0;



}