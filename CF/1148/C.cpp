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

int wz[SZ],a[SZ];

vector<pii> g;

void SWAP(int x,int y) {
    if(x == y) return ;
    g.push_back(make_pair(x,y));
    int xx = a[x],yy = a[y];
    wz[xx] = y;
    wz[yy] = x;
    a[x] = yy;
    a[y] = xx;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read(),wz[a[i]] = i;
    for(int i = 1;i <= n/2;i ++) {
        if(wz[i] <= n/2) {
            SWAP(wz[i],n);
            SWAP(n,i);
        }
        else {
            int x = wz[i];
            SWAP(x,1);
            SWAP(1,n);
            SWAP(i,n);
            SWAP(1,x);
        }
    }
    //cout << g.size() << endl;
    for(int i = n/2+1;i <= n;i ++) {
        int x = wz[i];
        if(x == i) continue;
        SWAP(x,1);
        SWAP(1,i);
        SWAP(x,1);
    }
  //  for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
    cout << g.size() << endl;
    for(pii x : g)
        printf("%d %d\n",x.first,x.second);
}
