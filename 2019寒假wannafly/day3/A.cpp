#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

struct frac {
    LL x,y;
    frac(LL xx,LL yy = 1) { LL d = __gcd(xx,yy); x = xx / d; y = yy / d; }
    frac operator +(frac o) { return frac(x*o.y+y*o.x,y*o.y); }
    frac operator -(frac o) { return frac(x*o.y-y*o.x,y*o.y); }
    frac operator *(frac o) { return frac(x*o.x,y*o.y); }
    frac operator /(frac o) { return frac(x*o.y,y*o.x); }
    bool operator ==(frac o) { return o.x == x && o.y == y; }
};

int n;
frac num[233];

bool dfs(int S) {

}

int tot = 0;

bool dfs_node(int d) {
    if(d == 10) return ;
    if(n >= 1) {
        n = d;
        if(!dfs((1<<n)-1)) { /// no solution
            for(int i = 0;i < n;i ++) printf("%d ",num[i].x); puts("");
            tot ++;
        }
        else return true;
    }
    for(int i = 1;i <= 10;i ++) {
        num[d] = i;
        if(dfs_node(d+1)) return true;
        num[d] = 0;
    }
    return false;
}

int main() {
    dfs_node(0);
    cout << tot << endl;
    return 0;
}
