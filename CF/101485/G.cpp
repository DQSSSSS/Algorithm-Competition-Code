#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

struct haha {
    int x,y;
}a[SZ],b[SZ];

int tree[SZ],n;
LL ans = 0;

int ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i&-i) ans += tree[i];
    return ans;
}

void add(int x,int d) {
    for(int i = x;i <= n;i += i&-i) tree[i] += d;
}

void cdq(int l,int r) {
    if(l == r) return ;
    int mid = l + r >>1;
    cdq(l,mid); cdq(mid+1,r);
   // printf("[%d,%d]\n",l,r);
   // for(int i = l;i <= r;i ++) printf("%d %d\n",a[i].x,a[i].y);
    int p = l,pl = l,pr = mid+1;
    while(pl <= mid || pr <= r) {
        if(pl > mid || (pr <= r && a[pr].x < a[pl].x)) {
            ans += ask(a[pr].y);
            b[p ++] = a[pr ++];
        }
        else {
            add(a[pl].y,1);
            b[p ++] = a[pl ++];
        }
    }
    for(int i = l;i <= mid;i ++) add(a[i].y,-1);
    for(int i = l;i <= r;i ++) a[i] = b[i];
}

int mp[SZ],pos[SZ][2];

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) mp[read()] = i;
    for(int i = 1;i <= n;i ++) a[mp[read()]].x = i;
    for(int i = 1;i <= n;i ++) a[mp[read()]].y = i;
   // for(int i = 1;i <= n;i ++) printf("%d %d\n",a[i].x,a[i].y);
    cdq(1,n);
    cout << ans << endl;
}
