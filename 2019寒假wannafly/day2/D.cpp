#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

int mp[22][22];
LL f[22][20010];
vector<int> rt[20010];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int u = read()-1,v = read()-1,w = read();
        mp[u][v] = mp[v][u] = max(w,mp[u][v]);
    }
    for(int i = 1;i < (1 << n);i ++) {
        for(int j = 0;j < n;j ++)
            if(i >> j & 1)
                rt[i].push_back(j),f[j][i] = -1e18;
    }
    for(int j = 0;j < n;j ++) f[j][1 << j] = 0;
    for(int S = 0;S < (1 << n);S ++) {
        for(int ii = 0;ii < rt[S].size();ii ++) {
            int i = rt[S][ii];
            int tmpS = S ^ (1 << i);
            for(int Sj = tmpS;Sj;Sj = (Sj - 1) & tmpS) {
                for(int jj = 0;jj < rt[Sj].size();jj ++) {
                    int j = rt[Sj][jj];
                    if(mp[i][j] == 0) continue;
                    int Si = S ^ Sj;
                    LL w = f[i][Si] + f[j][Sj] + 1ll * rt[Sj].size() * (n - rt[Sj].size()) * 1ll * mp[i][j];
                    f[i][S] = max(f[i][S],w);
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 0;i < n;i ++) ans = max(ans,f[i][(1 << n) - 1]);
    cout << ans << endl;
    return 0;
}
