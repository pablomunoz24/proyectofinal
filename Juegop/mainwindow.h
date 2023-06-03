#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "salud.h"
#include "puntaje.h"
#include "pirata.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <player.h>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>
#include <iostream>
#include <canon.h>
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
    void keyPressEvent(QKeyEvent *evento);

    QGraphicsScene *scene;
    player *jugador;       //nave  terceer nivel
    pirata *piratag;       //robots del primer y segundo
    Canon *bala;           //bala
    QMessageBox msgbox;   //caja de mensajes

    void menuprincipal();
    void escenario1();
    void escenario2();
    void escenario3();

    QTimer *definir_n1= new QTimer();
private:
    Ui::MainWindow *ui;

    Salud *corazon;  //establezco la vida
    puntaje *puntajee;   //establezco el puntaje
    QTimer *colision_1;

     bool juego;
    enemigos *enemigo1; //enemigos del nivel 2
    enemigos *enemigo2;
    enemigos *enemigo3;
    enemigos *enemigo4;
    enemigos *enemigo5;
    enemigos *enemigos6;
    enemigos *enemigos7;

    QList<enemigos*> listaenemigos_n2; //lista de enemigos nivel 2
    QTimer *timerenemigo_n2;//timer de los enemigos nivel 2
    QTimer *timerenemigo_n1;
    QTimer *timerenemigo_n3;
    //entorno
    pirata *piso; // piso
    pirata *muroderecho; //muro derecho
    pirata *muroizquierdo; //muro izquierdo

    void update_score(int s);
    void victoria();
private slots:
    void on_play_clicked();   //boton jugar
    void on_salir_clicked();   //boton salir

    void inicializarjuego();



    void movimiento_enemigos_n2();      //movimiento de los enegimos nivel 2
    void movimiento_enemigos_n1();
     void movimiento_enemigos_n3();

    void colision2(enemigos* bol);  //colision enemigos nivel 2

    void definir_nivel1();

};

#endif // MAINWINDOW_H
