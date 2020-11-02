#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;

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
    inline int read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return 1;
    }
    inline int read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return 1;
    }
    inline int read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
        return 1;
    }
    inline int read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
        return 1;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
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
};
using namespace fastIO;

int n;
vector<int> g[SZ];
LL a[SZ],b[SZ];
/*
bool vis[SZ];

struct haha {
    int u;
};

bool operator <(haha x,haha y) {
	int dx = b[x.u] - a[x.u];
	int dy = b[y.u] - a[y.u];
    if(dx < 0 && dy < 0)
    	return b[x.u] < b[y.u];
    else if(dx > 0 && dy > 0)
        return a[x.u] > a[y.u];
    else
    	return dx < dy;
}

priority_queue<haha> q;

LL bfs(int s) {
	LL ans = 0,now = 0;
    q.push((haha){s});
    for(int i = 1;i <= n;i ++) vis[i] = 0;
	vis[s] = 1;
	while(q.size()) {
		int u = q.top().u; q.pop();
		int d = b[u] - a[u];
		if(now - a[u] < 0) {
			ans += a[u] - now;
            now = b[u];
		}
		else
			now += b[u] - a[u];
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i];
			if(vis[v]) continue;
            vis[v] = 1;
            q.push((haha){v});
		}
	}
	return ans;
}
*/

int anc[SZ][22],deep[SZ],lg[SZ],maxdep;

void dfs(int u,int f) {
    anc[u][0] = f;
    deep[u] = deep[f] + 1;
    maxdep = max(maxdep,deep[u]);
    for(int i = 1;i <= lg[deep[u]];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == f) continue;
        dfs(v,u);
    }
}

int isanc(int u,int v) {
	bool f = 0;
	if(deep[u] < deep[v]) swap(u,v),f = 1;
    int dd = deep[u] - deep[v];
    for(int i = lg[maxdep];i >= 0;i --)
    	if(dd & (1 << i))
			u = anc[u][i];
	if(u == v) return f;
	return -1;
}

bool cmp(int u,int v) {
	int tmp = isanc(u,v);
    if(tmp != -1) return tmp;
	int dx = b[u] - a[u];
	int dy = b[v] - a[v];
    if(dx < 0 && dy < 0)  ///ÉËÑª
    	return b[u] == b[v] ? a[u] < b[u] : b[u] > b[v];
    else if(dx > 0 && dy > 0)  ///¼ÓÑª
        return a[u] == a[v] ? b[u] > b[u] : a[u] < a[v];
    else
    	return dx > dy;
}

int l[SZ];

int main() {
	for(int i = 1;i <= 100000;i ++) lg[i] = log2(i);
	int T;
	read(T);
	while(T --) {
        read(n);
        for(int i = 1;i <= n;i ++) g[i].clear();
        maxdep = 0;

        for(int i = 2;i <= n;i ++)
            read(a[i]),read(b[i]);
		for(int i = 1;i < n;i ++){
			int x,y;
			read(x),read(y);
            g[x].push_back(y);
            g[y].push_back(x);
		}
		dfs(1,0);
		for(int i = 2;i <= n;i ++) l[i] = i;
        sort(l + 2,l + 1 + n,cmp);
       // for(int i = 2;i <= n;i ++) cout << l[i] << " "; puts("");
        LL ans = 0,now = 0;
        for(int i = 2;i <= n;i ++) {
			int u = l[i];
			if(now - a[u] < 0) {
				ans += a[u] - now;
                now = b[u];
			}
			else {
				now -= a[u]; now += b[u];
			}
        }
        println(ans);
	}
	return 0;
}
/*
4
3
4 1
5 4
1 2
1 3
5
5 2
2 3
4 1
5 4
1 2
1 3
3 4
3 5
7
1 10
150 1
100 1
99 1
1 100
1 100
1 2
1 3
2 4
2 5
3 6
3 7
4
2 6
5 4
6 2
1 2
2 3
3 4
*/
