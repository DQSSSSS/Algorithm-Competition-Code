#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) fa[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        x = find(x),y = find(y);
        if(x == y) ans ++;
        else fa[x] = y;
    }
    cout << ans << endl;
    return 0;
}

/**
6 7
2 5
1 2
1 3
2 3
1 4
1 5
4 5
*/
