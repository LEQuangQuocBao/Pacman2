#ifndef PACMANWINDOW_H
#define PACMANWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "jeu.h"
//#include "joueurwindow.h"
#include "Mainwnd.h"

class Mainwnd::PacmanWindow : public QFrame
{

  public:
    Jeu jeu;

    QPixmap pixmapPacmanDefaut, pixmapPacman1, pixmapPacman2, pixmapPacman3, pixmapPacman4;
    QPixmap pixmapMur1, pixmapMur2, pixmapMur3, pixmapGrass;
    QPixmap pixmapGod, pixmapFantome1, pixmapFantome2, pixmapFantome3;
  public:
    PacmanWindow(QWidget *pParent=0, Qt::WindowFlags flags=0);

    void loadImage();
    void setupLabel();

    //void ajoutFantome();        // ajouter un fantome
    //void supprFantome();        // supprimer un fantome


  public:
    void paintEvent(QPaintEvent *);
    void paintMur(QPainter *);
    void paintFantome(QPainter *);

    void keyPressEvent(QKeyEvent *);
    void handleTimer();
    void handleCountdown();


    void configurer(string, string, int ,int ,int, int);
    void startJeu();
    void pauseJeu();
    void stopJeu();
    void gagneJeu(int );
    void handleResultat();
    void checkCollision(Pacman &);
    void handleCollision();

  public:
    QLabel* label_countdown;
    QLabel* label_marqueA;
    QLabel* label_marqueB;
    QTime countdown;
    QTimer *vitesseJeu;
    QTimer *countTime;

  public:
    //int timeId;
    bool gameFini;
    bool paused;
    bool gameGagne;
    string resultat;
    int countGod;
};

class PacmanButton : public QPushButton
    {
    //friend class PacmanWindow;
    protected:
        void keyPressEvent(QKeyEvent *);
    public:
        PacmanButton(QWidget *parent=0);
    };


#endif
