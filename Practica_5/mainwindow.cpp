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
        particulas[i].mover(1);

        // rebote paredes

        particulas[i].
            verificarColisionParedes(
                width(),
                height());

        // obstáculo inelástico

        colisiones::colisionObstaculo(
            particulas[i],
            300,
            200,
            150,
            100);

        // guardar datos

        salida
            << tiempo << " "
            << i << " "
            << particulas[i].getX() << " "
            << particulas[i].getY() << " "
            << particulas[i].getVx() << " "
            << particulas[i].getVy()
            << "\n";
    }


    // colisiones entre partículas

    for(size_t i=0;i<particulas.size();i++)
    {
        for(size_t j=i+1;
             j<particulas.size();j++)
        {
            if(colisiones::
                detectarColision(
                    particulas[i],
                    particulas[j]))
            {
                salida
                    << "COLISION "
                    << tiempo << " "
                    << i << " "
                    << j << "\n";
                colisiones::
                    colisionCompletamenteInelastica(
                        particulas[i],
                        particulas[j]);
            }
        }
    }

    archivo.close();

    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // obstáculo

    painter.setBrush(Qt::darkGray);

    painter.drawRect(
        300,
        200,
        150,
        100);

    // partículas

    painter.setBrush(Qt::blue);

    for(size_t i=0;i<particulas.size();i++)
    {
        painter.drawEllipse(
            particulas[i].getX(),

            particulas[i].getY(),

            particulas[i].getRadio()*2,

            particulas[i].getRadio()*2);
    }
}
