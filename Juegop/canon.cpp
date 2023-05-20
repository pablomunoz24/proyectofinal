#include "canon.h"

Canon::Canon(QGraphicsItem *parent)
{
    Q_UNUSED(parent);
    setPixmap(QPixmap(":/Imagenes para el juego/bala.png"));
    timerbala= new QTimer();
    connect(timerbala,SIGNAL(timeout()),this,SLOT(movimiento())); //conectar el timer con la funcion mover de las balas
    timerbala->start(50);   //50 milisegundos
}

void Canon::movimiento()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de colisiones
    for(int i = 0, n = colliding_items.size(); i < n; ++i)//condicion que me pregunta si hubo alguna colision
    {
        if(typeid(*(colliding_items[i])) == typeid (enemigos))
        {
            scene()->removeItem(colliding_items[i]); //remueve el enemigo
            scene()->removeItem(this); //remueve la bala
            delete this; //elimina la bala
            colliding_items[i]->hide();
        }
    }
    setPos(x(),y()-20); //establezco la posicion, x() y() son funciones de qQGraphicsItems y
                        //el -20 le da la velocidad a la bala. ya en este punto dispara
    if(pos().y()<-30){ //si se sale de la escena elimine y remueva la bala

        scene()->removeItem(this);               //remuevo la bala de la scena
        delete this;                            //elimina la bala de la memoria
    }
}
