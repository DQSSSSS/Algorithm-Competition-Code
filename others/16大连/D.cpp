#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a,b,x,y;

bool check(LL x,LL y) {
	if(x + y == a && x / __gcd(x,y) * y == b) return true;
	return false;
}

bool work(LL d) {
	LL a1 = a / d,b1 = b / d;
	LL delta = a1 *a1 - 4 * b1;
	LL gend = sqrt(delta);
	//cout << d << endl;
	if(gend * gend != delta) return false;
	if((a1 + gend) % 2) return false;
	LL x1 = a1 + gend >> 1,y1 = a1 - x1;
	LL x2 = a1 - gend >> 1,y2 = a1 - x2;
	//cout << d << " " << x1 << " " << x2 << endl;
	if(check(x1 * d,y1 * d)) { x = x1 * d; y = y1 * d; return true; }  
	if(check(x2 * d,y2 * d)) { x = x2 * d; y = y2 * d; return true; }
	//cout << "ff" << endl;
	return false;
}


void bl() {
	for(LL i = 0;i <= a;i ++) {
		LL x = i,y = a - i;
		if(x/__gcd(x,y)*y == b) { cout <<x << " " << y << endl; return ; }
	}
	puts("No Solution");
}

int main() {
	//cout << __gcd(308,490) << " " << 308/14 << " " << 490/14 << endl;
	while(~scanf("%lld%lld",&a,&b)) {
		x = y = -1;
		for(LL i = 1;i * i <= a;i ++) {
			if(a % i == 0) {
				if(b % i == 0) if(work(i)) break;
				if(b % (a/i) == 0)
					if(work(a / i)) break;
			}
		}
		//bl();
		//if(a == b) { printf("%lld %lld\n",0,a); continue; }
		if(x == -1) puts("No Solution");
		else {
			if(x > y) swap(x,y);
			//if(check(x,y)) 
				printf("%lld %lld\n",x,y);
			//printf("%lld %lld 233\n",x,y);
		}
	}
	return 0;
}
