//
// Created by Ali Hamdy on 14/11/2025.
//

#include "Enemy.h"
#include <time.h>
#include "raymath.h"
#include <iostream>
#define EnemyWidth 25
#define EnemyHeight 24
#define NumFramePerRow 5
#define PlayerHitBox 40
#define EnemyHitBox 30
Enemy::Enemy()
{
    srand(time(NULL));
    EnemyTexture = LoadTexture("Sprites/Enemy.png");
    RepeatingAnimation = (Animation){.first = 0 , .last = 4 , .current = 0 , .speed = 0.3 , .durationLeft = 0.1 , .type = Repeating};
}

Enemy::~Enemy()
{
}

void Enemy::SpawnEnemies(){
    for (int i = 0 ; i < NumOfEnem ; i++) {
           float x = rand() % 1000;
        if (Enemies[i].alive == false) {
            Enemies[i].alive = true;
            Enemies[i].Position = (Vector2){ x , 10};
        }
    }
}

void Enemy::Update(Vector2 Pos)
{   PlayerPos.x = Pos.x + 100;
    PlayerPos.y = Pos.y + 100;
    for (int i = 0 ; i < NumOfEnem ; i++) {
        Draw(i);
        Drawer.primDrawCircle(Enemies[i].Position.x + 25 , Enemies[i].Position.y + 25 , 30);
        if (Enemies[i].alive && !Isintersecting(PlayerPos , {Enemies[i].Position.x + 25 , Enemies[i].Position.y + 25})) {
            Vector2 dir = Vector2Normalize(Vector2Subtract(PlayerPos , Enemies[i].Position));
            Enemies[i].Position = Vector2Add(Enemies[i].Position , Vector2Scale(dir , 1));
            //DrawTexture(Orc , Enemies[i].Position.x , Enemies[i].Position.y , WHITE);


        }
    }
}

void Enemy::AnimationUpdate(Animation *self)
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
            case Oneshot:
                self->current = self->last;
                break;
        }
    }
}

Rectangle Enemy::animation_frame(Animation *self)
{
    int x =(self->current % NumFramePerRow) * EnemyWidth;
    int y = (self->current / NumFramePerRow) * EnemyHeight+ 56;
    return (Rectangle)
    {.x = (float)x , .y = (float)y , .width = EnemyWidth , .height = EnemyHeight};
}

bool Enemy::Isintersecting(Vector2 Playerpos, Vector2 Enemypos)
{float DistanceBetween = sqrt(pow(Enemypos.x - Playerpos.x , 2) +pow(Enemypos.y - Playerpos.y , 2));
    if ((int)DistanceBetween <= PlayerHitBox + EnemyHitBox){return true;}
    else{return false;}
}

void Enemy::Draw(int i)
{
    if (walking) {
        DrawTexturePro(EnemyTexture , animation_frame(&RepeatingAnimation)  , {Enemies[i].Position.x , Enemies[i].Position.y , 50 , 50} , {0 , 0} , 0.0 , WHITE);
    }
    AnimationUpdate(&RepeatingAnimation);
}
void Enemy::SetEnemNum(int x)
{
    NumOfEnem = x;

}
