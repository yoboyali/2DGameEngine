#include <iostream>
#include "Engine.h"
using namespace std;
#include "raylib/src/raylib.h"
int main()
{
        Engine engine;
        while (engine.running())  // main game loop
        {
            engine.Update();
            engine.render();
        }

        return 0;



}