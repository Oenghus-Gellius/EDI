#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
typedef struct Ponto TPonto;
TPonto *criaPonto(float x, float y);
float distancia(TPonto *p1,TPonto *p2);
void terminaPonto(TPonto *p);
//obtem o valor de x do ponto p
float getX(TPonto *p);
float getY(TPonto *p);
void setX(TPonto *p,float ax);
void setY(TPonto *p,float ay);
#endif // PONTO_H_INCLUDED
