#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int val[SZ];

struct seg {
    int l,r;
    int rev,ans[2];
}tree[SZ * 4];

void update(int p) {
    for(int i = 0;i < 2;i ++)
        tree[p].ans[i] = tree[p<<1].ans[i] + tree[p<<1|1].ans[i];
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].rev = 0;
    tree[p].ans[0] = 0;
    tree[p].ans[1] = 0;
    if(l == r) {
        tree[p].ans[1] = val[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushrev(int p) {
    tree[p].rev ^= 1;
    swap(tree[p].ans[0],tree[p].ans[1]);
}

void pushdown(int p) {
    if(tree[p].rev) {
        pushrev(p<<1);
        pushrev(p<<1|1);
        tree[p].rev = 0;
    }
}

void change(int p,int l,int r) {
   // if(p == 1) printf("[%d,%d]\n",l,r);
    if(l <= tree[p].l && tree[p].r <= r) {
        pushrev(p);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r);
    if(mid < r) change(p<<1|1,l,r);
    update(p);
}

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].ans[0];
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p<<1,l,r);
    if(mid < r) ans += ask(p<<1|1,l,r);
    return ans;
}

int num[SZ],tot = 0;
pii lst[SZ];
map<int,int> mp;
vector<int> g[SZ],dy[SZ];

struct haha {
    int opt,l,r,val;
}a[SZ];

int getpos(int x,int l) {
    return dy[x][lower_bound(g[x].begin(),g[x].end(),l) - g[x].begin()];
}

int main() {
   // freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);

    int T = read();
    while(T --) {
        int n = read();

        for(int i = 1;i <= tot;i ++) {
            g[i].clear();
            dy[i].clear();
            lst[i] = make_pair(0,0);
        }
        tot = 0;
        mp.clear();

        for(int i = 1;i <= n;i ++) {
            num[i] = read();
            if(!mp[num[i]]) mp[num[i]] = ++ tot;
            g[mp[num[i]]].push_back(i);
        }
        int q = read();
        for(int i = 1;i <= q;i ++) {
            a[i].opt = read();
            if(a[i].opt == 1) {
                a[i].l = read(),a[i].val = read();
                if(!mp[a[i].val]) mp[a[i].val] = ++ tot;
                g[mp[a[i].val]].push_back(a[i].l);
            }
            else {
                a[i].l = read()-1,a[i].r = read(),a[i].val = read();
                if(!mp[a[i].val]) mp[a[i].val] = ++ tot;
                g[mp[a[i].val]].push_back(a[i].l);
                g[mp[a[i].val]].push_back(a[i].r+1);
            }
        }

        int len = 0;
        for(int i = 1;i <= tot;i ++) {
            sort(g[i].begin(),g[i].end());
            int m = unique(g[i].begin(),g[i].end()) - g[i].begin();
            g[i].resize(m);
         //   printf("%d\n",i);
            for(int j = 0;j < g[i].size();j ++) {
                dy[i].push_back(++ len);
                val[len] = j + 1 == g[i].size() ? n-g[i][j]+1 : g[i][j+1]-g[i][j];
          //      cout << g[i][j] << " " << len << " " << val[len] <<endl;
            }
        }

        build(1,1,len);

        for(int i = 1;i <= n;i ++) {
            int x = mp[num[i]];
            if(lst[x].second) {
                change(1,getpos(x,lst[x].first),getpos(x,i)-1);
            }
            lst[x].second ^= 1;
            lst[x].first = i;
        }
        for(int i = 1;i <= tot;i ++) {
            if(lst[i].second) {
                change(1,getpos(i,lst[i].first),dy[i][dy[i].size()-1]);
            }
        }
      //  puts("--");
        for(int i = 1;i <= q;i ++) {
            int x = mp[a[i].val];
            if(a[i].opt == 1) {
                int pos = a[i].l,lst = mp[num[pos]];
                change(1,getpos(lst,pos),dy[lst][dy[lst].size()-1]);

                int l = getpos(x,a[i].l);
                int r = dy[x][dy[x].size()-1];
                change(1,l,r);
                num[pos] = a[i].val;
            }
            else {
                int l = getpos(x,a[i].l);
                int r = getpos(x,a[i].r+1)-1;
                LL tmp = ask(1,l,r);
                tmp *= a[i].r - a[i].l + 1 - tmp;
                printf("%lld\n",tmp);
            }
        }
    }
    return 0;
}

/**

1
5
1 3 2 3 1
5
2 1 5 1
2 1 2 1
2 1 4 3
1 1 2
2 1 3 2

8
2
6
4


*/
