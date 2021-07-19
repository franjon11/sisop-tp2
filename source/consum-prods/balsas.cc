/*
###################INTEGRANTES - TP2#################
#     Nombre y apellido     -         Padrón        #
-----------------------------------------------------
# Nasif Francisco José      -         101044        #
# Hejeij Agustin            -                       #
# Jacinto Renzo             -                       #
# Fanciotti Tomas           -         102179        #
#####################################################
*/


#include "../includes/includes.h"
#include "../includes/Area.h"
#include "../includes/sv_shm.h"
#include "../includes/sv_sem.h"

int main(){

    print_integrantes();
    
    // Area 
    Area* area;
    sv_shm a51(AREA51);
    area = static_cast <Area*>(a51.map(sizeof(Area)));

    // Semaforos
    sv_sem balsa(SEM_BALSA);
    sv_sem mutex(SEM_MUTEX);
    sv_sem nerds(SEM_NERDS);
    sv_sem serfs(SEM_SERFS);

    Mensaje dato;
    string rta;
    cout<<"Ingresa algo pa"<<endl;
    while (cin>>rta){

        balsa.wait();
        if (area->esFin()) break;

        mutex.wait();
        dato=area->saca();
        mutex.post();
  
        cout<<"leido: <"<<dato.getDato()<<">"<<endl;
        nerds.post();
        serfs.post();
    }             
    balsa.post();  //libera en cadena a los consumidores
    cout<<"nom"<<" termina"<<endl; //TODO: "nom" hecho string por error "undelcared identifier"
}
