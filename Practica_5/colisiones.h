#ifndef COLISIONES_H
#define COLISIONES_H

#include "particula.h"

class colisiones
{
public:

    static bool detectarColision(
        particula &p1,
        particula &p2);

    static void colisionCompletamenteInelastica(
        particula &p1,
        particula &p2);

    static void colisionObstaculo(
        particula &p,
        int x,
        int y,
        int ancho,
        int alto);
};

#endif // COLISIONES_H
