#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colisiones.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile archivo("datos.txt");

    archivo.open(QIODevice::WriteOnly | QIODevice::Text);

    archivo.close();
    tiempo = 0;

    resize(800,600);

    // 4 partículas

    particulas.push_back(
        particula(100,100,4,3,1,15));

    particulas.push_back(
        particula(300,200,-3,2,1,15));

    particulas.push_back(
        particula(500,300,2,-4,1,15));

    particulas.push_back(
        particula(200,400,-2,-3,1,15));

    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),
            this,SLOT(actualizar()));

    timer->start(16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{
    QFile archivo("datos.txt");


    archivo.open(QIODevice::Append |
                 QIODevice::Text);

    QTextStream salida(&archivo);
    //salida<<"tiempo id x y vx vy"<<"\n";

    // mover partículas

    for(size_t i=0;i<particulas.size();i++)
    {
        if(!particulas[i].getActiva())
            continue;
        particulas[i].mover(1);

        // rebote paredes

        particulas[i].
            verificarColisionParedes(
                width(),
                height());

        // obstáculo inelástico

        // obstáculo 1
        colisiones::colisionObstaculo(particulas[i],10,30,80,80);

        // obstáculo 2
        colisiones::colisionObstaculo(particulas[i],300,300,100,100);

        // obstáculo 3
        colisiones::colisionObstaculo( particulas[i],500,120,50,50);

        // obstáculo 4
        colisiones::colisionObstaculo(particulas[i],400,200,60,60);

        // guardar datos

        salida
            << tiempo << " "
            << i << " "
            << particulas[i].getX() << " "
            << particulas[i].getY() << " "
            << particulas[i].getVx() << " "
            << particulas[i].getVy()
            << "\n";
        for(size_t j=i+1;j<particulas.size();j++)
        {
            if(!particulas[j].getActiva())
                continue;
            if(colisiones::
                detectarColision(particulas[i],particulas[j]))
            {

                colisiones::
                    colisionCompletamenteInelastica(
                        particulas[i],
                        particulas[j]);
            }
        }

    }tiempo += 0.1;

    archivo.close();

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // obstáculo

    painter.setBrush(Qt::darkGray);

    painter.drawRect(10,30,80,80);

    painter.drawRect(300,300,100,100);

    painter.drawRect(500,120,50,50);

    painter.drawRect(400,200,60,60);

    // partículas

    painter.setBrush(Qt::blue);

    for(size_t i=0;i<particulas.size();i++)
    {
        if(!particulas[i].getActiva())
            continue;
        painter.drawEllipse(
            particulas[i].getX()- particulas[i].getRadio(),

            particulas[i].getY()- particulas[i].getRadio(),

            particulas[i].getRadio()*2,

            particulas[i].getRadio()*2);
    }
}
