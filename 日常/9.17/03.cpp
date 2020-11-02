#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;
const LL mod = 1000000007;


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

int ch[SZ][27];
int sz = 0,val[SZ],fa[SZ];
int id[SZ];

void insert(string s,int d)
{
    int p = 0;
    int l = s.length();;
    for(int i = 0;i < l;i ++)
    {
        int c = s[i] - 'a' + 1;
        if(!ch[p][c]) ch[p][c] = ++ sz,fa[sz] = p;
        p = ch[p][c];
        val[p] += d;
    }
    id[p] = d ^ 1;
}

int head[SZ],nxt[SZ],tot = 1,to[SZ];

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}


int fail[SZ];

queue<int> q;

void build_ac()
{
    fail[0] = 0;
    for(int i = 1;i <= 26;i ++)
    {
        int u = ch[0][i];
        if(u) { q.push(u); fail[u] = 0; }
    }
    while(q.size())
    {
        int f = q.front(); q.pop();
        for(int i = 1;i <= 26;i ++)
        {
            int u = ch[f][i];
            if(!u) continue;
            q.push(u);
            int v = fail[f];
            while(v && !ch[v][i]) v = fail[v];
            fail[u] = ch[v][i];
        }
    }
}

void dfs(int u)
{
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        dfs(v);
        val[u] += val[v];
    }
}

void init()
{
    tot = 1;
    for(int i = 0;i <= sz;i ++)
    {
        head[i] = fail[i] = id[i] = val[i] = fa[i] = 0;
        memset(ch[i],0,sizeof(ch[i]));
    }
    sz = 0;
}

char s[SZ];
vector<string> len[SZ];
string ss;

int maxlen = 0;

int main()
{
    int T; read(T);
    while(T --)
    {
        init();
        for(int i = 1;i <= maxlen;i ++) len[i].clear();
        maxlen = 0;

        int n; read(n);
        for(int i = 1;i <= n;i ++)
        {
            read(s); ss = s;
            len[ss.length()].push_back(ss);
            maxlen = max(maxlen,(int)ss.length());
        }
        bool flag = 0;
        for(int i = 0;i < len[maxlen].size() - 1;i ++)
            if(len[maxlen][i] != len[maxlen][i + 1])
                { flag = 1; break; }

        if(flag) { println("No"); continue; }

        for(int i = maxlen - 1;i >= 0;i --)
            for(int j = 0;j < len[i].size();j ++)
                insert(len[i][j],0);
        insert(len[maxlen][0],1);
    //    cout << sz << endl;
        build_ac();
    //    for(int u = 1;u <= sz;u ++) cout << val[u] << " "; puts("");
        for(int u = 1;u <= sz;u ++) build(fail[u],u);
        //for(int i = 1;i <= sz;i ++) if(!id[i]) val[i] = 0;
        dfs(0);
    //    for(int u = 1;u <= sz;u ++) if(id[u]) cout << u << " " << val[u] << endl;
        flag = 0;
        for(int u = 1;u <= sz;u ++)
            if(id[u] && !val[u])
            {
                flag = 1;  break;
            }
        if(flag) println("No");
        else
        {
            for(int j = 0;j < len[maxlen][0].length();j ++)
                print(len[maxlen][0][j]);
            println();
        }
    }
    return 0;
}

/*
233
5
abc
cde
abcde
abcde
bcde
*/
