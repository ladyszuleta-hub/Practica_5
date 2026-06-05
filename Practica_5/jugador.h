#ifndef JUGADOR_H
#define JUGADOR_H

#include <QString>

class Jugador
{
private:
    QString nombre;
    int id;

public:
    Jugador();
    Jugador(QString nombre, int id);

    QString getNombre() const;
    int getId() const;

    void setNombre(QString nombre);
    void setId(int id);
};

#endif
