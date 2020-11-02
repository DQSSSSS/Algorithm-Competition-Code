#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 500010;
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

int n,m,ff[SZ],tt[SZ];
map<pii,int> mp;

bool check(int delta) {
   // cout << delta << endl;
    for(int i = 1;i <= m;i ++) {
        int x = (ff[i] + delta) % n;
        int y = (tt[i] + delta) % n;
     //   cout << ff[i] << " " << tt[i] << " - " << x << " "<< y <<endl;
        if(!mp.count(make_pair(x,y))) return false;
    }
    return true;
}

bool check() {
    int x = n;
    for(int i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            if(check(n / i)) return true;
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x != 1) {
        if(check(n / x)) return true;
    }
    return false;
}


int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read()-1,y = read()-1;
        ff[i] = x;
        tt[i] = y;
        mp[make_pair(x,y)] = 1;
        mp[make_pair(y,x)] = 1;
    }
    puts(check() ? "Yes" : "No");
    return 0;
}
