//Trabajando recientemente 04.04.2017
/* Clase Instancia, contiene los datos de una instancia, como numero de objetos, capacidad e contenedor,
nombre de la instancia, sus limites inferiores (l1, l2 l3, l4 y l de Jarboui) y los indices de complejidad 
de cada instancia.*/
/* Se elimino la obtencion de los limites l4 y lJarboui, falta eliminar variables */

#ifndef zonaI
#include <math.h>

using namespace std;

class Instancia{
		vector<int> pObjetos;
		string nombre;
		int Cap;
		int nObjetos;
		//Limites inferiores
		int lb_1, lb_2, lb_3, lb_4, lb_lj;
		//Metricas
		int m_mxrep;
		double m_men, m_may, m_mult,m_unif, m_p, m_t, m_d, m_f, m_b, m_rango, m_coefvar, m_asimpear, m_curt;
		
   public:
		Instancia (string nom, vector<int> vo, int c){     
			pObjetos=vo;
			nObjetos=vo.size();
			Cap=c;
			nombre=nombre;
            lb_1=lb_2=lb_3=lb_4=lb_lj=0;
		    m_mxrep=0;
			m_men=m_may=m_mult=m_unif=m_p=m_t=m_d=m_f=m_b=m_rango=m_coefvar=m_asimpear=m_curt=0.0;
		//	obtieneIndices();  cout << "Indices " << endl;
		//	obtieneLimites();
		}
		Instancia() {
			nombre.clear();
			nObjetos=0;
			Cap=0;
			lb_1=lb_2=lb_3=lb_4=lb_lj=-1;
			m_mxrep=-1;
			m_men=m_may=m_unif=m_p=m_t=m_d=m_f=m_b=m_rango=m_coefvar=m_asimpear=m_curt=-1.0;
		}
	   
	   void asignaNombreInstancia(string n);
	   void asignapObjetos(vector<int> objs);
	   void asignaCapacidad(int C);
	   string obtieneNombre();
	   vector<int> obtienepObjetos();
	   int obtieneCapacidad();
	   int obtienenObjetos();
	   void obtieneLimites();
	   void obtieneIndices();
	   int obtieneLB1();
	   int obtieneLB2();
	   int obtieneLB3();
	   int obtieneLB4();
	   int obtieneLBJ();
	   int obtieneMaxRepe();
	   double obtieneMenor();
	   double obtieneMayor();
	   double obtieneUniformidad();
	   double obtieneP();
	   double obtieneT();
	   double obtieneD();
	   double obtieneF();
	   double obtieneB();
	   double obtieneRango();
	   double obtieneCoeficienteVariacion();
	   double obtieneAsimetriaPearson();
	   double obtieneCurtosis();
	   double obtieneMultiplicidad();
	   int obtieneLimiteInferior();
	   int LB2();
	   int LB1();
	   int LB3();
	   int LimiteJarboui();
	   int LB4 ();	
	   double Curtosis ();
	   int MaxRepe ();
	   int obtieneLBparte1();
	   int obtieneLBparte2();
private:
	int encuentraMinimoj(vector<int> N, vector<int> Nsub);
	int buscaK(int j, vector<int> ji, vector<int> Nprima, int l, vector<int> wsob) ;
	int minimoh(vector<int> Nprima, int j, vector<int> wsob);
	void encuentrajajb(int jajb[], vector<int> Ji, vector<int> Nprima, int j, vector<int> wsob);
	vector<int> NmenosF(vector<int> N, vector<int> F);
	vector<int> MTRP(int nsob, vector<int> wsob, int *zr);
		
	int J2prima(vector<int> J1, vector<int> J2);
	vector<int> subconjuntoAaB(int a, int b, int nsob, vector<int> wsob);
	vector<int> subconjuntoAaBdeC(int a, int b, vector<int> J);
	int sumawj(vector<int> J, vector<int> wsob);
	int Lmax(vector<int> J2, vector<int> J3, vector<int> wsob);		
	double sumadouble(vector<int> Jvec);
	double L3alfa(int alfa, int l2, vector<int> J1, vector<int> J2, vector<int> J3);	
	int LB2(int nsob, vector<int> wsob);
	int tetaJarboui();
	int vJarboui();
	int LJarboui();
	int fiJarboui();
	int psi1Jarboui(int beta);
	int psi2Jarboui(int beta);
	int psi3Jarboui(int beta);
	int jiJarboui(int eta);
	int lambda1Jarboui(int fi);
	int lambda2Jarboui(int fi);
	int lambdaJarboui(int fi);

	
	double Menor (); 
	double Mayor ();
	vector<int> SinRepeticiones ();
	double Multiplicidad ();

	double Uniformidad ();
	double d ();
	int factor(int si);
	double f();
	double b();
	double p();
	double t();
	double Rango ();
	double MediaAritmetica ();	
	double MediaGeometrica ();
	double Varianza ();
	double DesviacionEstandar ();
	double CoeficienteVariacion ();
	double AsimetriaPearson ();

    int perteneceB(int a, vector<int> conjunto);
	
	
  };
  

void Instancia::asignaNombreInstancia(string n){
	nombre=n;
}
void Instancia::asignapObjetos(vector<int> objs){
	pObjetos=objs;
	nObjetos=(int)objs.size();
}
void Instancia::asignaCapacidad(int C){
	Cap=C;
}
string Instancia::obtieneNombre(){
	return nombre;
}
vector<int> Instancia::obtienepObjetos(){
	return pObjetos;
}
int Instancia::obtieneCapacidad(){
	return Cap;
}
int Instancia::obtienenObjetos(){
	return nObjetos;
}
int Instancia::obtieneLB1(){
	return lb_1;
}
int Instancia::obtieneLB2(){
	return lb_2;
}
int Instancia::obtieneLB3(){
	return lb_3;
}
int Instancia::obtieneLB4(){
	return lb_4;
}
int Instancia::obtieneLBJ(){
	return lb_lj;
}
int Instancia::obtieneMaxRepe(){
	return m_mxrep;
}
double Instancia::obtieneMenor(){
	return m_men;
}
double Instancia::obtieneMayor(){
	return m_may;
}
double Instancia::obtieneUniformidad(){
	return m_unif;
}
double Instancia::obtieneP(){
	return m_p;
}
double Instancia::obtieneT(){
	return m_t;
}
double Instancia::obtieneD(){
	return m_d;
}
double Instancia::obtieneF(){
	return m_f;
}
double Instancia::obtieneB(){
	return m_b;
}
double Instancia::obtieneRango(){
	return m_rango;
}
double Instancia::obtieneCoeficienteVariacion(){
	return m_coefvar;
}
double Instancia::obtieneAsimetriaPearson(){
	return m_asimpear;
}
double Instancia::obtieneCurtosis(){
	return m_curt;
}

double Instancia::obtieneMultiplicidad() {
	return m_mult;
}

/* ******************************************************************* 
						LIMITES INFERIORES
   ******************************************************************* */
/* *******************   Limite de Jarboui   ************************* */

int Instancia::tetaJarboui() {
	int q=0, i=nObjetos, suma=0;
	
	while ((suma <= Cap) && (i >=0)) {
		suma+=pObjetos[--i];
		q++;
	}
	return q-1;
}

int Instancia::LJarboui() {
	int m1, m2;
	
	m1=lb_1;
	m2=(int)ceil( (float)nObjetos/(float)tetaJarboui());   	
	if (m1 > m2) return m1;
	return m2;
}

int Instancia::vJarboui() {
	int k,  LJ;
	float suma=0;
	int j, l, s1, s2, i;
	
	j=0;
	LJ=LJarboui();
	k=(int)floor((float)nObjetos/(float)LJ);
	l=LJ-1;
	//Suma de todos los pesos entre L1-1
	for(; j<nObjetos; j++)
		suma+=pObjetos[j];
	suma=(float)suma/(float)l;
	j=1;
	while ((suma > Cap) && (j <=k)) {
		suma-=((float)pObjetos[j-1]/(float)l);
		j++;
	}
	s1=j-1; // Primer maximo
	
	suma=0;
	i=0;
	while ((suma <= Cap) && (i < k)) {
		suma+=pObjetos[i++];
	}
	if (i==k && suma <=Cap) s2=i;
	else s2=i-1;
	//cout << " V de Jarboui : " << s1 << "   " << s2 << endl;
	//getchar();
	if (s1 > s2) return s1;
	return s2;
}



int Instancia::fiJarboui() {
	return (int)floor((float)nObjetos/(float)LJarboui());   
}

int Instancia::psi1Jarboui(int beta) {
	int iinicio, ifinal;
	int q, qfinal, suma=0, i;
	
	//    beta=tetaJarboui(); 
	qfinal=nObjetos-beta+1;
	q=1;
	while ((suma <= Cap) && (q <= qfinal+1)) {
		suma=0;
		iinicio=nObjetos-q-beta+2;
		ifinal=nObjetos-q+1;
		if (iinicio > 0) 
			for(i=iinicio; i<= ifinal; i++)
				suma+=pObjetos[i-1];
		q++;
	}
	return (q-2);
}

int Instancia::psi2Jarboui(int beta) {
	int teta, iinicio, ifinal;
	int q, qfinal, sumaO=0, i;
	float suma=0;
	int nL;
	
	nL=(int) floor((float)nObjetos/(float)LJarboui());    
	teta=tetaJarboui();
	//  beta=teta; //     Siempre beta debe tomar el valor de teta ???
	if (nL < beta && beta <=teta) {
		qfinal=(int) floor((float)nObjetos/(float)beta);
		q=1;
		sumaO=0;
		iinicio=nObjetos+1;
		while ((suma <= Cap) && (q <= qfinal+1)) {
			ifinal=iinicio-1;
			iinicio=nObjetos-q*beta+1;
			if (iinicio >0 ) {
				for(i=iinicio; i<= ifinal; i++)
					sumaO+=(pObjetos[i-1]);
				suma= ceil((float)sumaO/(float)q);
			}
			q++;
		}
		return (q-2);
	}
	else if (beta <= nL && beta <=teta) return LJarboui();
	return 0;
}

int Instancia::psi3Jarboui(int beta) {
	int nL;
	int nume, deno;
	
	//    beta=tetaJarboui();
	nL=(int) floor(nObjetos/LJarboui());  
	if (beta > nL) {
		nume=nObjetos-vJarboui()*LJarboui();
		deno=beta-vJarboui();
		return (int) floor((float)nume/(float)deno);
	}  
	else  return LJarboui();  
}   

int Instancia::jiJarboui(int eta) {
	int m1, m2, LJ;
	int max;
	int ps1, ps2, ps3;
	//eta=fiJarboui();
	
	LJ=LJarboui();
	if (eta >= fiJarboui()) {      
		ps1=psi1Jarboui(eta+1);
		ps2=psi2Jarboui(eta+1);
		ps3=psi3Jarboui(eta+1);       
		max=LJ-ps1;
		m1=LJ-ps2;
		m2=LJ-ps3;
		if (max < m1) max=m1;
		if (max < m2) max=m2;
		return max;
	} else return 0;
}

int Instancia::lambda1Jarboui(int fi) {
	int LJ, qfinal, i, q, iinicio;
	int suma, lq;
	
	LJ=LJarboui();
	if (fi < (int) ceil((float)nObjetos/(float)LJ)) {
		qfinal=LJ-1;    
		q=0;
		while (suma <=Cap && q<=qfinal) {
			suma=0;
			iinicio=q*fi+1;
			lq=LJ-q;
			for(i=iinicio; i<=nObjetos; i++)
				suma+=pObjetos[i-1];
			suma=suma/lq;
			q++;
		}
		if (suma <= Cap && q > qfinal) return q-1;
		return q-2;
	} 
	return LJ; // No cumplio ninguna de las condiciones anteriores
}

int Instancia::lambda2Jarboui(int fi) {
	int LJ, teta;
	
	teta=tetaJarboui();
	LJ=LJarboui();
	if (fi < (int)ceil((float)nObjetos/(float)LJ)) return (int) floor((float)(teta*LJ-nObjetos)/(float)(teta-fi));
	return LJ;
}

int Instancia::lambdaJarboui(int fi){
	int lam1, lam2, dd, LJ;
	
	LJ=LJarboui();
	dd=(int)ceil((float)nObjetos/(float)LJ);
	lam1=lambda1Jarboui(fi);
	lam2=lambda2Jarboui(fi);	
	if (fi < dd) {
		if (lam1 <= lam2) return lam1;
		return lam2;
	}
	return LJ;
}

int Instancia::LimiteJarboui(){
	int LJ, fi, ji, lambda;
	
	lb_1=LB1(); 
	LJ=LJarboui();
	fi=fiJarboui();
	ji=jiJarboui(fi);
	lambda=lambdaJarboui(fi);
	if(ji>lambda) return LJ+1;
	return LJ;  
}

/* *******************   LIMITE LB1 ******************  */
int Instancia::LB1(){
	int i=0, l1=0;
	
	for (; i<nObjetos; i++) 
		l1+=pObjetos.at(i);
	l1=(int)ceil((double)l1/Cap);
	return l1;
}
/* **************************   LIMITE LB3   *********************** */
/* ************************** MTRP ********************************* */
/* Encuentra el minimo de la diferencia de N - Nsub */
int Instancia::encuentraMinimoj(vector<int> N, vector<int> Nsub) {
	int i, j;
	vector<int> aux;
	int ban=0;
	
	for(i=0; i<(int)N.size(); i ++) {
		ban=0;
		for(j=0; j<(int)Nsub.size(); j++) {
			if (N.at(i)==Nsub.at(j))
				ban=1;				
		}
		if (ban==0)
			aux.push_back(N.at(i));
	}    
	
	/* El primer elemento de aux siempre es el mas pequeño por eso retorna 0, en caso de que aux sea vacio retorna -1*/
	if (!aux.empty())
		return aux.at(0);
	return -1;
}




/* Busca la k mas grande tal que la sumatoria sea menor que la CAPACIDAD */
int Instancia::buscaK(int j, vector<int> ji, vector<int> Nprima, int l, vector<int> wsob) {
	int k=1;
	int suma;
	
	suma=wsob.at(j) + wsob.at(Nprima.at(ji.at(l)));
	while( suma <= Cap ) {
		k++;
		l--;
		if (l < (int)ji.size() && l>=0 && l<(int)Nprima.size()) 
			suma+=wsob.at(Nprima.at(ji.at(l)));   
		if (l<0) break;
	}       
	return --k; 
}

/* Busca el h minimo tal que la suma de j mas h sean menor que la CAPACIDAD */
int Instancia::minimoh(vector<int> Nprima, int j, vector<int> wsob){
	int h=-1;
	
	for(h=0; h < (int)Nprima.size() && wsob.at(j)+wsob.at(Nprima.at(h)) >Cap; h++);
	return Nprima.at(h); 
}


/*Busca ja y jb */
void Instancia::encuentrajajb(int jajb[], vector<int> Ji, vector<int> Nprima, int j, vector<int> wsob){
	int ban=0;
	int x, y, maxx, maxy;
	
	maxx=-1;
	maxy=-1;
	for(x=0; x<(int)Nprima.size()-1 && ban==0; x++) {
		for(y=x+1; y<(int)Nprima.size() && ban==0; y++)
			if (wsob.at(j)+wsob.at(Nprima.at(x))+wsob.at(Nprima.at(y)) <= Cap) {
				maxx=x;
				maxy=y;
				ban=1;
			}
	}
	if (ban==1) {
		for(; x<(int)Nprima.size()-1; x++)
			for(; y< (int)Nprima.size(); y++)
				if (wsob.at(j)+wsob.at(Nprima.at(maxx))+wsob.at(Nprima.at(maxy)) < 
					wsob.at(j)+wsob.at(Nprima.at(x))+wsob.at(Nprima.at(y)) && 
					wsob.at(j)+wsob.at(Nprima.at(x))+wsob.at(Nprima.at(y)) <= Cap) {
						maxx=x;
						maxy=y;
					}
	}
	jajb[0]=maxx;
	jajb[1]=maxy;
}

int Instancia::perteneceB(int a, vector<int> conjunto){
	int i;
	
	for(i=0; i<(int)conjunto.size(); i++)
		if (conjunto.at(i)==a) return i;
	return -1;
}

vector<int> Instancia::NmenosF(vector<int> N, vector<int> F){
	int i, pos;
	
	for(i=0; i<(int)F.size(); i++) {
		if((pos=perteneceB(F.at(i), N))!=-1)
			N.erase(N.begin()+pos);			
	}	
	return N;
}
/* ******************************** Limite L3 ****************

nObjetos -- numero de objetos
pObjetos -- Arreglo de objetos (pesos)
Cap -- capacidad del contenedor
zr -- optimo
vectorB [i] -- i  es el numero de objeto, vectorB[i] es el numero de contenedor
vectorN -- vector que contiene el indice de los objetos a acomodar
**************************************************************** */

vector<int> Instancia::MTRP(int nsob, vector<int> wsob, int *zr) {
	vector<int> N, F, Ji;
	vector<int> Nsub, Nprima;
	vector<int> Otro;
	int i, j, k, jajb[2], jaster;
	vector<int> Prel;
	
	Prel.clear();
	for(i=0; i<nsob; i++)
		Prel.push_back(0);
	N.clear();
	for(i=0; i< nsob; i++)
		N.push_back(i);
	
	Nsub.clear();
	
	Ji.clear();
	(*zr)=0;
	
	while (1) {
		if (!Nsub.empty() && !N.empty())
			j=encuentraMinimoj(N, Nsub);
		else if (Nsub.empty()) j=N.at(0);
				
		/* N - {j} */
		Nprima.clear();
		for(i=0; i<(int)N.size(); i ++) {    
			if (N.at(i)!=j)
				Nprima.push_back(N.at(i));
		}    
		Ji.clear();
		for(i=0; i< (int)Nprima.size(); i++)
			Ji.push_back(i);
		F.clear();
		k=0;
		if (!Nprima.empty())
			k=buscaK(j, Ji, Nprima, Nprima.size()-1, wsob);
		if (k==0) F.push_back(j);
		else {
			jaster=minimoh(Nprima, j, wsob);
			if (k == 1 || wsob.at(j) + wsob.at(jaster)==Cap) {
				F.push_back(j);
				F.push_back(jaster);
			}
			else if (k == 2) {
				encuentrajajb(jajb, Ji, Nprima, j, wsob);
				if (wsob.at(jaster) >= wsob.at(Nprima.at(jajb[0])) + wsob.at(Nprima.at(jajb[1]))) {
					F.push_back(j);
					F.push_back(jaster);
				}
				else if (wsob.at(jaster) == wsob.at(Nprima.at(jajb[0])) && 
					(Nprima.at(jajb[1]) - Nprima.at(jajb[0]) <= 2 || wsob.at(j) + wsob.at(Nprima.at(jajb[1])-1) + wsob.at(Nprima.at(jajb[1])-2) > Cap)
					) {
						F.push_back(j);
						F.push_back(Nprima.at(jajb[0]));
						F.push_back(Nprima.at(jajb[1]));
					}
			}
		}
		if (F.empty()) Nsub.push_back(j);
		else {
			(*zr)=(*zr)+1;
			for (i=0; i< (int)F.size(); i++)
				Prel.at(F.at(i))=(*zr); 
			N=NmenosF(N, F);
		}
		Otro.clear();
		Otro=NmenosF(N, Nsub);
		if (Otro.empty()) break; //ban=0;
	}
	return Prel;
}

int Instancia::LB3() {
	int j, l3, z, zr, l2, k, nsob;
	vector<int> bj, wsob;
	
	l3=0;
	z=0;
	nsob=nObjetos;
	wsob=pObjetos;
	while(nsob >= 1 ) {
		bj=MTRP(nsob, wsob, &zr);
			z+=zr;
		k=0;
		for(j=0; j<nsob; j++) 
			if (bj.at(j)==0) {			   
				wsob.at(k)=wsob.at(j);
				k+=1;
			}
		nsob=k;	   
		if(nsob==0) l2=0;
		else l2=LB2(nsob, wsob);
		if (l3 < z+l2)
			l3=z+l2;
		nsob=nsob-1;	
	}
	return l3;
}
/* ***************************************************************** */
/* ***************** Limite LB2 ************************************ */
vector<int> Instancia::subconjuntoAaB(int a, int b, int nsob, vector<int> wsob){	
	vector<int> auxiliar;
	int i;
	
	auxiliar.clear();
	for(i=0; i<nsob; i++) {
		if (wsob.at(i) <= b && wsob.at(i) >= a)
			auxiliar.push_back(i);
	}
	
	return auxiliar;
}

int Instancia::sumawj(vector<int> J, vector<int> wsob) {
	int j, suma=0;	
	
	for(j=0; j<(int)J.size(); j++) 
		suma+=wsob.at(J.at(j));
	return suma;
}

int Instancia::Lmax(vector<int> J2, vector<int> J3, vector<int> wsob) {
	int maxi;
	double s, s1;
	
	s1=(J2.size()*Cap - sumawj(J2, wsob));
	s=(double)(sumawj(J3, wsob) - s1)/(double)Cap;
	maxi=(int)ceil(s);
	if (maxi > 0) return maxi;
	return 0;
}

int Instancia::LB2(int nsob, vector<int> wsob) {
	vector<int> J1, J2, J3;
	int lalfa, alfa, maxi=-1;
	
	J1.clear(); //La primera vez J1 es vacia ya que alfa es cero y no existen elementos que sean mayores que CAPACIDAD
	J2.clear();
	J3.clear();
	J2=subconjuntoAaB(Cap/2 + 1, Cap, nsob, wsob);
	J3=subconjuntoAaB(0, Cap/2, nsob, wsob); 
	maxi=J1.size() + J2.size() + Lmax(J2, J3, wsob);
	for(alfa=1; alfa <=Cap/2; alfa++) {
		J1=subconjuntoAaB(Cap-alfa +1, Cap, nsob, wsob);
		J2=subconjuntoAaB(Cap/2 + 1, Cap-alfa, nsob, wsob);
		J3=subconjuntoAaB(alfa, Cap/2, nsob, wsob); 
		lalfa=J1.size() + J2.size() + Lmax(J2, J3, wsob);
		if (maxi < lalfa) maxi=lalfa;
	} 
	return maxi;
}
/* ***************************************************************** */
/* ***************** Limite LB4 ************************************ */
vector<int> Instancia::subconjuntoAaBdeC(int a, int b, vector<int> J){	
	vector<int> auxiliar;
	int i;
	
	auxiliar.clear();
	for(i=0; i<(int)J.size(); i++) {
		if (pObjetos[J.at(i)] <= b && pObjetos[J.at(i)] >= a)
			auxiliar.push_back(J.at(i));
	}
	
	return auxiliar;
}

int Instancia::J2prima(vector<int> J1, vector<int> J2) {
	vector<int> J2pri, resta;
	int i, j;
	
	J2pri.clear();
	resta.clear();
	for(j=(int)J2.size()-1, i=0; j>=0 && i<(int)J1.size(); i++) {
		if(pObjetos[J2.at(j)] + pObjetos[J1.at(i)] <= Cap ) {
			J2pri.push_back(J2.at(j));
			J2pri.push_back(J1.at(i));			
			resta.push_back(J2.at(j));
			j--;
		}
	}
	resta=NmenosF(J2, resta);
	return (int)ceil((float)resta.size()/(float)2); 
}

double Instancia::sumadouble(vector<int> Jvec){
	int i;
	double suma;
	
	suma=0;
	for(i=0; i<(int)Jvec.size(); i++)
		suma+=(double)pObjetos[Jvec.at(i)];
	return suma;
}

double Instancia::L3alfa(int alfa, int l2, vector<int> J1, vector<int> J2, vector<int> J3) {
	double suma; 
	vector<int> j1al, j3al;
	
	j1al.clear();
	j3al.clear();
	j1al=subconjuntoAaBdeC(0, Cap-alfa, J1); /* Cambie el 1 por CAPACIDAD */
	j3al=subconjuntoAaBdeC(alfa, Cap, J3);
	suma=sumadouble(j1al);
	suma+=sumadouble(J2);
	suma+=sumadouble(j3al);
	suma=suma/Cap;
	suma=suma - j1al.size();
	suma=suma-l2;
	return suma;
}


int Instancia::LB4 () {
	vector<int> J1, J2, J3;
	int l1, l2, i;
	double maxl3, l3al;
	
	J1.clear();
	J2.clear();
	J3.clear();
	J1=subconjuntoAaB(Cap/2+1, Cap, nObjetos, pObjetos);
	J2=subconjuntoAaB(Cap/3+1, Cap/2, nObjetos, pObjetos);
	J3=subconjuntoAaB(1, Cap/3, nObjetos, pObjetos);
	l1=J1.size();
	l2=J2prima(J1, J2);
	if (!J3.empty())
		maxl3=L3alfa(pObjetos.at(J3.at(0)), l2, J1, J2, J3);
	for(i=1; i<(int)J3.size(); i++) {
		l3al=L3alfa(pObjetos.at(J3.at(i)), l2, J1, J2, J3);
		if (maxl3 < l3al)
			maxl3=l3al;
	}
	maxl3=(int)ceil((float)l1+(float)l2+(float)maxl3);
	return (int)maxl3;
}

/* ***************************************************************** */
void Instancia::obtieneLimites(){	
	lb_1=LB1();
	lb_2=LB2(nObjetos, pObjetos);
	cout << "l1: " << lb_1 << "   l2:" << lb_2 << "   l4: " << lb_4 << endl;
	if ((lb_1 == lb_2 && Curtosis()>8000) || Curtosis()>15000 ) //  esta condicion la puse para las testdual en donde L3 tarda muchisimo testdual1_binpack? y por el momento testdual3
	lb_3=0;
	else lb_3=LB3(); 
	//cout << "Limites l3" << endl;
	//lb_3=0;
	lb_lj=LimiteJarboui();
}



void Instancia::obtieneIndices(){
	m_men=Menor();
	m_may=Mayor();
	m_mxrep=MaxRepe();
	m_mult=Multiplicidad(); // ????
	m_unif=Uniformidad();
	m_d=d();
	m_f=f();
	m_b=b();
	m_p=p();
	m_t=t();
	m_rango=Rango();
	m_coefvar=CoeficienteVariacion();
	cout << "Coe : " << m_coefvar << endl;
	m_asimpear=AsimetriaPearson();
	m_curt=Curtosis();
}



/* ******************************************************************* 
                       INDICES DE COMPLEJIDAD                               
   ******************************************************************* */
double Instancia::Menor () {
	return (double) ((double)pObjetos.at(nObjetos-1)/(double)Cap);
}
double Instancia::Mayor () {
	return (double) ((double)pObjetos.at(0)/(double)Cap);
}
vector<int> Instancia::SinRepeticiones () {
	vector<int> m, S;
	int i, j, cont;
	
	S.clear();
	m.clear();
	for(i=0, j=0, cont=1; i<(nObjetos-1); i++) {
		if (pObjetos.at(i) != pObjetos.at(i+1)) {
			S.push_back(pObjetos.at(i));
			m.push_back(cont);  
			j++; cont=1;
		}
		else cont++;
	}
	S.push_back(pObjetos.at(nObjetos-1));
	m.push_back(cont);
	return m;
}

double Instancia::Multiplicidad () {
	vector<int> m, S;
	int i, sum=0;
	
	m.clear();
	S.clear();
	m=SinRepeticiones();
	sum=0;
	for(i=0; i< (int)m.size(); i++)
		sum+=m.at(i);
	return (double) ((double)sum/(double)m.size());
}

int Instancia::MaxRepe () {
	vector<int> m, S;
	int max, i;
	
	m.clear();
	S.clear();
	m=SinRepeticiones();
	max=m.at(0);
	for(i=1; i<(int)m.size(); i++)
		if (max < m.at(i))
			max=m.at(i);
	return max;
}

double Instancia::Uniformidad () {
	double R, r0, r1, sum, s, ss;
	vector<double> r;
	vector<double> B[4];
	int i, j;
	
	for(i=0; i<=3; i++)
		B[i].clear();
	r.clear();
	R=pObjetos.at(0)-pObjetos.at(nObjetos-1);
	for(i=0; i<=4; i++)          
		r.push_back(pObjetos.at(nObjetos-1) + ((double)(i*R)/4)); 
	j=nObjetos-1;
	for (i=1; i<=4; i++) {
		//j=nsob-1;
		r0=r.at(i-1);
		r1=r.at(i);
		while (j>=0 && pObjetos.at(j) <= r0) 
			j--;
		while (j >=0 && pObjetos.at(j) <= r1 && pObjetos.at(j) > r0) {
			B[i-1].push_back(pObjetos.at(j));
			j--;
		}
	}
	sum=0;
	s=((double)nObjetos/4);
	for(i=0; i<=3; i++) {
		ss=0;
		for(j=0; j<(int)(B[i].size()); j++)
			ss+=B[i].at(j);
		sum+=abs((long)(s - abs((long)ss)));
	}
	sum=sum/nObjetos;
	return 1-sum;
}

/* Indice del tamaño del caso */
double Instancia::p () {
	return  (double)nObjetos/1000;
}

/* Capacidad ocupada por un objeto promedio */
double Instancia::t () {
	int i;
	double s;
	
	s=0;
	for(i=0; i<nObjetos; i++)
		s+=((double)pObjetos.at(i)/(double)nObjetos);
	s=s/(double)Cap;
	return s;
}

/* Indice de dispersion */
double Instancia::d () {
	int i;
	double s, si, tT;
	
	s=0;
	tT=t();
	for(i=0; i< nObjetos; i++) {
		si=(double)pObjetos.at(i)/(double) Cap;
		si=(tT-si)*(tT-si);
		s+=si;
	}
	s=s/(double)nObjetos;
	s=sqrt(s);
	return s;
}

int Instancia::factor(int si){
	if (!(Cap % si)) return 1;
	return 0;
}

/* Indice de factores */
double Instancia::f(){
	int i;
	double s;
	
	s=0;
	for(i=0; i< nObjetos; i++)
		s+=factor(pObjetos.at(i));
	s=s/(double)nObjetos;
	return s;
}

double Instancia::b(){
	int i;
	double s;
	
	s=0;
	for(i=0; i<nObjetos; i++)
		s+=(double)pObjetos.at(i);
	if ((double)Cap >= s) return 1;
	return (double)Cap/s;
}
/* ************** Rango ************** */
double Instancia::Rango (){
	return (double)(pObjetos.at(0)-pObjetos.at(nObjetos-1));
}

double Instancia::MediaAritmetica (){
	int i;
	double p;
	
	p=0;
	for(i=0; i<nObjetos; i++)
		p+=pObjetos.at(i);
	p=p/(double)nObjetos;
	return p;	
}

/* La media geometrica solo se puede obtener si todos los pesos son positivos */
double Instancia::MediaGeometrica (){
	int i;
	double g;
	
	g=1;
	for(i=0; i<nObjetos; i++)
		g*=pow(pObjetos.at(i), 1/(double)nObjetos);
	return g;
}

double Instancia::Varianza (){
	int i;
	double s, ma;
	
	ma=MediaAritmetica ();
	s=0;
	for(i=0; i<nObjetos; i++)
		s+=pow((double)pObjetos.at(i),(double)2);    
	
	s=s/(double)nObjetos;
	
	ma=pow(ma,2);
	s=s-ma;
	
	return s;	
}

double Instancia::DesviacionEstandar (){
	double var;	
	var=Varianza();
	return pow(var, (double)1/2);
}

double Instancia::CoeficienteVariacion (){
	double media=MediaAritmetica();
	
	return DesviacionEstandar()/(double)abs((long)media); /* media aritmetica estaba sin parametros */
}

double Instancia::AsimetriaPearson (){
	int i;
	double media, s;
	
	media=MediaAritmetica();
	s=0;
	for(i=0; i<nObjetos; i++)
		s+=pow((pObjetos.at(i) - media), 3);
	
	s=s/pow(DesviacionEstandar(), 3);
	
	return s;
}

double Instancia::Curtosis (){
	int i;
	double s, d, g;
	
	g=MediaGeometrica();	
	d=DesviacionEstandar();	
	d=pow(d, 4);	
	for(i=0; i<nObjetos; i++)
		s+=pow((pObjetos.at(i)-g), 4);      /*aqui era la mediaGeometrica no la desviacion estandar*/
	
	return s/d;
}

int Instancia::LB2() {
	return LB2(nObjetos, pObjetos);
}

int Instancia::obtieneLimiteInferior() {	
	int lim, ljj, l1, l2, l3, numl;
	double porcItem1, porcMaxRepe, curt;
	
	porcItem1=(double)((double)pObjetos.at(0)*(double)100/(double)Cap);
	porcMaxRepe=(double)((double)MaxRepe()*(double)100/(double)nObjetos);
	if (porcItem1 < (double)25 && porcMaxRepe < (double)20) {
		ljj=LimiteJarboui();
		l1=LB1();
		if(ljj > l1) {
			cout << "Retorna lj " << endl; return ljj;
		}
		else {
			cout << "Retorna l1 " << endl; return l1;
		}
	}
	else if ((porcItem1 <=57 && porcMaxRepe < 10) || (porcItem1 > 57 && porcItem1 <= 59 && porcMaxRepe < 3) || (porcItem1 > 59 && porcItem1 <=65 && porcMaxRepe < 1.5)) {
		ljj=LimiteJarboui();
		l1=LB1();
		if(ljj > l1) {
			cout << "Retorna lj " << endl; return ljj;
		}
		else {
			cout << "Retorna l1 " << endl; return l1;
		}
	}
	else {
		l1=LB1();
		l2=LB2(nObjetos, pObjetos);
		ljj=LimiteJarboui();
		curt=Curtosis();
		if ((l1==l2 && curt > 8000) || (curt > 15000)) 
			l3=0;
		else 
			l3=LB3();
		lim=-1;	numl=-1;
		l1=LB1();
		l2=LB2(nObjetos, pObjetos);
		ljj=LimiteJarboui();
		if (l1 > lim) {
			lim=l1;	
			numl=1;
		}
		if (l2 > lim) {
			lim=l2;	
			numl=2;
		}
		if (l3 > lim) {
			lim=l3;
			numl=3;
		}
		if (ljj > lim) {
			lim=ljj;
			numl=5;
		}
		cout << "Retorna " << numl << "---- " << endl;
		return lim;	
	}
}
	
	//Primera parte del limite inferior
int Instancia::obtieneLBparte1() {	
	int lim=-1, ljj, l1;
	double porcItem1, porcMaxRepe;
		
		porcItem1=(double)((double)pObjetos.at(0)*(double)100/(double)Cap);
		porcMaxRepe=(double)((double)MaxRepe()*(double)100/(double)nObjetos);
		if (porcItem1 < (double)25 && porcMaxRepe < (double)20) {
			ljj=LimiteJarboui();
			l1=LB1();
			if(ljj > l1) {
				cout << "Retorna lj " << endl; return ljj;
			}
			else {
				cout << "Retorna l1 " << endl; return l1;
			}
		}
		else if ((porcItem1 <=57 && porcMaxRepe < 10) || (porcItem1 > 57 && porcItem1 <= 59 && porcMaxRepe < 3) || (porcItem1 > 59 && porcItem1 <=65 && porcMaxRepe < 1.5)) {
			ljj=LimiteJarboui();
			l1=LB1();
			if(ljj > l1) {
				cout << "Retorna lj " << endl; return ljj;
			}
			else {
				cout << "Retorna l1 " << endl; return l1;
			}
		}
		return lim;
	}
		// Obtiene limite inferior segunda parte
	int Instancia::obtieneLBparte2() {	
		int lim=-1, ljj, l1, l2, l3, numl;
		double porcItem1, porcMaxRepe, curt;
		
		porcItem1=(double)((double)pObjetos.at(0)*(double)100/(double)Cap);
		porcMaxRepe=(double)((double)MaxRepe()*(double)100/(double)nObjetos);
		
			l1=LB1();
			l2=LB2(nObjetos, pObjetos);
			ljj=LimiteJarboui();
			curt=Curtosis();
			if ((l1==l2 && curt > 8000) || (curt > 15000)) 
				l3=0;
			else 
				l3=LB3();
			lim=-1;	numl=-1;
			l1=LB1();
			l2=LB2(nObjetos, pObjetos);
			ljj=LimiteJarboui();
			if (l1 > lim) {
				lim=l1;	
				numl=1;
			}
			if (l2 > lim) {
				lim=l2;	
				numl=2;
			}
			if (l3 > lim) {
				lim=l3;
				numl=3;
			}
			if (ljj > lim) {
				lim=ljj;
				numl=5;
			}
			cout << "Retorna " << numl << "---- " << endl;
			return lim;	
		}	

#define zonaI
#endif
