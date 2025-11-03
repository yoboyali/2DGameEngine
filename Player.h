//
// Created by Ali Hamdy on 28/10/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "PrimitiveRenderer.h"
#define MaxBullets 100


class Player {

    //Structs and enums
typedef struct bullet
{
    Vector2 position;
    Vector2 velocity;
    bool active;
}bullet;
typedef enum Animationtype
{
    Repeating = 1,
    OneShot = 2,
}Animationtype;
typedef struct Animation
{
    int first;
    int last;
    int current;
    Animationtype type;
    float speed;
    float durationLeft;
}Animation;
typedef enum Direction
{
    Down = 0,
    BottomLeft = 64,
    TopLeft = 128,
    Up = 192,
    TopRight =256,
    BottomRight = 320,
    Right = 384,
    Left = 448,
}Direction;
//Variables
    float temp = 0.0;
    float PositionX = 600;
    float PositionY = 400;
    Vector2 PlayerInput = {0};
    Texture2D player_idle_texture;
    Texture2D player_walk_texture;
    Texture2D player_shoot_texture;
    Texture2D player_walk_ShootTexture;
    Texture2D Death_texture;
    Texture2D background;
    Animation RepeatingAnimations;
    Animation OneShotAnimation;
    Direction PlayerDirection = Down;
    bool walking , Shooting , dead;
    bullet bullets[MaxBullets] ={0};
    PrimitiveRenderer PrimDraw;
//Functions
    void InitializeVariables();

    void Animation_update(Animation *self);
    Rectangle animation_frame(Animation *slef , Direction Direction);
    Direction calculateDirection(Vector2 input);
    void ProjectileSpawn(Vector2 input);
    void UpdateBullets();

    void update();
public: Player();
        ~Player();
        void Draw();
        void Getinput(Vector2 input , bool shooting);
};



#endif //PLAYER_H
