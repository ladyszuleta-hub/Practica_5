#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spriteJugador.load(":/recursos/personaje.png");
    spriteObstaculo.load(":/recursos/obstaculo.png");

    resize(800,600);

    jugador1 = Jugador("Jugador 1",1);

    jugador2 = Jugador("Jugador 2",2);

    turno = 1;

    proyectilActivo = false;

    gravedad = 0.2;

    obstaculos.push_back(Obstaculo(100,450,120,120,100,1));

    obstaculos.push_back(Obstaculo(300,450,120,120,100,1));

    obstaculos.push_back(Obstaculo(450,100,120,120,100,2));

    obstaculos.push_back(Obstaculo(600,100,120,120,100,2));


    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    timer->start(16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{
    if(proyectilActivo)
    {
        proyectil.setVy(
            proyectil.getVy() + gravedad);

        proyectil.mover(1);


        proyectil.verificarColisionParedes(
            width(),
            height());

        for(size_t i=0; i<obstaculos.size(); i++)
        {
            if(obstaculos[i].estaDestruido())
                continue;

            float px = proyectil.getX();
            float py = proyectil.getY();
            float r  = proyectil.getRadio();

            int ox = obstaculos[i].getX();
            int oy = obstaculos[i].getY();
            int ow = obstaculos[i].getAncho();
            int oh = obstaculos[i].getAlto();

            if(px + r >= ox &&
                px - r <= ox + ow &&
                py + r >= oy &&
                py - r <= oy + oh)
            {
                float velocidad =sqrt(proyectil.getVx()*proyectil.getVx()+proyectil.getVy()*proyectil.getVy());

                float momento =proyectil.getMasa() * velocidad;

                float danio =0.5 * momento;

                obstaculos[i].recibirDanio(danio);

                proyectilActivo = false;

                if(turno == 1)
                    turno = 2;
                else
                    turno = 1;
            }
        }
    }

    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);


    for(size_t i=0; i<obstaculos.size(); i++)
    {
        if(obstaculos[i].estaDestruido())
            continue;

        painter.drawPixmap(
            obstaculos[i].getX(),
            obstaculos[i].getY(),
            obstaculos[i].getAncho(),
            obstaculos[i].getAlto(),
            spriteObstaculo
            );
        painter.drawText(
            obstaculos[i].getX(),
            obstaculos[i].getY()-5,
            QString::number(
                (int)obstaculos[i].getResistencia()
                )
            );
    }

    painter.setPen(Qt::white);

    if(turno == 1)
    {
        painter.drawText(
            20,
            20,
            "Turno: Jugador 1");
    }
    else
    {
        painter.drawText(
            20,
            20,
            "Turno: Jugador 2");
    }
    //jugadores
    painter.drawPixmap(190, 460,120, 120, spriteJugador);
    painter.drawPixmap(540, 150,120, 120, spriteJugador);

    if(proyectilActivo)
    {
        painter.setBrush(Qt::yellow);

        painter.drawEllipse(
            proyectil.getX()
                - proyectil.getRadio(),

            proyectil.getY()
                - proyectil.getRadio(),

            proyectil.getRadio()*2,

            proyectil.getRadio()*2);
    }
}
void MainWindow::cambiarTurno()
{
    if(turno == 1)
        turno = 2;
    else
        turno = 1;
}

void MainWindow::on_btnDisparar_clicked()
{
    if(proyectilActivo)
        return;

    float angulo =
        ui->txtAngulo->text().toFloat();

    float velocidad =
        ui->txtVelocidad->text().toFloat();

    float radianes =
        angulo * M_PI / 180.0;

    if(turno == 1)
    {
        proyectil.setX(200);
        proyectil.setY(450);

        proyectil.setVx(
            velocidad * cos(radianes));

        proyectil.setVy(
            -velocidad * sin(radianes));
    }
    else
    {
        proyectil.setX(550);
        proyectil.setY(250);

        proyectil.setVx(
            -velocidad * cos(radianes));

        proyectil.setVy(
            velocidad * sin(radianes));
    }

    proyectil.setRadio(10);

    proyectilActivo = true;

}

