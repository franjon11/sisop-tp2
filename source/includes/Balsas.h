#ifndef _BALSA_H
#define _BALSA_H

#include "includes.h"

#define BALSA_NOT_READY 0
#define FULL_OF_NERDS 1
#define FULL_OF_SERFS 2
#define NERDS_AND_SERFS 3

class Balsas{
private:
    int nerds = 0;
    int serfs = 0;

public:
    int getNerds();
    int getSerfs();

    void addNerd();
    void addSerf();
    void removeNerd(int n=1);
    void removeSerf(int n=1);

    int ready();
};


void Balsas::addNerd(){
    nerds++;
    cout << "Se añade un nerd" << endl;
}

void Balsas::addSerf(){
    serfs++;
    cout << "Se añade un serf" << endl;
}

int Balsas::getNerds() {
    return nerds;
}

int Balsas::getSerfs() {
    return serfs;
}

void Balsas::removeNerd(int n) {
    if(nerds >= n ) { nerds -= n; cout << "Se eliminan "<< n << " nerds de la balsa." << endl;}
}

void Balsas::removeSerf(int n) {
    if(serfs >= n ) { serfs -= n; cout << "Se eliminan "<< n << " serfs de la balsa." << endl; }
}

int Balsas::ready() {

    if ( serfs >= 4 ){
        return FULL_OF_SERFS;
    } else if (nerds >= 4){
        return FULL_OF_NERDS;
    } else if ( nerds >= 2 && serfs >= 2 ) {
        return NERDS_AND_SERFS;
    } else {
        return BALSA_NOT_READY;
    }
}

#endif

