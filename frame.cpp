#include "frame.h"
#include "ui_frame.h"
#include <QDir>

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);

}

Frame::~Frame()
{
    delete ui;
}


/*
QString filename = "X:/my_image";
QImage image(filename);
ui->label->setPixmap(QPixmap::fromImage(image));

 * */

int pagesel = 0;


void Frame::on_p_aligner_clicked()
{
    ui->p_page2->show();
    pagesel = 1;
    QString filename = helpfile + "PA1.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
void Frame::on_p_lift_clicked()
{
    ui->p_page2->hide();
    QString filename = helpfile + "LIFT.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
void Frame::on_p_changer_clicked()
{
    ui->p_page2->show();
    pagesel = 2;
    QString filename = helpfile + "CHANGER1.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
void Frame::on_p_loader_clicked()
{
    ui->p_page2->hide();
    QString filename = helpfile + "LOADER.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
void Frame::on_p_chuck_clicked()
{
    ui->p_page2->hide();
    QString filename = helpfile + "CHUCK.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
void Frame::on_p_page2_clicked()
{
    ui->p_page2->show();
    if(ui->p_page2->text() == "page 2")
    {
        ui->p_page2->setText("page 1");
        if(pagesel == 2)
        {
            QString filename = helpfile + "CHANGER2.PNG";
            QImage image(filename);
            ui->label_helploader->setPixmap(QPixmap::fromImage(image));
        }
        else if (pagesel == 1)
        {
            QString filename = helpfile + "PA2.PNG";
            QImage image(filename);
            ui->label_helploader->setPixmap(QPixmap::fromImage(image));
        }
    }
    else
    {
        ui->p_page2->setText("page 2");
        if(pagesel == 2)
        {
            QString filename = helpfile + "CHANGER1.PNG";
            QImage image(filename);
            ui->label_helploader->setPixmap(QPixmap::fromImage(image));
        }
        else if (pagesel == 1)
        {
            QString filename = helpfile + "PA1.PNG";
            QImage image(filename);
            ui->label_helploader->setPixmap(QPixmap::fromImage(image));
        }
    }
}
void Frame::on_p_cass_clicked()
{
    ui->p_page2->hide();
    QString filename = helpfile + "CASS.PNG";
    QImage image(filename);
    ui->label_helploader->setPixmap(QPixmap::fromImage(image));
}
