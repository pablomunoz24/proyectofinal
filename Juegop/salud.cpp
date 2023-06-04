#include "salud.h"

Salud::Salud()  //constructor
{

    setPlainText(QString::number(corazones)); //texto corazones o  las vidas
    setDefaultTextColor(Qt::red); //color de la letra rojo
    setFont(QFont("Trajan Pro",15)); //la fuente y el tamaño del texto

}

void Salud::muere()
{
    corazones-=1;  //resto los corazones de vida
    setPlainText(QString::number(corazones)); //actualizo
    if (corazones<1){
        corazones=0;
        setPlainText(QString::number(corazones)); //actualizo
    }
}

int Salud::getcorazones()
{
    return corazones;
}

void Salud::setcorazones(int _corazones)
{
    corazones= _corazones;
    setPlainText(QString::number(corazones));   //actualizar
}
