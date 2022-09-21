//#include <stdio.h>
//#include <iostream>
//#include <vector>
#include "Util.h"

#ifndef zonaH
//using namespace std;

class HeuristicaMBS
{
	Instancia ins;
	vector < vector <int > > contenedoresFinales;
	vector <int> listaZ;
	//vector <int> listaA;
	int k;
	int capacidadBin;
	int numeroItemsS;

public:
	HeuristicaMBS(Instancia i)
	{
		ins = i;
		listaZ = ins.obtienepObjetos();
		capacidadBin = ins.obtieneCapacidad();
		
		cout << "Propiedades de HMBS: \n";
		cout << capacidadBin << endl;
		cout << listaZ.size() << endl;
	}
	
	/*
	HeuristicaMBS(vector <int> vectorIn)
	{
		listaZ = vectorIn;
		capacidadBin = 17;
		
		cout << "Propiedades de HMBS: \n";
		cout << capacidadBin << endl;
	}
	*/
	int find1q(vector <int> listaPhi, int q, int j);
	int find2q(vector <int> listaPhi, int j);
	int sumaItemsA(vector <int> listaPhi);
	void eliminarItemsZ(vector <int> sk);
	vector <int> algoritmoL();
	vector < vector <int> > algoritmoMBS();

};

int HeuristicaMBS::find1q(vector <int> listaPhi, int q, int j)
{
	//if q == 0 && j == 0
	//q = 0
	//else
	if(q == 0 && j == 0)
	{
         q = 0;
    }
	else//ESTE IF SE VUELVE ELSE
	{
		q++;
		if(q == 8){
		cout << "ERROR: " << listaZ.at(q) << endl;
		getchar();
        }
		while(listaZ.at(q) != listaPhi.at(j))
		{
			q++;

			if(q == listaZ.size())
			{
				q = 0;
				break;
			}
		}
	}

	return q;
}

int HeuristicaMBS::find2q(vector <int> listaPhi, int j)
{
	int q = 0;

	while(listaZ.at(q) != listaPhi.at(j))
	{
		q++;
	}

	return q;
}

int HeuristicaMBS::sumaItemsA(vector <int> listaPhi)
{
	int i;
	int suma = 0;
	
	//cout << "Valor Phi: " << listaPhi.size() << endl;
	
	if(!listaPhi.empty())
	{
		for(i = 0; i < (int)listaPhi.size(); i++)
			suma = suma + listaPhi[i];
	}
	
	//cout << "Suma Phi: " << suma << endl;
	//getchar();
    return suma;
}

void HeuristicaMBS::eliminarItemsZ(vector <int> sk)
{
	vector <int> listaAuxiliar;
	int tamLista = sk.size();
	int i = 0, j = 0;

	while(i < listaZ.size())
	{
		while(j < sk.size())
		{
			if(listaZ.at(i) == sk.at(j))
			{
				i++;
				j++;
			}
			else
			{
				listaAuxiliar.push_back(listaZ.at(i));
				i++;
			}
		}

		if(j == sk.size()&&listaZ.size()>1)
		{
            if(listaZ.size()!=sk.size())
            {
                 listaAuxiliar.push_back(listaZ.at(i));
			     i++;
            }
		}
	}

	listaZ = listaAuxiliar;
	
	for(int x = 0; x < listaZ.size(); x++)
	cout << listaZ.at(x) << endl;
}

void eliminarAdelanteX(vector <int> phi, int j)
{
     int x = 0;
     if(j > 1 &&j < phi.size())
     {
     for(x = j; x < phi.size(); x++)
           phi.pop_back();
     }
}

vector <int> HeuristicaMBS::algoritmoL()//Este es el BUENO
{
	vector <int> contenedorFinal;
	vector <int> listaA;
	int slack = 0; //alpha
	int j = 0, q = 0;
	int s = listaZ.size();
	int ciclo = 0;

	listaA.insert(listaA.begin()+j, listaZ.at(q));
	//cout << "INICIO: " << listaA.at(j) << endl;

	while(sumaItemsA(listaA)!=capacidadBin)
	{
        cout << "Suma: " << sumaItemsA(listaA) << endl;
        getchar();                                   
        if( sumaItemsA(listaA) == 64 || sumaItemsA(listaA) == 52 )
        {
            for(int x = 0; x < listaA.size(); x++)
            cout << "A: " << listaA.at(x) << endl;
            getchar();
        }
        
        if( sumaItemsA(listaA) == 52 || sumaItemsA(listaA) == 66)
        {
            cout << "===> q: " << q << " j: " << j << " SIZE A: " << listaA.size() << "Z : " << listaZ.size() << endl; 
        }
        
		q = find1q(listaA, q, j);
		//cout << "Indice Q: " << q << endl;
		
		if(sumaItemsA(listaA)<capacidadBin)
		{//IF 1
			j++;
			if(sumaItemsA(listaA)>slack)
			{// IF2
				slack = sumaItemsA(listaA);
				contenedorFinal = listaA;
				cout << "SK1: " << contenedorFinal.size() << endl;
          }	
				while(q < s)//PASO 4
				{
					if(q < s - 1)
					{// IF ELSE 3
					//cout << " XXX: " << listaA.size() << endl;
					//cout << "ZZ: " << listaA.at(0) << endl;
                      //  if(listaA.size() > 1)
					    //    listaA.pop_back();
						listaA.insert(listaA.begin()+j, listaZ.at(q+1));
						//cout << "entradaA: " << listaA.at(j) << " j = " <<  j <<endl;
					    //cout << listaA.at(j) << endl;
						break;
					}
					else
					{
						if(j == 1)
						{
							break;
						}
						else
						{
							j--;
							q = find2q(listaA, j);
						}
					}//FIN IF ELSE 3
				}//FIN WHILE PASO 4
			//} FIN IF 2
		}// FIN IF 1
		else
			{
			//ELSE IF 1 
				while(q < s)
				{
					if(q < s-1)
					{
                         //if(listaA.size() > 1)
						listaA.pop_back();
						//eliminarAdelanteX(listaA, j);
						
						cout << "ERorR 52: tam: " << listaA.size() << " indice j = " << j << "indice Q = " << q << endl;
						getchar();
						listaA.insert(listaA.begin()+j, listaZ.at(q+1));
						
                        //cout << "entradaB: " << listaA.at(j) << " j = " <<  j <<endl;
					    //cout << listaA.at(j) << endl;
						break;
					}
					else
					{
                        
						if(j == 1)
						{
							break;
						}
						else
						{
							j--;
							if(q == 7)
                            {
                                 cout << "INDEX Q: " << q << " - " << j << endl;
                                 for(int z = 0; z < listaA.size(); z++)
                                 {
                                         cout << "-*->" << listaA.at(z) << endl;
                                 }
                            }
							q = find2q(listaA, j);
							cout << "Q now is: " << q << endl;
						}
					}
				}//FIN WHILE PASO 4	
			}//FIN IF ELSE 1
	}//FIN WHILE MAYOR
    
	contenedorFinal = listaA;
	
	
	cout << "Tam Bin: " << contenedorFinal.size() << endl;
	for(int i = 0; i < contenedorFinal.size(); i++)
	cout << "Elemento lista: " << contenedorFinal.at(i) << endl;
	
	return contenedorFinal;
}

vector < vector <int> > HeuristicaMBS::algoritmoMBS()
{
    cout << "HeuristicaMBS::algoritmoMBS()" << endl;
    cout << "Tam Z: " << listaZ.size() << endl;   
	vector <int> contenedor;
	vector < vector <int> > contenedores;
	int k = 0;

	while(!listaZ.empty())
	{
		contenedor = algoritmoL();	
		eliminarItemsZ(contenedor);
		//cout << "MBS SIZE: " << listaZ.size() << endl;
		contenedores.push_back(contenedor);
		k++;
	}

	return contenedores;
}

#define zonaH
#endif

/*
vector <int> HeuristicaMBS::algoritmoMBSoFFD()
{
       cout << "HeuristicaMBS::algoritmoL()" << endl;
       
	vector <int> contenedorFinal;
	vector <int> listaA;
	int slack = 0; //alpha
	int j = 0, q = 0;
	int s = listaZ.size();
	cout << "Tam listaZ en HMBS en algoritmoL: " << listaZ.size() << endl;

	while(sumaItemsA(listaA)!=capacidadBin)
	{
		if(sumaItemsA(listaA)<capacidadBin)
		{   
            if(listaA.empty())
            {
                listaA.insert(listaA.begin()+j, listaZ.at(q));
            }
            else
            {
                listaA.pop_back();
                listaA.insert(listaA.begin()+j, listaZ.at(q));
            }                            
			
			cout << "entradaA: " << listaA.at(j) << " j = " <<  j <<endl;
			cout << listaA.at(j) << endl;
			j++;
			if(sumaItemsA(listaA)>slack)
			{
				slack = sumaItemsA(listaA);
				contenedorFinal = listaA;

				if(q < listaZ.size()-1)
				{
					q++;
					listaA.insert(listaA.begin()+j, listaZ.at(q));//Podria quitarlo
					cout << "entradaB: " << listaA.at(j) << " j = " <<  j <<endl;
					cout << listaA.at(j) << endl;
				}
				else
				{
					if(j == 1)
						break;
					else
						j = j - 1;
				}
			}
		}
		else
		{
			if(q < listaZ.size()-1)
			{
				q++;
				listaA.pop_back();
				listaA.insert(listaA.begin()+j, listaZ.at(q));//Podria quitarlo
				cout << "entradaC: " << listaA.at(j) << " j = " <<  j <<endl;
				cout << listaA.at(j) << endl;
			}
			else
			{
					if(j == 1)
						break;
					else
						j = j - 1;
			}
		}
	}
	
	cout << "Tam Bin: " << contenedorFinal.size() << endl;
	for(int i = 0; i < contenedorFinal.size(); i++)
	cout << "Elemento lista: " << contenedorFinal.at(i) << endl;
	
	return contenedorFinal;
}
*/
