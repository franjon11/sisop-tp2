#ifndef INCLUDES_H
#define INCLUDES_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

#define CLAVE "/home"

#define AREA51 "Area51"

#define SEM_BALSA "A51_balsa"
#define INI_BALSA 0

#define SEM_MUTEX "A51_mutex"
#define INI_MUTEX 1

#define SEM_NERDS "A51_nerds"
#define INI_NERDS 0

#define SEM_SERFS "A51_serfs"
#define INI_SERFS 0


using namespace std;

void print_integrantes(){

    cout<<"Integrantes TP2"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Nasif Francisco José - 101044"<<endl;
    cout<<"Hejeij Agustín - 102324"<<endl;
    cout<<"Jacinto Renzo - 100627"<<endl;
    cout<<"Fanciotti Tomás - 102179"<<endl;
    cout<<"------------------------"<<endl;

}								

#endif
