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

    resize(1200,600);

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
    juego.actualizar();

    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setPen(Qt::white);

    // área de juego
    painter.drawRect(220,0,980,600);

    // referencia a los obstáculos del juego
    vector<Obstaculo>& obstaculos =juego.getObstaculos();

    for(size_t i=0; i<obstaculos.size(); i++)
    {
        if(obstaculos[i].estaDestruido())
            continue;

        painter.drawPixmap(obstaculos[i].getX(),obstaculos[i].getY(),
                           obstaculos[i].getAncho(),obstaculos[i].getAlto(),spriteObstaculo);

        painter.drawText(
            obstaculos[i].getX(),obstaculos[i].getY()-5,
            QString::number((int)obstaculos[i].getResistencia()));
    }

    // turno actual
    if(juego.getTurno() == 1)
    {
        painter.drawText(30,30,"Turno: Jugador 1");
    }
    else
    {
        painter.drawText(30,30,"Turno: Jugador 2");
    }

    // jugadores
    QRect j1 = juego.getRectJugador1();

    painter.drawPixmap(j1,spriteJugador);

    QRect j2 = juego.getRectJugador2();

    painter.drawPixmap(j2,spriteJugador);

    // proyectil
    if(juego.estaActivo())
    {
        particula& proyectil =
            juego.getProyectil();

        painter.setBrush(Qt::yellow);

        painter.drawEllipse(
            proyectil.getX() - proyectil.getRadio(),
            proyectil.getY() - proyectil.getRadio(),
            proyectil.getRadio()*2,
            proyectil.getRadio()*2
            );
    }
    if(juego.getGanador() != 0)
    {
        painter.setPen(Qt::red);

        painter.setFont(
            QFont("Arial",24,QFont::Bold));

        painter.drawText(
            rect(),
            Qt::AlignCenter,
            QString("GANA EL JUGADOR %1")
                .arg(juego.getGanador())
            );
    }
}


void MainWindow::on_btnDisparar_clicked()
{
    float angulo =ui->txtAngulo->text().toFloat();

    float velocidad =ui->txtVelocidad->text().toFloat();

    juego.disparar(angulo,velocidad);

}

