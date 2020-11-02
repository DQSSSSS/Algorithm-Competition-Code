#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

struct bigint {
    int a[SZ],n;

    void init(char s[]) {
        n = strlen(s);
        for(int i = 0;i < n;i ++) a[n-i] = s[i] - '0';
    }

    void println() {
        for(int i = n;i >= 1;i --) {
            putchar(a[i] + '0');
        }
        puts("");
    }
}a,b,one;

bigint operator -(const bigint &a,const bigint &b) {
    int x = 0;
    static bigint c; for(int i = 1;i <= c.n;i ++) c.a[i] = 0; c.n = 1;
    for(int i = 1;i <= max(a.n,b.n); i++) {
        c.a[i] = a.a[i] - b.a[i] - x;
        x = 0;
        if(c.a[i] < 0) c.a[i] += 10,x = 1;
    }
    c.n = max(a.n,b.n);
    while(c.n > 1 && c.a[c.n] == 0) c.n --;
    return c;
}

bool isend(const bigint &a) {
    if(a.n != 1) return false;
    if(a.a[1] != 0) return false;
    return true;
}

bigint get(const bigint &a) {
    if(a.n == 1) return a;
    int len = a.n / 2,n = a.n;
    static bigint ans; for(int i = 1;i <= ans.n;i ++) ans.a[i] = 0; ans.n = 1;
    bool isXbiggerY = true;
    for(int i = n-len+1,j = len;j >= 1;i ++,j --) {
        if(a.a[i] != a.a[j]) {
            if(a.a[i] < a.a[j]) {
              //  cout << i << " " << j << endl;
                isXbiggerY = true;
                break;
            }
            else {
                isXbiggerY = false;
                break;
            }
        }
    }
    //printf("len: %d is: %d\n",len,isXbiggerY);
    if(!isXbiggerY) { // -1
        static bigint tmp; tmp.n = len;
        for(int i = 1;i <= len;i ++) tmp.a[i] = a.a[i+n-len];
        one.n = 1; one.a[1] = 1;
        tmp = tmp - one;
        if(tmp.n == 1 && tmp.a[1] == 0) {
            ans.n = 1; ans.a[1] = 9; return ans;
        }
        if(tmp.n != len) {
            ans.n = n-1;
            for(int i = 1;i <= n-1;i ++) ans.a[i] = 9;
        }
        else {
            ans.n = n;
            for(int i = 1;i <= len;i ++) ans.a[i+n-len] = tmp.a[i];
            for(int i = n-len+1,j = len;j >= 1;i ++,j --)
                ans.a[j] = ans.a[i];
            if(n%2) ans.a[n/2+1] = a.a[n/2+1];
        }
    }
    else {
        ans.n = n;
        for(int i = 1;i <= n;i ++) ans.a[i] = a.a[i];
        for(int i = n-len+1,j = len;j >= 1;i ++,j --)
            ans.a[j] = ans.a[i];
    }
    return ans;
}

char s[SZ];
bigint vec[30];
int len;

int main() {
    freopen("I.in","r",stdin); freopen("I.out","w",stdout);
    int T = read();
    while(T --) {
        scanf("%s",s);
        a.init(s);
        len = 0;
        while(!isend(a)) {
            b = get(a);
            a = a - b;
            vec[++ len] = b;
        }
        printf("%d\n",len);
        for(int i = 1;i <= len;i ++) {
            vec[i].println();
        }
    }
}

/*
233
164695496494
2323232
*/
