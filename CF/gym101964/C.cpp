#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

vector<int> g[SZ];
int a[SZ],n;

int dfs(int u,int f,int d,int mid) {
    if(d == mid + 1) return 0;
    int ans = a[u];
    for(int v : g[u]) {
        if(v == f) continue;
        ans += dfs(v,u,d+1,mid);
    }
    return ans;
}

int check(int mid) {
    int ans = 0;
    for(int i = 1;i < 2 * n;i ++) {
        ans = max(ans,dfs(i,0,0,mid));
    }
    return ans;
}

int main() {
    n = read();
    int m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(i+n);
        g[i+n].push_back(x);
        g[i+n].push_back(y);
        g[y].push_back(i+n);
    }
    int l = -1,r = n;
    while(r - l > 1) {
        int mid = l + r >> 1;
        if(check(mid) >= m) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
/**
6 3
1 1 0 1 1 1
1 2
1 3
1 4
3 5
3 6


9 4
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9
*/
