#include "colisiones.h"

#include <cmath>

bool colisiones::detectarColision(
    particula &p1,
    particula &p2)
{
    float dx =
        p1.getX() - p2.getX();

    float dy =
        p1.getY() - p2.getY();

    float distancia =
        sqrt(dx*dx + dy*dy);

    return distancia <=
           p1.getRadio() +
               p2.getRadio();
}

void colisiones::colisionCompletamenteInelastica(
    particula &p1,
    particula &p2)
{
    float nuevaVx =

        (
            p1.getMasa() * p1.getVx()
            +
            p2.getMasa() * p2.getVx()
            )

        /

        (
            p1.getMasa()
            +
            p2.getMasa()
            );

    float nuevaVy =

        (
            p1.getMasa() * p1.getVy()
            +
            p2.getMasa() * p2.getVy()
            )

        /

        (
            p1.getMasa()
            +
            p2.getMasa()
            );

    p1.setVx(nuevaVx);
    p1.setVy(nuevaVy);

    p2.setVx(nuevaVx);
    p2.setVy(nuevaVy);
}

void colisiones::colisionObstaculo(
    particula &p,
    int x,
    int y,
    int ancho,
    int alto)
{
    if(p.getX() >= x &&
        p.getX() <= x + ancho &&
        p.getY() >= y &&
        p.getY() <= y + alto)
    {
        p.setVx(p.getVx()*0.7);

        p.setVy(p.getVy()*0.7);
    }
}
