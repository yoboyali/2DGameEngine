//
// Created by Ali Hamdy on 17/10/2025.
//

#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H



class PrimitiveRenderer {
public:
PrimitiveRenderer();
~PrimitiveRenderer();
int x1 , x0 , y1 , y0 ;
float slope;
void primDraw(int x0 ,  int x1 ,int y0 ,int y1);
void primDrawCirlce(int x , int y , int Radius);
void primDrawElipse(int x , int y , int Rx , int Ry);
void initVariables();
};



#endif //PRIMITIVERENDERER_H
