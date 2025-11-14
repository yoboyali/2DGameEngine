//
// Created by Ali Hamdy on 14/11/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#define MAXENEMIES 50

class Enemy {
public:
    Enemy();
    ~Enemy();

typedef struct Enem
{
    Vector2 velocity;
    Vector2 Position = {0};
    bool alive;
};
Vector2 PlayerPos;
Enem Enemies[MAXENEMIES];
int NumOfEnem;
void SpawnEnemies();
void Update(Vector2 Pos);
void Draw();
public: void SetEnemNum(int x);

};



#endif //ENEMY_H
