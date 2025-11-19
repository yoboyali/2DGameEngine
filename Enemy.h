//
// Created by Ali Hamdy on 14/11/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#include "PrimitiveRenderer.h"
#define MAXENEMIES 50


class Enemy {
public:
    Enemy();
    ~Enemy();
typedef enum AnimationType
{
    Repeating = 1,
    Oneshot = 2,
}AnimationType;
typedef struct Animation
{
    int first;
    int last;
    int current;
    AnimationType type;
    float speed;
    float durationLeft;
}Animation;
typedef enum Direction
{
    Down = 0,
    Up = 26,
    Left = 56,
    Right = 80,
}Direction;
typedef struct Enems
{
    Vector2 velocity;
    Vector2 Position = {0};
    bool alive;
}Enem;

Vector2 PlayerPos;
Vector2 BulletPos;
Enem Enemies[MAXENEMIES];
PrimitiveRenderer Drawer;
Animation RepeatingAnimation;
Animation OneshotAnimation;
Direction EnemyDirection = Down;
Texture2D EnemyTexture;
bool walking = true;
bool Intersecting;
int NumOfEnem;
void SpawnEnemies();
void Update(Vector2 Pos);
void AnimationUpdate(Animation *self);
Rectangle animation_frame(Animation *self , Direction dir);
Direction calculateDirection(Vector2 Coordinates);
bool Isintersecting(Vector2 Playerpos , Vector2 Enemypos , int R1 , int R2);
void Draw(int i);
public: void SetEnemNum(int x , Vector2 bullet);

};



#endif //ENEMY_H
