#include "particula.h"

particula::particula()
{
    x = 0;
    y = 0;

    vx = 0;
    vy = 0;

    masa = 1;
    radio = 5;
}

// Constructor con parámetros
particula::particula(float x, float y, float vx, float vy, float masa, float radio)
{
    this->x = x;
    this->y = y;

    this->vx = vx;
    this->vy = vy;

    this->masa = masa;
    this->radio = radio;
}
void particula::mover(float dt)
{
    x = x + vx * dt;
    y = y + vy * dt;
}
void particula::verificarColisionParedes(int anchoCaja, int altoCaja)
{
    // Pared izquierda o derecha
    if(x - radio <= 0 || x + radio >= anchoCaja)
    {
        vx = -vx;
    }

    // Techo o piso
    if(y - radio <= 0 || y + radio >= altoCaja)
    {
        vy = -vy;
    }
}
float particula::getX()
{
    return x;
}

float particula::getY()
{
    return y;
}

float particula::getVx()
{
    return vx;
}

float particula::getVy()
{
    return vy;
}

float particula::getMasa()
{
    return masa;
}

float particula::getRadio()
{
    return radio;
}
void particula::setX(float x)
{
    this->x = x;
}

void particula::setY(float y)
{
    this->y = y;
}

void particula::setVx(float vx)
{
    this->vx = vx;
}

void particula::setVy(float vy)
{
    this->vy = vy;
}

void particula::setMasa(float masa)
{
    this->masa = masa;
}

void particula::setRadio(float radio)
{
    this->radio = radio;
}
