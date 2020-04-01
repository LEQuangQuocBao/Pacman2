#include <iostream>
#include "pacmanwindow.h"

using namespace std;

PacmanWindow::PacmanWindow(QWidget *pParent, Qt::WindowFlags flags):QFrame(pParent, flags)
{
    // Taille des cases en pixels
    int largeurCase, hauteurCase;

    if (pixmapPacman.load("./data/pacman.bmp")==false)
    {
        cout<<"Impossible d'ouvrir pacman.png"<<endl;
        exit(-1);
    }

    if (pixmapFantome.load("./data/fantome.bmp")==false)
    {
        cout<<"Impossible d'ouvrir fantome.bmp"<<endl;
        exit(-1);
    }

    if (pixmapGod.load("./data/godFantome.png")==false)
    {
        cout<<"Impossible d'ouvrir god fantome.bmp"<<endl;
        exit(-1);
    }

    if (pixmapMur.load("./data/mur.bmp")==false)
    {
        cout<<"Impossible d'ouvrir mur.bmp"<<endl;
        exit(-1);
    }

    largeurCase = pixmapMur.width();
    hauteurCase = pixmapMur.height();

    resize(jeu.getNbCasesX()*largeurCase*2, jeu.getNbCasesY()*hauteurCase);

}

void PacmanWindow::configurer(int nJoueur, int nFantome, int vit, int mode)
{
    jeu.setInfoJeu(nJoueur,nFantome,vit, mode);
    jeu.init();
}

void PacmanWindow::startJeu()
{
    QTimer *timer = new QTimer(this);
    connect(timer, QTimer::timeout, this, PacmanWindow::handleTimer);
    timer->start(jeu.getVitesse());

    label_countdown = new QLabel("0:10", this);
    label_countdown->setGeometry(QRect(QPoint(900, 45), QSize(130, 50)));
    label_countdown->setFont(QFont("Arial", 30));

    countdown.setHMS(0,0,10,0);
    QTimer *time = new QTimer(this);
    connect(time, QTimer::timeout, this, PacmanWindow::handleCountdown);
    time->start(1000);

}


void PacmanWindow::paintEvent(QPaintEvent *e)
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

void PacmanWindow::keyPressEvent(QKeyEvent *event)
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

void PacmanWindow::handleTimer()
{
    jeu.evolue();
    repaint();
}

void PacmanWindow::handleCountdown()
{
    if (countdown.second() != 0)
        countdown = countdown.addSecs(-1);
    else
        //close();
    label_countdown->setText(countdown.toString("m:ss"));
}


void PacmanWindow::ajoutFantome()
{
    Fantome f;
    int x, y;
    Direction dir;
    // Initialize random position et direction
}

void PacmanWindow::supprFantome()
{
    if (!jeu.fantomes.empty())
        jeu.fantomes.pop_back();
}

// Classe PacmanButton
PacmanButton::PacmanButton(QWidget *parent) : QPushButton(parent) { }

void PacmanButton::keyPressEvent(QKeyEvent *e)
{
    if(parent() != NULL)
        QCoreApplication::sendEvent(parent(), e);
}

