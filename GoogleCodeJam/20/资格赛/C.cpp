#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int fa[SZ],col[SZ],L[SZ],R[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x,int y) {
   // cout << x << " " << y << endl;
    x = find(x);
    y = find(y);
    if(x != y) fa[x] = y;
}

void work() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        L[i] = read();
        R[i] = read();
    }
    for(int i = 1;i <= 2*n;i ++) fa[i] = i;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(i == j) continue;
            if(max(L[i],L[j]) < min(R[i],R[j])) {
                merge(i,j+n);
                merge(i+n,j);
            }
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(find(i) == find(i+n)) {
            puts("IMPOSSIBLE");
            return ;
        }
    }
    for(int i = 1;i <= 2*n;i ++) {
        int j = i <= n ? i+n : i-n;
        j = find(j);
        if(fa[i] == i) {
            if(col[j] == -1) col[i] = 0;
            else col[i] = col[j] ^ 1;
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(col[find(i)] == 0) printf("C");
        else printf("J");
    }
    puts("");
}

int main() {
    cout << sizeof(int) << endl;
    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
}


