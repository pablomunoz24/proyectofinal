#include "puntaje.h"

puntaje::puntaje()
{
    setPlainText(QString("puntaje: ")+QString::number(puntajee)); //establezco en pantalla
    setDefaultTextColor(Qt::white); //pinto
    setFont(QFont("Trajan Pro",18)); //fuente y tamaño
}

void puntaje::puntaje(int s)
{
  //  puntaje=s;
    //setPlainText(QString("Score: ")+QString::number(puntajee));
}

int puntaje::getpuntaje()
{
    return puntaje;
}
