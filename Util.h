//Trabajando recientemente 04.04.2017
#include <vector>
#include <stdlib.h>
#ifndef zonaU
class Util {
public:
	static int pertenece(int a, vector<int> conjunto); 
	static vector<int> NmenosFconElementosRepetidos(vector<int> N, vector<int> F);
	static vector<int> leeInstancia (char nn[], int *C);
	static void escribeValoresArreglo(string cadena, vector<int> valo);
	static vector<int> obtieneObjetosFijos(vector< vector < int > > contenedoresFFD, int peq, int Cap, vector<int> *numCon);
	static vector<int> obtieneObjetosFijos(vector< vector < int > > contenedoresFFD);
	static vector< vector <int> > contenedoresMasContenedoresFFD(vector< vector <int> > contenedores, vector< vector <int> > contenedoresFFD, vector <int> numCon);
	static vector< vector <int> > contenedoresMasContenedoresFFD(vector< vector <int> > contenedores, vector< vector <int> > contenedoresFFD);
	static vector<int> subconjuntoAaB(int a, int b, int nsob, vector<int> wsob);
	static vector<int> eliminaUnos(vector<int> wsob, int *nUnos);
	static vector<int> obtienePesosContenedores(vector< vector < int > > co);
	static vector< vector < int > > agregarUnos(vector< vector < int > > conte, int num1, int Cap);
};

int Util::pertenece(int a, vector<int> conjunto){
	int i;
	
	for(i=0; i<(int)conjunto.size(); i++)
		if (conjunto.at(i)==a) return i;
	return -1;
}
 vector<int> Util::NmenosFconElementosRepetidos(vector<int> N, vector<int> F){
	int i, pos;
	
	for(i=0; i<(int)F.size(); i++) {
		if((pos=pertenece(F.at(i), N))!=-1)
			N.erase(N.begin()+pos);			
	}	
	return N;
}

vector<int> Util::leeInstancia (char nombre[], int *C) {
	ifstream leer_fich (nombre);
	int dato;
	vector<int> pObj;
	
	pObj.clear();
	*C=0;
	if ( ! leer_fich) {
		cout << "No se ha podido abrir el fichero";  exit(1);
	}
	else {
			leer_fich >> dato;
			if (! leer_fich.eof()) {
				leer_fich >> dato;
				*C=dato;
			}
			do {
				dato=-1;
				leer_fich >> dato;
				if (dato != -1) { 
					pObj.push_back(dato);
				}
			}while(! leer_fich.eof() );
	}
	return pObj;
}

void Util::escribeValoresArreglo(string cadena, vector<int> valo){
	int i=0;
	
	cout << cadena << endl;
	for(;i<(int)valo.size(); i++)
		cout << "Valores:" << valo[i] <<endl;
	cout << endl;
getchar();
}

vector<int> Util::obtieneObjetosFijos(vector< vector < int > > contenedoresFFD, int peq, int Cap, vector<int> *numCon){
	int i,j, suma=0, por=0;
	vector<int> wsob;
	
	(*numCon).clear();
	wsob.clear();
	por=Cap*2/100; // No se usa esta variable, hay que revisar si es conveniente usarla o no
	for(i=0; i<(int)contenedoresFFD.size(); i++) {		
		for(j=0; j<(int)contenedoresFFD.at(i).size(); j++) {
			suma+=contenedoresFFD.at(i).at(j);
			if (contenedoresFFD.at(i).at(j) < 100) por=1;
		}
		if ((Cap-suma) < 1 &&  (int)contenedoresFFD.at(i).size() < 4 && por==0) { 
			(*numCon).push_back(i);
			for(j=0; j<(int)contenedoresFFD.at(i).size(); j++)
				wsob.push_back(contenedoresFFD.at(i).at(j));
		}
		suma=0;   por=0;
	}
	return wsob;
}

vector<int> Util::obtieneObjetosFijos(vector< vector < int > > contenedoresFFD){
	int i,j;
	vector<int> wsob;
	
	wsob.clear();
	for(i=0; i<(int)contenedoresFFD.size(); i++) {		
		for(j=0; j<(int)contenedoresFFD.at(i).size(); j++) {
			wsob.push_back(contenedoresFFD.at(i).at(j));
		}
	}
	return wsob;
}


vector< vector <int> > Util::contenedoresMasContenedoresFFD(vector< vector <int> > contenedores, vector< vector <int> > contenedoresFFD, vector <int> numCon){
	vector< vector <int> > contenedoresF;
	int i;
	
	contenedoresF.clear();
	for(i=0; i<(int)numCon.size(); i++)
		if ((int)contenedoresFFD.at(numCon.at(i)).size() != 0)
			contenedoresF.push_back(contenedoresFFD.at(numCon.at(i)));
	for(i=0; i<(int)contenedores.size(); i++)
		if ((int)contenedores.at(i).size() != 0)
			contenedoresF.push_back(contenedores.at(i));
	return contenedoresF;
}

vector< vector <int> > Util::contenedoresMasContenedoresFFD(vector< vector <int> > contenedores, vector< vector <int> > contenedoresFFD){
	vector< vector <int> > contenedoresF;
	int i;
	
	contenedoresF.clear();
	for(i=0; i<(int)contenedoresFFD.size(); i++)		
		contenedoresF.push_back(contenedoresFFD.at(i));
	for(i=0; i<(int)contenedores.size(); i++)
		contenedoresF.push_back(contenedores.at(i));
	return contenedoresF;
}

vector<int> Util::subconjuntoAaB(int a, int b, int nsob, vector<int> wsob){	
	vector<int> auxiliar;
	int i;
	
	auxiliar.clear();
	for(i=0; i<nsob; i++) {
		if (wsob.at(i) <= b && wsob.at(i) >= a)
			auxiliar.push_back(i);
	}
	
	return auxiliar;
}

vector<int> Util::eliminaUnos(vector<int> wsob, int *nUnos) {
   vector<int> SinUnos;
   int i, j;
   
   SinUnos.clear();
   for(i=0, j=(int)wsob.size(); i<(int)wsob.size(); i++) {
	   if (wsob.at(i)!=1) {
		SinUnos.push_back(wsob.at(i));
		j--;
	   }
   }
   (*nUnos)=j;
   return SinUnos;
}

vector<int> Util::obtienePesosContenedores(vector< vector < int > > co) {
	vector<int> pC;
	int i,j;
	
	pC.clear();
	pC.resize((int)co.size());
	for(i=0; i<(int)co.size(); i++) {
		pC.at(i)=0;
		for(j=0; j<(int)co.at(i).size(); j++)
			pC.at(i)+=co.at(i).at(j);
	}
	return pC;
}

vector< vector < int > > Util::agregarUnos(vector< vector < int > > conte, int num1, int Cap){
	vector< vector < int > > contenedores;
	vector<int> pesosBs;
	int i,j,k;
	
	contenedores.clear();
	contenedores=conte;
	pesosBs=obtienePesosContenedores(conte);
	k=0;
	for(i=0; i<(int)contenedores.size(); i++) {
		j=pesosBs.at(i);
		while (j<Cap && k<num1) {
			contenedores.at(i).push_back(1);
			j++;  k++;
		}
	}
	return contenedores;
}	
#define zonaU
#endif
