#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

struct FastIO{
  static const int S=1310720;
  int wpos,pos,len;char wbuf[S];
  FastIO():wpos(0){}
  inline int xchar(){
    static char buf[S];
    if(pos==len)pos=0,len=fread(buf,1,S,stdin);
    if(pos==len)return -1;
    return buf[pos++];
  }
  inline int read(){
    int c=xchar(),x=0;
    while(c<=32&&~c)c=xchar();
    if(c==-1)return -1;
    for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
    return x;
  }
    inline void println(UI x) {
        char s[12];
        int t = 0;
        while(x) s[t++] = x % 10 + '0',x /= 10;
        for(int i = t-1;i >= 0;i --) putchar(s[i]);
        puts("");
    }
}io;

const int MAXN = 1e7;

bool vis[SZ];
int pri[SZ / 10],tot,minp[SZ];
char mu[SZ];

void shai(int n) {
    mu[1] = 1;
    for(register int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1,minp[i] = i;
        for(register int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
                minp[m] = minp[i];
                break;
            }
            else {
                mu[m] = -mu[i];
                minp[m] = pri[j];
            }
        }
    }
}

struct mywork {
    int a[100010];
    UI tim[SZ];
    vector<int> g[100010];
    UI ans;

    void work(int n) {
        for(int i = 1;i <= n;i ++) g[i].clear();
        ans = 0;
        for(int i = 1;i <= n;i ++) {
            int x = a[i];
            vector<int> tmp;
            int lp = 0;
            while(x != 1) {
                int p = minp[x];
                if(p > lp) tmp.push_back(p),lp = p;
                x /= p;
            }
            int m = tmp.size();
            for(int s = 0;s < (1<<m);s ++) {
                int t = 1;
                for(int j = 0;j < m;j ++) {
                    if(s>>j&1) t *= tmp[j];
                }
                g[i].push_back(t);
            }
        }
    }

    inline void change(int p,int f) {
        for(int i = 0;i < g[p].size();i ++) {
            int t = g[p][i];
            ans -= t * mu[t] * tim[t] * tim[t];
            tim[t] += f * (a[p] / t);
            ans += t * mu[t] * tim[t] * tim[t];
        }
    }

    inline void del(int p) {
        change(p,-1);
    }

    inline void add(int p) {
        change(p,1);
    }
}A;

int B;

struct haha {
    int l,r,id;
}b[100010];

bool cmp(haha a,haha b) {
    if(a.l / B != b.l / B) return a.l < b.l;
    return a.r < b.r;
}

UI ans[100010];

int main() {
  //  freopen("3.in","r",stdin); freopen("my.out","w",stdout);
    shai(MAXN);
    int T = io.read();
    while(T --) {
        int n = io.read(),m = io.read();
        //int n,m; read(n),read(m);
        B = 3 * sqrt(n);
        for(int i = 1;i <= n;i ++) {
            A.a[i] = io.read();
          //  read(A.a[i]);
        }
        A.work(n);
        for(int i = 1;i <= m;i ++) {
            b[i].l = io.read(); b[i].r = io.read();
            b[i].id = i;
        }
        sort(b+1,b+1+m,cmp);
        int l = 1,r = 0;
       // for(int i = 1;i <= m;i ++) printf("%d %d\n",b[i].l,b[i].r);
        for(int i = 1;i <= m;i ++) {
            while(l < b[i].l) A.del(l),l ++;
            while(l > b[i].l) A.add(l-1),l --;
            while(r < b[i].r) A.add(r+1),r ++;
            while(r > b[i].r) A.del(r),r --;
            ans[b[i].id] = A.ans;
        }
        while(l <= r) A.del(l),l ++;
        for(int i = 1;i <= m;i ++) {
           // io.println(ans[i]);
            printf("%u\n",ans[i]);
            //println((LL)ans[i]);
        }
    }
}
/**
3
10 2
43 69 100 87 96 37 87 47 25 45
1 4
4 4
*/
