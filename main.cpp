#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QScreen>
#include <QDebug>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/INSBox/Servicetool/splash_INSBox.PNG"));
    splash->show();

    MainWindow w;
    int width = w.frameGeometry().width();
    int height = w.frameGeometry().height();

    QScreen *screen = a.primaryScreen();

    int screenWidth = screen->geometry().width();
    int screenHeight = screen->geometry().height();
    qDebug()<<"width"<<width<<"height"<<height<<"screenWidth"<<screenWidth<<"screenHeight"<<screenHeight;

    int realw = 0;
    int realh = 0;
    if((screenHeight/2)-(height/2) < 0) realh = 30;
    else realh = (screenHeight/2)-(height/2);
    if((screenWidth/2)-(width/2) < 0 ) realw = 30;
    else realw = (screenWidth/2)-(width/2);

 //   w.setGeometry((screenWidth/2)-(width/2), (screenHeight/2)-(height/2), width, height);
    w.setGeometry(realw, realh, width, height);

    QTimer::singleShot(1000,splash,SLOT(close()));
    QTimer::singleShot(1000,&w,SLOT(show()));
 //   w.show();
    return a.exec();

}
