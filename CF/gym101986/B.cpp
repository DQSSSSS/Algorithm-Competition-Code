#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
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

struct haha {
    int x,y;
}a[22];

struct hehe {
    int x,y,i,j;
}b[333];

bool cmp(hehe a,hehe b) {
    return a.x * b.y < a.y * b.x;
}

int n;

bool vis[22];
vector<int> g[22];

int dfs_sz(int u) {
    vis[u] = 1;
    int ans = 1;
    for(int v : g[u]) {
        if(vis[v]) continue;
        ans += dfs_sz(v);
    }
    return ans;
}

int work(int S) {
    haha tmp[22];
    int m = 0;
    for(int i = 0;i < n;i ++) {
        if(S >> i & 1)
            tmp[m ++] = a[i];
    }

    if(m < 4) return 0;

    int tot = 0;
    for(int i = 0;i < m;i ++) {
        for(int j = i+1;j < m;j ++) {
            b[++ tot] = (hehe){tmp[i].x-tmp[j].x,tmp[i].y-tmp[j].y,i,j};
            if(b[tot].x < 0) b[tot].x *= -1,b[tot].y *= -1;
            if(b[tot].x == 0 && b[tot].y < 0) b[tot].y *= -1;
        }
    }

    sort(b + 1,b + 1 + tot,cmp);

    int ans = 0;
    //for(int i = 1;i <= tot;i ++) { cout << b[i].x << " " << b[i].y << " " << b[i].i << " " << b[i].j << endl; }
    for(int i = 1,lst = 1;i <= tot;i ++) {
        if(i == tot || b[i].x*b[i+1].y != b[i].y*b[i+1].x) {
/*
            for(int j = lst;j <= i;j ++) {
                g[b[j].i].clear();
                g[b[j].j].clear();
                vis[b[j].i] = 0;
                vis[b[j].j] = 0;
            }

            for(int j = lst;j <= i;j ++) {
                g[b[j].i].push_back(b[j].j);
                g[b[j].j].push_back(b[j].i);
            }
*/
            int sum = i - lst + 1;
            ans = max(ans,sum * (sum - 1) / 2);

            lst = i + 1;
        }
    }
    return ans;
}

int f[SZ];

int dfs(int S) {
    if(f[S] != -1) return f[S];
    //cuot << S << endl;
    int ans = work(S);
    for(int S2 = (S-1)&S;S2;S2 = (S2 - 1)&S) {
        ans = max(ans,dfs(S2)+dfs(S-S2));
    }
    return f[S] = ans;
}

int main() {
    n = read();
    for(int i = 0;i < n;i ++) a[i].x = read(),a[i].y = read();
    memset(f,-1,sizeof f);
   // cout << work((1<<n)-1) << endl;
    //for(int i = 0;i < (1<<n)-1;i ++)
    //    cout << i << " " << work(i) << endl;
    printf("%d\n",dfs((1<<n)-1));
}
