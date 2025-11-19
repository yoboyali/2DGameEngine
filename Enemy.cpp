//
// Created by Ali Hamdy on 14/11/2025.
//

#include "Enemy.h"
#include <time.h>
#include "raymath.h"
#include <iostream>
#define EnemyWidth 26
#define EnemyHeight 24
#define NumFramePerRow 5
#define PlayerHitBox 40
#define EnemyHitBox 60
#define EnemyDrawsize 50
Enemy::Enemy()
{
    srand(time(NULL));
    EnemyTexture = LoadTexture("Sprites/Enemy.png");
    RepeatingAnimation = (Animation){.first = 0 , .last = 4 , .current = 0 , .speed = 0.3 , .durationLeft = 0.1 , .type = Repeating};
    Intersecting = false;
}

Enemy::~Enemy()
{
    UnloadTexture(EnemyTexture);
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
{    PlayerPos.x = Pos.x + 100;
     PlayerPos.y = Pos.y + 100;
    for (int i = 0; i < NumOfEnem; i++) {
        if (Isintersecting(BulletPos , Enemies[i].Position , 0 , EnemyHitBox)){Enemies[i].alive = false;}
        if (!Enemies[i].alive) continue;

        Vector2 centerI = {
            Enemies[i].Position.x + EnemyDrawsize,
            Enemies[i].Position.y + EnemyDrawsize,
        };

        for (int j = 0; j < NumOfEnem; j++) {
            //if (Isintersecting(BulletPos , Enemies[j].Position)){Enemies[j].alive = false;}
            if (i == j || !Enemies[j].alive) continue;

            Vector2 centerJ = {
                Enemies[j].Position.x +EnemyDrawsize,
                Enemies[j].Position.y +EnemyDrawsize,
            };

            float dx = centerI.x - centerJ.x;
            float dy = centerI.y - centerJ.y;
            float distSq = dx*dx + dy*dy;
            float minDist = EnemyHitBox * 2;

            if (distSq < minDist * minDist && !Isintersecting(PlayerPos , centerI , PlayerHitBox , EnemyHitBox)) {
                Vector2 push = Vector2Normalize({dx, dy});
                Enemies[i].Position = Vector2Add(Enemies[i].Position, Vector2Scale(push, 1.0f));
            }
        }

        centerI = {
            Enemies[i].Position.x +EnemyDrawsize,
            Enemies[i].Position.y +EnemyDrawsize,
        };
        if (!Isintersecting(PlayerPos , centerI ,PlayerHitBox , EnemyHitBox)) {
            Vector2 dir = Vector2Normalize(Vector2Subtract(PlayerPos, centerI));
            Enemies[i].Position = Vector2Add(Enemies[i].Position, Vector2Scale(dir, 1.0f));
        }
        calculateDirection(centerI);
        Draw(i);
        Drawer.primDrawCircle(centerI.x, centerI.y, EnemyHitBox);
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

Rectangle Enemy::animation_frame(Animation *self , Direction dir)
{
    int x =(self->current % NumFramePerRow) * EnemyWidth;
    int y = (self->current / NumFramePerRow) * EnemyHeight;
    return (Rectangle)
    {.x = (float)x , .y = (float)y , .width = EnemyWidth , .height = EnemyHeight};
}

Enemy::Direction Enemy::calculateDirection(Vector2 Coordinates)
{
    float angle = atan2f(Coordinates.y , Coordinates.x);
    float deg = angle * (180 / 3.14);
    if (deg < 0){
        deg += 360;
    }
    if(deg >= 337.5 || deg < 22.5){return Right;}
    else if(deg < 112.5){return Down;}
    else if(deg < 202.5){return Left;}
    else if(deg < 292.5){return Up;}
}

bool Enemy::Isintersecting(Vector2 Playerpos, Vector2 Enemypos , int R1 , int R2)
{float DistanceBetween = sqrt(pow(Enemypos.x - Playerpos.x , 2) +pow(Enemypos.y - Playerpos.y , 2));
    if ((int)DistanceBetween <= R1 + R2){Intersecting = true ; return true;}
    else{Intersecting = false ;return false;}
}

void Enemy::Draw(int i)
{
    if (walking) {
        DrawTexturePro(EnemyTexture , animation_frame(&RepeatingAnimation , EnemyDirection )  , {Enemies[i].Position.x , Enemies[i].Position.y , 100 , 100} , {0, 0} , 0.0 , WHITE);
    }
    AnimationUpdate(&RepeatingAnimation);
}
void Enemy::SetEnemNum(int x , Vector2 bullet)
{   BulletPos = bullet;
    NumOfEnem = x;

}
