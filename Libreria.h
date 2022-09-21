#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Libreria
{
      int n; 
      
      public:
             Libreria(int x)
             {
                          n = x;
             }
      void mensajes();
};

void Libreria::mensajes()
{
     cout << "Been Down so godamn long \n";
}
