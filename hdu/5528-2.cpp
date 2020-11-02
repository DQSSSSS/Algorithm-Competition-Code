#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 10000010;
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


int main() {
    int T = read();
    while(T --) {
        int n = read();
        ULL ans1 = 0,ans2 = 0;
        for(ULL i = 1;i * i <= n;i ++) {
            if(n % i == 0) {
                ans1 += i * i; ans2 += n;
                cout << i * i << " " << -n << endl;
                if(i * i != n) {
                    ans1 += n / i * n / i,ans2 += n;
            		cout << n / i * n / i << " "<< -n << endl;
            	}
            }
        }
        printf("%llu\n",ans1 - ans2);
    }
}
