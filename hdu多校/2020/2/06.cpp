#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
    int n;
    int a[SZ];
    void input() {
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
    }
}a,b,c;


void print(vector<int> a) {
    printf("%d\n",a.size());
    for(int x : a) printf("%d ",x); puts("");
}

LL fib[SZ];

vector<int> calc(LL p) {
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3;i <= c.n;i ++)
        fib[i] = (fib[i-1] + fib[i-2])%p;
    LL A = 0,B = 0,C = 0;
    for(int i = 1;i <= a.n;i ++)
        (A += a.a[i] * fib[i]) %= p;
    for(int i = 1;i <= b.n;i ++)
        (B += b.a[i] * fib[i]) %= p;
    for(int i = 1;i <= c.n;i ++)
        (C += c.a[i] * fib[i]) %= p;

    vector<int> ans;
    for(int i = 1;i <= c.n;i ++) {
        if(c.a[i] == 0) {
            if(i>1 && c.a[i-1]) continue;
            if(i<c.n && c.a[i+1]) continue;
            LL tmp = (C + fib[i]) % p;
            if(A * B % p == tmp) {
                ans.push_back(i);
            }
        }
    }
   // printf("%lld %lld %lld\n",A,B,C);
   // print(ans);
    return ans;
}

vector<int> merge(vector<int> &a,vector<int> &b) {
    vector<int> c;
    int pl = 0,pr = 0;
    while(pl < a.size() || pr < b.size()) {
        if(pl < a.size() && pr < b.size() && a[pl] == b[pr]) {
            c.push_back(a[pl]);
            pl ++; pr ++; continue;
        }
        if(pl >= a.size() || (pr < b.size() && a[pl] > b[pr])) {
            pr ++;
        }
        else {
            pl ++;
        }
    }
    return c;
}

bool ispri(int n) {
    if(n <= 1) return false;
    for(int i = 2;i * i <= n;i ++) {
        if(n%i==0) return false;
    }
    return true;
}

int main() {
//    for(int i = 1e9;i <= 1e9+1000;i ++) if(ispri(i)) printf("%d,",i);


    int T = read();
    while(T --) {
        a.input();
        b.input();
        c.input();
        //vector<int> pri = {(int)1e9+7,(int)1e9+9,998244353,1000000753,1000000787,1000000801,1000000829,1000000861,1000000871,1000000891,1000000901,1000000919,1000000931,1000000933,1000000993};
        vector<int> pri = {(int)1e9+7,(int)1e9+9,998244353,1000000753,1000000787};
        vector<int> ans;
        for(int i = 1;i <= c.n;i ++)
            if(c.a[i] == 0)
                ans.push_back(i);
        for(int p : pri) {
            vector<int> tmp = calc(p);
            ans = merge(ans,tmp);
        }
      //  printf("%d\n",ans.size());
        assert(ans.size() == 1);
        printf("%d\n",ans[0]);
    }
}
