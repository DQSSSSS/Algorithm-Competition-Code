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
	/*freopen("B.txt","w",stdout);
	srand(time(0));
    int n = 5,q = 20;
	cout << n << " " << q<< endl;
    while(q --) {
        int opt = rand() % 3 + 1;
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        while(u == v) v = rand() % n + 1;
        int w = rand() % 2;
        int val = rand();
        if(opt == 1) cout << opt << " " << u << " " << w << " " << val << endl;
        if(opt == 2) cout << opt << " " << u << " " << w << endl;
        if(opt == 3) cout << opt << " " << u << " " << v << " " << w << endl;
    }*/
    srand(time(0));
    freopen("C.txt","w",stdout);
	int n = 10000,m = rand() % n;
    cout << n << " " << m << endl;
	for(int i = 1;i <= n;i ++)
		cout << rand() % 2;
}
