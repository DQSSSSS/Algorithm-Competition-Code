#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e7 + 10;
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

char mp[22][22];
int A[22][22];
int vis[1<<24],cc;
int f[1<<24],n;
pii tmp[22];

void print(int S) {
    for(int i = 2*n-1;i >= 0;i --) printf("%d",S>>i&1);
}

#define ABS(a) ((a)<0?-(a):(a))
#define MIN(a,b) min(a,b)

inline int dfs(int S) {
    if(vis[S] == cc) return f[S];
    vis[S] = cc;
    int tmp[3][2*n+1];
    tmp[0][0] = tmp[1][0] = tmp[2][0] = 0;
    int w[2*n];
    for(int i = 0,j = n,ii = 1;i < 2*n;i ++) {
        if(S>>i&1) {
            if(i+1 < 2*n && !(S>>(i+1)&1)) {
                w[i] = A[ii][j];
                int c;
                char x = mp[ii][j];
                if(x == '.') c=0;
                else if(x == 'B') c=1;
                else if(x == 'W') c=2;
                tmp[c][++ tmp[c][0]] = i;
            }
            j --;
        }
        else ii ++;
    }
    int ans = INF;
    if(tmp[0][0]) {
        for(int p = 1;p <= tmp[0][0];p ++) {
            int i = tmp[0][p];
            ans = min(ans,dfs(S^(3<<i)));
        }
        return f[S] = ans;
    }

    for(int j = 1;j < 3;j ++)
        for(int p = 1;p <= tmp[j][0];p ++) {
            int i = tmp[j][p];
            ans = min(ans,dfs(S^(3<<i)) + w[i]);
        }
    for(int p1 = 1;p1 <= tmp[1][0];p1 ++) {
        int i1 = tmp[1][p1];
        for(int p2 = 1;p2 <= tmp[2][0];p2 ++) {
            int i2 = tmp[2][p2];
            int W = ABS(w[i1]-w[i2]);
           // cout << w[i1] << " " << w[i2] << " " << W << endl;
            ans = min(ans,dfs(S^(3<<i1)^(3<<i2)) + W);
        }
    }
    //print(S); printf("  %d\n",ans);
    return f[S] = ans;
}

int main() {
    //freopen("G.in","r",stdin);
    while(~scanf("%d",&n)) {
        cc ++;
        for(int i = n;i >= 1;i --) {
            scanf("%s",mp[i]+1);
        }
        for(int i = n;i >= 1;i --) {
            for(int j = 1;j <= n;j ++) {
                scanf("%d",&A[i][j]);
            }
        }
        //memset(f,0,sizeof f); memset(vis,0,sizeof vis);
        //clr(0,0,0);
        f[(1<<(n+n))-(1<<n)] = 0;
        vis[(1<<(n+n))-(1<<n)] = cc;
        printf("%d\n",dfs((1<<n)-1));
    }
}
/**
12
WBB.WBB.WBB.
BWBWBWBWBWBW
WBWWWBWWWBWW
BBBWBBBWBBBW
WBB.WBB.WBB.
BWBWBWBWBWBW
WBWWWBWWWBWW
BBBWBBBWBBBW
WBB.WBB.WBB.
BWBWBWBWBWBW
WBWWWBWWWBWW
BBBWBBBWBBBW
1 1 1 0 1 1 1 0 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 0 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 0 1 1 1 0
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1

4
WBB.
BWBW
WBWW
BBBW
1 1 1 0
1 1 1 1
1 1 1 1
1 1 1 14
*/
