#ifndef MDIY_H
#define MDIY_H

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
};

#endif // MDIY_H
