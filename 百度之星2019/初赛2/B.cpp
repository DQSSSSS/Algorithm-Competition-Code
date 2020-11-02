#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

int n,m,g[111][111];

void work(char a[],char b[]) {
    for(int i = 1;i <= m;i ++) {
        int use[111] = {};
        for(int j = 1;j <= m;j ++) {
            if(a[i] == b[j]) {
                use[j] = 1;
            }
        }
        int d[111] = {};
        for(int j = 1;j <= m;j ++) {
            if(g[i][j] && use[j]) d[j] = 1;
        }
        for(int j = 1;j <= m;j ++) g[i][j] = d[j];
    }
}

int vis[SZ],match[SZ],del[SZ];

bool dfs(int u) {
    for(int i = 1;i <= m;i ++) {
        if(g[u][i] && !del[i]) {
            if(vis[i]) continue;
            vis[i] = 1;
            if(!match[i] || dfs(match[i])) {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= m;i ++) {
            for(int j = 1;j <= m;j ++) {
                g[i][j] = 1;
            }
        }
        for(int i = 1;i <= n;i ++) {
            char s[2][111];
            scanf("%s%s",s[0]+1,s[1]+1);
            work(s[0],s[1]);
        }
      /*  for(int i = 1;i <= m;i ++) {
            for(int j = 1;j <= m;j ++) {
                printf("%d ",g[i][j]);
            }
            puts("");
        }*/
        for(int i = 1;i <= m;i ++) match[i] = 0,del[i] = 0;
        bool flag = 0;
        for(int i = 1;i <= m;i ++) {
            for(int j = 1;j <= m;j ++) vis[j] = 0;
            if(!dfs(i)) {
                flag = 1; break;
            }
        }
        if(flag) { puts("-1"); continue; }
        else {
            for(int i = 1;i <= m;i ++) {
                for(int j = 1;j <= m;j ++) {
                    if(g[i][j] && !del[j]) {
                        del[j] = 1;
                        bool flag = 0;
                        for(int k = 1;k <= m;k ++) if(!del[k]) match[k] = 0;
                        for(int k = i+1;k <= m;k ++) {
                            for(int l = 1;l <= m;l ++) vis[l] = 0;
                            if(!dfs(k)) {flag = 1; break;}
                        }
                       // printf("%d %d -> %d\n",i,j,flag);
                        if(flag) del[j] = 0;
                        else {
                            printf("%d%c",j,i==m?'\n':' ');
                            break;
                        }
                    }
                }
            }
        }
    }
}
