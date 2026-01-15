#ifndef FRAME_H
#define FRAME_H

#include <QFrame>

namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr);
    ~Frame();
    QString helpfile = "C:/INSBox/Servicetool/Files/HELP/";

private slots:
    void on_p_aligner_clicked();
    void on_p_loader_clicked();
    void on_p_chuck_clicked();
    void on_p_lift_clicked();
    void on_p_changer_clicked();
    void on_p_page2_clicked();
    void on_p_cass_clicked();

private:
    Ui::Frame *ui;
};

#endif // FRAME_H
