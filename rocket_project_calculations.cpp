#include <iostream>
#include <vector>
#include <valarray>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <Windows.h>

using namespace std;
#define int long long
#define vector valarray

const double u0 = 1000;
const double mt = 2; //масса топлива изначальная
const double M0 = 5; //масса ракеты изначальная
const double dm0 = 0.5; //скорость горения топлива
double S = 0.01; //площадь Миделя ракеты
double Cx = 0.5; //коэф лобового сопротивления
const double ht = 0.0025; //шаг времени расчета
const double g = 9.80665; //ускорение свободного падения
const double rho0 = 1.2754;
double t = 0;
vector<double> aCur = {0.0, 0.0, 0.1, 0.2}; // 0 - X, 1 - Y, 2 - Vx, 3 - Vy


double dm (double t){ //вычисление производной по времени
	return ((t<=(mt/dm0))?(+dm0):0);
}

double M(double t){ //вычисление массы ракеты в данный момент
	return ((t<=(mt/dm0))?(M0-dm0*t):(M0-mt));
}

double rho(double y){
	return rho0 * exp(-0.0001 * y);
}


vector<double> f (vector<double> a){ //функция для расчета правой части уравнения
	vector<double> res(4);
	res[0]=a[2];
	res[1]=a[3];

	double o = sqrt((a[2] * a[2] + a[3] * a[3]));
	
	res[2]= dm(t)/M0 * u0 * a[2]/o - (Cx*S*0.5)*rho(a[1])/M0 * o * a[2];
	res[3] = -M(t)/M0 * g + dm(t)/M0 * u0 * a[3]/o - (Cx*S*0.5)*rho(a[1])/M0 * o * a[3];

	return res;
}

void step(){
	vector<double> k1(4);
	vector<double> k2(4);
	vector<double> k3(4);
	vector<double> k4(4);

	k1 = f(aCur);
	t+=0.5*ht;
	k2 = f(aCur+0.5*ht*k1);
	k3 = f(aCur+0.5*ht*k2);
	t+=0.5*ht;
	k4 = f(aCur+ht*k3);

	aCur += ht/6.0 * (k1+2.0*k2+2.0*k3+k4);
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("output.txt", "w", stdout);

	int i=0;
	bool no_fuel_printed = false;
	bool enter_need=false;
	double max=-1;
	cout << fixed << setprecision(4) << t << " " << aCur[0] << " " << aCur[1] << " " << aCur[2] << " " << aCur[3] << endl;		
	do{

		step();

		if (aCur[1]<=(0.5*max) && S!=5){ 
			S= 5;
			Cx = 1;
			enter_need=true;
		}

		if (t>=mt/dm0 && !no_fuel_printed){
			no_fuel_printed = true;
			enter_need=true;
		}

		if (enter_need){ cout << "\n\n"; enter_need=false;}

		cout << fixed << setprecision(4) << t << " " << aCur[0] << " " << aCur[1] << " " << aCur[2] << " " << aCur[3];	
		
		cout << endl;
		
		++i;
		if (aCur[1]>max) max=aCur[1];	
	}while (aCur[1]>0 && i<1000000);

	return 0;
}

