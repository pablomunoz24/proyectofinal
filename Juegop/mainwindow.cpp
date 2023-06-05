#include "mainwindow.h"
#include "canon.h"
#include "ui_mainwindow.h"
int punt=0;//variable que tiene puntaje
int vidas;//variable que tiene las vidas
int nivel=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Escape de la isla calavera"));  //le pone un titulo a la ventana

    scene= new QGraphicsScene();  //creo un objeto de tipo QGrap
    ui->graphicsView->setScene(scene); //establezco la escena
  scene->setSceneRect(0,0,990,640);
  scene->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondom.png")); //fondo del menu principal
  coraim=new pirata(28,36,50,50);
  coraim->setImagen(4);
  corazon= new Salud(); //creo un objeto de tipo Hearts
   corazon->setPos(53,16); //posicion x y pero dentro de la escena

   puntajee= new puntaje();   //creo un objeto de tipo Score para el puntaje

   piratag= new pirata(500,500,112,155);   //creo un objeto llamado piratag
   piratag->setImagen(0);

   nave=new pirata(10,500,248,165);
   nave->setImagen(3);

   piso = new pirata(500,575,1000,50); //creo el piso
   piso->setImagen(2);
   muroderecho = new pirata(1025,350,50,800); //creo el muro derecho
   muroizquierdo = new pirata(-25,350,50,800); //creo el muro izquierdo

   timerenemigo_n2= new QTimer;
   timerenemigo_n1 = new QTimer;
   timerenemigo_n3= new QTimer;

   musica=new QMediaPlayer;

   menuprincipal();   //llamo la funcion menuprincipal
 }

 MainWindow::~MainWindow()
 {
   delete ui;
 }

 void MainWindow::keyPressEvent(QKeyEvent *evento)  //al presionar el teclado
 {
   if(evento->key()==Qt::Key_W){
       this->nave->mov_arriba();
   }

   if(evento->key()==Qt::Key_S){
       this->nave->mov_abajo();
   }

   if(evento->key()==Qt::Key_D){
       if(nivel==3){
       this->nave->mov_derecha();
       }
       if(nivel==1 or nivel==2){
       piratag->setImagen(0);
       this->piratag->mov_derecha();
       }
   }

   if(evento->key()==Qt::Key_A){
       if(nivel==3){
       this->nave->mov_izquierda();
       }
       if(nivel==1 or nivel==2){
        piratag->setImagen(1);
       this->piratag->mov_izquierda();
       }
   }

   if(evento->key()==Qt::Key_Space){
       bala=new Canon();                       //creo un objeto de tipo canon
       if(piratag->getImagen()==0){
       bala->setPos(piratag->getpx()+50, piratag->getpy()-85);
       scene->addItem(bala);                    //agregre la bala a la escen
       }
       if(piratag->getImagen()==1){
           bala->setPos(piratag->getpx()-50, piratag->getpy()-85);
           scene->addItem(bala);                    //agregre la bala a la escen

       }
       if(nivel==3){
           bala->setPos(nave->getpx()-20,nave->getpy()-85);
       }
       if(puntajee->getpuntaje()==100 || corazon->getcorazones()==0){
           bala->hide();
       }

   }
  }
 void MainWindow::menuprincipal()
 {
      juego=false;

      ui->play->show();
      ui->salir->show();
      timerenemigo_n2->stop();
      timerenemigo_n1->stop();
      musica->setMedia(QUrl("qrc:/n/Musica para el juego/y2mate.com - Gangplank Galleon Restored to HD.mp3"));
      musica->play();

 }
 void MainWindow::escenario1()
 {
     ui->play->hide(); //oculto el boton jugar
     ui->salir->hide();  //oculto el boton sali
     nivel=1;
     vidas=3;
     juego=true;
     scene->addItem(piso);
     corazon->setcorazones(vidas);
     scene->addItem(corazon);      //le agrego la salud o vida o corazones a la escena
     scene->addItem(coraim);
     ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondo1.jpg"));
     puntajee->setPos(850,0);
     scene->addItem(puntajee);           //añado el puntaje en la escena

     scene->addItem(piratag);  //lo agrego a la escena



      corazon->setcorazones(3);

     enemigo1 = new enemigos(150,-500,105,94);
     enemigo1->setImagen(1);                    //selecionar imagen
     listaenemigos_n2.push_back(enemigo1); //agrego enemigo 1 a la lista
     scene->addItem(listaenemigos_n2.at(0)); //añado enemigo 1 a la escena

     enemigo2 = new enemigos(850,-500,105,94); //creo enemigo 2
     enemigo2->setImagen(2);
     listaenemigos_n2.push_back(enemigo2);
     scene->addItem(listaenemigos_n2.at(1));

     enemigo3 = new enemigos(500,-350,105,94); //creo enemigo 3
     enemigo3->setImagen(1);
     listaenemigos_n2.push_back(enemigo3);
     scene->addItem(listaenemigos_n2.at(2));

     enemigo4 = new enemigos(750,-350,105,94); //creo enemigo 4
     enemigo4->setImagen(2);
     listaenemigos_n2.push_back(enemigo4);
     scene->addItem(listaenemigos_n2.at(3));

     connect(timerenemigo_n2,SIGNAL(timeout()),this,SLOT(movimiento_enemigos_n1()));
     timerenemigo_n2->start(10);
     connect(definir_n1,SIGNAL(timeout()),this,SLOT(definir_nivel1()));
     definir_n1->start(50);

 }
 void MainWindow::escenario2()
 {
     ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondo2.jpg"));
     puntajee->setpuntaje(40); //actualizar puntaje
     nivel=2;


     timerenemigo_n2->stop();
     scene->addItem(piso);

     listaenemigos_n2.clear();

     if(!piratag->isActive())
     {
         scene->addItem(piratag);
     }
     piratag->setpx(10); //actualizar posicion


     if(!corazon->isActive())
     {
         scene->addItem(corazon);
     }

     if(!puntajee->isActive())
     {
         scene->addItem(puntajee);
     }


     //fuerzaaerea 6
     enemigo5 = new enemigos(25,-150,70,51,10,90);
     enemigo5->setImagen(3);
     listaenemigos_n2.push_back(enemigo5); //
     scene->addItem(listaenemigos_n2.at(0));

     //fuerzaaerea 7
     enemigos6 = new enemigos(975,-150,70,51,10,90);
     enemigos6->setImagen(3); //seleccionar la imagen
     listaenemigos_n2.push_back(enemigos6);
     scene->addItem(listaenemigos_n2.at(1));

     //fuerzaaerea 8
     enemigos7 = new enemigos(250,-350,70,51,10,90);
     enemigos7->setImagen(3); //selecionar imagen
     listaenemigos_n2.push_back(enemigos7);
     scene->addItem(listaenemigos_n2.at(2));



     connect(timerenemigo_n1,SIGNAL(timeout()),this,SLOT(movimiento_enemigos_n2())); //conecto
     timerenemigo_n1->start(10);
     connect(definir_n1,SIGNAL(timeout()),this,SLOT(definir_nivel1()));
     definir_n1->start(50);




     update_score(40); //



 }
 void MainWindow::escenario3()
 {
     ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/mar.png"));
     puntajee->setpuntaje(70); //actualizar puntaje
     nivel=3;
     timerenemigo_n1->stop();
     piratag->hide();
     piso->hide();
     scene->addItem(nave);
     listaenemigos_n2.clear();
     if(!corazon->isActive()) //condicion que pregunta si vidas ya esta en escena
     {
         scene->addItem(corazon);
     }

     if(!puntajee->isActive()) //condicion que pregunta si los puntos ya estan en escena
     {
         scene->addItem(puntajee);
     }

     enemigo8 = new enemigos(150,-500,105,105);
     enemigo8->setImagen(4);                    //selecionar imagen
     listaenemigos_n2.push_back(enemigo8);
     scene->addItem(listaenemigos_n2.at(0));

     enemigo9 = new enemigos(850,-500,105,105);
     enemigo9->setImagen(4);
     listaenemigos_n2.push_back(enemigo9);
     scene->addItem(listaenemigos_n2.at(1));

     enemigo10 = new enemigos(500,-350,105,105);
     enemigo10->setImagen(4);
     listaenemigos_n2.push_back(enemigo10);
     scene->addItem(listaenemigos_n2.at(2));


     connect(timerenemigo_n3,SIGNAL(timeout()),this,SLOT(movimiento_enemigos_n3()));
     timerenemigo_n3->start(10);
     connect(definir_n1,SIGNAL(timeout()),this,SLOT(definir_nivel1()));
     definir_n1->start(50);


 }

 void MainWindow::update_score(int s)
 {
     for(int i=0;i<listaenemigos_n2.size();i++) //recorre la lista de los enemigos
     {
         if(!listaenemigos_n2.at(i)->isVisible()) //condicion que pregunta si el enemigos no es visible
         {
             s=s+10; // 10 puntos vale cada enemigo
         }
     }
     punt=s;
     puntajee->setpuntaje(s); //da el valor de punts a los puntos
 }
 void MainWindow::movimiento_enemigos_n1()
 {
     for(int i=0; i<listaenemigos_n2.size();i++) //ciclo que lee toda la lista de enemigos
     {


         if(i==0) {
             listaenemigos_n2.at(i)->arriba_abajo(100,200,280,1); //movimiento armonico simple
         }
         if(i==1)  {
             listaenemigos_n2.at(i)->arriba_abajo(900,200,280,1); //movimiento armonico simple
         }
         if(i==2){
             listaenemigos_n2.at(i)->MCU(200,300,150,1,0); //darle movimiento circular uniforme
         }

         if(i==3)  {
             listaenemigos_n2.at(i)->MCU(850,300,150,-1,-3.1416); //darle el omvimiento circular uniforme
         }

         colision2(listaenemigos_n2.at(i)); //funcion que detecta el choque y actualiza las vidas

         update_score(0);    //actualizo puntaje
     }
     if(puntajee->getpuntaje()==40)
     {

         escenario2();
     }
 }
 void MainWindow::movimiento_enemigos_n2()
 {
     for(int i=0; i<listaenemigos_n2.size();i++) //ciclo que lee toda la lista de fuerzaaereas
     {


         if(i==0)
         {

             if(listaenemigos_n2.at(i)->getVel()>70){listaenemigos_n2.at(i)->setVel(70);} //condicion para que no supere cierta velocidad
             if(listaenemigos_n2.at(i)->getVelx()<45){listaenemigos_n2.at(i)->setVelx(45);} //condicion para que no rebote con una velocidad menor
         }

         if(i==1)
         {

             if(listaenemigos_n2.at(i)->getVel()>70){listaenemigos_n2.at(i)->setVel(70);} //condicion para que no supere cierta velocidad
             if(listaenemigos_n2.at(i)->getVelx()<45){listaenemigos_n2.at(i)->setVelx(45);} //condicion para que no rebote con una velocidad menor
         }

         if(i==2)
         {

             if(listaenemigos_n2.at(i)->getVel()>60){listaenemigos_n2.at(i)->setVel(60);} //condicion para que no supere cierta velocidad
             if(listaenemigos_n2.at(i)->getVelx()<30){listaenemigos_n2.at(i)->setVelx(30);} //condicion para que no rebote con una velocidad menor
         }

         //mover a la derecha
         if(listaenemigos_n2.at(i)->getDir()==1) //condicion para preguntar por la direcion
         {

             listaenemigos_n2.at(i)->actualizarposicion_derecha(); //actualiza la posicion
             listaenemigos_n2.at(i)->actualizarvelocidad(); //actualiza la velocidad
             listaenemigos_n2.at(i)->setX(listaenemigos_n2.at(i)->getPosx()); //setea la posicion en x
             listaenemigos_n2.at(i)->setY(-listaenemigos_n2.at(i)->getPosy());//setea la posicion en y
         }

         //mover a la izquierda
         if(listaenemigos_n2.at(i)->getDir()==2) //condicion para preguntar la direccion
         {
             listaenemigos_n2.at(i)->actualizarposicion_izquierda(); //actualiza la posicion
             listaenemigos_n2.at(i)->actualizarvelocidad(); //actualiza la velocidad
             listaenemigos_n2.at(i)->setX(listaenemigos_n2.at(i)->getPosx()); //setea la posicion en x
             listaenemigos_n2.at(i)->setY(-listaenemigos_n2.at(i)->getPosy());//setea la posicion en y
         }

         //rebote con el piso

         if(listaenemigos_n2.at(i)->collidesWithItem(piso)) //condicion para preguntar si colisiono con el piso
         {


             listaenemigos_n2.at(i)->rebotepiso(); //aplicar rebote
         }
         //rebote con el muro derecho
         if (listaenemigos_n2.at(i)->collidesWithItem(muroderecho)) //condicion que pregunta si colisiono con el muro derecho
         {

             listaenemigos_n2.at(i)->setDir(2); //actualizar la direccion de movimiento
         }
         //rebote con el muro izquierdo
         if (listaenemigos_n2.at(i)->collidesWithItem(muroizquierdo)) //condicion que pregunta si colisiono con el muro izquierdo
         {

             listaenemigos_n2.at(i)->setDir(1);//actualizar la direccion de movimiento
         }

         colision2(listaenemigos_n2.at(i));
         update_score(40);
     }
     if(puntajee->getpuntaje()==70)
     {

         escenario3();
     }
 }
 void MainWindow::movimiento_enemigos_n3()
 {
     for(int i=0; i<listaenemigos_n2.size();i++) //ciclo que lee toda la lista de enemigos
     {


         if(i==0) {
             listaenemigos_n2.at(i)->movimiento_triangular(100,200,280,1); //movimiento armonico simple
         }
         if(i==1)  {
             listaenemigos_n2.at(i)->movimiento_triangular(900,200,280,-1); //movimiento armonico simple
         }
         if(i==2){
             listaenemigos_n2.at(i)->MCU(500,300,150,1,0); //darle movimiento circular uniforme
         }

         colision2(listaenemigos_n2.at(i)); //funcion que detecta el choque y actualiza las vidas

         update_score(70);    //actualizo puntaje
     }
}

 void MainWindow::colision2(enemigos *bol)
 {
     if(nivel==1 || nivel==2){

     if(piratag->collidesWithItem(bol)&&bol->isVisible()){ //pregunta q si hubo colision con un enemigo visible
          corazon->muere(); //disminuye las vidas

         if(corazon->getcorazones()==2){


             piratag->setpx(500);

         }
         if(corazon->getcorazones()==1){

             piratag->setpx(500);

         }
     }
    }
  if(nivel==3){
      if(nave->collidesWithItem(bol)&&bol->isVisible()){ //pregunta q si hubo colision con un enemigo visible
           corazon->muere(); //disminuye las vidas

          if(corazon->getcorazones()==2){
                nave->setpx(10);
          }
          if(corazon->getcorazones()==1){
                nave->setpx(10);
          }
      }

  }

 }
 void MainWindow::definir_nivel1()
 {
     if (corazon->getcorazones()==0){           //perdio
         piratag->hide();
         piso->hide();
         corazon->hide();
         coraim->hide();
         nave->hide();

         for(int i=0;i<listaenemigos_n2.size();i++)
         {
             if(listaenemigos_n2.at(i)->isVisible())
             {
                 scene->removeItem(listaenemigos_n2.at(i));
             }
         }
         /*musica->stop();
         musica->setMedia(QUrl("qrc:/n/Musica para el juego/y2mate.com - Bonus Game Win  Donkey Kong Country OST.mp3"));
         musica->play();
         */



         ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/badend.jpg"));
     }

      else if(puntajee->getpuntaje()==100){
             piratag->hide();
             nave->hide();
             coraim->hide();
             corazon->hide();

             for(int i=0;i<listaenemigos_n2.size();i++)
             {
                 if(listaenemigos_n2.at(i)->isVisible())
                 {
                     scene->removeItem(listaenemigos_n2.at(i));
                 }
             }
            /* musica->stop();
             musica->setMedia(QUrl("qrc:/n/Musica para el juego/y2mate.com - Bonus Game Win  Donkey Kong Country OST.mp3"));
             musica->play();
             */
             ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/godendi.png"));

       }
     }


 void MainWindow::on_play_clicked()
 {
     escenario1();
 }

 void MainWindow::on_salir_clicked()    //cierra el juego
 {
     this->close();
 }


void MainWindow::victoria()
 {



 }

 void MainWindow::inicializarjuego()   //inicializar juego si ya habia perdido o ganado
 {
     if(nivel==1){
     scene->removeItem(listaenemigos_n2.at(0));
     scene->removeItem(listaenemigos_n2.at(1));
     scene->removeItem(listaenemigos_n2.at(2));
     scene->removeItem(listaenemigos_n2.at(3));
     scene->removeItem(piratag);

     }
     if(nivel==2){
         scene->removeItem(listaenemigos_n2.at(0));
         scene->removeItem(listaenemigos_n2.at(1));
         scene->removeItem(listaenemigos_n2.at(2));
         scene->removeItem(piratag);
         }


    listaenemigos_n2.clear();

     puntajee->setpuntaje(0);
     escenario1();
 }



