#include "enemigos.h"
Enemigos::Enemigos()
{

}

Enemigos::Enemigos(double x, double y, double ancho_, double largo_)
{
    largo=largo_; //tomar el largo
    ancho=ancho_; //tomar el ancho
    posx = x; //tomar la posicion inicial en x
    posy = y; //tomar la posicion inicial en y
    setPos(posx,-posy); //dar posicion en x y en y
}

double Enemigos::getPosx()
{
    return posx; //retorna la posicion en x.
}

double Enemigos::getPosy()
{
    return posy; //retorna la posicion en y.
}

double Enemy::getVelx()
{
    return velx; //retorna la velocdiad en x
}

double Enemy::getVely()
{
    return vely; //retorna la velocidad en y
}

void Enemigos::setVelx(double vx_)
{
    velx=vx_;
}

void Enemigos::setVely(double vy_)
{
    vely=vy_;
}

void Enemigos::setVel(double vel_)
{
    vel=vel_; //darle un valor a la velocidad
}

double Enemigos::getVel()
{
    return vel; //retorna la velocidad
}

void Enemigos::setImagen(int imagen_)
{
    if(imagen_==1)
    {
        pixmap = new QPixmap(":/multimedia/fantasma.png");
    }
    if(imagen_==2)
    {
        pixmap = new QPixmap(":/multimedia/fantasma2.png");
    }

}

void Enemigos::MCU(double x, double y, int r_, double W_, double Desfase_)
{
    W = W_; //velocidad angular
    r=r_; //radio de giro
    i=i+Rad; //angulo de giro
    posx =x+r*cos(i*W+Desfase_); //posicion en x
    posy =y+r*sin(i*W); //posicion en y
    setPos(posx,posy); //dar posicion en x y y
}

void Enemigos::arriba_abajo(double x, double y, int r_, double W_)
{
    W = W_; //velocidad angular
    r=r_; //radio de giro
    i=i+Rad; //angulo de giro
    posx =x; //posicion en x
    posy =y+r*cos(i*W); //posicion en y, movimimient pendular
    setPos(posx,posy); //dar posicion en x y y
}


QRectF Enemigos::boundingRect() const
{
    return QRectF(-ancho/2,-largo/2,ancho,largo); //retorna un rectangulo
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-largo/2,*pixmap,0,0,ancho,largo);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
