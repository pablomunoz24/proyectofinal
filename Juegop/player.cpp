#include "player.h"


player::player()              //ancho:100 alto:100 de la nave  posicion x:500  y:570 de la nave osea abajo en la mitad
{                                        //constructor inicializado por defecto
    this->ancho=100;
    this->alto=100;
    this->posicion_x=500;
    this->posicion_y=570;
    this->velocidad=20;           //velocidad de la nave
    imagen_personaje= new QPixmap(":/Imagenes para el juego/barco.png");
    this->setPos(this->posicion_x, this->posicion_y);        //establezco la posicion en la escena
}

player::~player()
{

}


void player::mover_arriba()  //nave se mueve hacia arriba
{
    if ((this->posicion_y - this->velocidad)>30){ //si supera el cero en y no se mueve
        this->posicion_y-=this->velocidad;   //hacia arriba en ye es negativo
        this->actualizar_posicion();     //actualiza la posicion
    }
  }

void player::mover_abajo()
{
    if ((this->posicion_y + this->velocidad)<580){ //si supera los 600 no se mueve en altura
        this->posicion_y+=this->velocidad;
        this->actualizar_posicion();
    }
}

void player::mover_izquierda()
{
    if ((this->posicion_x - this->velocidad)>-30){
        this->posicion_x-=this->velocidad;
        this->actualizar_posicion();
    }
}

void player::mover_derecha()
{
    if ((this->posicion_x + this->velocidad)<1030){
        this->posicion_x+=this->velocidad;
        this->actualizar_posicion();
    }
}

QRectF player::boundingRect() const  //crea el cuadro de la nave
{
    return QRectF(-this->ancho/2,-this->alto/2,this->ancho,this->alto);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-this->ancho/2,-this->alto/2,*imagen_personaje,0,0,this->ancho,this->alto); //pinta la nave y da la imagen
    this->update();                               //llama la funcion actualizar
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

double player::getposicion_x()
{
    return posicion_x;
}

double player::getposicion_y()
{
    return posicion_y;
}

void player::actualizar_posicion()
{
    this->setPos(this->posicion_x, this->posicion_y);
}
