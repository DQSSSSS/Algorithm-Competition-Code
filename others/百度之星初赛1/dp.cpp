#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 150010;
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
	for(int t = 1;;t ++){
		system("datamaker.exe");
		system("C.exe");
		system("C-std.exe");
		if(!system("fc my.txt std.txt")) {
			cout << t << " " << "AC" << endl;
		}
		else {
			cout << t <<" " << "WA" << endl;
			break;
		}

	}
}
