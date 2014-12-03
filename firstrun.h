#ifndef FIRSTRUN_H
#define FIRSTRUN_H

#include <QWidget>

namespace Ui {
class Firstrun;
}

class Firstrun : public QWidget
{
    Q_OBJECT
    
public:
    explicit Firstrun(QWidget *parent = 0);
    ~Firstrun();

private slots:
    void show_label();
    void hide_label();
    void ha_dialog();
    void btnl1();
    void btnl2();
    void gl_btn_click();

    
private:

    Ui::Firstrun *ui;
    int flag1, flag2;
    void setbgcolor(QWidget *w, int r, int g, int b);
};

#endif // FIRSTRUN_H
