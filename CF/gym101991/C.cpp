#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

map<string, int> mp[3];

int get(int x) {
    int pp = x / 5 * 5;
    if(x - pp == 1) x = pp;
    else if(x - pp == 4) x = pp + 5;
    return x;
}

int main() {
    freopen("coffee.in","r",stdin);
    int T = read();
    char s[22];
    while(T --) {
        int n = read(),m = read();
        mp[0].clear();
        mp[1].clear();
        mp[2].clear();
        for(int i = 1;i <= n;i ++) {
            scanf("%s",s);
            string ss = s;
            for(int j = 0;j < 3;j ++)
                mp[j][ss] = read();
        }
        for(int i = 1;i <= m;i ++) {
            char name[22],sz[22],cof[22];
            scanf("%s%s%s",name,sz,cof);
            int d;
            string cofname = cof;
            if(sz[0] == 's') d = 0;
            if(sz[0] == 'm') d = 1;
            if(sz[0] == 'l') d = 2;
            int ans = 100 / m + mp[d][cofname];
            printf("%s %d\n",name,get(ans));
        }
    }
}
