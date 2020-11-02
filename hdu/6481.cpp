#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

ULL work(ULL n) {
    ULL ans = 1,t = n;
    for(ULL i = n + 1;i <= 2*n;i ++) {
        ULL x = i;
        while(t && x%2 == 0) x/=2,t--;
        ans *= x;
    }
    return ans;
}

ULL ksm(ULL a,ULL b) {
    ULL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

const int MAXN = 2e7;
int nxt[MAXN+10],n;

void getnxt(int s[]) {
    nxt[0] = nxt[1] = 0;
    for(int i = 1;i < n;i ++) {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}

int get(int s[]) {
    getnxt(s);
    return n - nxt[n];
}

int s[MAXN+10];

int main() {
    for(int j = 0;j <= 63;j ++) {
        n = 0;


        ULL ans1 = 1,ans2 = 1,B = 22;
        for(ULL i = 1;i <= (1<<B);i += 2) ans1 *= i;
        for(ULL i = (1<<B)+1;i <= (1<<(B+1));i += 2) ans2 *= i;
        cout << ans1 << " " << ans2 << endl;
        while(1);
        //for(int i = 0;i < 100;i ++) cout << s[i]; puts("");
        s[n] = 5;
        int ans = get(s);
        cout << j << " " << ans << endl;
        //for(int i = 0;i < ans;i ++) printf("%d",s[i]); puts("");
    }
}
