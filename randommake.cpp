#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<fstream>
using namespace std;
double rand_val() { //(0,1)までの一様乱数生成
	double a;
	a = (rand() + 0.5) / (RAND_MAX + 1);
	return a;
}
double rnd_uni(double a, double b) { //区間(a,b)における一様乱数生成
	return a + (b - a) * rand_val();
}
double rnd_exp(double ramda) { //スペクトルramdaの指数分布生成
	return -log(1 - rand_val()) / ramda;
}
int main() {
	ofstream ofs("乱数生成.csv");
	srand(18140024);
	double a, b,ramda;
	cin >> a >> b>>ramda;
	double unisum1 = 0; //一様乱数の和
	double expsum1 = 0; //指数分布の和
	double unisum2 = 0; //一様乱数の二乗の和
	double expsum2 = 0; //指数分布の二乗の和
	for (int i = 0; i < 1000; i++) { //試行回数1000回
		double x = rnd_uni(a, b);
		double y= rnd_exp(ramda);
		double Fx, Fy;
		unisum1 += x;
		expsum1 += y;
		unisum2 += x*x;
		expsum2 += y*y;
		Fx = (x - a) / (b - a); //一様乱数の確率変数を生成
		Fy = 1 - exp(-1 * ramda * y); //指数分布の確率変数生成
		ofs<< x<<","<<Fx<<","<< y<<","<<Fy << endl;
		cout << x << "," << y << endl;
	}
	double uniave = unisum1 / 1000;//一様乱数の平均
	double expave = expsum1 / 1000;//指数分布の平均
	double unidis = (unisum2/1000) - uniave * uniave; //一様乱数の分散
	double expdis = (expsum2/1000)- expave * expave; //指数分布の分散
	cout << "uniave" << uniave << " " << "expave" << expave << endl;
	cout << "unidis" << unidis << " " << "expdis" << expdis<< endl;
}
