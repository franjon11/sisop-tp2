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
#include "../includes/Balsas.h"
#include "../includes/sv_shm.h"
#include "../includes/sv_sem.h"


int main(){

    print_integrantes();
    
    // Area
    Balsas* balsa;
    sv_shm a51(AREA51);
    balsa= reinterpret_cast<Balsas*>(a51.map(sizeof(Balsas)));
    
    // Semaforos
    sv_sem mutex(SEM_MUTEX);
    sv_sem semaforo_nerds(SEM_NERDS);
    sv_sem semaforo_serfs(SEM_SERFS);

    mutex.wait();

    balsa->addNerd();
    switch (balsa->ready()) {

        case FULL_OF_NERDS:

            cout << "Balsa llena: FULL_OF_NERDS" << endl;

            balsa->removeNerd(4);
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_nerds.post();
            break;

        case FULL_OF_SERFS:

            cout << "Balsa llena: FULL_OF_SERFS" << endl;

            balsa->removeSerf(4);
            semaforo_serfs.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            break;

        case NERDS_AND_SERFS:

            cout << "Balsa llena: NERDS_AND_SERFS" << endl;

            balsa->removeNerd(2);
            balsa->removeSerf(2);
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            break;

        case BALSA_NOT_READY:
            cout << "La balsa no está lista. Integrantes: " << balsa->getNerds() << " nerds y " << balsa->getSerfs() << " serfs." << endl;
            break;
    }

    mutex.post();
    semaforo_nerds.wait();

    cout << "El proceso asociado a este NERD, partió en una balsa." << endl;
}

