#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QGraphicsTextItem>
#include <QFont>


class puntaje: public QGraphicsTextItem
{
    int puntajee=0;
public:
    puntaje();
    void setpuntaje(int s);
    int getpuntaje();
};

#endif // SCORE_H
