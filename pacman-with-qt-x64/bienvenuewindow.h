#ifndef BIENVENUEWINDOW_H
#define BIENVENUEWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "Mainwnd.h"

class Mainwnd::bienvenuewindow: public QFrame
{
public:
    bienvenuewindow(QWidget* pparent=0, Qt::WindowFlags flags=0);

public:
    QVBoxLayout *vbox;

    QPushButton *btnUnJoueur;
    QPushButton *btnDeuxJoueur;
    QPushButton *btnMarque;
    QPushButton *btnSortie;
};


#endif
