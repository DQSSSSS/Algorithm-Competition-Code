#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL lcm(LL a,LL b) {
	return a / __gcd(a,b) * b;
}

struct frac {
	LL x,y;
	frac(LL a = 0,LL b = 1) {
		if(b < 0) a = -a,b = -b;
		x = a / __gcd(a,b);
		y = b / __gcd(a,b);
	}

	frac operator +(const frac &o) const {
        return frac(x * o.y + y * o.x,y * o.y);
	}
	frac operator -(const frac &o) const {
        return frac(x * o.y - y * o.x,y * o.y);
	}
	frac operator *(const frac &o) const {
        return frac(x * o.x,y * o.y);
	}
	frac operator /(const frac &o) const {
        return frac(x * o.y,y * o.x);
	}
	void print() {
		if(y == 1) printf("%lld\n",x);
        else printf("%lld/%lld\n",x,y);
	}
};


int main(){

}
