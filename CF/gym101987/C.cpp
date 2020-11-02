#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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

int n;
double r[SZ],rr[SZ];
int p[SZ];

double work(int L,int R) {
    for(int i = 1;i <= n;i ++) rr[i] = r[p[i+L-1]];
    double ans = rr[1] + rr[n];
    for(int i = 1;i < n;i ++)
        ans += sqrt(rr[i] * rr[i+1]) * 2;
    return ans;
}

void get(int n) {
    for(int i=1,d=n/2;i<=n/2;i+=2,d-=2)
        p[i] = d;
    for(int i=2,d=n/2+2;i<=n/2;i+=2,d+=2)
        p[i] = d;
    for(int i=n,d=n/2+1;i>n/2;i-=2,d+=2)
        p[i] = d;
    for(int i=n-1,d=n/2-1;i>n/2;i-=2,d-=2)
        p[i] = d;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) r[i] = read();
    sort(r+1,r+1+n);
    if(n % 2 == 0) {
        get(n);
        printf("%.10f\n",work(1,n));
    }
    else {
        get(n-1);
        for(int i = 1;i <= n - 1;i ++) if(p[i] > n/2) p[i] ++;
        p[0] = n/2+1;
        p[n] = n/2+1;
       // for(int i = 1;i <= n;i ++) cout << p[i] << " "; puts("");
        printf("%.10f\n",min(work(1,n),work(0,n-1)));
    }
}
