//
// Created by Ali Hamdy on 14/11/2025.
//

#include "Enemy.h"
#include <time.h>
#include "raymath.h"

Enemy::Enemy()
{
    srand(time(NULL));
}

Enemy::~Enemy()
{
}

void Enemy::SpawnEnemies(){
    for (int i = 0 ; i < NumOfEnem ; i++) {
           float x = rand() % 1000;
        if (Enemies[i].alive == false) {
            Enemies[i].alive = true;
            Enemies[i].Position = (Vector2){ x , -1};
        }
    }
}

void Enemy::Update(Vector2 Pos)
{   PlayerPos.x = Pos.x + 100;
    PlayerPos.y = Pos.y + 100;
    for (int i = 0 ; i < NumOfEnem ; i++) {
        if (Enemies[i].alive) {

            Vector2 dir = Vector2Normalize(Vector2Subtract(PlayerPos , Enemies[i].Position));
            Enemies[i].Position = Vector2Add(Enemies[i].Position , Vector2Scale(dir , 1));
            DrawRectangle(Enemies[i].Position.x , Enemies[i].Position.y ,50 , 50 , RED);
            DrawPixel(Enemies[i].Position.x , Enemies[i].Position.y , BLUE);
        }
    }
}

void Enemy::Draw()
{

}

void Enemy::SetEnemNum(int x)
{
    NumOfEnem = x;

}
