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
#include "../includes/sv_sem.h"
#include "../includes/sv_shm.h"

int main() {

    print_integrantes();

    // Creo el Area 51
    sv_shm a51(AREA51);
    cout<<"<== Area 51 Inicializada ==>"<<endl;

    // Creo los semaforos
    cout<<"<== Inicializando los semaforos ==>"<<endl;
	sv_sem balsa(SEM_BALSA,INI_BALSA);
    cout<<"< Inicializado el semaforo "<<SEM_BALSA<<" con ini "<<INI_BALSA<<" >"<<endl;

	sv_sem mutex(SEM_MUTEX,INI_MUTEX);
    cout<<"< Inicializado el semaforo "<<SEM_MUTEX<<" con ini "<<INI_MUTEX<<" >"<<endl;

    sv_sem nerfs(SEM_NERDS, INI_NERDS);
    cout << "< Inicializado el semaforo " << SEM_NERDS << " con ini " << INI_NERDS << " >" << endl;

    sv_sem serfs(SEM_SERFS,INI_SERFS);
    cout<<"< Inicializado el semaforo "<<SEM_SERFS<<" con ini "<<INI_SERFS<<" >"<<endl;

	cout<<"<== Semaforos inicializados ==>"<<endl;
}
