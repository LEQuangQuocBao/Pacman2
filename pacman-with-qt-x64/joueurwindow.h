#ifndef ONEPLAYERWINDOW_H
#define ONEPLAYERWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
//#include "jeu.h"
#include <string>
#include "Mainwnd.h"

using namespace std;

class Mainwnd::joueurWindow : public QFrame{

  public:
    joueurWindow(QWidget* pparent=0, Qt::WindowFlags flags=0);
    void configurer();

//    void handleCommence();
    //void handleRetourne();
    //void handleCommence();

    int getVitesse()
    {
        return (labelVT->text()).toInt();
    }

    int getNombreFantomes()
    {
        return (labelNF->text()).toInt();
    }

    string getName1()
    {
        if ((name1.text()).toStdString()=="")
            return (name1.placeholderText()).toStdString();
        else
            return (name1.text()).toStdString();
    }

    string getName2()
    {
        if ((name2.text()).toStdString()=="")
            return (name2.placeholderText()).toStdString();
        else
            return (name2.text()).toStdString();
    }

    void setNombre(int a){
        nombreJoueur = a;
    }

    int getNombre(){
        return nombreJoueur;
    }


    int getNumMode(){
        return (labelMO->text()).toInt();
    }

    public:
    QLineEdit name1;
    QLineEdit name2;
    QLabel *labelNF;
    QLabel *labelVT;
    QLabel *labelMO;
    int numeroMode;
    int nombreJoueur;
    QPushButton *btnCommence;
    QPushButton *btnRetourne;

};


#endif
