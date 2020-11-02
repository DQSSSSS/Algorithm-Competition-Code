#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

LL Mu[233];

bool work(int id,int x) {
    LL g = 0;
    for(LL i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            LL t = 0;
            while(x % i == 0) x /= i,t ++;
            g = __gcd(g,t);
        }
    }
    if(x != 1) g = __gcd(g,1ll);
   // cout << id << " " << g << endl;
    return g == 1;
}

LL mi(LL a,LL b,LL x) {
    LL ans = 1;
    for(int i = 1;i <= b;i ++) {
        if(x / a < ans) return x + 1;
        ans *= a;
    }
    return ans;
}

LL lst;

LL Div(LL x,LL n) {
	//cout << x << " " << lst << endl;
    LL l = 1,r = lst + 1;
    while(r - l > 1) {
    	LL mid = l + r >> 1;
        if(mi(mid,x,n) <= n) l = mid;
        else r = mid;
    }
  //  cout << l << endl;
    return lst = l;
}

LL work(LL x) {
    LL ans = 0;
    for(int i = 2;i <= 64;i ++)
        ans += Mu[i] * Div(i,x);
    return ans + x + 1;
}

int mu(LL x) {
    int ans = 1;
	for(LL i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            LL t = 0;
            while(x % i == 0) x /= i,t ++;
            if(t >= 2) return 0;
            ans = -ans;
        }
    }
    if(x != 1) ans = -ans;
    return ans;
}
int main() {
	int T = read();
	for(int i = 1;i <= 100;i ++) Mu[i] = mu(i);
	while(T --) {
        LL n = read();
        lst = sqrt(n) + 1;
       	printf("%lld\n",work(n));
	}
	return 0;
}
