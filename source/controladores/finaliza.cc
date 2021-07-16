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
    
	sv_shm a51(AREA51);
	sv_sem balsa(SEM_BALSA);

	Area* area;
	area = static_cast <Area*>(a51.map(sizeof(Area)));
	area->setFin();
	balsa.post();

	cout<<"Marcado el Fin"<<endl;
}
