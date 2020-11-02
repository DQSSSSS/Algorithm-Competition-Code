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


int main() {
    int T = read();
    while(T --) {
        int n = read(),k = read();
        if(k%3 == 0) {
            n %= k+1;
            if(n < k) {
                if(n % 3 == 0) puts("Bob");
                else puts("Alice");
            }
            else if(n == k) puts("Alice");
        }
        else {
            if(n % 3 == 0) puts("Bob");
            else puts("Alice");
        }
    }
}
