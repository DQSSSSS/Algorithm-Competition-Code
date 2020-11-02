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

int n,m;
LL a[SZ],b[SZ];

bool pd() {
	LL suma = 0,sumb = 0;
	for(int i = 1;i <= n;i ++) suma += a[i];
	for(int i = 1;i <= m;i ++) sumb += b[i];
    return suma != sumb;
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    m = read();
    for(int i = 1;i <= m;i ++) b[i] = read();
    if(pd()) { puts("-1"); return 0; }
    LL suma = a[1],sumb = b[1],pa = 1,pb = 1,len = 0;
    while(pa <= n && pb <= m) {
        if(suma == sumb) { suma = a[++ pa],sumb = b[++ pb],len ++; }
        if(suma < sumb) { suma += a[++ pa]; continue; }
        if(suma > sumb) { sumb += b[++ pb]; continue; }
    }
    cout << len << endl;
    return 0;
}
