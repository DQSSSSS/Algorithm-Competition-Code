#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

map<int,int> mp;

int get(int n) {
    int ans = 0;
    while(!mp[n]) {
        if(!mp[n]) ans ++;
        mp[n] = 1;
        n ++;
        while(n%10==0) n/=10;
    }
    return ans;
}

int main() {
    int n = read();
    cout << get(n) << endl;
}
