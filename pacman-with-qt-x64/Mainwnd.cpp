#include <iostream>
#include "Mainwnd.h"
#include "bienvenuewindow.h"
#include "pacmanwindow.h"
#include "joueurwindow.h"


using namespace std;

Mainwnd::Mainwnd(QWidget* pparent) : QMainWindow(pparent){
    init_bienvenueWnd();
    setCentralWidget(bienvenueWnd);

//    PacmanButton *b = new PacmanButton(pacmanWnd);

    QPixmap newpix("./data/newGame.png");
    QPixmap openpix("open.png");
    QPixmap quitpix("./data/quit.png");

    QAction *nouveauJeu = new QAction(newpix, "&Nouveau Jeu", this);
    QAction *open = new QAction(openpix, "&...", this);
    QAction *fermer = new QAction(quitpix, "&Fermer", this);
    fermer->setShortcut(tr("CTRL+Q"));

    QMenu *file;
    file = menuBar()->addMenu("&Option");
    file->addAction(nouveauJeu);
    file->addAction(open);
    file->addSeparator();
    file->addAction(fermer);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(fermer, &QAction::triggered, this, close);

    resize(800, 500);
}

void Mainwnd::keyPressEvent(QKeyEvent *e){
    pacmanWnd->keyPressEvent(e);
}

void Mainwnd::init_bienvenueWnd(){

    bienvenueWnd = new bienvenuewindow();
    //les signaux et les slots pour bienvenueWnd
    connect(bienvenueWnd->btnUnJoueur,QPushButton::clicked, this, handleUnJoueur);
    connect(bienvenueWnd->btnDeuxJoueur,QPushButton::clicked, this, handleDeuxJoueur);
    connect(bienvenueWnd->btnSortie,QPushButton::clicked, this, close);
}

void Mainwnd::init_caractWnd(int nombreJoueur){

    caractWnd = new joueurWindow();
    caractWnd->setNombre(nombreJoueur);
    caractWnd->configurer();
    //les signaux et les slots pour caractWnd
    connect(caractWnd->btnCommence,QPushButton::clicked, this, handleCommence);
    connect(caractWnd->btnRetourne,QPushButton::clicked, this, handleRetourne);
}

void Mainwnd::init_pacmanWnd(int nJoueur, int nFantome, int vit, int mode){
    pacmanWnd = new PacmanWindow();
    pacmanWnd->configurer(nJoueur,nFantome,vit,mode);
    pacmanWnd->startJeu();
}

void Mainwnd::handleUnJoueur(){
    init_caractWnd(1);
    setCentralWidget(caractWnd);
}

void Mainwnd::handleDeuxJoueur(){
    init_caractWnd(2);
    setCentralWidget(caractWnd);
}

void Mainwnd::handleCommence(){
    init_pacmanWnd(caractWnd->getNombre(),caractWnd->getNombreFantomes(),caractWnd->getVitesse(),caractWnd->getNumMode());
    setCentralWidget(pacmanWnd);
}

void Mainwnd::handleRetourne(){
    init_bienvenueWnd();
    setCentralWidget(bienvenueWnd);
}



void Mainwnd::changeEcran(int ab){
    switch (ab){
        case 1: setCentralWidget(bienvenueWnd);
                //connect(bienvenueWnd->,QPushButton::clicked, this, close);
                break;
//        case 2: setCentralWidget(b);
//                break;
    }

}
