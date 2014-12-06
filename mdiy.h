#ifndef MDIY_H
#define MDIY_H
#include <QPushButton>

#include <QWidget>

namespace Ui {
class mDiy;
}

class mDiy : public QWidget
{
    Q_OBJECT
    
public:
    explicit mDiy(QWidget *parent = 0);
    ~mDiy();
    
private slots:
        void save_setting();
private:
    Ui::mDiy *ui;
    //set all color Acitvate, Inactivate Disable
    void hilight_button_color_all(QPushButton *btn, int R, int G, int B, int transparent);

    void hilight_button_t(QPushButton* btn, int R, int G, int B, int transparent, int layer);
    void hilight_button_activate(QPushButton *btn, int R, int G, int B, int transparent);
    void hilight_button_Inactivate(QPushButton *btn, int R, int G, int B, int transparent);
    void hilight_button_Disable(QPushButton *btn, int R, int G, int B, int transparent);
    //void hilight_button_color(QPushButton *btn, char* color);

};

#endif // MDIY_H
