#ifndef CANON_H
#define CANON_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QDebug>
#include <enemy.h>
#include <score.h>



class Canon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Canon(QGraphicsItem *parent = 0);
    QTimer * timerbala;

public slots:
    void movimiento();
};

#endif // BULLETS_H
