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
bool particula::verificarColisionParedes(int izquierda,int derecha,int arriba,int abajo)
{
    if(x - radio <= izquierda)
    {
        x = izquierda + radio;
        vx = -vx;
        return true;
    }

    else if(x + radio >= derecha)
    {
        x = derecha - radio;
        vx = -vx;
        return true;
    }

    if(y - radio <= arriba)
    {
        y = arriba + radio;
        vy = -vy;
        return true;
    }

    else if(y + radio >= abajo)
    {
        y = abajo - radio;
        vy = -vy;
        return true;
    }
    return false;
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
