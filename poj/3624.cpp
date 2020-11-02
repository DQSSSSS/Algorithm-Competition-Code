#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int w[SZ],d[SZ];
LL f[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) d[i] = read(),w[i] = read();
    for(int i = 1;i <= n;i ++)
        for(int j = m;j >= d[i];j --)
            f[j] = max(f[j],f[j-d[i]]+w[i]);
    cout << f[m] << endl;
}
