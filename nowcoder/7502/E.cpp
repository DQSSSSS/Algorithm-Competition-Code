#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const LL INF = 1e18 + 10;
const int mod = 1e9+7;
const LD eps = 1e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct BIT {
    int tree[SZ],n;

    void add(int x,int d) {
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    int ask(int x) {
        int ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }
}bit;

struct haha {
    int x,y,d,l,r,type,id;
};

int n,m,fuck[SZ];
vector<haha> poly[2];
vector<haha> squa[2];

bool cmp(haha &a,haha &b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.type != b.type){
        if(a.type == 0 && b.type == 1) {
            if(a.d < 0) return true;
            return false;
        } else {
            if(b.d > 0) return true;
            return false;
        }
    }
    return true;
}

void work(vector<haha> &a, vector<haha> &b) {
    vector<haha> c;
    for(auto &p : a) c.push_back(p);
    for(auto &p : b) {
        if(fuck[p.id]) continue;
        c.push_back(p);
    }
    sort(c.begin(),c.end(),cmp);

    set<int> s;
    for(auto &p : c) {
        s.insert(p.y);
    }

    for(auto &p : c) {
        if(p.type) {
            if(fuck[p.id]) continue;
            auto itl = s.lower_bound(p.l);
            if(itl != s.end() && *itl <= p.r) fuck[p.id] = 1;
        } else {
            s.erase(p.y);
        }
    }
}

struct ASK {
    int x,y,id,r,l;
}ask[SZ];

void dfs() {
    bool flag = 0;
    for(int i = 1;i <= m;i ++){
        if(ask[i].r-ask[i].l > 1) {
            flag = 1; break;
        }
    }
    if(!flag) return ;

    squa[0].clear();
    squa[1].clear();
    for(int i = 1;i <= m;i ++){
        int mid = ask[i].l + ask[i].r >> 1;
        int x = ask[i].x, y = ask[i].y;
        squa[0].push_back((haha){      y, 0, 0, x, x+mid-1, 1, i});
        squa[0].push_back((haha){y+mid-1, 0, 0, x, x+mid-1, 1, i});

        squa[1].push_back((haha){      x, 0, 0, y, y+mid-1, 1, i});
        squa[1].push_back((haha){x+mid-1, 0, 0, y, y+mid-1, 1, i});
        fuck[i] = 0;
    }

    work(poly[0], squa[0]);
    work(poly[1], squa[1]);
    for(int i = 1;i <= m;i ++) {
        int mid = ask[i].l + ask[i].r >> 1;
        if(fuck[i]) ask[i].r = mid;
        else ask[i].l = mid;
    }
    dfs();
}



int main() {
//    freopen("E.in","r",stdin); freopen("E.out","w",stdout);
    while(~scanf("%d%d",&n,&m)) {
        poly[0].clear();
        poly[1].clear();
        int maxX = 0,maxY = 0;
        for(int i = 1,lx,ly;i <= n;i ++) {
            int x = read(),y = read();
            if(i > 1) {
                if(lx == x) {
                    int minn = y,maxn = ly;
                    if(minn > maxn) swap(minn,maxn);
                    poly[0].push_back((haha){minn,x,1,0,0,0,0});
                    poly[0].push_back((haha){maxn,x,-1,0,0,0,0});
                } else {
                    int minn = x,maxn = lx;
                    if(minn > maxn) swap(minn,maxn);
                    poly[1].push_back((haha){minn,y,1,0,0,0,0});
                    poly[1].push_back((haha){maxn,y,-1,0,0,0,0});
                }
                maxX = max(maxX,abs(x-lx)+1);
                maxY = max(maxY,abs(y-ly)+1);
            }
            lx = x;
            ly = y;
        }

        for(int i = 1;i <= m;i ++) {
            ask[i].x = read();
            ask[i].y = read();
            ask[i].id = i;
            ask[i].l = 1;
            ask[i].r = max(maxX,maxY)+1;
        }

        dfs();

        for(int i = 1;i <= m;i ++) {
            printf("%d\n",ask[i].l);
        }
        return 0;
    }
}
