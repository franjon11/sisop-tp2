#include "../includes.h"
#include "../Sem-SV/sv_sem.h"

int main() {

    // Creo el Area 51
    sv_shm a51(AREA51);
    cout<<"<== Area 51 Inicializada ==>"<<endl;

    // Creo los semaforos
    cout<<"<== Inicializando los semaforos ==>"<<endl;
	sv_sem balsa(SEM_BALSA,INI_BALSA);
    cout<<"< Inicializado el semaforo "<<SEM_BALSA<<" con ini "<<INI_BALSA<<" >"<<endl;

	sv_sem mutex(SEM_MUTEX,INI_MUTEX);
    cout<<"< Inicializado el semaforo "<<SEM_MUTEX<<" con ini "<<INI_MUTEX<<" >"<<endl;

    sv_sem nerfs(SEM_NERFS,INI_NERFS);
    cout<<"< Inicializado el semaforo "<<SEM_NERFS<<" con ini "<<INI_NERFS<<" >"<<endl;

    sv_sem serfs(SEM_SERFS,INI_SERFS);
    cout<<"< Inicializado el semaforo "<<SEM_SERFS<<" con ini "<<INI_SERFS<<" >"<<endl;

	cout<<"<== Semaforos inicializados ==>"<<endl;
}
