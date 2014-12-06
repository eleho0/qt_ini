#include "mdiy.h"
#include <QSettings>
#include "ui_mdiy.h"

mDiy::mDiy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mDiy)
{
    ui->setupUi(this);
    QSettings *fav = new QSettings("/usr/fav.ini",QSettings::IniFormat);
    //ui->lineEdit_editor->setText(QVariant(fav->value("fav/editor", "vi").toString()));
    ui->lineEdit_editor->setText(fav->value("fav/editor", "vi").toString());
    ui->lineEdit_fruit->setText(fav->value("fav/fruit", "orange").toString());
    delete fav;

    ui->button_9527->setStyleSheet("color: blue;"
            "background-color: yellow;"
            "selection-color: yellow;"
            "selection-background-color: blue;");

    hilight_button_color_all(ui->button_1521, 200, 20, 10, 100);
    hilight_button_activate(ui->button_2822, 210, 110, 100, 150);

    hilight_button_t(ui->button_exit, 200, 50, 30, 188, 1);

    connect(ui->pushButton_ok,SIGNAL(clicked()),this, SLOT(save_setting()));
}

mDiy::~mDiy()
{
    delete ui;
}

void mDiy::save_setting()
{
    QSettings *fav = new QSettings("/usr/fav.ini",QSettings::IniFormat);
    QString fav_fruit = ui->lineEdit_fruit->text();
    QString fav_editor = ui->lineEdit_editor->text();
    fav->setValue("fav/editor", fav_editor);
    fav->setValue("fav/fruit", fav_fruit);

    delete fav;

}
//set all color Acitvate, Inactivate Disable

void mDiy::hilight_button_color_all(QPushButton *btn, int R, int G, int B, int transparent)
{
    QPalette palette = btn->palette();
    QBrush brush(QColor(R, G, B, transparent));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active,   QPalette::Button, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
    btn->setPalette(palette);
}

void mDiy::hilight_button_t(QPushButton *btn, int R, int G, int B, int transparent, int layer)
{
    QPalette palette = btn->palette();
    QBrush brush(QColor(R, G, B, transparent));
    brush.setStyle(Qt::SolidPattern);
    switch(layer){
        case 1:
            palette.setBrush(QPalette::Active,   QPalette::Button, brush);
            break;
        case 2:
            palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
            break;
        case 3:

            palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
            break;
        default:

            break;


    }

    btn->setPalette(palette);
}




void mDiy::hilight_button_activate(QPushButton *btn, int R, int G, int B, int transparent)
{
    QPalette palette = btn->palette();
    QBrush brush(QColor(R, G, B, transparent));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active,   QPalette::Button, brush);
    btn->setPalette(palette);
}

void mDiy::hilight_button_Inactivate(QPushButton *btn, int R, int G, int B, int transparent)
{
    QPalette palette = btn->palette();
    QBrush brush(QColor(R, G, B, transparent));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
    btn->setPalette(palette);
}

void mDiy::hilight_button_Disable(QPushButton *btn, int R, int G, int B, int transparent)
{

    QPalette palette = btn->palette();
    QBrush brush(QColor(R, G, B, transparent));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
    btn->setPalette(palette);

}


