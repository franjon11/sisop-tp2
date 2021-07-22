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
#include "../includes/Queue.h"
#include "../includes/sv_shm.h"
#include "../includes/sv_sem.h"


int main(){

    print_integrantes();
    
    // Area
    Queue* fila;
    sv_shm a51(AREA51);
    fila= reinterpret_cast <Queue*>(a51.map(sizeof(Queue)));
    
    // Semaforos
    sv_sem mutex(SEM_MUTEX);
    sv_sem semaforo_nerds(SEM_NERDS);
    sv_sem semaforo_serfs(SEM_SERFS);

    mutex.wait();

    fila->addSerf();
    switch (fila->ready()) {

        case FULL_OF_NERDS:

            cout << "Balsa FULL_OF_NERDS" << endl;

            fila->removeNerd(4);
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_nerds.post();
            break;

        case FULL_OF_SERFS:

            cout << "Balsa FULL_OF_SERFS" << endl;

            fila->removeSerf(4);
            semaforo_serfs.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            break;

        case NERDS_AND_SERFS:

            cout << "Balsa NERDS_AND_SERFS" << endl;

            fila->removeNerd(2);
            fila->removeSerf(2);
            semaforo_nerds.post();
            semaforo_nerds.post();
            semaforo_serfs.post();
            semaforo_serfs.post();
            break;

        case QUEUE_NOT_READY:
            cout << "La balsa no está lista. Integrantes: " << fila->getNerds() << " nerds y " << fila->getSerfs() << " serfs." << endl;
            break;
    }

    mutex.post();
    semaforo_serfs.wait();

    cout << "El proceso asociado a este SERF, partió en una balsa." << endl;
}
