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
  corazon= new Salud(); //creo un objeto de tipo Hearts
   corazon->setPos(0,0); //posicion x y pero dentro de la escena

   puntajee= new puntaje();   //creo un objeto de tipo Score para el puntaje


   jugador= new player();   //creo un objeto de tipo player llamado jugador

   piratag= new pirata(500,500,112,155);   //creo un objeto llamado piratag
   piratag->setImagen(0);

   piso = new pirata(500,575,1000,50); //creo el piso
   piso->setImagen(1);
   muroderecho = new pirata(1025,350,50,800); //creo el muro derecho
   muroizquierdo = new pirata(-25,350,50,800); //creo el muro izquierdo

   timerenemigo_n2= new QTimer;
   timerenemigo_n1 = new QTimer;

   menuprincipal();   //llamo la funcion menuprincipal
 }

 MainWindow::~MainWindow()
 {
   delete ui;
 }

 void MainWindow::keyPressEvent(QKeyEvent *evento)  //al presionar el teclado
 {
  if(juego){
   if(evento->key()==Qt::Key_W){
       this->jugador->mover_arriba();         //nave primer escenario
   }

   if(evento->key()==Qt::Key_S){
       this->jugador->mover_abajo();          //nave primer escenario
   }

   if(evento->key()==Qt::Key_D){
       this->jugador->mover_derecha();     //nave primer escenario
       if(nivel==1 or nivel==2){
       this->piratag->mov_derecha();
       }
   }

   if(evento->key()==Qt::Key_A){
       this->jugador->mover_izquierda();      //nave primer escenario
       if(nivel==1 or nivel==2){
       this->piratag->mov_izquierda();
       }
   }

   if(evento->key()==Qt::Key_Space){
       bala=new Canon();                       //creo un objeto de tipo bullets
       bala->setPos(piratag->getpx()+7, piratag->getpy()-85);
       scene->addItem(bala);                    //agregre la bala a la escena

   }
  }
 }
 void MainWindow::menuprincipal()
 {
      juego=false;
      ui->play->show();
      ui->salir->show();

 }
 void MainWindow::escenario1()
 {
     ui->play->hide(); //oculto el boton jugar
     ui->salir->hide();  //oculto el boton sali
     nivel=1;
     vidas=3;
     juego=true;
     scene->addItem(piso);
     corazon->setcorazones(vidas); //le ingreso que tendra 6 corazones
     scene->addItem(corazon);      //le agrego la salud o vida o corazones a la escena

     ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondo1.jpg"));
     puntajee->setPos(850,0);            //establezco donde pondre el puntaje en la escena x:920 y:0  esquina superior derecha
     scene->addItem(puntajee);           //añado el puntaje en la escena

     scene->addItem(piratag);  //lo agrego a la escena



      corazon->setcorazones(3);

     enemigo1 = new enemigos(150,-500,105,94); //creo enemigo 1 - x y ancho:135 la imagen tiene mas ancho del fantasma -  alto
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
     juego=true;

     timerenemigo_n2->stop();
     scene->addItem(piso);

     listaenemigos_n2.clear(); //vacias lista de fuerzaaereas

     if(!piratag->isActive()) //condicion que pregunta si el tanque ya esta en escena
     {
         scene->addItem(piratag); //agregar la chillin
     }
     piratag->setpx(10); //actualizar posicion


     if(!corazon->isActive()) //condicion que pregunta si vidas ya esta en escena
     {
         scene->addItem(corazon);
     }

     if(!puntajee->isActive()) //condicion que pregunta si los puntos ya estan en escena
     {
         scene->addItem(puntajee);
     }


     //fuerzaaerea 6
     enemigo5 = new enemigos(25,-150,70,51,10,90);
     enemigo5->setImagen(3);
     listaenemigos_n2.push_back(enemigo5); //
     scene->addItem(listaenemigos_n2.at(0)); //añado fuerzaaerea 1 a la escena

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

         colision2(listaenemigos_n2.at(i)); //funcion que detecta el choque y actualiza las vidas
         update_score(40); //funcion que detecta que el diparo haya acertado a un fuerzaaerea y actualiza el puntaje
         if(puntajee->getpuntaje()==70)
         {
             victoria();
         }
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

         update_score(0);    //actualizo puntaje
     }
     if(puntajee->getpuntaje()==40)
     {
         escenario2();
     }
 }


 void MainWindow::colision2(enemigos *bol)
 {

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
 void MainWindow::definir_nivel1()
 {
     if (corazon->getcorazones()==0){           //perdio
         definir_n1->stop();
         timerenemigo_n2->stop();
         piratag->hide();
         piso->hide();
         corazon->hide();
         delete enemigo1;
         delete enemigo2;
         delete enemigo3;
         delete enemigo4;
         delete enemigo5;
         delete enemigos6;
         delete enemigos7;
         ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/badend.jpg"));
     }
     else{

         if(puntajee->getpuntaje()==70){
             timerenemigo_n1->stop();
             definir_n1->stop();
             piratag->hide();
             piso->hide();
             corazon->hide();
             delete enemigo1;
             delete enemigo2;
             delete enemigo3;
             delete enemigo4;
             delete enemigo5;
             delete enemigos6;
             ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/badend.jpg"));
         }
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



