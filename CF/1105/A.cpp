#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();

    int ans = 1e9,id = 0;
    for(int t = 1;t <= 100;t ++) {
        int tmp = 0;
        for(int i = 1;i <= n;i ++) {
            int x = a[i];
            if(x < t) tmp += t - 1 - x;
            if(x > t) tmp += x - t - 1;
        }
        if(tmp < ans) ans = tmp,id = t;
    }
    cout << id << " " << ans << endl;
}
