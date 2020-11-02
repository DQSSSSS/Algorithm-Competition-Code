#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[SZ];

struct seg {
    int l,r;
    int a,b,c; /// () )))(((
}tree[SZ * 4];

void update(int p) {
    int t = min(tree[p << 1].c,tree[p << 1 | 1].b);
    tree[p].a = tree[p << 1].a + tree[p << 1 | 1].a + t * 2;
    tree[p].b = tree[p << 1].b + tree[p << 1 | 1].b - t;
    tree[p].c = tree[p << 1].c + tree[p << 1 | 1].c - t;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].a = 0;
        tree[p].b = s[l] == ')';
        tree[p].c = s[l] == '(';
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid+1,r);
    update(p);
}

seg ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid && mid < r) {
        seg L = ask(p << 1,l,r),R = ask(p << 1 | 1,l,r),ans;
        int t = min(L.c,R.b);
        ans.a = L.a + R.a + t * 2;
        ans.b = L.b + R.b - t;
        ans.c = L.c + R.c - t;
        return ans;
    }
    else if(l <= mid) return ask(p << 1,l,r);
    else if(mid < r) return ask(p << 1 | 1,l,r);
}

int main() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    build(1,1,n);
    int q = read();
    for(int i = 1;i <= q;i ++) {
        int L = read(),R = read();
        printf("%d\n",ask(1,L,R).a);
    }
    return 0;
}
