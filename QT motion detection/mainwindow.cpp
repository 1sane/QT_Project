    #include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{


    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    ui->fermer_camera->setVisible(false);
    ui->ouvrir_camera->setVisible(false);
    ui->pushButton_4->setVisible(false);

    ui->label->setVisible(true);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);

    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("identifiant");
    ui->lineEdit_2->setPlaceholderText("mot de passe");

  //  ui->lineEdit_3->setVisible(false);
  //  ui->lineEdit_3->setPlaceholderText("rentrez une adresse ip de la forme: X.X.X.X");


    timer = new QTimer(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    QString link = "http://localhost/phpmyadmin/index.php?route=/sql&db=projet&table=patients&pos=0";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_pushButton_2_clicked()//connexion
{
    QString identifiant = ui->lineEdit->text();
    QString motDePasse = ui->lineEdit_2->text();

    QString id = "root";
    QString mdp = "admin";

    static int i=3;



    ui->lineEdit->setFocus();

    if(id == identifiant)
    {
        ui->lineEdit_2->setFocus();
    }



   if (identifiant == id && motDePasse == mdp)
   {
    ui->pushButton->setVisible(true);
    ui->ouvrir_camera->setVisible(true);
    ui->fermer_camera->setVisible(true);
    ui->pushButton_4->setVisible(true);

    ui->label->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);



    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);


    ui->pushButton_2->setVisible(false);
   }else
   {   i--;
       ui->label->setText("Identifiant et mot de passe incorrect " +QString::number(i)+ " essais");

   }
   if(i == 0)
   {

       close();
   }

}






void MainWindow::on_pushButton_4_clicked()
{
    ui->label_2->setText("Ici, l'affichages des erreurs");
}









void MainWindow::on_ouvrir_camera_clicked()
{
       capture.open(0);

    if(!capture.isOpened())  // teste l'initialisation
    {
        cout << "la camera n'a pas pu s'ouvrir" << endl;
    }
    else //
    {
        cout << "camera ouverte" << endl;
    }


    //Détection de mouvement

   capture >> imgPremiere;

   cvtColor(imgPremiere,imgPremiere, COLOR_BGR2GRAY);

   GaussianBlur(imgPremiere, imgPremiere, Size(21,21), 0);

  //Fin détection mouvements

        connect(timer, SIGNAL(timeout()), this, SLOT(update_window())); // connexion de la caméra à l'affichage
        timer->start(20); //appel du timer toute les 20 ms









}

void MainWindow::on_fermer_camera_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));//déconnexion du flux à l'affichage
    capture.release();

    Mat image = Mat::zeros(img.size(),CV_8UC3);// initialisation d'une matrice à 0, de la taille de l'image, avec pour type une image à trois canaux couleurs.8bits par pixel par canal, Unsigned char, 3 canaux
    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888); // permet à l'image de type Mat de s'afficher avec QImage avec le format BGR
    ui->label_3->setPixmap(QPixmap::fromImage(qt_image));// transforme l'image en QPixmap qui va permettre d'en avoir l'accès via boutons et label
    ui->label_3->resize(ui->label_3->pixmap()->size());// redimentionne le label par rapport à la taille de l'image

    destroyAllWindows();

    cout << "caméra fermée" << endl;
}

void MainWindow::update_window()
{

    //détection de mouvements

    capture >> img;//stockage de la vidéo

    Mat imgClone=img.clone();
    cvtColor(img, img, COLOR_BGR2GRAY);
    GaussianBlur(img, img, Size(15,15), 0);
    absdiff(imgPremiere, img,imgDelta);
    threshold(imgDelta, imgThresh, 25, 255, THRESH_BINARY);
    dilate(imgThresh, imgThresh, Mat(), Point(-1, -1), 2);
    findContours(imgThresh, monVecteur, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    cout<<"No of contours : "<<monVecteur.size()<<endl;

    for(size_t i = 0; i<monVecteur.size(); i++)
    {
        Rect x = boundingRect(monVecteur[i]);
        rectangle(imgClone, x ,Scalar(255,0,0), 2);

    }

    qt_image = QImage((const unsigned char*) (imgClone.data), imgClone.cols, imgClone.rows, QImage::Format_RGB888);
    ui->label_3->setPixmap(QPixmap::fromImage(qt_image));
    ui->label_3->resize(ui->label_3->pixmap()->size());

      //imshow("1",img);
      //imshow("delta", imgThresh);
      imshow("Final",imgClone);

    //Fin détection de mouvement
      }















