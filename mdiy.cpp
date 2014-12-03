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
