//
// Created by Ali Hamdy on 28/10/2025.
//

#include "Player.h"
#include "raymath.h"
#include <cmath>
#include "PrimitiveRenderer.h"
#define PlayerWidth 48
#define PlayerHeight 64
#define PlayerSpeed 5
#define NumFramePerRow 8
#define PlayerDrawSize 200

void Player::InitializeVariables()
{
    player_idle_texture = LoadTexture("/Users/alihamdy/CLionProjects/OOP4/Sprites/Idle_Gun.png");
    player_walk_texture = LoadTexture("/Users/alihamdy/CLionProjects/OOP4/Sprites/walk_aiming.png");
    player_walk_ShootTexture =LoadTexture("/Users/alihamdy/CLionProjects/OOP4/Sprites/walk_Shooting.png");
    player_shoot_texture = LoadTexture("/Users/alihamdy/CLionProjects/OOP4/Sprites/Shooting.png");
    Death_texture = LoadTexture("/Users/alihamdy/CLionProjects/OOP4/Sprites/death_Gun.png");
    RepeatingAnimations = (Animation){.first = 0 , .last = 7 , .current = 0 , .speed = 0.1 , .durationLeft = 0.1     , .type = Repeating};
    OneShotAnimation =(Animation){.first = 0 , .last = 7 , .current = 0 , .speed = 0.1 , .durationLeft = 0.1 , .type = OneShot};
    PlayerDirection = Down;
    background =LoadTexture("/Users/alihamdy/room1.png");

}

Player::Player()
{
    InitializeVariables();

}

Player::~Player()
{
    UnloadTexture(player_idle_texture);
    UnloadTexture(player_shoot_texture);
    UnloadTexture(player_walk_texture);
    UnloadTexture(player_walk_ShootTexture);
    UnloadTexture(Death_texture);
    UnloadTexture(background);
}

void Player::Animation_update(Animation *self)
{
    float deltaTime = GetFrameTime();
    self->durationLeft -= deltaTime;
    if (self->durationLeft <=0.0) {
        self->durationLeft = self->speed;
        self->current++;
    }
    if (self->current > self->last) {
        switch (self->type) {
            case Repeating:
                self->current = self->first;
                break;
            case OneShot:
                self->current = self->last;
                break;
        }
    }
}

Rectangle Player::animation_frame(Animation *self, Direction Direction)
{
    int x =(self->current % NumFramePerRow) * PlayerWidth;
    int y = (self->current / NumFramePerRow) * PlayerHeight + Direction;
    return (Rectangle)
    {.x = (float)x , .y = (float)y , .width = PlayerWidth , .height = PlayerHeight};
}

Player::Direction Player::calculateDirection(Vector2 input)
{
    float angle = atan2f(input.y , input.x);
    float deg = angle * (180 / 3.14);
    if (deg < 0){
        deg += 360;
}
if(deg >= 337.5 || deg < 22.5){return Right;}
else if(deg < 67.5){return BottomRight;}
else if(deg < 112.5){return Down;}
else if(deg < 157.5){return BottomLeft;}
else if(deg < 202.5){return Left;}
else if(deg < 247.5){return TopLeft;}
else if(deg < 292.5){return Up;}
else{return TopRight;}
}


void Player::ProjectileSpawn(Vector2 input)
{

}

void Player::UpdateBullets()
{
}

void Player::Draw()
{
    update();
   //
    DrawTexturePro(background , {0 , 0 ,480 ,320} ,{0 ,0, 1200 , 800} , {0,0} , 0.0 , WHITE);
    PrimDraw.primDrawCirlce(PositionX + 100 , PositionY + 100 , 30);
    if (Shooting && !walking &&!dead) {
        DrawTexturePro(player_shoot_texture ,animation_frame(&RepeatingAnimations , PlayerDirection) ,{PositionX , PositionY , PlayerDrawSize , PlayerDrawSize } , {0,0} , 0.0 ,WHITE);
    }
    if (walking && !Shooting && !dead) {
        DrawTexturePro(player_walk_texture ,animation_frame(&RepeatingAnimations , PlayerDirection) ,{PositionX , PositionY , PlayerDrawSize  , PlayerDrawSize } , {0,0} , 0.0 ,WHITE);
    }
    if (!walking && !Shooting && !dead) {
        DrawTexturePro(player_idle_texture ,animation_frame(&RepeatingAnimations , PlayerDirection) ,{PositionX , PositionY , PlayerDrawSize  , PlayerDrawSize } , {0,0} , 0.0 ,WHITE);
    }
    if (walking && Shooting && !dead) {
        DrawTexturePro(player_walk_ShootTexture ,animation_frame(&RepeatingAnimations , PlayerDirection) ,{PositionX , PositionY , PlayerDrawSize  , PlayerDrawSize } , {0,0} , 0.0 ,WHITE);
    }
    if (dead) {
        DrawTexturePro(Death_texture ,animation_frame(&OneShotAnimation  , PlayerDirection) ,{PositionX , PositionY , PlayerDrawSize  , PlayerDrawSize } , {0,0} , 0.0 ,WHITE);
    }
   //;
}

void Player::update()
{
    Animation_update(&RepeatingAnimations);
    Animation_update(&OneShotAnimation);

}

void Player::Getinput(Vector2 input , bool shooting)
{
PlayerInput.x = input.x;
PlayerInput.y = input.y;
Shooting = shooting;
    if(PlayerInput.x != 0 || PlayerInput.y != 0){
        walking = true;
        PlayerDirection = calculateDirection(PlayerInput);
        PositionX += PlayerInput.x * PlayerSpeed;
        PositionY += PlayerInput.y * PlayerSpeed;
        PositionX = Clamp(PositionX , -70 , 1130 - PlayerWidth);
        PositionY = Clamp(PositionY , -70 , 730 - PlayerHeight);
    }
    else {
        walking = false;
    }
}

