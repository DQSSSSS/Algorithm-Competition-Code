#include <bits/stdc++.h>

using namespace std;
#define N 500005

namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

int X,Y,V;

struct Edge
{
  int to, next;
} e[N * 2];

  int dds = 0;
  int s[16 * N];
  int ls[16 * N], rs[16 * N];
  void insert(int &u, int l, int r)
  {
    if (!u)
    {
      u = ++dds;
     // s[u] = ls[u] = rs[u] = 0;
    }
    if (l == r)
    {
      s[u] += V;
      return;
    }
    s[u] += V;
    int mid = (l + r) >> 1;
    if (X <= mid)
      insert(ls[u], l, mid);
    else
      insert(rs[u], mid + 1, r);
  }
  int query(int u, int l, int r)
  {
    if (!u)
      return 0;
    if (X <= l && Y >= r)
      return s[u];
    int mid = (l + r) >> 1;
    if (Y <= mid)
      return query(ls[u], l, mid);
    else if (X > mid)
      return query(rs[u], mid , r);
    else
      return query(ls[u], l, mid) + query(rs[u], mid + 1, r);
  }

int n, m;
int head[N], v[N];
int fa[N][20], dep[N];
int cnt = 0;
int sum, rt;

void addedge(int x, int y)
{
  e[++cnt] = (Edge){y, head[x]};
  head[x] = cnt;
}

void dfs(int x, int f)
{
  for (int i = head[x]; i; i = e[i].next)
  {
    int v = e[i].to;
    if (v != f)
    {
      fa[v][0] = x;
      dep[v] = dep[x] + 1;
      dfs(v, x);
    }
  }
}

int sz[N], g[N];
bool vis[N];
int d[N];
int father[N];

void find_root(int x, int f)
{
  sz[x] = 1, g[x] = 0;
  for (int i = head[x]; i; i = e[i].next)
  {
    int v = e[i].to;
    if (v != f && !vis[v])
    {
      find_root(v, x);
      sz[x] += sz[v];
      g[x] = max(g[x], sz[v]);
    }
  }
  g[x] = max(g[x], sum - sz[x]);
  if (g[x] < g[rt])
    rt = x;
}

int root[N][2];

void get_dep(int tr, int x, int fa)
{
  X = d[x],V = v[x];
  insert(root[tr][0], 0, n);
  for (int i = head[x]; i; i = e[i].next)
  {
    int vv = e[i].to;
    if (vv != fa && !vis[vv])
    {
      d[vv] = d[x] + 1;
      get_dep(tr, vv, x);
    }
  }
}

void get_dep1(int tr, int x, int fa)
{
  X = d[x],V = v[x];
  insert(root[tr][1], 0, n);
  for (int i = head[x]; i; i = e[i].next)
  {
    int vv = e[i].to;
    if (vv != fa && !vis[vv])
    {
      d[vv] = d[x] + 1;
      get_dep1(tr, vv, x);
    }
  }
}

void work(int x)
{
  vis[x] = true;
  d[x] = 0;
  get_dep(x, x, 0);
  for (int i = head[x]; i; i = e[i].next)
  {
    int v = e[i].to;
    if (!vis[v])
    {
      sum = sz[v];
      g[0] = sum;
      rt = 0;
      find_root(v, 0);
      father[rt] = x;
      d[v] = 1;
      get_dep1(rt, v, x);
      work(rt);
    }
  }
}

int lca(int x, int y)
{
  if (dep[x] < dep[y])
    swap(x, y);
  int delta = dep[x] - dep[y];
  for (int i = 0; i < 20; i++)
  {
    if ((delta >> i) & 1)
      x = fa[x][i];
  }
  for (int i = 19; i >= 0; i--)
  {
    if (fa[x][i] != fa[y][i])
    {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  if (x != y)
    return fa[x][0];
  else
    return x;
}

int dis(int x, int y)
{
  int z = lca(x, y);
  return dep[x] + dep[y] - 2 * dep[z];
}

void updata(int u, int val)
{
  X = 0,Y = 0;
  int now = query(root[u][0], 0, n);
  int delta = val - now;
  X = 0,V = delta;
  insert(root[u][0], 0, n);
  for (int i = u; father[i]; i = father[i])
  {
    int dl = dis(u, father[i]);
    X = dl,V = delta;
    insert(root[father[i]][0], 0, n);
    X = dl,V = delta;
    insert(root[i][1], 0, n);
  }
}

int ask(int u, int k)
{
  int j = k;
  X = 0,Y = k;
  int ret = query(root[u][0], 0, n);
  for (int i = u; father[i]; i = father[i])
  {
    int dl = dis(father[i], u);
    X = 0,Y = k -dl;
    ret += query(root[father[i]][0], 0, n);
    ret -= query(root[i][1], 0, n);
  }
  return ret;
}

int main()
{
   /* int __size__=128<<20;
    char*__p__=(char*)malloc(__size__)+ __size__;
    __asm__("movl %0, %%esp\n"::"r"(__p__));
    freopen("3730/10.in","r",stdin);
    freopen("3730/my.out","w",stdout);*/
  read(n);read(m);
  for (int i = 1; i <= n; i++)
    father[i] = 0;
  for (int i = 1; i <= n; i++)
    read(v[i]);
  for (int i = 1; i <= n; i++)
    head[i] = 0;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    read(x);read(y);
    addedge(x, y);
    addedge(y, x);
  }
  sum = n;
  rt = 0;
  g[0] = n;
  dep[1] = 0;
  dfs(1, 0);
  for (int k = 1; (1 << k) <= n; k++)
    for (int i = 1; i <= n; i++)
      fa[i][k] = fa[fa[i][k - 1]][k - 1];
  for (int i = 1; i <= n; i++)
    vis[i] = false;
  find_root(1, 0);
  work(rt);
  int ans = 0;
  for (int i = 1; i <= m; i++)
  {
    int opt, x, y;
    read(opt),read(x),read(y);
    x ^= ans;
    y ^= ans;
    if (opt == 0)
    {
      ans = ask(x, y);
      println(ans);
    }
    else
      updata(x, y);
  }
}
