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

int a[22][10010],G[22][22],W[22][22],f[22][22][100010],n,m;

string get(int S) {
    string s;
    for(int i = n - 1;i >= 0;i --) {
        char c = (S >> i & 1) + '0';
        s += c;
    }
    return s;
}

int dfs(int s,int e,int S) {
    if(f[s][e][S] != -1) return f[s][e][S];
    int ans = 0;
    for(int i = 0;i < n;i ++)
        if(i != e && i != s && (S >> i & 1))
            ans = max(ans,min(dfs(s,i,S^(1<<e)),G[i][e]));
    return f[s][e][S] = ans;
}

int main() {
    n = read(),m = read();
    for(int i = 0;i < n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = read();
    if(n == 1) {
        int ans = 1e9;
        for(int k = 1;k < m;k ++) ans = min(ans,abs(a[0][k] - a[0][k+1]));
        cout << ans << endl;
        return 0;
    }
    for(int i = 0;i < n;i ++)
        for(int j = i+1;j < n;j ++) {
            int ans = 1e9;
            for(int k = 1;k <= m;k ++) ans = min(ans,abs(a[i][k] - a[j][k]));
            G[i][j] = G[j][i] = ans;
        }

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++) {
            int ans = 1e9;
            for(int k = 1;k < m;k ++) ans = min(ans,abs(a[j][k] - a[i][k+1]));
            W[i][j] = ans;
        }

    memset(f,-1,sizeof f);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < n;j ++)
            if(i != j)
                f[i][j][(1<<i)|(1<<j)] = G[i][j];
    int ans = 0;
    for(int s = 0;s < n;s ++) {
        for(int e = 0;e < n;e ++) {
            if(s == e) continue;
            int tmp = min(dfs(s,e,(1<<n)-1),W[s][e]);
            ans = max(ans,tmp);
        }
    }
    cout << ans << endl;
}
