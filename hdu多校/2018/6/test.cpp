#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

int randint() {
	return rand() << 16 | rand();
}

int main() {
	freopen("233.txt","w",stdout);
    srand(time(0));
    int T = 10;
    cout << T << endl;
    while(T --) {
		int n = 1e5,m = 2e5;
		cout << n << " " << m << endl;
		for(int i = 2;i <= n;i ++)
			printf("%d %d %d\n",randint() % (i - 1) + 1,i,randint() % (n + 1));
		for(int i = n;i <= m;i ++) {
			int x = randint() % n + 1;
			int y = randint() % n + 1;
			int v = randint() % (n + 1);
			printf("%d %d %d\n",x,y,v);
		}
	}

}
