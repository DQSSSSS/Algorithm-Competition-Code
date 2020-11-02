#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

bool check(ULL n) {
    for(ULL x = n * n + 1;x <= n * (n + 2);x ++)
        if(n * n * n * n % x == 0) {
        	cout << n << " " << x - n * n << endl;
        	return true;
        }
    return false;
}

int main() {
	int tot = 0;
    for(ULL i = 1;i <= 55000;i ++) {
    	if(check(i)) {
    		//cout << ++ tot << " " << i << endl;
    	}
    }


   /* int n = 10;
    int a[233] = {0};
    for(int i = 1;i <= n;i ++) {
    	int x;
    	cin >> x >> a[i];
    }

    for(int i = 1;i <= n;i ++) cout << a[i] - a[i - 1] << endl;
*/
//    while(cin >> n) {
	/*    for(int i = 2;i <= n;i ++) {
            if(n % i == 0) {
            	int t = 0;
                while(n % i == 0) n /= i,t ++;
            	cout << i << " " << t << endl;
            }
	    }
	    if(n != 1) cout << n << " " << 1 << endl;
	    puts("");*/

  //  }
}
/**
1 2
2 6
3 12
4 70
5 84
6 408
7 1170
8 2378
9 13860
10 16296
11 80782
*/
