#ifndef JUEGO_H
#define JUEGO_H
#include <vector>

#include "jugador.h"
#include "particula.h"
#include "obstaculo.h"
#include "colisiones.h"
#include <QRect>

using namespace std;

class Juego
{
private:

    Jugador jugador1;
    Jugador jugador2;
    QRect rectJugador1;
    QRect rectJugador2;

    particula proyectil;

    vector<Obstaculo> obstaculos;

    int turno;

    bool proyectilActivo;

    float gravedad;
    int rebotes;
    int ganador;

public:

    Juego();

    void actualizar();

    void cambiarTurno();

    void disparar(float angulo,float velocidad);

    // getters

    particula& getProyectil();

    vector<Obstaculo>& getObstaculos();

    int getTurno() const;

    bool estaActivo() const;
    bool infraestructuraDestruida(int jugador);

    int getGanador() const;
    QRect getRectJugador1() const;
    QRect getRectJugador2() const;
    void verificarImpactoJugadores();
};


#endif // JUEGO_H
