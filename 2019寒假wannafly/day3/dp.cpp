#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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
    for(int t = 1;;t ++) {
        system("data.exe");
        system("Hstd.exe");
        system("H.exe");
        if(!system("fc my.out std.out")) {
            cout << t << " AC" << endl;
        }
        else {
            cout << t << " WA" << endl;
            return 0;
        }
    }
}
