#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "puntaje.h"
#include "salud.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "salud.h"
#include <QMessageBox>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <iostream>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QGraphicsScene *scene;

private:
    Ui::MainWindow *ui;
    puntaje *puntajee;   //establezco el puntaje
    salud *corazon;  //establezco la vida
   //Player *jugador;       //nave  terceer nivel
    //Robots *robots_n2;       //robots del primer y segundo
    //Bullets *bala;           //bala
    QMessageBox msgbox;   //caja de mensajes
};
#endif // MAINWINDOW_H
