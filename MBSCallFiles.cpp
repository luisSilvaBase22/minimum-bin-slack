//Trabajando recientemente 04.04.2017
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <cstdlib>

#include <fstream>
#include <time.h>
#include "Instancia.h"
#include "HeuristicaMBS2.h"

using namespace std;

int main()
{
    cout << "MBS" << endl;
    
	int i, j, c;
	vector < vector <int> > contenedoresMBS;
	vector <int> listaIn;
	
	char nombre[50], nomF[50], nomInstancia[50], nomDirectorio[50];
	ofstream salida;		
	ifstream entrada;
	
	// Variables para calcular y mostrar TIEMPO
	float calculatedTime;
	clock_t	start, end;
	
	strcpy(nomDirectorio, "");
	//**********************************************************************************
	//********* CAMBIR LAS SIGUIENTES LINEAS PARA ACCEDER A RUTA DE LAS INSTANCIAS ***
	strcpy(nomDirectorio, "53NIRUP/");//<---CARPETA
	cout << nomDirectorio << endl;
	entrada.open("53NIRUP/instanciasPrueba");//<----CARPETA Y archivo plano con nombre de instancias
	
	//***********************************  FIN DEL COMENTARIO ***************************
	//***********************************************************************************
	//comeIn/instanciasArticulo
	//comeIn/isntancias2
    do{
	strcpy(nomF, "");
	strcpy(nombre, "");
	strcpy(nomInstancia, "");
	
    entrada.getline(nomInstancia, 50);
	//cout << entrada << endl;
    strcat(nomF, nomDirectorio );
	strcat(nomF, nomInstancia);
	cout << "Archivo: " << nomInstancia << endl;
	if ( ! entrada) {
		cout << "No se ha podido abrir el fichero";  exit(1);
	}
			// Lectura de los datos de la instancia 
	//		cout << " Nombre de la instancia : " << nomF;
	
	//char nomF[50] = "Entrada";
	
    listaIn = Util::leeInstancia(nomF, &c);
	Instancia ins(nomF, listaIn, c);
	HeuristicaMBS2 heu(ins);
	//HeuristicaMBS heu(listaIn);
	
	//cout << "Minimum Bin Slack \n";
	start = clock();
	
	contenedoresMBS = heu.algoritmoMBS();
	
    end = clock();
	calculatedTime = (end - start) / (CLK_TCK * 1.0);
	
	cout << "Contenedores \n";
	
	for(i = 0; i < contenedoresMBS.size(); i++)
	{
          for(j = 0; j < contenedoresMBS.at(i).size(); j++)
          {
                cout << "-->" <<contenedoresMBS.at(i).at(j);
          }
		cout << "\n";
	}
	
	cout << "Numero de contenedores utilizados: " << contenedoresMBS.size() << "\n" << endl;
	cout << "Tiempo de solucion: " << calculatedTime << endl;
	//getchar();
}
while(!entrada.eof());

	cout << "Pulse cualquier tecla para terminar...";
	getchar();
}

