#include <iostream>
#include "bienvenuewindow.h"
//#include "pacmanwindow.h"
//#include "joueurwindow.h"

using namespace std;

Mainwnd::bienvenuewindow::bienvenuewindow(QWidget* pparent, Qt::WindowFlags flags) : QFrame(pparent, flags){

    vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);

    btnUnJoueur = new QPushButton("Un Joueur", this);
    btnUnJoueur->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnDeuxJoueur = new QPushButton("Deux Joueur", this);
    btnDeuxJoueur->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnMarque = new QPushButton("Meilleur Marque", this);
    btnMarque->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btnSortie = new QPushButton("Sortie", this);
    btnSortie->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vbox->addWidget(btnUnJoueur);
    vbox->addWidget(btnDeuxJoueur);
    vbox->addWidget(btnMarque);
    vbox->addWidget(btnSortie);

    setLayout(vbox);
}

