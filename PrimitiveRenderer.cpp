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

void PrimitiveRenderer::FillBuffer(int x , int y , Color color)
{
    buffer[x][y] = color;
}

void PrimitiveRenderer::EmptyBuffer()
{
    for (int i = 0 ; i < 1200 ; i++) {
        for (int j = 0 ; j < 800 ; j++) {
            buffer[i][j] = BLACK;
        }
    }
}


void PrimitiveRenderer::primDrawCircle(int x, int y, int Radius)
{
    float step = 1 / Radius;
    for (int i = 0 ; i < 90 ;i++) {
        int X = x + Radius *cos(i* DEG2RAD);
        int Y = y + Radius *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Radius *-cos(i* DEG2RAD);
        Y = y + Radius *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Radius *cos(i* DEG2RAD);
        Y = y + Radius *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Radius *-cos(i* DEG2RAD);
        Y = y + Radius *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);


    }
}

void PrimitiveRenderer::primDrawEllipse(int x, int y, int Rx, int Ry)
{
    for (int i = 0 ; i < 360 ;i+= 0.001) {
        int X = x + Rx *cos(i* DEG2RAD);
        int Y = y + Ry *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Rx *-cos(i* DEG2RAD);
        Y = y + Ry *sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Rx *cos(i* DEG2RAD);
        Y = y + Ry *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);
        X = x + Rx *-cos(i* DEG2RAD);
        Y = y + Ry *-sin(i* DEG2RAD);
        DrawPixel(X , Y , WHITE);
        FillBuffer(X , Y, WHITE);

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

    std::vector<Vector2> pixelToCheck;
    pixelToCheck.push_back({(float)x,(float)y});
    while (pixelToCheck.size()>0) {
        Vector2 point=pixelToCheck.back();
        pixelToCheck.pop_back();
        x=point.x;
        y=point.y;
        if (x < 1200 && x > 0 && y < 800 && y > 0)
        {

            Color targetColor = buffer[x][y];
            if (ColorisEqual(targetColor , EdgeColor) || ColorisEqual(targetColor , FillColor))
                continue;
            FillBuffer(x,y,FillColor);
            DrawPixel(x , y , FillColor);
            pixelToCheck.push_back({point.x+1,point.y});
            pixelToCheck.push_back({point.x-1,point.y});
            pixelToCheck.push_back({point.x,point.y+1});
            pixelToCheck.push_back({point.x,point.y-1});

        }


    }


    return 0;
}

bool PrimitiveRenderer::ColorisEqual(Color a, Color b)
{
    return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;

}

void PrimitiveRenderer::initVariables()
{
    x0 = 0;
    x1 = 0;
    y0 = 0;
    y1 = 0;
    slope = 0.0;
}
