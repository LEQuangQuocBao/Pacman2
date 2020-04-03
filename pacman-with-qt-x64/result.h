#ifndef RESULT_H
#define RESULT_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "Mainwnd.h"

class Mainwnd::resultWindow : public QFrame
{
public:
    QLabel *resultat;
    QPushButton *btnRejouer;
    QPushButton *btnSortir;
public:
    resultWindow(QWidget* pparent=0, Qt::WindowFlags flags=0);
    void setResultat(string );
};

#endif
