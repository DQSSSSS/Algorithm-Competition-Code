#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 400010;
const int INF = 1e9 + 10;
const int mod = 10007;
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
	freopen("H.in","w",stdout);
	mt19937 randint(time(0));
    int m = 20;
    string l,r;
    int ln = randint() % m + 1;
    int rn = randint() % m + 1;
    ln = rn;
    for(int i = 1;i <= ln;i ++) {
        if(i == 1) l += randint() % 9 + '1';
        else l += randint() % 10 + '0';
    }
    for(int i = 1;i <= rn;i ++) {
        if(i == 1) r += randint() % 9 + '1';
        else r += randint() % 10 + '0';
    }
    if(ln > rn) swap(l,r);
    if(ln == rn) {
        if(l > r) swap(l,r);
    }
    cout << l << endl;
    cout << r << endl;
    cout << randint() % 20 + 1 << endl;
}

