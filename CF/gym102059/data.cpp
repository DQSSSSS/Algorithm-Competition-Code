#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300100;
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

mt19937 rd(time(0));

int main() {
    freopen("G.in","w",stdout);
    int n = rd() % 10 + 1,k = rd() % 4;
    cout << n << " " << k << endl;
    for(int i = 1;i <= n;i ++) cout << rd() % 10 + 1 << " ";
}

/**
7 1
2 3 100 2 1 2 100
*/
