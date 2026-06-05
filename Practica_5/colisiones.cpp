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

void colisiones::colisionCompletamenteInelastica(particula &p1,particula &p2)
{
    float masaTotal=p1.getMasa()+p2.getMasa();
    float nuevaVx =

        (
            p1.getMasa() * p1.getVx()
            +
            p2.getMasa() * p2.getVx()
            )

        /masaTotal;
    float nuevaVy =

        (
            p1.getMasa() * p1.getVy()
            +
            p2.getMasa() * p2.getVy()
            )

        /masaTotal;
    float nuevoX =(p1.getMasa()*p1.getX()+p2.getMasa()*p2.getX()) / masaTotal;

    float nuevoY =(p1.getMasa()*p1.getY()+p2.getMasa()*p2.getY()) / masaTotal;

    p1.setMasa(masaTotal);

    p1.setVx(nuevaVx);
    p1.setVy(nuevaVy);

    p1.setX(nuevoX);
    p1.setY(nuevoY);

    // marcar p2 como eliminada
    p2.setActiva(false);
}

void colisiones::colisionObstaculo(particula &p,int x,int y,int ancho,int alto)
{
    float e=0.7;
    float px = p.getX();
    float py = p.getY();
    float r  = p.getRadio();
    if(px + r >= x && px - r <= x + ancho && py + r >= y && py - r <= y + alto)
    {
        float izquierda = std::abs((px + r) - x);
        float derecha = std::abs((x + ancho) - (px - r));
        float arriba = std::abs((py + r) - y);
        float abajo = std::abs((y + alto) - (py - r));
        float minimo = izquierda;
        int lado = 0;

        if(derecha < minimo)
        {
            minimo = derecha;
            lado = 1;
        }
        if(arriba < minimo)
        {
            minimo = arriba;
            lado = 2;
        }
        if(abajo < minimo)
        {
            lado = 3;
        }
        // izquierda
        if(lado == 0)
        {
            p.setX(x - r);

            p.setVx(-e * p.getVx());
        }
        // derecha
        else if(lado == 1)
        {
            p.setX(x + ancho + r);

            p.setVx(-e * p.getVx());
        }
        // arriba
        else if(lado == 2)
        {
            p.setY(y - r);

            p.setVy(-e * p.getVy());
        }
        // abajo
        else
        {
            p.setY(y + alto + r);

            p.setVy(-e * p.getVy());
        }

    }
}
