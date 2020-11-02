#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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
    int n,m;
    cin >> n >> m;
    n += 11;
    int d = n / 9; n %= 9;
	cout << 1;
	for(int i = 1;i <= d - 1;i ++) cout << 0;
	for(int i = 1;i <= d;i ++) cout << 9; puts("");
	cout << 8;
	for(int i = 1;i <= d - 1;i ++) cout << 9;
	for(int i = 1;i <= d - 1;i ++) cout << 0; cout << 1;
   	return 0;
}
