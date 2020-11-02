#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

int vis[10000010];
int pri[10000010];
int minp[10000010];

void shai(int n) {
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) minp[i] = i,pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            minp[m] = pri[j];
            if(i%pri[j]==0) {
                break;
            }
        }
    }
}

map<int,int> mp;
vector<int> id[SZ];
vector<int> g[SZ];
int L[SZ],R[SZ],fa[SZ];

bool fuck(int x,int l,int r) {
    return L[x] < l && R[x] > r;
}

bool solve(int l,int r,int f) {
    if(l>r) return true;
    int pl = l,pr = r;
    while(pl <= pr) {
        if(fuck(pl,l,r)) {
            fa[pl] = f;
            return solve(l,pl-1,pl) && solve(pl+1,r,pl);
        }
        pl ++;
        if(pl <= pr) {
            if(fuck(pr,l,r)) {
                fa[pr] = f;
                return solve(l,pr-1,pr) && solve(pr+1,r,pr);
            }
            pr --;
        }
    }
    return false;
}

int a[SZ];

int main() {
    shai(1e7);
    int n,tot = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&a[i]);
        int x = a[i];
        while(x > 1) {
            int p = minp[x];
            if(!mp[p]) mp[p] = ++ tot;
            id[mp[p]].push_back(i);
            //cout << mp[p] << " " << i << endl;
            while(x%p==0) x /= p;
        }
    }

    for(int i = 1;i <= n;i ++) L[i] = 0,R[i] = n + 1;
    for(int i = 1;i <= tot;i ++) {
        for(int j = 0;j < id[i].size();j ++) {
            int x = id[i][j];
            if(j + 1 < id[i].size()) R[x] = min(R[x],id[i][j+1]);
            if(j) L[x] = max(L[x],id[i][j-1]);
        }
    }
    //for(int i = 1;i <= n;i ++) printf("%d ",L[i]); puts("");
    //for(int i = 1;i <= n;i ++) printf("%d ",R[i]); puts("");

    if(solve(1,n,0)) {
        for(int i = 1;i <= n;i ++) printf("%d ",fa[i]);
    }
    else puts("impossible");
}
