#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m;
char s[SZ];
int nx[SZ][22];

void get_nxt() {
    int b[22] = {0},id[22] = {0};
    for(int i = n;i >= 1;i --) {
        int c = s[i] - 'a';
        for(int j = 0;j < m;j ++) {
            if(id[j]) nx[i][j] = b[j];
            b[j] |= 1 << c;
        }
        b[c] = 0;
        id[c] = i;
    }
}

int tim[22];

bitset<(1<<17)> tmp,g,f;
bool mp[22][22];

int main() {
    n = read(),m = read();
    scanf("%s",s + 1);
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < m;j ++)
            mp[i][j] = read();
    get_nxt();

    g.set();
    for(int i = 0;i < m;i ++) {
        for(int j = 0;j <= i;j ++) {
            if(mp[i][j]) continue;
            tmp.set();
            for(int k = 1;k <= n;k ++) {
                if(s[k] - 'a' == i) {
                    if(nx[k][j] && (nx[k][j] >> i & 1) == 0)
                        tmp.reset(((1<<m)-1)^nx[k][j]);
                }
                else if(s[k] - 'a' == j) {
                    if(nx[k][i] && (nx[k][i] >> j & 1) == 0)
                        tmp.reset(((1<<m)-1)^nx[k][i]);
                }
            }

        /*    cout << i << " " << j << endl;
            for(int l = 0;l < (1<<m);l ++)
                if(!tmp[l])
                    cout << l << " ";*/
            //puts("");
            for(int l = (1<<m)-1;l > 0;l --) {
                if(tmp[l]) continue;
                for(int k = 0;k < m;k ++)
                    if(k != i && k != j && (l>>k&1))
                        tmp.reset(l ^ (1<<k));

            }
/*
            for(int k = 0;k < m;k ++) {
                for(int l = 0;l < (1<<m);l ++)
                    if(l >> k & 1)
                        if(k != i && k != j)
                            if(tmp[l^(1<<k)])
                                tmp.set(l);
            }
*/
            g &= tmp;
           // cout << S << " " << i << " " << j << endl;
          /*  for(int l = 0;l < (1<<m);l ++) {
                cout << (l&S) << " " << tmp[l] << " ";
                for(int k = 0;k < m;k ++)
                    if(l >> k & 1) printf("%c ",k+'a');
                puts("");
            }
            puts("");*/

        }
    }

  /* for(int j = 0;j < (1<<m);j ++){
        cout << j << " " << g[j] << " ";
        for(int i = 0;i < m;i ++)
            if(j >> i & 1) printf("%c ",i+'a');
        puts("");
    }*/
    for(int i = 1;i <= n;i ++) tim[s[i]-'a']++;

    f[(1<<m)-1] = 1;
    for(int S = (1<<m)-1;S > 0;S --) {
        if(!f[S]) continue;
        for(int i = 0;i < m;i ++) {
            if(S >> i & 1) {
                int x = S ^ (1 << i);
                if(f[x]) continue;
                f[x] = g[x];
            }
        }
    }

    int ans = n;
    for(int S = (1<<m)-1;S >= 0;S --) {
        if(f[S]) {
            int tmp = 0;
            for(int i = 0;i < m;i ++) {
                if(S >> i & 1) {
                    tmp += tim[i];
                }
            }
            ans = min(ans,tmp);
        }
    }

    printf("%d\n",ans);
}
