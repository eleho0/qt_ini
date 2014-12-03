#include "firstrun.h"
#include "mdiy.h"
#include "ui_firstrun.h"

Firstrun::Firstrun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Firstrun)
{

    ui->setupUi(this);
    connect(ui->pushButton_hide, SIGNAL(clicked()), this, SLOT(hide_label()));
    connect(ui->pushButton_show, SIGNAL(clicked()), this, SLOT(show_label()));
    connect(ui->pushButton_ha,SIGNAL(clicked()),this,SLOT(ha_dialog()));
}

Firstrun::~Firstrun()
{
    delete ui;
}

void Firstrun::show_label()
{
    ui->label->show();

}

void Firstrun::hide_label()
{
    ui->label->hide();
}

void Firstrun::ha_dialog()
{
    mDiy* dlg = new mDiy();
    dlg->show();
}
