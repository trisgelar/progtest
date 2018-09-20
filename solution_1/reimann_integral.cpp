#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
	return pow(x,2.0);
}
double preRiemannSum(int n, double a, double b){
	double s=0.0;
	double inc=0.0;
	double xi=0.0;
	inc = (b - a) / n;
	for (int i = 1; i <= n; ++i)
	{
		xi = ((a + (i*inc))/2);
		s = s + f(xi)*((i+(i*inc))-i);
	}	
	return s;
}

// recursive
double riemannSum(double s, double a, double b, double e){
	double a0, a1, b0, b1, ds = 0.0;
	double s0,s1 = 0.0;
	int j=0;
	a0 = a;
	a1 = (a+b)/2;
	b0 = a1;
	s0 = (b0-a0)*f((a0+b0)/2);
	s1 = (b1-a1)*f((a1+b1)/2);

	if(fabs(s-(s0+s1)) >= e){
		return riemannSum(s0,a0,b0,e)+riemannSum(s1,a1,b1,e);
	}else{
		return s;
	}
}

int main(){
	double so = preRiemannSum(10, 1.0, 10.0);
	cout << "Pre Calculation Riemann : " << so << endl;
	cout << riemannSum(so, 1, 10, 5.0) << endl;
	return 0;
}