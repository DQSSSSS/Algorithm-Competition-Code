#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int n,m;

struct haha {
    int l,r;
    int sum;
}tree[SZ * 220];

int Tcnt = 0,rt[SZ];
stack<int> TT;

void change(int l,int r,int &now,int lst,int val,int d) {
    if(!now) {
        if(!TT.empty()) now = TT.top(),TT.pop();
        else now = ++ Tcnt;
        tree[now] = tree[lst];
    }
    tree[now].sum += d;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(val <= mid) change(l,mid,tree[now].l,tree[lst].l,val,d);
    else change(mid+1,r,tree[now].r,tree[lst].r,val,d);
    if(tree[now].sum == 0) TT.push(now),now = 0;
}

int ask(int l,int r,int now,int L,int R) {
    if(L <= l && r <= R) {
        return tree[now].sum;
    }
    int mid = l + r >> 1,ans = 0;
    if(L <= mid) ans += ask(l,mid,tree[now].l,L,R);
    if(mid < R) ans += ask(mid + 1,r,tree[now].r,L,R);
    return ans;
}

void change(int x,int val,int d) {
    for(int i = x;i <= n;i += i & -i)
        change(1,n,rt[i],rt[i],val,d);
}

int ask(int x,int l,int r) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += ask(1,n,rt[i],l,r);
    return ans;
}

int ys[SZ],b[SZ];

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        ys[read()] = i;
    for(int i = 1;i <= n;i ++) {
        b[i] = ys[read()];
        change(i,b[i],1);
    }
   // for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
    for(int i = 1;i <= m;i ++) {
        int opt = read();
        if(opt == 1) {
            int la = read(),ra = read(),lb = read(),rb = read();
            printf("%d\n",ask(rb,la,ra) - ask(lb-1,la,ra));
        }
        else {
            int l = read(),r = read();
            change(r,b[r],-1); change(l,b[l],-1);
            swap(b[l],b[r]);
            change(r,b[r],1); change(l,b[l],1);
        }
    }
    return 0;
}
