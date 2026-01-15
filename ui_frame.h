/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QLabel *label_helploader;
    QPushButton *p_loader;
    QPushButton *p_aligner;
    QPushButton *p_changer;
    QPushButton *p_chuck;
    QPushButton *p_lift;
    QPushButton *p_page2;
    QPushButton *p_cass;

    void setupUi(QFrame *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName("Frame");
        Frame->resize(800, 1000);
        label_helploader = new QLabel(Frame);
        label_helploader->setObjectName("label_helploader");
        label_helploader->setGeometry(QRect(0, 30, 800, 1000));
        label_helploader->setFocusPolicy(Qt::WheelFocus);
        label_helploader->setScaledContents(false);
        label_helploader->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_helploader->setWordWrap(true);
        p_loader = new QPushButton(Frame);
        p_loader->setObjectName("p_loader");
        p_loader->setGeometry(QRect(0, 0, 76, 27));
        p_aligner = new QPushButton(Frame);
        p_aligner->setObjectName("p_aligner");
        p_aligner->setGeometry(QRect(81, 0, 76, 27));
        p_changer = new QPushButton(Frame);
        p_changer->setObjectName("p_changer");
        p_changer->setGeometry(QRect(162, 0, 76, 27));
        p_chuck = new QPushButton(Frame);
        p_chuck->setObjectName("p_chuck");
        p_chuck->setGeometry(QRect(243, 0, 76, 27));
        p_lift = new QPushButton(Frame);
        p_lift->setObjectName("p_lift");
        p_lift->setGeometry(QRect(324, 0, 76, 27));
        p_page2 = new QPushButton(Frame);
        p_page2->setObjectName("p_page2");
        p_page2->setGeometry(QRect(720, 5, 76, 25));
        p_cass = new QPushButton(Frame);
        p_cass->setObjectName("p_cass");
        p_cass->setGeometry(QRect(405, 0, 76, 27));

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QFrame *Frame)
    {
        Frame->setWindowTitle(QCoreApplication::translate("Frame", "Frame", nullptr));
        label_helploader->setText(QString());
        p_loader->setText(QCoreApplication::translate("Frame", "Loader", nullptr));
        p_aligner->setText(QCoreApplication::translate("Frame", "Aligner", nullptr));
        p_changer->setText(QCoreApplication::translate("Frame", "Changer", nullptr));
        p_chuck->setText(QCoreApplication::translate("Frame", "Chuck", nullptr));
        p_lift->setText(QCoreApplication::translate("Frame", "Lift", nullptr));
        p_page2->setText(QCoreApplication::translate("Frame", "page 2", nullptr));
        p_cass->setText(QCoreApplication::translate("Frame", "Cass", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
