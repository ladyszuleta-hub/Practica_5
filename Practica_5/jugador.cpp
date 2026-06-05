#include "jugador.h"

Jugador::Jugador()
{
    nombre = "Jugador";
    id = 0;
}

Jugador::Jugador(QString nombre, int id)
{
    this->nombre = nombre;
    this->id = id;
}

QString Jugador::getNombre() const
{
    return nombre;
}

int Jugador::getId() const
{
    return id;
}

void Jugador::setNombre(QString nombre)
{
    this->nombre = nombre;
}

void Jugador::setId(int id)
{
    this->id = id;
}
