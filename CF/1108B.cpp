#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int t[SZ],a[SZ];

int main() {
    int n = read();
    int maxn = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),maxn = max(maxn,a[i]),t[a[i]] ++;
    for(int i = 1;i <= maxn;i ++)
        if(maxn % i == 0) t[i] --;
    int a = 0;
    for(int i = 1;i <= maxn;i ++) {
        if(t[i]) a = max(a,i);
    }
    cout << maxn << " " << a << endl;
}
