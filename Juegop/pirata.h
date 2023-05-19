#ifndef PIRATA_H
#define PIRATA_H


#include <qpixmap.h>
#include <QGraphicsItem>
#include <QObject> //es la clase base de todos los objetos
#include <QPainter> //realiza pintura de bajo nivel en widgets


class pirata:public QObject, public QGraphicsItem
{
public:
    pirata();
    ~pirata();
    void mov_izquierda();
    void mov_derecha();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    double getpy();
    double getpx();

        void setpx(double x);
        void setpy(double y);

    private:
        double posicio_x;
        double posicio_y;
        double alt;
        double anch;

        void actualizr_posicion();

        double velocidd;   //velocidad del robots
        QPixmap *im_pirata;   //robot

};

#endif // PIRATA_H
