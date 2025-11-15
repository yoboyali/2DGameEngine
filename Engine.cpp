//
// Created by Ali Hamdy on 17/10/2025.
//

#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Player.h"
#include <iostream>
#define FrameRate 60
#define WindowWidth 1200
#define WindowHeight 800

Engine::Engine()
{
    initWindow();
}

Engine::~Engine()
{

}

const bool Engine::running() const
{
    return !WindowShouldClose();
}

void Engine::initWindow()
{
    InitWindow(WindowWidth , WindowHeight , "Hello World");
    SetTargetFPS(FrameRate);
    FemaleAdventurer = new Player;
    posx = 250;
    posy = 250;
}

void Engine::Update()
{
    Vector2 pos = GetMousePosition();
    this ->x = pos.x;
    this ->y = pos.y;
    input = {0};
    //std::cout<<x<<std::endl;
    //std::cout<<y<<std::endl;

    event();

}

void Engine::event()
{
    if(WindowShouldClose()) {
        CloseWindow();
    }
    if (IsKeyDown(KEY_D)) {
        input.x += 1.0;
    }
    if (IsKeyDown(KEY_A)) {
        input.x -= 1.0;
    }
    if (IsKeyDown(KEY_W)) {
        input.y -= 1.0;
    }
    if (IsKeyDown(KEY_S)) {
        input.y += 1.0;
    }
    if (IsKeyDown(KEY_J)) {
        shooting = true;
    }
    FemaleAdventurer->GetInput(input , shooting);
    shooting =false;

}

void Engine::render()
{
    BeginDrawing();
    ClearBackground(BLACK);
    std::vector<Vector2> x = {{100 , 100} , {100 , 200} , {200 , 100} , {200 , 200}};
    draw.primDrawPolyline( x, WHITE);
    draw.primDrawPolygon({100 , 100}, 4 , 30 , 90 , WHITE , BLACK);
    DrawPolyLines({200 , 200} , 4 , 30 ,  90 , WHITE);
    FemaleAdventurer->Draw();
    DrawText("Health:" , 10 , 750 , 35 , RED);

    EndDrawing();
}
