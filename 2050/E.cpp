#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e4 + 10;
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

char s[SZ];

bool check(int a,int b) {
    return (a==11&&b<10) || (b==11&&a<10) || (a>=10&&b>=10&&abs(a-b)>=2);
}

int f[SZ][12][12],visf[SZ][12][12];
int g[SZ][3],visg[SZ][3];

int dfsf(int i,int a,int b);
int dfsg(int i,int delta);

int dfs(int i,int a,int b) {
    if(i == 0) {
        if(type == 0 && a == 0 && b == 0) return 0;
        return -INF;
    }
    if(a < 0 || b < 0) return -INF;
    if(delta) return -INF;

    if(visf[i][a][b]) return f[i][a][b];
    visf[i][a][b]=1;
    if(s[i] == 'A') {
        if(a) return f[i][a][b] = dfsf(i-1,a-1,b);
        else {
            if(b != 0) return -INF;
            int ans = 1+dfsg(i-1,1);
            for(int j = 0;j <= 9;j ++) ans = max(ans,1+dfsf(i-1,10,j));
            return f[i][a][b] = ans;
        }
    }
    else if(s[i] == 'B') {
        if(b) return f[i][a][b] = dfsf(i-1,a,b-1);
        else {
            if(a != 0) return -INF;
            int ans = 1+dfsg(i-1,-1);
            for(int j = 0;j <= 9;j ++) ans = max(ans,1+dfsf(i-1,j,10));
            return f[i][a][b] = ans;
        }
    }
    else {
        int ans = -INF;
        if(a) ans = max(ans,dfsf(i-1,a-1,b));
        else if(b == 0) {
            ans = max(ans,1+dfsg(i-1,1));
            for(int j = 0;j <= 9;j ++) ans = max(ans,1+dfs(i-1,0,10,j,0));
        }

        if(b) ans = max(ans,dfs(i-1,0,a,b-1,0));
        else if(a == 0) {
            ans = max(ans,1+dfs(i-1,1,0,0,-1));
            for(int j = 0;j <= 9;j ++) ans = max(ans,1+dfs(i-1,0,j,10,0));
        }
        return f[i][a][b] = ans;
    }
}

int dfsg(int i,int delta) {
    if(i == 0) return -INF;
    if(a || b) return -INF;
    if(abs(delta) > 1) return -INF;

    if(visg[i][delta+1]) return g[i][delta+1];
    visg[i][delta+1]=1;
    if(s[i] == 'A') {
        if(delta == -1) return -INF;
        int ans = dfs(i-1,1,0,0,delta-1);
        if(delta == 1) ans = max(ans,dfs(i-1,0,10,10,0));
        return g[i][delta+1] = ans;
    }
    else if(s[i] == 'B') {
        if(delta == 1) return -INF;
        int ans = dfs(i-1,1,0,0,delta+1);
        if(delta == -1) ans = max(ans,dfs(i-1,0,10,10,0));
        return g[i][delta+1] = ans;
    }
    else {
        int ans = -INF;
        if(delta == -1) {
            ans = dfs(i-1,0,10,10,0);
            ans = max(ans,dfs(i-1,1,0,0,0));
        }
        else if(delta == 0) {
            ans = max(dfs(i-1,1,0,0,1),dfs(i-1,1,0,0,-1));
        }
        else {
            ans = dfs(i-1,0,10,10,0);
            ans = max(ans,dfs(i-1,1,0,0,0));
        }
        return g[i][delta+1] = ans;
    }
}

int main() {
    freopen("E.txt","r",stdin);
    freopen("E2.txt","w",stdout);
    int T = read();
    while(T --) {
        int n = 1;
        char c = getchar();
        while(c == 'A' || c == 'B' || c == '?') s[n ++] = c,c = getchar();
        n --;
        for(int i = 0;i <= n;i ++) {
            memset(f[i],-63,sizeof f[i]);
            memset(g[i],-63,sizeof g[i]);
            memset(visf[i],0,sizeof visf[i]);
            memset(visg[i],0,sizeof visg[i]);
        }
        f[0][0][0] = 0;
        int ans = 0;
        for(int i = 0;i <= 10;i ++)
            for(int j = 0;j <= 10;j ++) {
                ans = max(ans,dfs(n,0,i,j,0));
            }
        for(int i = -1;i <= 1;i ++) {
            ans = max(ans,dfs(n,1,0,0,i));
        }
/*
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j <= 10;j ++)
                for(int k = 0;k <= 10;k ++) {
                    if(f[i][j][k] >= 0) {
                        printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
                    }
                }
        }
        puts("");
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j <= 2;j ++)
                if(g[i][j] >= 0) {
                    printf("%d %d %d\n",i,j-1,g[i][j]);
                }
        }
        */
        printf("%d\n",ans);
    }
}
/**
BBBBBBBBBB?AAAABAAAABBBBBBBAABBB

10B 4A 1B 4A

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

*/
