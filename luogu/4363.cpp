#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

int A[22][22],B[22][22];
bool vis[SZ];
int f[SZ],n,m;
pii tmp[22];

int dfs(int S,int b) {
    if(vis[S]) return f[S];
    vis[S] = 1;
    if(b) {
        int ans = 1e9;
        for(int i = 0,j = m,ii = 1;i < n+m;i ++) {
            if(S>>i&1) {
                if(i+1 < n+m && !(S>>(i+1)&1)) {
                    ans = min(ans,dfs(S^(3<<i),b^1)-B[ii][j]);
                }
                j --;
            }
            else ii ++;
        }
        return f[S] = ans;
    }
    else {
        int ans = -1e9;
        for(int i = 0,j = m,ii = 1;i < n+m;i ++) {
            if(S>>i&1) {
                if(i+1 < n+m && !(S>>(i+1)&1)) {
                    ans = max(ans,dfs(S^(3<<i),b^1)+A[ii][j]);
                }
                j --;
            }
            else ii ++;
        }
        return f[S] = ans;
    }
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            A[i][j] = read();
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            B[i][j] = read();
        }
    }
    f[(1<<(n+m))-(1<<n)] = 0;
    vis[(1<<(n+m))-(1<<n)] = 1;
    printf("%d\n",dfs((1<<m)-1,0));
}

