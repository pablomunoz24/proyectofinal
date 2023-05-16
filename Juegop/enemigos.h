#ifndef ENEMIGOS_H
#define ENEMIGOS_H


#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>

class Enemigos: public QGraphicsItem
{

    double posx; //posicion en x del enemigo.
    double posy; //posicion en y del enemigo.
    double ancho; //ancho del enemigo.
    double largo; //largo del enemigo.
    double vel;
    double velx;
    double vely;
    double g=9.8; //gravedad
    double delta=0.1; //timepo
    double pi=3.1416; //pi
    double angulo; //angulo
    int dir;
    int r; //radio para el MCU
    double Rad= 0.01745329252; //radianes
    double i=0; // variable para variar los radianes
    double W; //velocidad angular
    double velocidad_rotacion=0; //velocidad angular
    QPixmap *pixmap; //variable pixmap
    int imagen; //variable para seleccionar imagen

public:
    Enemigos();
    Enemigos(double x, double y, double ancho_, double largo_); //sobre carga deconstructor

    double getPosx(); //funcion para tomar la posicion en x.
    double getPosy(); //funcion para tomar la posicion en y.

    double getVelx(); //funcion para tomar la velocidad en x.
    double getVely(); //funcion para tomar la velocidad en y.

    void setVelx(double vx_); //funcion para dar la velocdad en x
    void setVely(double vy_); //funcion para dar la velocdad en y

    void setVel(double vel_); //funcion que da velocidad al enemigo
    double getVel(); //funcion obtener la velocidad.


    void setImagen(int imagen_); //funcion para seleccionar la imagen


    void MCU(double x, double y, int r_, double W_, double Desfase_); //movimentiento circular uniforme
    void arriba_abajo(double x, double y, int r_, double W_);         //movimiento armonico simple

    QRectF boundingRect() const; //funcion que dibuja
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //funcion que pinta
};

#endif // ENEMY_H
