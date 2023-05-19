#include "enemigos.h"

enemigos::enemigos()
{

}

enemigos::enemigos(double x, double y, double ancho_, double largo_)
{
    largo=largo_; //tomar el largo
    ancho=ancho_; //tomar el ancho
    posx = x; //tomar la posicion inicial en x
    posy = y; //tomar la posicion inicial en y
    setPos(posx,-posy); //dar posicion en x y en y
}

double enemigos::getPosx()
{
    return posx; //retorna la posicion en x.
}

double enemigos::getPosy()
{
    return posy; //retorna la posicion en y.
}

double enemigos::getVelx()
{
    return velx; //retorna la velocdiad en x
}

double enemigos::getVely()
{
    return vely; //retorna la velocidad en y
}

void enemigos::setVelx(double vx_)
{
    velx=vx_;
}

void enemigos::setVely(double vy_)
{
    vely=vy_;
}

void enemigos::setVel(double vel_)
{
    vel=vel_; //darle un valor a la velocidad
}

double enemigos::getVel()
{
    return vel; //retorna la velocidad
}

void enemigos::setImagen(int imagen_)
{
    if(imagen_==1)
    {
        pixmap = new QPixmap(":/Imagenes para el juego/images.png");
    }
    if(imagen_==2)
    {
        pixmap = new QPixmap(":/Imagenes para el juego/images.png");
    }

}

void enemigos::MCU(double x, double y, int r_, double W_, double Desfase_)
{
    W = W_; //velocidad angular
    r=r_; //radio de giro
    i=i+Rad; //angulo de giro
    posx =x+r*cos(i*W+Desfase_); //posicion en x
    posy =y+r*sin(i*W); //posicion en y
    setPos(posx,posy); //dar posicion en x y y
}

void enemigos::arriba_abajo(double x, double y, int r_, double W_)
{
    W = W_; //velocidad angular
    r=r_; //radio de giro
    i=i+Rad; //angulo de giro
    posx =x; //posicion en x
    posy =y+r*cos(i*W); //posicion en y, movimimient pendular
    setPos(posx,posy); //dar posicion en x y y
}


QRectF enemigos::boundingRect() const
{
    return QRectF(-ancho/2,-largo/2,ancho,largo); //retorna un rectangulo
}

void enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-largo/2,*pixmap,0,0,ancho,largo);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
