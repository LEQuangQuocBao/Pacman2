#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>

class Mainwnd : public QMainWindow {

private:
    class bienvenuewindow;
    class joueurWindow;
    class PacmanWindow;

public:
    Mainwnd(QWidget *parent = 0);
    ~Mainwnd(){};

    void changeEcran(int );

public:
    bienvenuewindow * bienvenueWnd;
    joueurWindow *caractWnd;
    PacmanWindow *pacmanWnd;
    //PacmanWindow * c;


public:
//Initlisation les QFrame
    void init_bienvenueWnd();
    void init_caractWnd(int );
    void init_pacmanWnd(int, int, int, int);

//Les slots pour bienvenueWnd
    void handleUnJoueur();
    void handleDeuxJoueur();
//Les slots pour caractWnd

    void handleCommence();
    void handleRetourne();

    void keyPressEvent(QKeyEvent *);

};




#endif // MAINWINDOW_H_INCLUDED
