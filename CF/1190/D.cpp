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
    int x,y;
}a[SZ];

bool cmp(haha a,haha b) { return a.y == b.y ? a.x < b.x : a.y > b.y; }

map<int,int> mp;

int tree[SZ],lsh[SZ];

void add(int x,int d) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[i] += d;
}

int ask(int x) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read(),a[i].y = read();
        lsh[++ lsh[0]] = a[i].x;
    }
    sort(a+1,a+1+n,cmp);
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    for(int i = 1;i <= n;i ++) {
        a[i].x = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x)-lsh;
    }
    LL ans = 0,num = 0;
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || a[i].y != a[i+1].y) {
            for(int j = lst;j <= i;j ++) {
                if(mp[a[j].x] == 0) add(a[j].x,1);
                mp[a[j].x] ++;
            }
            for(int j = lst;j <= i;j ++) {
                int x = (j == i ? ask(lsh[0])+1 : ask(a[j+1].x)) - ask(a[j].x);
                ans += 1ll * x * ask(a[j].x);
            }
            lst = i + 1;
        }
    }
    cout << ans << endl;
}

/**
7
1 2
2 1
2 3
3 2
4 1
4 3
5 2

6
2 1
2 2
3 1
3 2
2 3
3 3

*/
