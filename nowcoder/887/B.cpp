#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

int a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = n;i >= 0;i --) a[i] = read();

        if(n >= 3) puts("No");
        else {
            if(n <= 1) puts("Yes");
            else if(n == 2 && 1ll * a[1] * a[1] - 4ll * a[2] * a[0] >= 0) puts("No");
            else puts("Yes");
        }
    }
}
