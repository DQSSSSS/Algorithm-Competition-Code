#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 550010;
const LL INF = 1e18;
const LD eps = 1e-7;
const double PI = acos(-1);


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


struct Complex {
    double x,y;
    Complex(double x = 0,double y = 0) :x(x),y(y) {}
    Complex operator *(const Complex &o) const { return Complex(x*o.x-y*o.y,x*o.y+y*o.x);}
    void operator /=(const double &o) { x /= o; y /= o;}
    Complex operator +(const Complex &o) const { return Complex(x + o.x,y + o.y);}
    Complex operator -(const Complex &o) const { return Complex(x - o.x,y - o.y);}
};
 
 
LL ksm(LL a,LL b,LL mod) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
 
struct FFT {
    Complex wn[SZ],wnInv[SZ];
    void init(int n) {
        for(int i = 0;i < n;i ++) {
            wnInv[i].x = wn[i].x = cos(2 * PI / n * i);
            wn[i].y = sin(2 * PI / n * i);
            wnInv[i].y = -wn[i].y;
        }
    }
     
    void Transform(Complex a[],int n,const Complex wn[]) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i > j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l <<= 1) {
            int m = l / 2;
            for(Complex *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    Complex t = wn[n / l * i] * p[i + m];
                    p[i + m] = p[i] - t;
                    p[i] = p[i] + t;
                }
            }
        }
    }
     
    void dft(Complex a[],int n) {
        Transform(a,n,wn);
    }
     
    void idft(Complex a[],int n) {
        Transform(a,n,wnInv);
        for(int i = 0;i < n;i ++) {
            a[i].x /= n; a[i].y /= n;
        }
    }
}fft;

Complex c1[SZ]; 
 
void multiply(LL *a1,int n1,LL *ans) {
	int n = 1;
	while(n < 2*n1) n *= 2;
	for(int i = 0;i < n1;i ++) c1[i] = a1[i];
	fft.init(n); fft.dft(c1,n);
	for(int i = 0;i < n;i ++) c1[i] = c1[i] * c1[i];
	fft.idft(c1,n);
	for(int i = 0;i < 2 * n1 - 1;i ++) ans[i%n1] += (LL)(c1[i].x+0.5);
}
 
vector<int> getGtmp;
int getG(int p) {
	if(p == 2) return 1;
    int x = p - 1;
    for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
    for(int k = 2;;k ++)
        for(int i = 0;i < getGtmp.size();i ++) {
            if(ksm(k,getGtmp[i],p) == 1) {
                if(getGtmp[i] == x)
                    return k;
                else break;
            }
        }
}
 
LL a[SZ],polya[SZ],id[SZ];
int n,mod;
LL ans[SZ];
 
int main() {
    //freopen("I.in","r",stdin); freopen("I.out","w",stdout);
    //scanf("%d%d",&n,&mod);
    read(n);
    read(mod);
    for(int i = 1;i <= n;i ++)
        //scanf("%lld",&a[i]);
        read(a[i]);
    int g = getG(mod);
   // cout <<g << endl;
    for(int i = 0,now = 1;i < mod - 1;i ++) {
        id[now] = i;
        now = 1ll * now * g % mod;
    }
    int zero = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] % mod == 0) zero ++;
        else polya[id[a[i] % mod]] ++;
    }
    multiply(polya,mod-1,ans);
    LL zerofa = 1ll * n * n;
    for(int i = 0;i < mod - 1;i ++) zerofa -= ans[i];
    for(int i = 1;i <= n;i ++) {
        LL Ans;
        if(a[i] >= mod) Ans = 0;
        else {
            if(a[i] == 0) Ans = zerofa;
            else Ans = ans[id[a[i]]];
        }
       // printf("%lld\n",Ans);
        println(Ans);
    }
    return 0;
}
/**
7 2
0 2 0 1 2 3 4
*/
