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
    vector<int> a;

    void init(char s[]) {
        int n = strlen(s);
        a.resize(n);
        for(int i = 0;i < n;i ++) a[n-i-1] = s[i] - '0';
    }

    void println() const {
        for(int i = a.size()-1;i >= 0;i --) {
            putchar(a[i] + '0');
        }
        puts("");
    }
}a,b,one;

bigint operator -(const bigint &a,const bigint &b) {
    int x = 0;
    bigint c; c.a.resize(a.a.size());
    for(int i = 0;i < a.a.size(); i++) {
        c.a[i] = a.a[i] - (i<b.a.size()?b.a[i]:0) - x;
        x = 0;
        if(c.a[i] < 0) c.a[i] += 10,x = 1;
    }
    int n = c.a.size();
    while(n > 1 && c.a[n-1] == 0) n --;
    c.a.resize(n);
    return c;
}

bool isend(const bigint &a) {
    if(a.a.size() != 1) return false;
    if(a.a[0] != 0) return false;
    return true;
}

bigint get(const bigint &a) {
    if(a.a.size() == 1) return a;
    int len = a.a.size() / 2,n = a.a.size();
    bigint ans;
    bool isXbiggerY = true;
    for(int i = n-len,j = len-1;j >= 0;i ++,j --) {
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
        bigint tmp; tmp.a.resize(len);
        for(int i = 0;i < len;i ++) tmp.a[i] = a.a[i+n-len];
        tmp = tmp - one;
        if(tmp.a.size() == 1 && tmp.a[0] == 0) {
            ans.a.resize(1); ans.a[0] = 9; return ans;
        }
        if(tmp.a.size() != len) {
            ans.a.resize(n-1);
            for(int i = 0;i < n-1;i ++) ans.a[i] = 9;
        }
        else {
            ans.a.resize(n);
            for(int i = 0;i < len;i ++) ans.a[i+n-len] = tmp.a[i];
            for(int i = n-len,j = len-1;j >= 0;i ++,j --)
                ans.a[j] = ans.a[i];
            if(n%2) ans.a[n/2] = a.a[n/2];
        }
    }
    else {
        ans.a.resize(n);
        for(int i = 0;i < n;i ++) ans.a[i] = a.a[i];
        for(int i = n-len,j = len-1;j >= 0;i ++,j --)
            ans.a[j] = ans.a[i];
    }
    return ans;
}

char s[SZ];
vector<bigint> vec;

int main() {
//    freopen("I.in","r",stdin); freopen("I.out","w",stdout);
    one.a.resize(1); one.a[0] = 1;
    int T = read();
    while(T --) {
        scanf("%s",s);
        a.init(s);
        vec.clear();
        while(!isend(a)) {
            b = get(a);
            a = a - b;
            vec.push_back(b);
        }
        printf("%d\n",vec.size());
        for(auto t : vec) {
            t.println();
        }
    }
}

/*
233
164695496494
2323232
*/
