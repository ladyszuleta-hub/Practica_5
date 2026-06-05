#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <vector>
#include "obstaculo.h"
#include "jugador.h"
#include "particula.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    void paintEvent(QPaintEvent *event);

private slots:

    void actualizar();


    void on_btnDisparar_clicked();

private:

    Ui::MainWindow *ui;

    std::vector<Obstaculo> obstaculos;
    Jugador jugador1;
    Jugador jugador2;

    int turno;
    void cambiarTurno();

    QTimer *timer;
    float tiempo;

    particula proyectil;
    bool proyectilActivo;
    float gravedad;

    QPixmap spriteJugador;
    QPixmap spriteObstaculo;

};

#endif // MAINWINDOW_H
