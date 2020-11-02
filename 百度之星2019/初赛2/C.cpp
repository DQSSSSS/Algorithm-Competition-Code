#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

int a[SZ],n;

int maxn;
vector<int> g[SZ],tmp[SZ];

void dfs(int pos) {
   // cout << pos << " " << d << " " << maxd << endl;
    if(pos == n+1) {
      /*  puts("----------------");
        for(int i = 1;i <= n;i ++) {
            for(int x : tmp[i]) printf("%d ",x);
            puts("");
        }*/
        int x = 0;
        for(int i = 1;i <= n;i ++)
            for(int d : tmp[i])
                x ^= d;
        if(x > maxn) {
            for(int i = 1;i <= n;i ++) g[i] = tmp[i];
            maxn = x;
        }
        return ;
    }
    for(int i = 0;i*2<=a[pos];i ++) {
        tmp[pos].clear();
        tmp[pos].push_back(i);
        tmp[pos].push_back(i);
        tmp[pos].push_back(a[pos]-2*i);
        dfs(pos+1);
    }
}

int main() {
    freopen("C.in","r",stdin); freopen("std.out","w",stdout);
    int T = read();
    while(T --) {
        maxn = -1;
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        dfs(1);
      /*  printf("-----------\n");
        printf("ans: %d\n",maxn);
        for(int i = 1;i <= n;i ++) {
            for(int x : g[i]) printf("%d ",x);
            puts("");
        }*/
        cout << maxn <<endl;
    }
}
