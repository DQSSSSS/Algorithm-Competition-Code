#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
const int mod = 100003;
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

int pri[150000010 / 10],phi[150000010],tot;
bool vis[150000010];

int g[SZ];
//vector<int> g[SZ];

void shai(int n) {
    phi[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
            }
            else {
                phi[m] = phi[i] * (pri[j]-1);
            }
        }
    }
    /*int maxd = 0;
    for(int i = 1;i < tot;i ++) {
        if(pri[i+1] - pri[i] >= 100) printf("%d %d\n",pri[i],pri[i + 1]),maxd ++;
    }
    cout << maxd << endl;*/
    for(int i = 1;i <= n;i ++) {
       // g[phi[i]].push_back(i);
        g[phi[i]]++;
    }
    int maxd = 0,v;
    for(int i = 1;i <= n;i ++) {
        if(maxd<(int)g[i]) maxd = g[i],v = i;
    }
    cout << maxd << " " << v << endl;
    /*for(int i = 1;i <= 100;i ++) {
        printf("%d: ",i);
        for(int x : g[i]) printf("%d ",x); puts("");
    }*/
}

int main() {
    shai(1.5e8);
}
