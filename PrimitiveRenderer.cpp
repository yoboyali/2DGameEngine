//
// Created by Ali Hamdy on 17/10/2025.
//

#include "PrimitiveRenderer.h"
#include "iostream"
#include "math.h"
#include "raylib.h"

//Open and closed polyline , set of points or  linesegment
//closed polygon same as polyline and a polygon chain that breaks
//filling using border and and flood
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

void PrimitiveRenderer::primDrawPolyline(std::vector<Vector2> Side, Color color)
{
    for (int i = 0 ; i < Side.size() ; i++) {
        int j = (i + 1) % Side.size();
        DrawLine(Side[i].x , Side[i].y , Side[j].x , Side[j] .y, color);
    }
}

void PrimitiveRenderer::primDrawPolygon(Vector2 center, int sides, float radius, float rotation, Color EdgeColor,Color FillColor)
{
    if (sides < 3){sides = 3;}
    float centralangle = DEG2RAD * rotation;
    float anglestep = 360/(float)sides*DEG2RAD;
    float x , y , x1 , y2;
    for (int i = 0 ; i < sides ; i++) {
        x = center.x + cosf(centralangle)*radius;
        y = center.y + sinf(centralangle) * radius;
        x1= center.x + cosf(centralangle + anglestep) * radius;
        y2 = center.y + sinf(centralangle + anglestep) * radius;
        DrawLine(x , y , x1 , y2 , EdgeColor);
        centralangle += anglestep;
    }

}

int PrimitiveRenderer::Floodfill(int x, int y, Color FillColor, Color EdgeColor)
{
    return 0;
}

void PrimitiveRenderer::initVariables()
{
    x0 = 0;
    x1 = 0;
    y0 = 0;
    y1 = 0;
    slope = 0.0;
}
