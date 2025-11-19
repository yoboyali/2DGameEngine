//
// Created by Ali Hamdy on 17/10/2025.
//

#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H
#include <vector>

#include "raylib.h"



class PrimitiveRenderer {
public:
PrimitiveRenderer();
~PrimitiveRenderer();
    Color buffer[1200][800];
int x1 , x0 , y1 , y0;
float slope;
void primDraw(int x0 ,  int x1 ,int y0 ,int y1);
void FillBuffer(int x , int y , Color color);
void EmptyBuffer();
void primDrawCircle(int x , int y , int Radius);
void primDrawEllipse(int x , int y , int Rx , int Ry);
void primDrawPolyline(std::vector<Vector2> Sides, Color color);
void primDrawPolygon(Vector2 center , int sides , float radius , float rotation , Color EdgeColor , Color FillColor);
int Floodfill(int x  ,int y , Color FillColor , Color EdgeColor);
bool ColorisEqual(Color a , Color b);
void Borderfill();
void initVariables();
};



#endif //PRIMITIVERENDERER_H
