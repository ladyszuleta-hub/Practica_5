#include "particula.h"

particula::particula()
{
    x = 0;
    y = 0;

    vx = 0;
    vy = 0;

    masa = 1;
    radio = 5;
    activa=true;

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
    activa=true;
}
void particula::mover(float dt)
{
    x = x + vx * dt;
    y = y + vy * dt;
}
void particula::verificarColisionParedes(int anchoCaja, int altoCaja)
{
    if (x - radio <= 0)
    {
        x = radio;
        vx = -vx;
    }
    else if (x + radio >= anchoCaja)
    {
        x = anchoCaja - radio;
        vx = -vx;
    }

    if (y - radio <= 0)
    {
        y = radio;
        vy = -vy;
    }
    else if (y + radio >= altoCaja)
    {
        y = altoCaja - radio;
        vy = -vy;
    }
}
float particula::getX() const
{
    return x;
}

float particula::getY() const
{
    return y;
}

float particula::getVx() const
{
    return vx;
}

float particula::getVy() const
{
    return vy;
}

float particula::getMasa() const
{
    return masa;
}

float particula::getRadio() const
{
    return radio;
}
bool particula:: getActiva() const{return activa;}
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

void particula::setActiva(bool estado)
{
    activa = estado;
}
