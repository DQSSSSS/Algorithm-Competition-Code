#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
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

int a[SZ],fuck[SZ];

int main() {
    int T = read();
    while(T --) {
        LL n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            fuck[a[i]] = 0;
        }
        sort(a+1,a+1+n);
        int ans = 0;
        for(int i = n;i >= 1;i --) {
            if(fuck[a[i]]) continue;
            if(a[i] - ans * m > 0) {
                ans ++;
                fuck[a[i]] = 1;
            }
        }
        printf("%d\n",ans);
    }
}

