#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef pair<LL,LL> pii;
typedef pair<UI,UI> puu;
const int SZ = 8e6 + 10;
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

map<puu,int> mp;
map<puu,int> mark;
vector<puu> ans;

void dfs(UI now,UI l) {
    if(l == 33) return ;
    puu x = make_pair(now,l);
    if(mark.count(x)) return ;
    if(mp.count(x)) {
        dfs(now<<1,l+1);
        dfs(now<<1|1,l+1);
    }
    else {
        ans.push_back(x);
    }
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        mp.clear();
        mark.clear();
        ans.clear();
        printf("Case #%d:\n",++ cc);
        int n = read();
        for(int i = 1;i <= n;i ++) {
            UI a,b,c,d;
            int l;
            scanf("%u.%u.%u.%u/%d",&a,&b,&c,&d,&l);
            UI x = a;
            x <<= 8; x |= b;
            x <<= 8; x |= c;
            x <<= 8; x |= d;
            x >>= 32-l;
            mark[make_pair(x,l)] = 1;
            l --; x /= 2;
            while(l >= 0) {
                mp[make_pair(x,l)] = 1;
                l --; x /= 2;
            }
        }
        dfs(0,0);

        printf("%d\n",ans.size());
        for(pii x : ans) {
            UI d = x.first << (32-x.second),l = x.second;
            printf("%u.%u.%u.%u/%u\n",d>>24&255,d>>16&255,d>>8&255,d&255,l);
        }
    }
}
/**
3
0
1
0.0.0.0/1
1
128.0.0.0/1
*/
