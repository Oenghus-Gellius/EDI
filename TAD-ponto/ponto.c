#include <math.h>
#include <stdlib.h>
#include  "ponto.h"
struct Ponto{
    float x,y;
};

TPonto *criaPonto(float ax, float ay){
    TPonto *p = (TPonto*)malloc(sizeof(TPonto));
    p->x=ax;
    p->y=ay;
    return p;
}

void terminaPonto(TPonto *p){
    free(p);
}
float distancia(TPonto *p1,TPonto *p2){
    float dx = p1->x-p2->x;
    float dy = p1->y-p2->y;
/*float dx = p1.v[0]-p2.v[0];
    float dy = p1.v[1]-p2.v[1];*/
    return sqrt(dx*dx+dy*dy);
}

float getX(TPonto *p){
    return p->x;
}
float getY(TPonto *p){
    return p->y;
}
void setX(TPonto *p,float ax){
    p->x = ax;
}
void setY(TPonto *p,float ay){
    p->y = ay;
}
