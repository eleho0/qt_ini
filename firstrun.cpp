#include "firstrun.h"
#include "mdiy.h"
#include "ui_firstrun.h"

Firstrun::Firstrun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Firstrun)
{

    ui->setupUi(this);
    //去焦点
    ui->do_button->setFocusPolicy(Qt::NoFocus);
    ui->re_button->setFocusPolicy(Qt::NoFocus);
    ui->mi_button->setFocusPolicy(Qt::NoFocus);
    ui->fa_button->setFocusPolicy(Qt::NoFocus);
    ui->so_button->setFocusPolicy(Qt::NoFocus);
    ui->la_button->setFocusPolicy(Qt::NoFocus);
    ui->si_button->setFocusPolicy(Qt::NoFocus);


    connect(ui->pushButton_hide, SIGNAL(clicked()), this, SLOT(hide_label()));
    connect(ui->pushButton_show, SIGNAL(clicked()), this, SLOT(show_label()));
    connect(ui->pushButton_ha,SIGNAL(clicked()),this,SLOT(ha_dialog()));
    connect(ui->btn1,SIGNAL(clicked()),this,SLOT(btnl1()));
    connect(ui->btn2,SIGNAL(clicked()),this,SLOT(btnl2()));

    connect(ui->do_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->re_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->mi_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->fa_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->so_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->la_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
    connect(ui->si_button,SIGNAL(clicked()), SLOT(gl_btn_click()));
}

Firstrun::~Firstrun()
{
    delete ui;
}

void Firstrun::show_label()
{
    ui->msglabel->show();

}

void Firstrun::hide_label()
{
    ui->msglabel->hide();
}

void Firstrun::ha_dialog()
{
    mDiy* dlg = new mDiy();
    dlg->show();
}

void Firstrun::btnl1()
{
    ++flag1;

    switch(flag1){

    case 1:
        setbgcolor(ui->label,   230, 210, 110);
        setbgcolor(ui->label_2,   0, 0, 0);
        setbgcolor(ui->label_3,   0, 0, 0);
        break;
    case 2:
        setbgcolor(ui->label,   0, 0, 0);
        setbgcolor(ui->label_2,  230, 210, 110);
        setbgcolor(ui->label_3,  0, 0, 0);
        break;

    case 3:
        setbgcolor(ui->label,   0, 0, 0);
        setbgcolor(ui->label_2,  0, 0, 0);
        setbgcolor(ui->label_3,  230, 210, 110);
        break;

    case 4:
        flag1 = 0;
        setbgcolor(ui->label,   230, 210, 210);
        setbgcolor(ui->label_2,  230, 210, 210);
        setbgcolor(ui->label_3,  230, 210, 210);
        break;

    default:
        flag1 = 0;
        break;
    }


}

void Firstrun::btnl2()
{
    ++flag2;

    switch(flag2){

    case 1:
        setbgcolor(ui->label_4,   230, 210, 110);
        setbgcolor(ui->label_5,   0, 0, 0);
        setbgcolor(ui->label_6,   0, 0, 0);
        break;
    case 2:
        setbgcolor(ui->label_4,   230, 210, 110);
        setbgcolor(ui->label_5,   230, 210, 110);
        setbgcolor(ui->label_6,   0, 0, 0);
        break;

    case 3:
        setbgcolor(ui->label_4,   230, 210, 110);
        setbgcolor(ui->label_5,   230, 210, 110);
        setbgcolor(ui->label_6,   230, 210, 110);
        break;

    case 4:
        flag2 = 0;
        setbgcolor(ui->label_4,   0, 0, 0);
        setbgcolor(ui->label_5,   0, 0, 0);
        setbgcolor(ui->label_6,   0, 0, 0);
        break;

    default:
        flag2 = 0;
        break;
    }
}

void Firstrun::gl_btn_click()
{
    QWidget* curr_widget = this->focusWidget();

    if(curr_widget->inherits("QLineEdit")){


        QPushButton* anci_PB = dynamic_cast<QPushButton*>(sender());
        QString str = anci_PB->text();

        QLineEdit *curr_le = static_cast<QLineEdit*>(curr_widget);
        curr_le->insert(str);
    }
}

void Firstrun::setbgcolor(QWidget *w, int r, int g, int b)
{
    w->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(r,g,b));
    w->setPalette(palette);
}

