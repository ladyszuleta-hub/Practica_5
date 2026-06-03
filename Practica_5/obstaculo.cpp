#include "obstaculo.h"

Obstaculo::Obstaculo() : x(0), y(0), ancho(80), alto(40),resistencia(100.0f), jugadorDuenio(1)
{}

Obstaculo::Obstaculo(int x, int y, int ancho, int alto,float resistencia, int jugadorDuenio): x(x), y(y), ancho(ancho), alto(alto),
    resistencia(resistencia), jugadorDuenio(jugadorDuenio)
{}

int   Obstaculo::getX() const{
    return x; }
int   Obstaculo::getY() const {
    return y; }
int   Obstaculo::getAncho() const {
    return ancho; }
int   Obstaculo::getAlto() const {
    return alto; }
float Obstaculo::getResistencia() const {
    return resistencia; }
int   Obstaculo::getJugador() const {
    return jugadorDuenio; }
bool  Obstaculo::estaDestruido() const {
    return resistencia <= 0.0f; }

void Obstaculo::recibirDanio(float danio)
{
    resistencia -= danio;
    if (resistencia < 0.0f)
        resistencia = 0.0f;
}
