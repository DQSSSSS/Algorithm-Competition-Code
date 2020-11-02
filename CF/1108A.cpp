#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

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
    int q = read();
    while(q --) {
        int l1 = read(),r1 = read();
        int l2 = read(),r2 = read();
        if(l1 == l2 && r1 == r2) {
            cout << l1 << " " << r1 << endl;
        }
        else if(l1 == l2) {
            cout << l1 << " " << r2 << endl;
        }
        else if(r1 == r2) {
            cout << r1 << " " << l2 << endl;
        }
        else {
            cout << l1 << " " << l2 << endl;
        }
    }
}
