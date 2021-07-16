#include "../includes.h"
#include "../Area.h"
#include "../Sem-SV/sv_shm.h"
#include "../Sem-SV/sv_sem.h"

int main(){

	sv_shm a51(AREA51);
	sv_sem balsa(SEM_BALSA);

	Area* area;
	area = static_cast <Area*>(a51.map(sizeof(Area)));
	area->setFin();
	balsa.post();

	cout<<"Marcado el Fin"<<endl;
}
