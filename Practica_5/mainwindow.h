#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <vector>
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


private:

    Ui::MainWindow *ui;

    QTimer *timer;
    float tiempo;

    std::vector<particula> particulas;
};

#endif // MAINWINDOW_H
