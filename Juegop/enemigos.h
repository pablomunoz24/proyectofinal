#ifndef ENEMIGOS_H
#define ENEMIGOS_H


#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>

class enemigos: public QGraphicsItem
{

    double posx; //posicion en x del enemigo.
    double posy; //posicion en y del enemigo.
    double ancho; //ancho del enemigo.
    double largo; //largo del enemigo.
    double vel;
    double velx;
    double vely;
    double g=9.8; //gravedad
    double delta=0.08; //timepo
    double pi=3.1416; //pi
    double angulo; //angulo
    int dir;
    int cto;
    int r; //radio para el MCU
    double Rad= 0.0174533; //radianes
    double i; // variable para variar los radianes
    double W; //velocidad angular
    QPixmap *pixmap; //variable pixmap
    int imagen; //variable para seleccionar imagen

public:
    enemigos();
    enemigos(double x, double y, double ancho_, double largo_); //sobre carga deconstructor
    enemigos(double x, double y, double ancho_, double largo_, double vi, double ang_);

    double getPosx(); //funcion para tomar la posicion en x.
    double getPosy(); //funcion para tomar la posicion en y.

    double getVelx(); //funcion para tomar la velocidad en x.
    double getVely(); //funcion para tomar la velocidad en y.

    void setVelx(double vx_); //funcion para dar la velocdad en x
    void setVely(double vy_); //funcion para dar la velocdad en y

    void setVel(double vel_); //funcion que da velocidad al enemigo
    double getVel(); //funcion obtener la velocidad.
    void rebotepiso(); //funcion que simula rebote con el piso
    void actualizarposicion_derecha();
    void actualizarvelocidad();
    void actualizarposicion_izquierda();

    void setDir(int dir_); //funcion para cambiar la direccion.
    int getDir(); //funcion para tomar la direccion.

    void setImagen(int imagen_); //funcion para seleccionar la imagen

    void MCU(double x, double y, int r_, double W_, double Desfase_); //movimentiento circular uniforme
    void arriba_abajo(double x, double y, int r_, double W_);         //movimiento armonico simple
    void movimiento_triangular(double x, double y, int r_, double W_);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ENEMIGOS.H
