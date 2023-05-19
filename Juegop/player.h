#ifndef PLAYER_H
#define PLAYER_H


#include <qpixmap.h>
#include <QGraphicsItem>
#include <QObject> //es la clase base de todos los objetos
#include <QPainter> //realiza pintura de bajo nivel en widgets
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QTimer> //incluir la libreria Qtimer
#include <QGraphicsScene> //incluir la libreria QgraphicsScene
#include <QList> //incluir la libreria Qlist

//jugador que representa la nave del primer nivel y tercero
class player: public QObject, public QGraphicsItem
{

public:
    player();   //constructor
    ~player();
    void mover_arriba();  //movimientos de la nave
    void mover_abajo();
    void mover_izquierda();
    void mover_derecha();

    QRectF boundingRect() const override;  //cuadro de la nave
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override; //pinta la nave

    double getposicion_x();
    double getposicion_y();


private:
    double alto;
    double ancho;
    double posicion_x;
    double posicion_y;
    void actualizar_posicion();

    double velocidad;   //velocidad de la nave
    QPixmap *imagen_personaje;   //la nave

};

#endif // PLAYER_H
