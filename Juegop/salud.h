#ifndef SALUD_H
#define SALUD_H

#include <QGraphicsTextItem>
#include <QFont>

//clase corazones o vidas
class salud : public QGraphicsTextItem
{
    int corazones; //vidas o corazones

public:
    salud();  //constructor
    void muere(); //funcion cuando pierde vidas
    int getcorazones(); //funcion retorna la cantida de corazones
    void setcorazones(int _corazones); //funcion actualiza los corazones

};

#endif // HEARTS_H
