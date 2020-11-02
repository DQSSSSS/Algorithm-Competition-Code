#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

vector<int> g;
ULL G[44];
map<ULL,int> f;

int dfs(ULL S) {
    if(f.count(S)) return f[S];
    int p = __builtin_ctzll(S);
    return f[S] = max(dfs(S ^ (1ll << p)),dfs(S & G[p]) + 1);
}

map<string,int> mp;

int n,m;
void work() {
    ULL S = 1ll << m; S --;
    for(int j : g) S &= ~(1ll << j);
    for(int j : g) G[j] &= S;
    g.clear();
}

int main() {
    n = read(),m = read();
    for(int i = 0;i < m;i ++) G[i] = (1ll << m) - 1;

    for(int i = 1,j = 0;i <= n;i ++) {
        int x = read();
        if(x == 1) work();
        else {
            char s[44]; scanf("%s",s); string name = s;
            if(!mp.count(name)) mp[name] = j ++;
            g.push_back(mp[name]);
        }
    }
    work();
    f[0] = 0;
    cout << dfs((1ll << m) - 1) << endl;
    return 0;
}

