#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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
    haha(int a,int b) { x = min(a,b); y = max(a,b); x = min(x,INF); y = min(y,INF); }
};

int check(haha a,haha b) {
    if(a.x == b.x && a.y == b.y) return 0;
    if(a.x == b.x) return a.y < b.y ? 1 : -1;
	return a.x < b.x ? 1 : -1;
}

int n,m;
int a[233],b[233];

int check() {
	a[1] += 2; a[2] ++; b[1] += 2; b[2] ++;
    haha A1 = haha(a[1],INF),A2 = haha(a[2],a[3]);
    haha B1 = haha(b[1],INF),B2 = haha(b[2],b[3]);
    if(check(A1,A2) == -1) swap(A1,A2);
    if(check(B1,B2) == -1) swap(B1,B2);
    if(check(A1,B1) == 0) return check(A2,B2);
    return check(A1,B1);
}

int main() {
//	freopen("1010.in","r",stdin);
//	freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
		n = read(),m = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		for(int i = 1;i <= m;i ++) b[i] = read();
		for(int i = n + 1;i <= 3;i ++) a[i] = INF;
		for(int i = m + 1;i <= 3;i ++) b[i] = INF;
		n = m = 3;
        printf("%d\n",check());
    }
    return 0;
}
/**


*/
