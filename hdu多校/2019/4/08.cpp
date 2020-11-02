#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

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


int lsh[SZ];

struct node{
    int l,r;
    int cnt;
}tree[20000010];

int Tcnt,rt[SZ];

void insert(int l,int r,int last,int &now,int v) {
    now = ++ Tcnt;
    tree[now] = tree[last];
    tree[now].cnt += 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(v <= mid) insert(l,mid,tree[last].l,tree[now].l,v);
    else insert(mid + 1,r,tree[last].r,tree[now].r,v);
}

int ask_rank(int l,int r,int x) {
    int ans = 0;
    int L = 1,R = lsh[0];
    int tl = rt[l-1],tr = rt[r];
    while(L!=R) {
        int mid = L + R >> 1;
        if(x <= lsh[mid]) tl = tree[tl].l,tr = tree[tr].l,R = mid;
        else {
            ans += tree[tree[tr].l].cnt - tree[tree[tl].l].cnt;
            tl = tree[tl].r,tr = tree[tr].r,L = mid + 1;
        }
    }
    if(x>=lsh[L]) ans += tree[tr].cnt - tree[tl].cnt;
    //printf("%d %d %d %d\n",L,R,x,ans);
    return ans;
}

int ask_num(int l,int r,int k) {
    if(k == 0) return -INF;
    if(k > r-l+1) return INF;
    int L = 1,R = lsh[0];
    int tl = rt[l-1],tr = rt[r];
    while(L!=R) {
        int mid = L + R >> 1;
        int t = tree[tree[tr].l].cnt - tree[tree[tl].l].cnt;
        if(t < k) k -= t,tl = tree[tl].r,tr = tree[tr].r,L = mid + 1;
        else tl = tree[tl].l,tr = tree[tr].l,R = mid;
    }
    return lsh[L];
}
/*
int ask_pre(int l,int r,int x) {
    int k = ask_rank(l,r,x);
  //  printf("pre: %d %d\n",x,k);
    if(k == 0) return -INF;
    int L = 1,R = 1e6;
    int tl = rt[l-1],tr = rt[r];
    while(L!=R) {
        int mid = L + R >> 1;
        int t = tree[tree[tr].l].cnt - tree[tree[tl].l].cnt;
        if(t < k) k -= t,tl = tree[tl].r,tr = tree[tr].r,L = mid + 1;
        else tl = tree[tl].l,tr = tree[tr].l,R = mid;
    }
    return L;
}

int ask_nxt(int l,int r,int x) {
    int k = r-l+1-ask_rank(l,r,x-1);
  //  printf("nxt: %d %d\n",x-1,ask_rank(l,r,x-1));
    if(k == 0) return INF;
    int L = 1,R = 1e6;
    int tl = rt[l-1],tr = rt[r];
    while(L!=R) {
        int mid = L + R >> 1;
        int t = tree[tree[tr].r].cnt - tree[tree[tl].r].cnt;
        if(t < k) k -= t,tl = tree[tl].l,tr = tree[tr].l,R = mid;
        else tl = tree[tl].r,tr = tree[tr].r,L = mid+1;
    }
    return L;
}
*/
/*
void read(int &n) {
    n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
}
*/
int a[SZ];

int main() {
	//freopen("1.in","r",stdin); freopen("1.out","w",stdout);
    int T; read(T);
    while(T --) {
        int n,m;
        read(n),read(m);
        Tcnt = 0;
        for(int i = 1;i <= n;i ++) read(a[i]),lsh[i]=a[i];
        sort(lsh+1,lsh+1+n); lsh[0] = unique(lsh+1,lsh+1+n)-lsh-1;
        for(int i = 1;i <= n;i ++) {
            int x = lower_bound(lsh+1,lsh+1+lsh[0],a[i])-lsh;
            insert(1,lsh[0],rt[i-1],rt[i],x);
        }
        int lstans = 0;
        while(m --) {
            int L,R,P,K;
            read(L),read(R),read(P),read(K);
            L ^= lstans; R ^= lstans; P ^= lstans; K ^= lstans;
/*            assert(1<=L && L<=R && R<=n);
            assert(P <= 1e6);
            assert(1 <= K && K <= 169);
            assert(K <= R-L+1);*/
            /*
            int nowrank = ask_rank(L,R,P);
            int l,r,ans;
            l = nowrank,r = nowrank+1;
            while(K --) {
                int pre = ask_num(L,R,l);
                int nxt = ask_num(L,R,r);
                if(P-pre < nxt-P) ans=P-pre,l --;
                else ans=nxt-P,r ++;
            }*/
            int l = -1,r = 1e6+1;
            while(r-l>1) {
                int mid = l + r >> 1;
                int d = ask_rank(L,R,P+mid) - ask_rank(L,R,P-mid-1);
              //  cout << mid << " " << d << endl;
                if(d < K)
                    l = mid;
                else
                    r = mid;
            }
            int ans = r;
            println(lstans=ans);
           // printf("%d\n",lstans=ans);
        }
    }
}
/**
1
5 2
31 2 5 45 4
1 5 5 1
2 5 33 3
*/
