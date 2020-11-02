#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

struct BIT {
    int tree[SZ],n;
    void init(int _n) {
        n = _n;
        n ++;
        for(int i = 1;i <= n;i ++) tree[i] = 0;
    }

    void add(int x,int d) {
        x ++;
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }
    int ask(int x) {
        x ++;
        int ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    int ask(int l,int r) {
        return ask(r)-ask(l-1);
    }
}tb;

pii X[SZ],Y[SZ];
vector<int> del[SZ],add[SZ];

void work(pii X[],pii Y[],int n,int m,LL &V,LL &E) {
   // puts("-------------------");
    for(int i = 0;i <= m;i ++) del[i].clear(),add[i].clear();
    for(int i = 1;i <= n;i ++) {
        if(X[i].first < X[i].second) {
            del[X[i].first].push_back(i);
            add[X[i].second].push_back(i);
        }
    }
    tb.init(n);
    for(int i = 1;i <= n;i ++) {
        if(X[i].first >= 1) {
            tb.add(i,1);
        }
    }
    for(int i = 1;i <= m;i ++) {
        sort(add[i].begin(),add[i].end());
        sort(del[i].begin(),del[i].end());
        for(int x : add[i]) tb.add(x,1);
        if(Y[i].first < Y[i].second) {
            if(Y[i].first >= 1) {
                int sum = tb.ask(1,Y[i].first);
                V += sum;
                E += sum - 1;
            }
            if(Y[i].second <= n) {
                int sum = tb.ask(Y[i].second,n);
                V += sum;
                E += sum - 1;
            }
        }
        else {
            int t = tb.ask(1,n);
            V += t;
            E += t - 1;
        }
        for(int x : del[i]) tb.add(x,-1);
     //   cout << V << " " << E << endl;
    }
}

int lshx[SZ],lshy[SZ];
pii a[SZ];
char opt[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read(),k = read();
        lshx[0] = lshy[0] = 0;
        for(int i = 1;i <= k;i ++) {
            a[i].first = read();
            a[i].second = read();
            char s[2]; scanf("%s",s);
            opt[i] = s[0];
            lshx[++ lshx[0]] = a[i].first;
            lshy[++ lshy[0]] = a[i].second;
        }
        lshx[++ lshx[0]] = 0; lshx[++ lshx[0]] = n;
        lshy[++ lshy[0]] = 0; lshy[++ lshy[0]] = m;
        sort(lshx+1,lshx+1+lshx[0]); n = unique(lshx+1,lshx+1+lshx[0]) - lshx - 1;
        sort(lshy+1,lshy+1+lshy[0]); m = unique(lshy+1,lshy+1+lshy[0]) - lshy - 1;
        for(int i = 1;i <= k;i ++) {
            a[i].first = lower_bound(lshx+1,lshx+1+n,a[i].first)-lshx;
            a[i].second = lower_bound(lshy+1,lshy+1+m,a[i].second)-lshy;
        //    cout << a[i].first << " "<< a[i].second << endl;
        }

        for(int i = 1;i <= n;i ++) X[i].first = -1,X[i].second = m+1;
        for(int i = 1;i <= m;i ++) Y[i].first = -1,Y[i].second = n+1;
        for(int i = 1;i <= k;i ++) {
            int x = a[i].first,y = a[i].second;
            char s[2]; s[0] = opt[i];
            if(s[0] == 'U') X[x].second = min(X[x].second,y);
            if(s[0] == 'D') X[x].first = max(X[x].first,y);
            if(s[0] == 'L') Y[y].first = max(Y[y].first,x);
            if(s[0] == 'R') Y[y].second = min(Y[y].second,x);
        }
        X[1].first = m; X[1].second = 1; X[n].first = m; X[n].second = 1;
        Y[1].first = n; Y[1].second = 1; Y[m].first = n; Y[m].second = 1;

       // for(int i = 1;i < n;i ++) printf("%d %d\n",X[i].first,X[i].second);
       // for(int i = 1;i < m;i ++) printf("%d %d\n",Y[i].first,Y[i].second);

        LL V = 0,E = 0;
        work(X,Y,n,m,V,E);
        work(Y,X,m,n,V,E);
        V /= 2;
        printf("%lld\n",1+E-V);
    }
}
