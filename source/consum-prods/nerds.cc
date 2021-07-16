/*
###################INTEGRANTES - TP2#################
#     Nombre y apellido     -         Padrón        #
-----------------------------------------------------
# Nasif Francisco José      -         101044        #
# Hejeij Agustin            -                       #
# Jacinto Renzo             -                       #
# Fanciotti Tomas           -                       #  
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
    a= static_cast <Area*>(a51.map(sizeof(Area)));
    
    // Semaforos
    sv_sem nerfs(SEM_NERFS,INI_NERFS);
    sv_sem cons(SEM_BALSA,INI_BALSA);
    sv_sem mutex(SEM_MUTEX,INI_MUTEX);

    string lee;
    cout<<"Ingrese un string"<<endl;
    while (cin>>lee){

        nerfs.wait();
        cout<<"-- poniendo "<<lee<<endl;

        mutex.wait();
        cout<<"en el mutex ..."<<endl;
        a->pone(Mensaje (lee));
        mutex.post();

        balsa.post();
    }
    cout<<" terminado"<<endl;
}

