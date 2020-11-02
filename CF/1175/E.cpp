#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
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
    int l,r,id,ans;
}a[SZ],b[SZ];

bool cmpr(haha a,haha b) {
    return a.r < b.r;
}
bool cmpl(haha a,haha b) {
    return a.l < b.l;
}
bool cmpid(haha a,haha b) {
    return a.id < b.id;
}

int R[SZ],anc[SZ][22],deep[SZ],vis[SZ],maxr[SZ];
vector<int> g[SZ];

void dfs(int u,int f,int gen) {
    anc[u][0] = f;
    vis[u] = 1;
    maxr[u] = a[gen].r;
    deep[u] = deep[f] + 1;
    R[u] = a[u].r;
    for(int i = 1;anc[u][i-1];i ++)
        anc[u][i] = anc[anc[u][i-1]][i-1];
    for(int v : g[u]) {
        dfs(v,u,gen);
    }
}


int nx[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i].l = read(),a[i].r = read();
    for(int i = 1;i <= m;i ++) b[i].l = read(),b[i].r = read(),b[i].id = i;

    sort(a+1,a+1+n,cmpr);

    for(int i = 1;i <= n;i ++) a[i].id = i;
    for(int i = n,lst = n;i >= 1;i --) {
        while(lst > i && a[i].r < a[lst].l) lst --;
        if(i == n) nx[i] = -1;
        else if(a[i].r >= a[lst].l && a[i].l < a[lst].l) {
            g[lst].push_back(i);
        }
        else nx[i] = -1;
    }

    for(int i = n;i >= 1;i --) {
        if(!vis[i]) dfs(i,0,i);
    }

    sort(a+1,a+1+n,cmpl);
    sort(b+1,b+1+m,cmpl);

    for(int cc = 1,i = 1,id = 0;cc <= m;cc ++) {
        int l = b[cc].l;
        int r = b[cc].r;
        while(i <= n && a[i].l <= l) {
            if(a[i].r > a[id].r) id = i;
            i ++;
        }
       // printf("%d %d %d %d\n",cc,l,r,a[id].id);
        if(id == 0 || maxr[a[id].id] < r) b[cc].ans = -1;
        else {
            int L = -1,R = deep[a[id].id];
            while(R - L > 1) {
                int mid = L + R >> 1;
                int dd = mid,x = a[id].id;
                for(int j = 0;j <= 20;j ++)
                    if(dd >> j & 1) x = anc[x][j];
              //  cout << mid << " " << x << endl;
                if(::R[x] >= r) R = mid;
                else L = mid;
            }
           // cout << R << " " << R+1 << endl;
            b[cc].ans = R + 1;
        }
    }
    sort(b+1,b+1+m,cmpid);
  //  for(int i = 1;i <= m;i ++) printf("%d %d %d\n",b[i].ans,b[i].l,b[i].r);
    for(int i = 1;i <= m;i ++) printf("%d\n",b[i].ans);
}

/**
5 1
-1 -2 5 -4 8

*/
