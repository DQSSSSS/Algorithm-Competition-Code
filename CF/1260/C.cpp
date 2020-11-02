#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int a,b,k;
bool check() {
    if(a == b) return true;
    int d = __gcd(a,b);
    int x = (a-d-1)/b+1;
    if(x >= k) return false;
    return true;
}

int main() {
    int T = read();
    while(T --) {
        a = read(),b = read(),k = read();
        if(a < b) swap(a,b);
        if(!check()) puts("REBEL");
        else puts("OBEY");
    }
}
