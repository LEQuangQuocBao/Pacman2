#ifndef BIENVENUEWINDOW_H
#define BIENVENUEWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "Mainwnd.h"

class Mainwnd::bienvenuewindow
{
public:
    bienvenuewindow(QWidget* pparent=0, Qt::WindowFlags flags=0);
//    QPushButton*  getButton(){
//        return oneP;
//    }

protected:
    //void openOPW1();
    //void openOPW2();
public:
    QVBoxLayout *vbox;
    QPushButton *oneP;
    QPushButton *twoP;
};


#endif
