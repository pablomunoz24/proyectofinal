#ifndef PIRATA_H
#define PIRATA_H


#include <qpixmap.h>
#include <QGraphicsItem>
#include <QObject> //es la clase base de todos los objetos
#include <QPainter> //realiza pintura de bajo nivel en widgets


class pirata:public QObject, public QGraphicsItem
{
    double posicio_x;
    double posicio_y;
    double alt;
    double anch;
    double velocidd=15;
    QPixmap *pixmap; //variable pixap
public:
    pirata();
    pirata(double x, double y, double ancho_, double largo_); //sobre carga del constructor
    void mov_izquierda();
    void mov_derecha();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    double getpy();
    double getpx();

        void setpx(double x);
        void setpy(double y);
        void setImagen(int i); //escoger la imagen


    private:


        void actualizr_posicion();



};

#endif // PIRATA_H
