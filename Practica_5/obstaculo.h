#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QString>

class Obstaculo
{
public:
    Obstaculo();Obstaculo(int x, int y, int ancho, int alto,float resistencia, int jugadorDuenio);

    // Getters
    int   getX()           const;
    int   getY()           const;
    int   getAncho()       const;
    int   getAlto()        const;
    float getResistencia() const;
    int   getJugador()     const;
    bool  estaDestruido()  const;

    // Recibir daño
    void recibirDanio(float danio);

private:
    int   x, y;
    int   ancho, alto;
    float resistencia;
    int   jugadorDuenio;   // 1 o 2 → a quién pertenece
};

#endif // OBSTACULO_H
