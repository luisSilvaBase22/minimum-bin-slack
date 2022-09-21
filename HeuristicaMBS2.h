//Trabajando recientemente 04.04.2017
//#include <stdio.h>
//#include <iostream>
//#include <vector>
#include "Util.h"

#ifndef zonaH
//using namespace std;

class HeuristicaMBS2
{
	Instancia ins;
	vector < vector <int > > contenedoresFinales;
	vector <int> listaZ;
	//vector <int> listaA;
	int k;
	int capacidadBin;
	int numeroItemsS;

public:
	HeuristicaMBS2(Instancia i)
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
	int find2q(vector <int> listaPhi, int q, int j);
	int sumaItemsA(vector <int> listaPhi);
	void eliminarItemsZ(vector <int> sk);
	vector <int> eliminarX(vector <int> lista, int j, int q);
	void swapContenedor(vector <int> phi, int j, int q);
	vector <int> borraRepetidosZ(vector <int> sk);
    vector <int> algoritmoL();
	vector < vector <int> > algoritmoMBS();

};

void HeuristicaMBS2::eliminarItemsZ(vector <int> sk)
{
	vector <int> listaAuxiliar;
	int tamLista = sk.size();
	int i = 0, j = 0;
	/*
	*****
    cout << "HOLA" << endl;
    cout << "H T SK: " << sk.size() << endl;
    */
    
    /*
    cout << "TAM EZ: " << listaZ.size() << endl;
    for(int m = 0; m < listaZ.size(); m++)
    {
            cout << "EZ: " << listaZ.at(m) << endl;
    }
    cout << "BIEN" << endl;
	*/
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
				//listaAuxiliar.push_back(listaZ.at(i));
				if(listaAuxiliar.empty())
				listaAuxiliar.insert(listaAuxiliar.begin(), listaZ.at(i));
				else
				listaAuxiliar.push_back(listaZ.at(i));
                i++;
			}
		}
		
		//for(int z = 0; z < listaAuxiliar.size(); z++)
		//cout << "D " << listaAuxiliar.at(z) << endl;
		if(j == sk.size() && listaZ.size() > 1)
		{
            if(listaZ.size()!=sk.size())
            {
                 if(i < listaZ.size())                       
                 listaAuxiliar.push_back(listaZ.at(i));
			     i++;
            }
		}
	}

	listaZ = listaAuxiliar;
	//cout << "TSHUSS" << endl;
	//for(int x = 0; x < listaZ.size(); x++)
	//cout << listaZ.at(x) << endl;
}

int HeuristicaMBS2::sumaItemsA(vector <int> listaPhi)
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

int HeuristicaMBS2::find1q(vector <int> listaPhi, int q, int j)
{
	
	if(q == 0 && j == 0)
	{
         q = 0;
    }
	else
	{
        if(q < listaZ.size()-1)
        q++;
        //if(q == listaPhi.size())
        //q--;
		//if(q == 8){
		//cout << "FIN: " << endl;//listaZ.at(q) << endl;
		//getchar();
        //}
        
       // try
        //{
		while(listaZ.at(q) != listaPhi.at(j))
		{
			q++;

			if(q == listaZ.size())
			{
				q = 0;
				break;
			}
		}
       //}
          //catch(...)
          //{
                 //cout << "RUNTIMEERROR Q = " << q << "J = "<< j << endl;
                 //q = find2q(listaPhi, j);
                 //q = 0;
          //}
	}

	return q;
}

int HeuristicaMBS2::find2q(vector <int> listaPhi, int q, int j)
{	
/*    
for(int x = 0; x < listaPhi.size(); x++)
{
        cout << "A: " << listaPhi.at(x) << endl;
}
*/
	while(listaZ.at(q) != listaPhi.at(j))
	{
        if(q < listaZ.size()-1)
          {
            q++;
          }
		else
		{
       //     cout << "SIZE = " << listaZ.size() << endl;
            if(q == listaZ.size()-1)
            {
               q = 0;
               
            }
        }
	}

	return q;
}


vector <int> HeuristicaMBS2::eliminarX(vector <int> phi, int j, int q)
{
       vector <int> aux;
       
       if(j == phi.size()-1)
       {
            phi.pop_back();
       }
       else
       {
           if(phi.size() != 1 && j < phi.size())
           phi.erase(phi.begin()+j);
       }
       
       aux = phi;
       
       return aux;
}

void HeuristicaMBS2::swapContenedor(vector <int> phi, int j, int q)
{
       if(j == phi.size()-1)
       {
            phi.pop_back();
       }
       else
       {
           if(phi.size() != 1 && j < phi.size())
           {
               if(phi.at(j+1)!=listaZ.at(q))
               {
                  phi.erase(phi.begin()+j, phi.end());
                  phi.insert(phi.begin()+j, listaZ.at(q+1));
               }
           }
       }
}

vector <int> HeuristicaMBS2::borraRepetidosZ(vector <int> sk)
{
     int i = 0;
     int j = 0;
     int salida = 0;
     /*
     *****
     cout << "Tam SK: " << sk.size() << endl;
     cout << "Tam Z: " << listaZ.size() << endl;
     for(int m = 0; m < sk.size(); m++)
     cout << "SK: " << sk.at(m) << endl;
     
     cout << "BORRANDO" << endl;
     */
     while(i < sk.size())
     {
             while(j < listaZ.size())
             {
                     if(sk.at(i)==listaZ.at(j))
                     {
                         salida++;
                         j++;
                         break;
                     }
                 j++;
             }
          i++;
     }
     //cout << "J = " << j << endl;
     //cout << "Salida = " << salida << endl;
     if(j == listaZ.size() && salida <sk.size())
          sk.erase(sk.begin()+salida);
     /*     
     cout << "En lista: " << endl;
     for(int m = 0; m < sk.size(); m++)
     cout << "SK: " << sk.at(m) << endl;
     */
     
     //*** cout << "Borrados REPETIDOS" << endl; 
     
     return sk;
}


vector <int> HeuristicaMBS2::algoritmoL()
{
	vector <int> contenedorFinal;
	vector <int> listaA;
	int slack = 0; //alpha
	int j = 0, q = 0;
	int qAnterior = 0;
	int s = listaZ.size();
	int salida = 0;
	int repetido = 0;
	
	//***cout << "ENTRA L" << endl;
	
    
    /*
	cout << "TAM INIL: " << listaZ.size() << endl;
	for(int i = 0; i < listaZ.size(); i ++)
	cout << "INI: " << listaZ.at(i) << endl;
	getchar();
	*/
    //cout << "NEW LIST SIZE = " << listaZ.size() << endl;
	listaA.insert(listaA.begin()+j, listaZ.at(q));
	/*
    listaA.insert(listaA.begin()+j+1, listaZ.at(q+1));
	j = 1;
    q = 1;
	*/
	while(sumaItemsA(listaA)!=capacidadBin)//PASO 1
	{
         /*cout << "SUMA: " << sumaItemsA(listaA) << endl;
         cout << "Q = " << q << "<-> J = " << j << endl; 
         getchar();
              for(int y = 0; y < listaA.size(); y++)
				{
                        cout << "L : " << listaA.at(y) << endl;
                }
	cout << "SLACK = " << slack << endl;
	*/
	
	if(sumaItemsA(listaA)<=slack)
	{
        //repetido++;
        //if(repetido > 2)
        //cout << "Escape" << endl;
        break;
    }
    
    	q = find1q(listaA, q, j);
    	 
		if(sumaItemsA(listaA) < capacidadBin)//PASO 2
		{
			j++;
			if(sumaItemsA(listaA) > slack)//PASO 3
			{
                if(contenedorFinal.size() < listaZ.size())
                {
				slack = sumaItemsA(listaA);
				contenedorFinal = listaA;
				//contenedorFinal = swapContenedor(listaA, contenedorFinal);
                }
                else
                {
          //          cout << "FALSO" << endl;
                    break;
                }
			}//FIN PASO 3
		}	
		
        while(q < s)//PASO 4
		{
			if(q < s - 1)
			{
                listaA = eliminarX(listaA, j, q);
                //if(qAnterior == s-1)
                //    listaA.erase(listaA.begin()+j, listaA.end());
                
				listaA.insert(listaA.begin()+j, listaZ.at(q+1));
                //swapContenedor(listaA, j, q);
                break;
			}
			
			if(j == 1)
			{
            //    cout << "SALIDA J = " << j << endl;  
                salida = 1;
				break;
			}
			else
			{
      //          cout << "ENTRA " << endl;
      //		  cout << "Q = " << q << " J = " << j << endl;
                j--;
                qAnterior = q;
				q = find2q(listaA, q, j);
	  		  //cout << "NUEVOS Q = " << q << " J = " << j << endl;
			}
		}//FIN paso 4
		if(salida == 1)
		{
            salida = 0;
            break;
        }
	}

    
	if(sumaItemsA(listaA) == capacidadBin)
      {
           contenedorFinal = listaA;
      }
	/*
	****
    cout << "SALE L" << endl;
	*/
	
    /*
	cout << "Tam Bin: " << contenedorFinal.size() << endl;
	for(int i = 0; i < contenedorFinal.size(); i++)
    cout << "Elemento lista: " << contenedorFinal.at(i) << endl;
    */
    //for(int i = 0; i < listaZ.size(); i++)
//	{
    //cout << "Elemento lista: " << listaZ.at(i) << endl;
//getchar();
//}
    return contenedorFinal;
}

vector < vector <int> > HeuristicaMBS2::algoritmoMBS()
{
       /*
    cout << "HeuristicaMBS::algoritmoMBS()" << endl;
    cout << "Tam Z: " << listaZ.size() << endl;   
	*/
    vector <int> contenedor;
	vector < vector <int> > contenedores;
	int k = 0;

	while(!listaZ.empty())
	{
		contenedor = algoritmoL();
        contenedor = borraRepetidosZ(contenedor);
        //getchar();	
		eliminarItemsZ(contenedor);
		//cout << "MBS SIZE: " << listaZ.size() << endl;
		contenedores.push_back(contenedor);
		k++;
	}

	return contenedores;
}

#define zonaH
#endif

