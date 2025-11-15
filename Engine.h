//
// Created by Ali Hamdy on 17/10/2025.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "Player.h"
#include "PrimitiveRenderer.h"
#include <raylib.h>

class Engine {
public:
    Engine();
    ~Engine();
    const bool running() const;
    void initWindow();
    void Update();
    void event();
    void render();

    //variables
    int x;
    int y;
    int posx;
    int posy;
    bool shooting = false;
    Vector2 input = {0};
    PrimitiveRenderer draw;
    Player* FemaleAdventurer;
};



#endif //ENGINE_H
