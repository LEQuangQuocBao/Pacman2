#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "bienvenuewindow.h"
#include "joueurwindow.h"
#include "pacmanwindow.h"

class Mainwnd : public QMainWindow {

private:
    class bienvenuewindow ;

public:
    Mainwnd(QWidget *parent = 0);
    ~Mainwnd(){};

    void changeEcran(int );

private:
    bienvenuewindow * a;
    Joueur *b;
    PacmanWindow * c;


};




#endif // MAINWINDOW_H_INCLUDED
