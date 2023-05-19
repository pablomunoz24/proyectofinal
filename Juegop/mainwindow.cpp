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
  scene->setSceneRect(0,0,990,640); // x:0 y:0 ancho:1000 alto:600
  scene->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondom.png")); //fondo del menu principal
  corazon= new Salud(); //creo un objeto de tipo Hearts
   corazon->setPos(-50,0); //posicion x y pero dentro de la escena

   puntajee= new puntaje();   //creo un objeto de tipo Score para el puntaje

   colision_1= new QTimer();

   jugador= new player();   //creo un objeto de tipo player llamado jugador

   piratag= new pirata();   //creo un objeto de tipo Robots llamado robots_n2

   timerenemigo_n2= new QTimer();  //creo un objeto de tipo QTimer - tiempo repeticion enemigo nivel 2

   menuprincipal();   //llamo la funcion menuprincipal
 }

 MainWindow::~MainWindow()
 {
   delete ui;
 }

 void MainWindow::keyPressEvent(QKeyEvent *evento)  //al presionar el teclado
 {
   if(evento->key()==Qt::Key_W){
       this->jugador->mover_arriba();         //nave primer escenario
   }

   if(evento->key()==Qt::Key_S){
       this->jugador->mover_abajo();          //nave primer escenario
   }

   if(evento->key()==Qt::Key_D){
       this->jugador->mover_derecha();     //nave primer escenario
       if(nivel==1){                       //robots segundo escenario
       this->piratag->mov_derecha();
       }
   }

   if(evento->key()==Qt::Key_A){
       this->jugador->mover_izquierda();      //nave primer escenario
       if(nivel==1){                         //robots segundo escenario
       this->piratag->mov_izquierda();
       }
   }

   if(evento->key()==Qt::Key_Space){
       if(nivel==1){                             //si estoy en el nivel 2
       bala=new Canon();                       //creo un objeto de tipo bullets
       bala->setPos(piratag->getpx()+7, piratag->getpy()-85); // bala disparara desde centro del robots. +7 -85 para q dispare del cañon del robot
       scene->addItem(bala);                    //agregre la bala a la escena
       }
   }
 }
 void MainWindow::menuprincipal()
 {
      ui->play->show();
      ui->salir->show();

 }
 void MainWindow::escenario1()
 {
     ui->play->hide(); //oculto el boton jugar
     ui->salir->hide();  //oculto el boton sali
     nivel=1;
     vidas=3;
     corazon->setcorazones(vidas); //le ingreso que tendra 6 corazones
     scene->addItem(corazon);      //le agrego la salud o vida o corazones a la escena

     ui->graphicsView->setBackgroundBrush(QPixmap(":/Imagenes para el juego/fondo2.jpg"));
     puntajee->setPos(920,0);            //establezco donde pondre el puntaje en la escena x:920 y:0  esquina superior derecha
     scene->addItem(puntajee);           //añado el puntaje en la escena

     scene->addItem(piratag);  //lo agrego a la escena

      srand(time(NULL));

      corazon->setcorazones(3);

     enemigo1 = new enemigos(150,-500,82,100); //creo enemigo 1 - x y ancho:135 la imagen tiene mas ancho del fantasma -  alto
     enemigo1->setImagen(1);                    //selecionar imagen
     listaenemigos_n2.push_back(enemigo1); //agrego enemigo 1 a la lista
     scene->addItem(listaenemigos_n2.at(0)); //añado enemigo 1 a la escena

     enemigo2 = new enemigos(850,-500,140,100); //creo enemigo 2
     enemigo2->setImagen(2);
     listaenemigos_n2.push_back(enemigo2);
     scene->addItem(listaenemigos_n2.at(1));

     enemigo3 = new enemigos(500,-350,135,100); //creo enemigo 3
     enemigo3->setImagen(1);
     listaenemigos_n2.push_back(enemigo3);
     scene->addItem(listaenemigos_n2.at(2));

     enemigo4 = new enemigos(750,-350,140,100); //creo enemigo 4
     enemigo4->setImagen(2);
     listaenemigos_n2.push_back(enemigo4);
     scene->addItem(listaenemigos_n2.at(3));

     connect(timerenemigo_n2,SIGNAL(timeout()),this,SLOT(movimiento_enemigos_n2()));
     timerenemigo_n2->start(10);

     connect(definir_n2,SIGNAL(timeout()),this,SLOT(definir_nivel2()));
     definir_n2->start(500);
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
 void MainWindow::movimiento_enemigos_n2()
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

 void MainWindow::definir_nivel2()
 {
     msgbox.setWindowTitle("juego terminado");  //titulo de la caja de mensaje
     msgbox.setIcon(QMessageBox::Information);  //q es una caja de tipo informativa
     msgbox.setStandardButtons(QMessageBox::Yes); //boton de yes de la caja de meensaje
     msgbox.addButton(QMessageBox::No);          //agrega el boton no
     msgbox.setDefaultButton(QMessageBox::Yes);  //boton por defecto sera el yes
     if (corazon->getcorazones()==0){           //perdio
         definir_n2->stop();                   //detener el cronometro
         msgbox.setText("supervivencia fallida! volver a jugar");
         timerenemigo_n2->stop();                  //detengo el timer que genera las nubes y asteroides
         if(QMessageBox::Yes==msgbox.exec()){     //si presiona yes para volver a jugar
             inicializarjuego();
         }else{                                    //si presiona no
             QCoreApplication::quit();             //cierra el programa
         }

     }
     else{

         if(puntajee->getpuntaje()==40){   //con corazones y cronometro cero gano

             timerenemigo_n2->stop();
             definir_n2->stop();                //detengo el timer que genera las nubes y asteroid
             msgbox.setText("supervivencia exitosa! volver a jugar");
             if(QMessageBox::Yes==msgbox.exec()){     //si presiona yes para volver a jugar
                 inicializarjuego();
             }else{                                    //si presiona no
                 QCoreApplication::quit();             //cierra el programa
             }
         }
     }
 }


 void MainWindow::mover_scenas()
 {
     this->scene->advance();
 }

 void MainWindow::on_play_clicked()
 {
     escenario1();
 }

 void MainWindow::on_salir_clicked()    //cierra el juego
 {
     this->close();
 }


 void MainWindow::definir_resultado()  //define si gano o perdio
 {
     msgbox.setWindowTitle("juego terminado");  //titulo de la caja de mensaje
     msgbox.setIcon(QMessageBox::Information);  //q es una caja de tipo informativa
     msgbox.setStandardButtons(QMessageBox::Yes); //boton de yes de la caja de meensaje
     msgbox.addButton(QMessageBox::No);          //agrega el boton no
     msgbox.setDefaultButton(QMessageBox::Yes);  //boton por defecto sera el yes
     if (corazon->getcorazones()==0){           //perdio
         cronometro->stop();                   //detener el cronometro
         msgbox.setText("supervivencia fallida! volver a jugar");
         if(QMessageBox::Yes==msgbox.exec()){     //si presiona yes para volver a jugar
             inicializarjuego();
         }else{                                    //si presiona no
             QCoreApplication::quit();             //cierra el programa
         }

     }

 }

 void MainWindow::inicializarjuego()   //inicializar juego si ya habia perdido o ganado
 {
     if(nivel==1){
     colision_1->stop();
     timerenemigo_n2->stop();
     definir_n2->stop();
     scene->removeItem(listaenemigos_n2.at(0));
     scene->removeItem(listaenemigos_n2.at(1));
     scene->removeItem(listaenemigos_n2.at(2));
     scene->removeItem(listaenemigos_n2.at(3));
     scene->removeItem(piratag);
     }
     puntajee->setpuntaje(0);
     cronometr.setHMS(0,0,20);
     escenario1();
 }



