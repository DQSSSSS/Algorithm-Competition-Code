#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const LL INF = 1e18;
const LD eps = 1e-7;
const LD PI = acos(-1);

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
	for(int t = 0;;t ++) {
		system("data.exe");
		system("201B.exe");
		system("201B-std.exe");
		if(!system("fc B.out Bstd.out")) {
			cout << t << " : AC" << endl;
		}
		else {
			cout << t << " : wa" << endl;
			break;
		}
	}
}
