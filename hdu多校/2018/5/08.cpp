#include<bits/stdc++.h>
///#define Min(x,y) ((x) < (y) ? (x) : (y))
#define Min(x,y) min(x,y)
#define Max(x,y) max(x,y)
///#define Max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
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

struct matrix {
	int a[11];
	matrix() { memset(a,0,sizeof(a)); }
	matrix(int c) { memset(a,0,sizeof(a)); a[c] = 1; }
	void update(const matrix &o,int c) {
		for(int i = 0;i <= 9;i ++) a[i] = max(a[i],o.a[i]);
		for(int i = 0;i <= c;i ++) a[c] = max(a[c],o.a[i] + 1);
		a[c] = max(a[c],1);
	}
	void update(const matrix &o) {
		for(int i = 0;i <= 9;i ++) a[i] = max(a[i],o.a[i]);
		for(int i = 0;i <= c;i ++) a[c] = max(a[c],o.a[i] + 1);
		a[c] = max(a[c],1);
	}
	void print() {
		for(int i = 0;i < 10;i ++)
			printf("%d ",a[i]);
		puts("");
	}
}f[SZ],g[SZ];

int n;
char s[SZ];

struct node {
	matrix f,m;
	int l,r;
}tree[11][SZ * 4];

void update(int id,int p) {
    tree[p].f = update()
}

void build(int id,int p,int l,int r) {
	tree[p].l = l; tree[p].r = r;
    if(l == r) {
		tree[p].f = matrix(s[l] - '0');
		return ;
    }
    int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}


int main() {
	int T = read();
    while(T --) {
    	n = read();
    	scanf("%s",s + 1);
        for(int i = 1;i <= n;i ++) {
            int c = s[i] - '0';
            f[i].update(f[i - 1],c);
        }
        for(int i = n;i >= 1;i --)
        	g[i].update(g[i + 1],s[i] - '0');
		//for(int i = 1;i <= n;i ++) f[i].print(); puts("");
		//for(int i = 1;i <= n;i ++) g[i].print(); puts("");
		for(int i = 0;i < 10;i ++)
			build(i,1,1,n);
    }
	return 0;
}
