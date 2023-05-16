#include "salud.h"

salud::salud()  //constructor
{

    setPlainText(QString("corazones:")+QString::number(corazones)); //texto corazones o  las vidas
    setDefaultTextColor(Qt::red); //color de la letra rojo
    setFont(QFont("Trajan Pro",15)); //la fuente y el tamaño del texto

}

void salud::pierdevidas()
{
    corazones-=1;  //resto los corazones de vida
    setPlainText(QString("corazones:")+QString::number(corazones)); //actualizo
    if (corazones<1){
        corazones=0;
        setPlainText(QString("corazones:")+QString::number(corazones)); //actualizo
    }
}

int salud::getcorazones()
{
    return corazones;
}

void salud::setcorazones(int _corazones)
{
    corazones= _corazones;
    setPlainText(QString("corazones:")+QString::number(corazones));   //actualizar
}
