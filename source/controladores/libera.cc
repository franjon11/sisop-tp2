/*
###################INTEGRANTES - TP2#################
#     Nombre y apellido     -         Padrón        #
-----------------------------------------------------
# Nasif Francisco José      -         101044        #
# Hejeij Agustin            -         102324        #
# Jacinto Renzo             -         100627        #
# Fanciotti Tomas           -         102179        #
#####################################################
*/


#include "../includes/includes.h"
#include "../includes/Area.h"
#include "../includes/sv_shm.h"
#include "../includes/sv_sem.h"

int main(){

    print_integrantes();
    
    sv_shm a51(AREA51);
    sv_sem balsa(SEM_BALSA);
    sv_sem mutex(SEM_MUTEX);
    sv_sem nerfs(SEM_NERDS);
    sv_sem serfs(SEM_SERFS);

    cout<<"<== Liberando el area ==>"<<endl;
    a51.del();
    cout<<"< Liberado el area "<<SEM_BALSA<<" >"<<endl;
    cout<<"<== Area liberada ==>"<<endl;
    
    cout<<"<== Liberando los semaforos ==>"<<endl;
    balsa.del();
    cout<<"< Liberado el semaforo "<<SEM_BALSA<<" >"<<endl;
    mutex.del();
    cout<<"< Liberado el semaforo "<<SEM_MUTEX<<" >"<<endl;
    nerfs.del();
    cout << "< Liberado el semaforo " << SEM_NERDS << " >" << endl;
    serfs.del();
    cout<<"< Liberado el semaforo "<<SEM_SERFS<<" >"<<endl;
    

    cout<<"<==  Todos los semaforos fueron liberados ==>"<<endl;
}
