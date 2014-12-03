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
    
private:

    Ui::Firstrun *ui;
};

#endif // FIRSTRUN_H
