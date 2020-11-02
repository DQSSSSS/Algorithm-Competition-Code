#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

map<int,int> mp;
vector<int> g[SZ];

int main() {
    int n = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        int x = read();
        for(int j = 2;j * j <= x;j ++) {
            if(x % j == 0) {
                if(!mp[j]) mp[j] = ++ tot;
                g[mp[j]].push_back(i);
                while(x % j == 0) x /= j;
            }
        }
        if(x != 1) {
            if(!mp[x]) mp[x] = ++ tot;
            g[mp[x]].push_back(i);
        }
    }

   // cout << tot << endl;
    LL ans = 0;
    for(int i = 1;i <= tot;i ++) {
        LL tmp = 1ll * n * (n + 1) / 2;
        LL lst = 0;
     //   for(int x : g[i]) cout << x << " "; puts("");
        for(int x : g[i]) {
            LL len = x - lst - 1;
            tmp -= len * (len + 1) / 2;
            lst = x;
        }
        LL len = n - lst;
        tmp -= len * (len + 1) / 2;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}

