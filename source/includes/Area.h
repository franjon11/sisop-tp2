#ifndef Area_h
#define Area_h

#include "Mensaje.h"

class Area{
	public:
		static const int size =5;
	private:
		Mensaje  ms [size];
		bool finalizo=false;
		int ip=0;
		int is=0;
		int iPone();
		int iSaca();
	public:
		Area(){ cout<<"Construida un Area"<<endl;};
		Mensaje & operator [] (int i);
		void pone(Mensaje m);
		Mensaje saca();
		void setFin();
		bool esFin();
};

int Area::iPone(){
	int aux=ip;
	ip=(ip+1)%size;
	return aux;
}

int Area::iSaca(){
	int aux=is;
	is=(is+1)%size;
	return aux;
}
void Area::pone(Mensaje m){
	ms[iPone()]=m;
}

Mensaje Area::saca(){
	Mensaje m=ms[iSaca()];
	return m;
}	
void Area::setFin(){					
	finalizo=true;
}

bool Area::esFin() {
	return finalizo;
}

#endif
