#include "pirata.h"

pirata::pirata()
{

}

pirata::pirata(double x, double y, double ancho_, double largo_){
    posicio_x=x; //asignar la posicion en x ingresada.
    posicio_y=y; //asignar la posicion en y ingresada.
    anch=ancho_; //asignar el ancho del pirata.
    alt=largo_; //asignar el largo del pirata.
    this->setPos(posicio_x, posicio_y);        //establezco la posicion en la escena
}

void pirata::mov_izquierda()
{
    if ((posicio_x - velocidd)>-10){
        posicio_x-=velocidd;
        actualizr_posicion();
    }
}
void pirata::setImagen(int i)
{
    // actualizar la imagen
    if(i==0)
    {
        pixmap = new QPixmap(":/Imagenes para el juego/pirata.png");
    }
    if(i==1)
    {
        pixmap = new QPixmap(":/Imagenes para el juego/pngegg.png");
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
    painter->drawPixmap(-anch/2,-alt/2,*pixmap,0,0,anch,alt);
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
