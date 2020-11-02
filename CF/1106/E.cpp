#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100100;
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

struct haha {
    int d,w;
};

bool operator <(haha a,haha b) {
    if(a.w != b.w) return a.w > b.w;
    return a.d > b.d;
}

multiset<haha> s;

vector<haha> ins[SZ],del[SZ];

int nx[SZ],val[SZ];
LL f[SZ][210];

int main() {
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= k;i ++) {
        int s = read(),t = read(),d = read(),w = read();
        ins[s].push_back((haha){d,w});
        del[t].push_back((haha){d,w});
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < ins[i].size();j ++) {
            s.insert(ins[i][j]);
        }
        if(s.empty()) { nx[i] = i + 1; continue;}
        nx[i] = s.begin() -> d + 1;
        val[i] = s.begin() -> w;
        for(int j = 0;j < del[i].size();j ++) {
            multiset<haha> :: iterator it = s.find(del[i][j]);
            s.erase(it);
        }
    }
    nx[0] = 1;

    for(int i = 0;i <= n+1;i ++)
        for(int j = 0;j <= m;j ++)
            f[i][j] = 1e18;
    f[0][0] = 0;

   // for(int i = 0;i <= n;i ++) cout << nx[i] << " "; puts("");
   // for(int i = 0;i <= n;i ++) cout << val[i] << " "; puts("");

    for(int i = 0;i <= n;i ++)
        for(int j = 0;j <= m;j ++) {
            f[nx[i]][j] = min(f[nx[i]][j],f[i][j] + val[i]);
            if(j < m) f[i+1][j+1] = min(f[i+1][j+1],f[i][j]);
        }
    LL ans = 1e18;
    for(int i = 0;i <= m;i ++) ans = min(ans,f[n+1][i]);
    cout << ans << endl;
    return 0;
}
/**
5 0 3
1 3 3 5
1 3 4 5
2 5 5 8
*/
