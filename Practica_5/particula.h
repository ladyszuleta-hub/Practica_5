#ifndef PARTICULA_H
#define PARTICULA_H

class particula
{

private:

    // Posición
    float x;
    float y;

    // Velocidad
    float vx;
    float vy;

    // Propiedades físicas
    float masa;
    float radio;

public:

    // Constructor vacío
    particula();

    // Constructor con parámetros
    particula(float x, float y,float vx, float vy,float masa, float radio);

    void mover(float dt);

    // Rebote con paredes
    void verificarColisionParedes(int anchoCaja, int altoCaja);

    // Getters
    float getX();
    float getY();

    float getVx();
    float getVy();

    float getMasa();
    float getRadio();

    // Setters
    void setX(float x);
    void setY(float y);

    void setVx(float vx);
    void setVy(float vy);

    void setMasa(float masa);
    void setRadio(float radio);
};

#endif // PARTICULA_H
