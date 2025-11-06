//
// Created by Ali Hamdy on 17/10/2025.
//

#include "PrimitiveRenderer.h"
#include "iostream"
#include "math.h"
#include "raylib.h"

PrimitiveRenderer::PrimitiveRenderer()
{
    initVariables();
}

PrimitiveRenderer::~PrimitiveRenderer()
{
    EndDrawing();
    CloseWindow();
}

void PrimitiveRenderer::primDraw(int x0 , int x1 , int y0 , int y1)
{
    float x = x1 - x0;
    float y = y1 - y0;
    slope = y / x;
    float temp = y0;
    for (int i = x0 ; i < x1 ; i++) {
        DrawPixel(i , temp , BLACK );
        temp = temp + slope;
        std::cout<<i<<":"<<round(temp)<<std::endl;
    }
}

void PrimitiveRenderer::primDrawCircle(int x, int y, int Radius)
{

    for (int i = 0 ; i < 90 ;i++) {
        int X = x + Radius *cos(i* DEG2RAD);
        int Y = y + Radius *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Radius *-cos(i* DEG2RAD);
        Y = y + Radius *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Radius *cos(i* DEG2RAD);
        Y = y + Radius *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Radius *-cos(i* DEG2RAD);
        Y = y + Radius *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);

    }
}

void PrimitiveRenderer::primDrawEllipse(int x, int y, int Rx, int Ry)
{
    for (int i = 0 ; i < 90 ;i++) {
        int X = x + Rx *cos(i* DEG2RAD);
        int Y = y + Ry *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Rx *-cos(i* DEG2RAD);
        Y = y + Ry *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Rx *cos(i* DEG2RAD);
        Y = y + Ry *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        X = x + Rx *-cos(i* DEG2RAD);
        Y = y + Ry *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);

    }
}

void PrimitiveRenderer::initVariables()
{
    x0 = 0;
    x1 = 0;
    y0 = 0;
    y1 = 0;
    slope = 0.0;
}
