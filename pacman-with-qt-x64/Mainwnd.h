#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include <string>
#include <fstream>
using namespace std;

class Mainwnd : public QMainWindow {

private:
    class bienvenuewindow;
    class joueurWindow;
    class PacmanWindow;
    class resultWindow;
    //fstream resultat;
    string result[2][5];

public:
    Mainwnd(QWidget *parent = 0);
    ~Mainwnd(){};

public:
    bienvenuewindow * bienvenueWnd;
    joueurWindow *caractWnd;
    PacmanWindow *pacmanWnd;
    resultWindow *resultWnd;


public:
//Initlisation les QFrame
    void init_bienvenueWnd();
    void init_caractWnd(int );
    void init_pacmanWnd(string, string, int, int, int, int);
    void init_resultWnd(string);

//Les slots pour bienvenueWnd
    void handleUnJoueur();
    void handleDeuxJoueur();
//Les slots pour caractWnd

    void handleCommence();
    void handleNouveauJeu();
    void handleResultat();
    void handleMeuilleurNote();

    void compareResultat(PacmanWindow &);
    void readfile();
    void writefile();

    void keyPressEvent(QKeyEvent *);
    void timerEvent(QTimerEvent *);
private:
    int timerId;
    bool inGame;
};




#endif // MAINWINDOW_H_INCLUDED
