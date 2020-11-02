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
    int a,b,id;
}b[SZ],a[SZ];

bool cmp(haha a,haha b) { return a.a < b.a; }
bool cmp2(haha a,haha b) { return a.id < b.id; }


int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i].a = read(),a[i].id = i;
    for(int i = 1;i <= m;i ++) b[i].a = read(),b[i].b = read(),b[i].id = i;

    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);

    int sum = 0;
    for(int i = 1,j = 1;i <= n;i ++) {
        while(j <= m && b[j].a <= a[i].a) sum += b[j].b,j ++;
        a[i].b = sum;
    }
    sort(a+1,a+1+n,cmp2);
    for(int i = 1;i <= n;i ++) printf("%d ",a[i].b);
}

