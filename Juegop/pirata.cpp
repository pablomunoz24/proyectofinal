#include "pirata.h"

pirata::pirata()
{
    anch=70;    //ancho del robots
    alt=130;     //alto del robots
    posicio_x=500;  //posicion en x inicial
    posicio_y=500;  //posicion en y inicial
    velocidd=15;           //velocidad de la nave
    im_pirata= new QPixmap(":/Imagenes para el juego/pirata.png");
    this->setPos(posicio_x, posicio_y);        //establezco la posicion en la escena
}

pirata::~pirata()
{

}

void pirata::mov_izquierda()
{
    if ((posicio_x - velocidd)>-10){
        posicio_x-=velocidd;
        actualizr_posicion();
    }
}

void pirata::mov_derecha()
{
    if ((posicio_x + velocidd)<1020){
        posicio_x+=velocidd;
        actualizr_posicion();
    }
}

QRectF pirata::boundingRect() const
{
    return QRectF(-anch/2,-alt/2,anch,alt);
}

void pirata::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-anch/2,-alt/2,*im_pirata,0,0,anch,alt);
    this->update();
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

double pirata::getpy()
{
    return posicio_y;
}

double pirata::getpx()
{
    return posicio_x;
}

void pirata::setpx(double x)
{
    posicio_x=x;
    setX(posicio_x);
}

void pirata::setpy(double y)
{
    posicio_y=y;
    setX(posicio_y);
}

void pirata::actualizr_posicion()
{
    this->setPos(posicio_x, posicio_y);
}
