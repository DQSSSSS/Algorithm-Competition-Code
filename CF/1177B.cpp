#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int ask(LL k) {
    LL len,now = 0;
    for(LL i = 1,t = 9;;i ++,t *= 10) {
        if(now + i * t > k) { len = i; break; }
        now += i * t;
    }
    if(now == k) return 9;
    LL x = k - now;
    LL t = (x-1) / len; x = (x-1) % len + 1;
    LL mi = 1;
    for(LL i = 1;i <= len-1;i ++) mi *= 10;
    mi += t;
    x = len - x;
    int ans;
    while(mi) {
        if(!x) { ans = mi % 10; break; }
        x --;
        mi /= 10;
    }
    return ans;
}

int main() {
   // for(int i = 1;i <= 100;i ++) printf("%d",ask(i));
    LL k = read();
    cout << ask(k);
}
