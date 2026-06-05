#include "juego.h"
#include <cmath>

Juego::Juego()
{
    jugador1 = Jugador("Jugador 1",1);

    jugador2 = Jugador("Jugador 2",2);
    rectJugador1 = QRect(440,460,40,51);
    rectJugador2 = QRect(940,460,40,51);

    turno = 1;
    rebotes = 0;
    ganador = 0;

    proyectilActivo = false;

    gravedad = 0.98;

    obstaculos.push_back(
        Obstaculo(310,460,120,37,100,1));

    obstaculos.push_back(
        Obstaculo(490,460,120,37,100,1));
    obstaculos.push_back(
        Obstaculo(400,400,120,37,100,1));

    obstaculos.push_back(
        Obstaculo(810,460,120,37,100,2));

    obstaculos.push_back(
        Obstaculo(990,460,120,37,100,2));
    obstaculos.push_back(
        Obstaculo(900,400,120,37,100,2));

}
void Juego::disparar(float angulo, float velocidad)
{
    rebotes = 0;
    if(proyectilActivo)
        return;

    float radianes =
        angulo * M_PI / 180.0;

    if(turno == 1)
    {
        proyectil.setX(460);
        proyectil.setY(395);

        proyectil.setVx(
            velocidad*cos(radianes));

        proyectil.setVy(
            -velocidad*sin(radianes));
    }
    else
    {
        proyectil.setX(960);
        proyectil.setY(395);

        proyectil.setVx(
            -velocidad*cos(radianes));

        proyectil.setVy(
            -velocidad*sin(radianes));
    }

    proyectil.setRadio(10);

    proyectilActivo = true;
}
void Juego::cambiarTurno()
{
    if(turno == 1)
        turno = 2;
    else
        turno = 1;
}
void Juego::actualizar()
{
    if(!proyectilActivo)
        return;

    proyectil.setVy(
        proyectil.getVy() + gravedad);

    proyectil.mover(1);
    verificarImpactoJugadores();

    if(proyectil.verificarColisionParedes(220,1200,0,600)){rebotes++;}

    for(size_t i=0;i<obstaculos.size();i++)
    {
        if(obstaculos[i].estaDestruido())
            continue;

        float px = proyectil.getX();
        float py = proyectil.getY();
        float r = proyectil.getRadio();

        int ox = obstaculos[i].getX();
        int oy = obstaculos[i].getY();

        int ow = obstaculos[i].getAncho();
        int oh = obstaculos[i].getAlto();

        if(px+r >= ox &&
            px-r <= ox+ow &&
            py+r >= oy &&
            py-r <= oy+oh)
        {
            float velocidad =
                sqrt(
                    proyectil.getVx()*proyectil.getVx()
                    +
                    proyectil.getVy()*proyectil.getVy()
                    );

            float momento =
                proyectil.getMasa()
                *
                velocidad;

            float danio =
                0.5 * momento;

            obstaculos[i].recibirDanio(
                danio);

            colisiones::colisionObstaculo(proyectil,ox,oy,ow,oh);
            rebotes++;
            if(rebotes >= 8)
            {
                proyectilActivo = false;

                cambiarTurno();
            }
        }
    }

}
bool Juego::infraestructuraDestruida(int jugador)
{
    for(size_t i=0; i<obstaculos.size(); i++)
    {
        if(obstaculos[i].getJugador() == jugador &&
            !obstaculos[i].estaDestruido())
        {
            return false;
        }
    }

    return true;
}
void Juego::verificarImpactoJugadores()
{
    QRect proyectilRect(
        proyectil.getX() - proyectil.getRadio(),
        proyectil.getY() - proyectil.getRadio(),
        proyectil.getRadio()*2,
        proyectil.getRadio()*2
        );

    if(turno == 1)
    {
        if(infraestructuraDestruida(2))
        {
            if(proyectilRect.intersects(rectJugador2))
            {
                ganador = 1;
                proyectilActivo = false;
            }
        }
    }
    else
    {
        if(infraestructuraDestruida(1))
        {
            if(proyectilRect.intersects(rectJugador1))
            {
                ganador = 2;
                proyectilActivo = false;
            }
        }
    }
}

int Juego::getGanador() const
{
    return ganador;
}
particula& Juego::getProyectil()
{
    return proyectil;
}

vector<Obstaculo>& Juego::getObstaculos()
{
    return obstaculos;
}

int Juego::getTurno() const
{
    return turno;
}

bool Juego::estaActivo() const
{
    return proyectilActivo;
}
QRect Juego::getRectJugador1() const
{
    return rectJugador1;
}

QRect Juego::getRectJugador2() const
{
    return rectJugador2;
}
