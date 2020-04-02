#include <iostream>
#include "pacmanwindow.h"

using namespace std;

Mainwnd::PacmanWindow::PacmanWindow(QWidget *pParent, Qt::WindowFlags flags):QFrame(pParent, flags)
{
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    loadImage();

}

void Mainwnd::PacmanWindow::loadImage(){

    // Taille des cases en pixels
    int largeurCase, hauteurCase;

    if (pixmapPacman.load("./data/pacman.png")==false)
    {
        cout<<"Impossible d'ouvrir pacman.png"<<endl;
        exit(-1);
    }

    if (pixmapFantome.load("./data/fantome.png")==false)
    {
        cout<<"Impossible d'ouvrir fantome.png"<<endl;
        exit(-1);
    }

    if (pixmapGod.load("./data/godFantome.png")==false)
    {
        cout<<"Impossible d'ouvrir god fantome.bmp"<<endl;
        exit(-1);
    }

    if (pixmapMur.load("./data/mur.png")==false)
    {
        cout<<"Impossible d'ouvrir mur.png"<<endl;
        exit(-1);
    }

    //PacmanButton *a = new PacmanButton(this);

    largeurCase = pixmapMur.width();
    hauteurCase = pixmapMur.height();

    resize(jeu.getNbCasesX()*largeurCase*2, jeu.getNbCasesY()*hauteurCase);

}

void Mainwnd::PacmanWindow::configurer(int nJoueur, int nFantome, int vit, int mode)
{
    jeu.setInfoJeu(nJoueur,nFantome,vit, mode);
    jeu.init();
}

void Mainwnd::PacmanWindow::startJeu()
{
    vitesseJeu = new QTimer(this);
    connect(vitesseJeu, QTimer::timeout, this, PacmanWindow::handleTimer);
    vitesseJeu->start(jeu.getVitesse());

    label_countdown = new QLabel("0:10", this);
    label_countdown->setGeometry(QRect(QPoint(650, 45), QSize(130, 50)));
    label_countdown->setFont(QFont("Arial", 30));

    countTime = new QTimer(this);
    countdown.setHMS(0,0,10,0);
    connect(countTime, QTimer::timeout, this, PacmanWindow::handleCountdown);
    countTime->start(1000);

}


void Mainwnd::PacmanWindow::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);
    list<Fantome>::const_iterator itFantome;
    list<GodFantome>::const_iterator itGod;
    int x, y;

    // Taille des cases en pixels
    int largeurCase, hauteurCase;

    largeurCase = pixmapMur.width();
    hauteurCase = pixmapMur.height();

    // Dessine les cases
    for (y=0;y<jeu.getNbCasesY();y++)
        for (x=0;x<jeu.getNbCasesX();x++)
			if (jeu.getCase(x,y)==MUR)
                painter.drawPixmap(x*largeurCase, y*hauteurCase, pixmapMur);

    // Dessine les fantomes
    for (itFantome=jeu.fantomes.begin(); itFantome!=jeu.fantomes.end(); itFantome++)
        painter.drawPixmap(itFantome->getPosX()*largeurCase, itFantome->getPosY()*hauteurCase, pixmapFantome);

    // Dessine les gods
    for (itGod=jeu.godFantomes.begin(); itGod!=jeu.godFantomes.end(); itGod++)
        painter.drawPixmap(itGod->getPosX()*largeurCase, itGod->getPosY()*hauteurCase, pixmapGod);

	// Dessine Pacman
	painter.drawPixmap(jeu.pacmanA.getPosX()*largeurCase, jeu.pacmanA.getPosY()*hauteurCase, pixmapPacman);
	if (jeu.getNombreJoueur() == 2)
        painter.drawPixmap(jeu.pacmanB.getPosX()*largeurCase, jeu.pacmanB.getPosY()*hauteurCase, pixmapPacman);

}

void Mainwnd::PacmanWindow::keyPressEvent(QKeyEvent *event)
{

    if (event->key()==Qt::Key_Left)
        jeu.deplacePacman(jeu.pacmanA,GAUCHE);
    else if (event->key()==Qt::Key_Right)
        jeu.deplacePacman(jeu.pacmanA,DROITE);
    else if (event->key()==Qt::Key_Up)
        jeu.deplacePacman(jeu.pacmanA,HAUT);
    else if (event->key()==Qt::Key_Down)
        jeu.deplacePacman(jeu.pacmanA,BAS);

    if (jeu.getNombreJoueur() == 2)
        if (event->key()==Qt::Key_A)
            jeu.deplacePacman(jeu.pacmanB,GAUCHE);
        else if (event->key()==Qt::Key_D)
            jeu.deplacePacman(jeu.pacmanB,DROITE);
        else if (event->key()==Qt::Key_W)
            jeu.deplacePacman(jeu.pacmanB,HAUT);
        else if (event->key()==Qt::Key_S)
            jeu.deplacePacman(jeu.pacmanB,BAS);
    //Pacman mange un Fantom
//    for(auto it = jeu.fantomes.begin(); it != jeu.fantomes.end(); it++){
//        if(it->getPosX() == jeu.getPacmanX() && it->getPosY() == jeu.getPacmanY())
//            jeu.fantomes.erase(it);
//    }
    update();
}

void Mainwnd::PacmanWindow::handleTimer()
{
    jeu.evolue();
    repaint();
}

void Mainwnd::PacmanWindow::handleCountdown()
{
    if (countdown.second() != 1)
        countdown = countdown.addSecs(-1);
    else
        countTime->stop();
    label_countdown->setText(countdown.toString("m:ss"));
}


//void Mainwnd::PacmanWindow::ajoutFantome()
//{
//    Fantome f;
//    int x, y;
//    Direction dir;
//    // Initialize random position et direction
//}
//
//void Mainwnd::PacmanWindow::supprFantome()
//{
//    if (!jeu.fantomes.empty())
//        jeu.fantomes.pop_back();
//}



// Classe PacmanButton
PacmanButton::PacmanButton(QWidget *parent) : QPushButton(parent) { }

void PacmanButton::keyPressEvent(QKeyEvent *e)
{
    if(parent() != NULL)
        QCoreApplication::sendEvent(parent(), e);
}

