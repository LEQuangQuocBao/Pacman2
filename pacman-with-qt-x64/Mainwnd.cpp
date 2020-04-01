#include <iostream>
#include "Mainwnd.h"
#include "bienvenuewindow.h"
#include "pacmanwindow.h"
#include "joueurwindow.h"


using namespace std;

Mainwnd::Mainwnd(QWidget* pparent) : QMainWindow(pparent){
    a = new bienvenuewindow();
    b = new Joueur();
    c = new PacmanWindow();
    setCentralWidget(a);
}

void Mainwnd::changeEcran(int ab){
    switch (ab){
        case 1: setCentralWidget(a);
                connect(a->oneP,QPushButton::clicked, this, close);
                break;
        case 2: setCentralWidget(b);
                break;
    }

}
