#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int a[SZ],n;

int check() {
    int flag = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i]) flag = 1;
    }
    if(!flag) return 2;
    int t = 0;
    for(int i = 1;i < n;i ++) {
        if(a[i] == a[i+1]) t ++;
        if(t > 1) return 2;
    }
    LL sum = 0;
    if(t == 1) {
        for(int i = 1;i < n;i ++) {
            if(a[i] == a[i+1]) {
                if(a[i] == 0) return 2;
                a[i] --;
                break;
            }
        }
        sort(a+1,a+1+n);
        for(int i = 1;i < n;i ++) {
            if(a[i] == a[i+1]) t ++;
            if(t > 1) return 2;
        }
        sum = 1;
    }
    for(int i = 1;i <= n;i ++) {
        sum += a[i] - (i - 1);
    }
    sum %= 2;
    if(sum == 0) {
        return 2;
    }
    else {
        return 1;
    }
}

int main() {
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a+1,a+1+n);
    puts(check() == 2 ? "cslnb" : "sjfnb");
    return 0;
}
