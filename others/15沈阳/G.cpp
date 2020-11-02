#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
const int SZ = 1e6 + 10;
const LL INF = 1e18;
const LD eps = 1e-5;

double t,v1,v2;

LD jie(LD A,LD B,LD v1,LD v2) {
	LD v = pow(v1/v2,2);
	LD a = 1-v,b = -2*A*v,c = B*B-A*A*v;
	LD delta = b*b-4*a*c;
	if(delta < -eps) return -1;//puts("no solution");
	if(fabs(delta) < eps) {
		delta = 0;
		LD x = -b/(2*a);
		if(fabs(x) < eps) x = 0;
		if(fabs(x - 300) < eps) x = 300;
		if(0 <= x && x <= 300 + eps) return x;
		return -1;
	}
	LD y;
	if(b < 0) y = -0.5*(b-sqrt(delta));
	else y = -0.5*(b+sqrt(delta));		
	//LD x1 = (-b+sqrt(delta)) / (2*a);
	//LD x2 = (-b-sqrt(delta)) / (2*a);
	LD x1 = y / a;
	LD x2 = c / y;
	if(x1 > x2) swap(x1,x2);
	if(x1 < 0 && x2 < 0) return -1;
	if(fabs(x1) < eps) x1 = 0;
	if(fabs(x2) < eps) x2 = 0;
	if(fabs(x1 - 300) < eps) x1 = 300;
	if(fabs(x2 - 300) < eps) x2 = 300;
	bool f1 = 0,f2 = 0;
	LD x;
	if(0 <= x1 && x1 <= 300 + eps) x = x1,f1 = 1;
	if(0 <= x2 && x2 <= 300 + eps) x = x2,f2 = 1;
	if(f1 && f2) while(1);
	//x = x2;
	//cout << x1 << " " <<x2 << " " << x << endl;
	return x;
}
	
bool check() {
	if(v1 >= v2) return true;
	LD x1 = jie(300,300,v1,v2);
	//cout << "x1 " << x1 << endl;
	int t1 = 0;
	if(x1 >= 0) {
		if(fabs(x1 - 300) > eps && ( 300 - x1) / v2 + t + eps >= (x1+300)/v1) t1 ++;
		if(( 600 - x1) / v2 + t + eps >= (x1+600)/v1) t1 ++;
		if(( 900 - x1) / v2 + t + eps >= (x1+900)/v1) t1 ++;
		if(t1 >= 2) return true;
	}
	
	LD x2 = jie(-900,300,v1,-v2);
	//cout << "x2 " << x2 << endl;
	int t2 = 0;
	if(x2 >= 0) {
		LD dd = sqrt(pow(300,2) + pow(300-x2,2));
		if(x2 > eps && x2        / v2 + t + eps >= (dd+600) / v1) t2 ++;
		if(          ( x2 + 300) / v2 + t + eps >= (dd+900) / v1) t2 ++;
		if(t2 >= 2) return true;
	}

	LD x3 = jie(600-300*(v2/v1),300,v1,v2);
	//cout << "x3 " << x3 << endl;
	int t3 = 0;
	if(x3 >= 0) {
		if(fabs(x3 - 300) > eps &&  (300 - x3) / v2 + t + eps >= (x3+300) / v1) t3 ++;
		if(                         (600 - x3) / v2 + t + eps >= (x3+600) / v1) t3 ++;
		if(t3 >= 2) return true;
	}
	return false;
}
	
int main() {
	int T,cc = 0;
    scanf("%d",&T);
    while(T --){
        scanf("%lf%lf%lf",&t,&v1,&v2);
        printf("Case #%d: ",++ cc);
        if(check()) puts("Yes");
        else puts("No");
    }
    return 0;
}

/*
233
2000 100 300
*/
