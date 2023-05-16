#include "mainwindow.h"
#include "ui_mainwindow.h"
int pun=0;//variable que tiene puntaje
int vida;//variable que tiene las vidas
int nivel=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Escape de la isla calavera"));  //le pone un titulo a la ventana

    scene= new QGraphicsScene();  //creo un objeto de tipo QGrap
    ui->graphicsView->setScene(scene); //establezco la escena
  scene->setSceneRect(0,0,970,610); // x:0 y:0 ancho:1000 alto:600
  scene->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondom.png")); //fondo del menu principal

   // corazon= new Hearts(); //creo un objeto de tipo Hearts
    //corazon->setPos(-50,0); //posicion x y pero dentro de la escena

    //puntajee= new Score();   //creo un objeto de tipo Score para el puntaje

    //jugador= new Player();   //creo un objeto de tipo player llamado jugador

    //robots_n2= new Robots();   //creo un objeto de tipo Robots llamado robots_n2

}

MainWindow::~MainWindow()
{
    delete ui;
}

