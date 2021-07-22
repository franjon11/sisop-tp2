#ifndef _QUEUE_H
#define _QUEUE_H

#include "includes.h"

#define QUEUE_NOT_READY 0
#define FULL_OF_NERDS 1
#define FULL_OF_SERFS 2
#define NERDS_AND_SERFS 3

class Queue{
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


void Queue::addNerd(){
    nerds++;
    cout << "Se añade un nerd a la fila" << endl;
}

void Queue::addSerf(){
    serfs++;
    cout << "Se añade un serf a la fila" << endl;
}

int Queue::getNerds() {
    return nerds;
}

int Queue::getSerfs() {
    return serfs;
}

void Queue::removeNerd(int n) {
    if(nerds >= n ) { nerds -= n; cout << "Suben "<< n << " nerds a la balsa." << endl;}
}

void Queue::removeSerf(int n) {
    if(serfs >= n ) { serfs -= n; cout << "Suben "<< n << " serfs a la balsa." << endl; }
}

int Queue::ready() {

    if ( serfs >= 4 ){
        return FULL_OF_SERFS;
    } else if (nerds >= 4){
        return FULL_OF_NERDS;
    } else if ( nerds >= 2 && serfs >= 2 ) {
        return NERDS_AND_SERFS;
    } else {
        return QUEUE_NOT_READY;
    }
}

#endif

