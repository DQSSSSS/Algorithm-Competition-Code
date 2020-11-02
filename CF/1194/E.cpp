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
    int p,l,r;
};

bool cmpp(haha a,haha b) { return a.p < b.p; }
bool cmpl(haha a,haha b) { return a.l < b.l; }
bool cmpr(haha a,haha b) { return a.r < b.r; }

vector<haha> V,H;

int tree[SZ];

void add(int x,int d) {
    x += 5001;
    for(int i = x;i <= 10001;i += i & -i) tree[i] += d;
}

int ask(int x) {
    x += 5001;
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[i];
    return ans;
}

int ask(int l,int r) {
    return ask(r) - ask(l-1);
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int x1 = read(),y1 = read(),x2 = read(),y2 = read();
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        if(x1 == x2) V.push_back((haha){x1,y1,y2});
        else H.push_back((haha){y1,x1,x2});
    }

    sort(H.begin(),H.end(),cmpp);
    sort(V.begin(),V.end(),cmpr);

    LL ans = 0;

    for(int i = 0;i < H.size();i ++) {
        for(int j = 0;j < V.size();j ++) if(V[j].l <= H[i].p) add(V[j].p,1);
        int k = 0;
        for(int j = i+1;j < H.size();j ++) {
            while(k < V.size()) {
                if(V[k].l > H[i].p) k ++;
                else {
                    if(V[k].r < H[j].p) add(V[k].p,-1),k ++;
                    else break;
                }
            }
            int l = max(H[i].l,H[j].l);
            int r = min(H[i].r,H[j].r);
            if(l > r) continue;
            LL tmp = ask(l,r);
            ans += tmp * (tmp-1) / 2;
         //   printf("%d %d %d, %d %d %d, %d\n",H[i].p,H[i].l,H[i].r,H[j].p,H[j].l,H[j].r,tmp);
        }
        while(k < V.size()) {
            if(V[k].l > H[i].p) k ++;
            else {
                add(V[k].p,-1),k ++;
            }
        }
    }

    cout << ans << endl;

}


