#ifndef PACMANWINDOW_H
#define PACMANWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "jeu.h"
//#include "joueurwindow.h"
#include "Mainwnd.h"

class Mainwnd::PacmanWindow : public QFrame
{

  protected:
    Jeu jeu;

    QPixmap pixmapPacman, pixmapTime, pixmapFantome, pixmapMur, pixmapGod;
    QPixmap pixmapPacHaut, pixmapPacBas, pixmapPacGauche, pixmapPacDroite;
  public:
    PacmanWindow(QWidget *pParent=0, Qt::WindowFlags flags=0);

    void loadImage();


    void ajoutFantome();        // ajouter un fantome
    void supprFantome();        // supprimer un fantome

    bool isCollision();
    void handleCollision();

    bool isCollisionTime();
    bool handleCollisionTime();


  public:
        void paintEvent(QPaintEvent *);
        void keyPressEvent(QKeyEvent *);
    void handleTimer();
    void handleCountdown();
    //void drawObjects(QPainter *);
    //void finishGame(QPainter *, QString);
    //void moveObjects();

    void configurer(int ,int ,int, int);
    void startJeu();
    void pauseJeu();
    //void stopGame();
    void victory();
    //void checkCollision();

  private:
    QLabel* label_countdown;
    QLabel* label_marqueA;
    QLabel* label_marqueB;
    QTime countdown;
    QTimer *vitesseJeu;
    QTimer *countTime;

  private:
    //int timeId;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
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
