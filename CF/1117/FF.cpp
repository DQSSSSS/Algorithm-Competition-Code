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

int tim[22],f[SZ],tmp[SZ],g[SZ],vis[SZ];

int dfs(int S,int n) {
    if(n == 0) return 0;
    if(f[S]) return f[S];
    if(g[S]) return f[S] = INF;
    int ans = n;
    for(int i = 0;i < m;i ++) {
        if((S >> i & 1) == 0)
            ans = min(ans,dfs(S^(1<<i),n-tim[i]));
    }
    return f[S] = ans;
}

bool mp[22][22];

int main() {
    n = read(),m = read();
    scanf("%s",s + 1);
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < m;j ++)
            mp[i][j] = read();
    get_nxt();

    for(int i = 0;i < m;i ++) {
        for(int j = 0;j <= i;j ++) {
            if(mp[i][j]) continue;
            for(int k = 0;k < (1 << m);k ++) tmp[k] = 0;
            for(int k = 1;k <= n;k ++) {
                if(s[k] - 'a' == i) {
                    if(nx[k][j]) tmp[nx[k][j]] = 1;
                }
                else if(s[k] - 'a' == j) {
                    if(nx[k][i]) tmp[nx[k][i]] = 1;
                }
            }
            for(int k = 0;k < m;k ++)
                for(int l = 0;l < (1<<m);l ++)
                    if(l >> k & 1)
                        tmp[l] |= tmp[l^(1<<k)];
            int S = 1 << m; S --;
            S &= (1<<m)-1 - (1 << i);
            S &= (1<<m)-1 - (1 << j);
           // cout << S << " " << i << " " << j << endl;
          /*  for(int l = 0;l < (1<<m);l ++) {
                cout << (l&S) << " " << tmp[l] << " ";
                for(int k = 0;k < m;k ++)
                    if(l >> k & 1) printf("%c ",k+'a');
                puts("");
            }
            puts("");*/
            for(int l = 0;l < (1<<m);l ++) {
                g[l&S] |= tmp[l];
            }
        }
    }
 /*  for(int j = 0;j < (1<<m);j ++){
        cout << j << " " << g[j] << " ";
        for(int i = 0;i < m;i ++)
            if(j >> i & 1) printf("%c ",i+'a');
        puts("");
    }

    for(int i = 1;i <= n;i ++) {
        printf("%d:\n",i);
        for(int j = 0;j < m;j ++) {
            printf("%c : ",j+'a');
            for(int k = 0;k < m;k ++)
                if(nx[i][j] >> k & 1)
                    printf("%c ",k+'a');
            puts("");
        }
    }
*/
   /* for(int i = 0;i < m;i ++)
        for(int j = 0;j < (1<<m);j ++)
            if(j & (1<<i)) g[j] |= g[j^(1<<i)];
    g[(1<<m)-1] = 0;*/
   /* for(int j = 0;j < (1<<m);j ++){
        for(int i = 0;i < m;i ++)
            if(j >> i & 1) printf("%c ",i+'a');
        cout << j << " " << g[j] << endl;
    }*/
    for(int i = 1;i <= n;i ++) tim[s[i]-'a']++;
    printf("%d\n",dfs(0,n));
}
