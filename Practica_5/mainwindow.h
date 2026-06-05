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
#include "juego.h"

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
    Juego juego;

    //std::vector<Obstaculo> obstaculos;

    QTimer *timer;
    float tiempo;

    QPixmap spriteJugador;
    QPixmap spriteObstaculo;


};

#endif // MAINWINDOW_H
