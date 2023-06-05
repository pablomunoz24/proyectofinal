#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMediaPlayer>
#include "salud.h"
#include "puntaje.h"
#include "pirata.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>
#include <iostream>
#include "canon.h"
#include "enemigos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    Salud *corazon;  //establezco la vida
    puntaje *puntajee;   //establezco el puntaje
    QTimer *colision_1;
    QTimer *definir_n1= new QTimer();

    void keyPressEvent(QKeyEvent *evento);
     bool juego;
    enemigos *enemigo1;
    enemigos *enemigo2;
    enemigos *enemigo3;
    enemigos *enemigo4;
    enemigos *enemigo5;
    enemigos *enemigos6;
    enemigos *enemigos7;
    enemigos *enemigo8;
    enemigos *enemigo9;
    enemigos *enemigo10;

    QList<enemigos*> listaenemigos_n2;
    QTimer *timerenemigo_n2;//timer de los enemigos nivel 2
    QTimer *timerenemigo_n1;
    QTimer *timerenemigo_n3;
    //entorno
    pirata *piso; // piso
    pirata *muroderecho; //muro derecho
    pirata *muroizquierdo; //muro izquierdo

    QGraphicsScene *scene;
    pirata *coraim;
    pirata *nave;
    pirata *piratag;
    Canon *bala;
    QMediaPlayer *musica;


    void menuprincipal();
    void escenario1();
    void escenario2();
    void escenario3();
    void update_score(int s);
    void victoria();
private slots:
    void on_play_clicked();   //boton jugar
    void on_salir_clicked();   //boton salir

    void inicializarjuego();



    void movimiento_enemigos_n2();
    void movimiento_enemigos_n1();
     void movimiento_enemigos_n3();

    void colision2(enemigos* bol);

    void definir_nivel1();

};

#endif // MAINWINDOW_H
