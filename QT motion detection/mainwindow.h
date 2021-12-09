#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <QLineEdit>
#include <QTimer>
#include <iostream>
#include <opencv2/highgui.hpp>              // pour l'affichage dans l'interface (videocapture)
#include <opencv2/imgproc.hpp>              // pour le traitement d'image (changement de format)
#include <opencv2/imgproc/types_c.h>        //pour l'erreur ‘CV_BGR2RGB’ was not declared in this scope


#include <vector>
//
using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_ouvrir_camera_clicked();

    void on_fermer_camera_clicked();

    void update_window();


private:

    Ui::MainWindow *ui;

    QTimer *timer;
    VideoCapture capture;

//
   Mat img, imgDelta, imgThresh, imgPremiere;
   vector <vector<Point>> monVecteur;

//


    QImage qt_image;


};
#endif // MAINWINDOW_H
