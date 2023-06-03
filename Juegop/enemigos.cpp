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
enemigos::enemigos(double x, double y, double ancho_, double largo_, double vi, double ang_)
{
    largo=largo_; //tomar el largo
    ancho=ancho_; //tomar el ancho
    posx = x; //tomar la posicion inicial enx
    posy = y; //tomar la posicion inicial en y
    vel = vi; //tomar la velocidad inicial
    angulo=(ang_/180)*pi; //tomar el angulo inicial
    setPos(posx,-posy); //dar posicion en x y en y
    dir=1;
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
    if(imagen_==3){
        pixmap = new QPixmap(":/Imagenes para el juego/rana.png");
    }

}
void enemigos::actualizarposicion_derecha()
{
    posx=posx+velx*delta; //x=x0+Vx*T
    posy=posy+vely*delta-(0.5*g*delta*delta); //y=y0+Vy*t-(9.8/2)*t^2
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
    posx =x; //posicion en
    posy =y+r*cos(i*W); //posicion en y, movimimient pendular
    setPos(posx,posy); //dar posicion en x y y

}
void enemigos::movimiento_triangular(double x, double y, int r_, double W_)
{
    W = W_; //velocidad angular
    r=r_; //radio de giro
    i=i+Rad; //angulo de giro
    posx =x+r*cos(i*W); //posicion en
    posy =y+r*cos(i*W); //posicion en y, movimimient
    setPos(posx,posy); //dar posicion en x y y
}
void enemigos::rebotepiso()
{
    velx=vel*cos(angulo); //vx=v*cos(angulo)
    vely=-vel*sin(angulo)+g*delta; //vy=v*sin(angulo)-g*T
    angulo=atan2(vely,velx); //angulo = arctan(vy/vx)
    vel=vel+sqrt(velx*velx+vely*vely); //v=(vx^2+vy^2)^1/2
    posx=posx+velx*delta; //x=x0+Vx*T
    posy=posy+vely*delta+(0.5*g*delta*delta); //y=y0+Vy*t-(9.8/2)*t^2
}
void enemigos::actualizarvelocidad()
{
    velx=vel*cos(angulo); //vx=v*cos(angulo)
    vely=vel*sin(angulo)-g*delta; //vy=v*sin(angulo)-g*T
    angulo=atan2(vely,velx); //angulo = arctan(vy/vx)
    vel=sqrt(velx*velx+vely*vely); //v=(vx^2+vy^2)^1/2
}
void enemigos::actualizarposicion_izquierda()
{
    posx=posx-velx*delta; //x=x0+Vx*T
    posy=posy+vely*delta-(0.5*g*delta*delta); //y=y0+Vy*t-(9.8/2)*t^2
}

void enemigos::setDir(int dir_)
{
    dir=dir_; //dar la dirrecion
}

int enemigos::getDir()
{
    return dir; //retornar la direccion
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
