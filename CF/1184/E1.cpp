#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

struct haha {
    int x,y,z;
}l[SZ];

bool cmp(haha a,haha b) { return a.z < b.z; }

struct edge {
    int t,d;
};

int fa[SZ];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) l[i].x = read(),l[i].y = read(),l[i].z = read();
    int x = l[1].x,y = l[1].y;
    sort(l+2,l+1+m,cmp);
    int l = -1,r = 1e9+1;
    while(r-l>1) {
        int mid = l + r >> 1;
        for(int i = 1;i <= n;i ++) fa[i] = i;
        for(int i = 2;i <= m;i ++) {
            if(::l[i].z >= mid) break;
            int x = find(::l[i].x);
            int y = find(::l[i].y);
            if(x != y) {
               fa[x] = y;
            }
        }
        if(find(x) == find(y)) r = mid;
        else l = mid;
    }
    cout << l << endl;
}
