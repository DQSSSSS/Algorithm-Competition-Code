#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 150010;
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

int main() {
    for(int t = 1;;t ++) {
        system("data.exe");
        system("GG.exe");
        system("GGG.exe");
    	if(!system("fc haha.txt std.txt")) {
			cout << t << "  : AC\n";
    	}
    	else {
    		cout << t << "  : WA\n";
    		break;
    	}
    }
}
