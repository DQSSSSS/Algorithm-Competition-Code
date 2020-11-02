#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500100;
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

int n;
vector<int> g[SZ];
char c[SZ];
int du[SZ],w[SZ],notleaf[SZ];

int check() {
    if(n <= 2) return 0;
    if(n == 3) {
        int t = 0;
        for(int i = 1;i <= n;i ++) if(c[i] == 'W') t ++;
        if(t >= 2) return 1;
        return 0;
    }
    int leaf = 0,wleaf = 0;
    //for(int i = 1;i <= n;i ++) cout << i << " " << du[i] << " " << w[i] << " " << notleaf[i] << endl;
    for(int i = 1;i <= n;i ++) {
        if(du[i] >= 4) return 4;
        if(w[i] >= 2) return 2;
        if(c[i] == 'W' && w[i]) return 1;
        if(du[i] >= 3 && notleaf[i] >= 2) return 3;
        if(c[i] == 'W' && du[i] > 1) return 6;
        if(w[i] && du[i] >= 3) return 7;

        if(du[i] == 1) leaf ++;
        if(du[i] == 1 && c[i] == 'W') wleaf ++;
    }
    if(leaf == 2 && wleaf == 2) {
        if(n % 2) return 9;
        return 0;
    }
    if(leaf == 3 && wleaf == 1) {
        if(n >= 6 && n % 2 == 0) return 10;
        return 0;
    }
    if(leaf == 4) {
        if(n >= 7 && n % 2) return 5;
        return 0;
    }
    return 0;
}

void init() {
    for(int i = 1;i <= n;i ++) {
        g[i].clear();
        du[i] = 0;
        w[i] = 0;
        notleaf[i] = 0;
    }
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read();
        init();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
            du[x] ++; du[y] ++;
        }
        scanf("%s",c+1);
        for(int u = 1;u <= n;u ++) {
            for(int i = 0;i < g[u].size();i ++) {
                int v = g[u][i];
                if(c[v] == 'W') w[u] ++;
                if(du[v] > 1) notleaf[u] ++;
            }
        }
        int flag = check();
       // cout << flag << endl;
        //if(++ cc == 8554 && !flag) cout << c+1 << endl;
        puts(flag ? "White" : "Draw");
    }
    return 0;
}
/**
1
7
1 2
4 3
2 4
4 5
5 6
5 7
NNNNNNN

233
4
1 2
1 3
1 4
WNNN
6
1 2
2 3
2 4
4 5
5 6
NNNNNW
9
1 2
2 3
3 4
4 5
5 6
6 7
2 8
6 9
NNNNNNNNN
*/
