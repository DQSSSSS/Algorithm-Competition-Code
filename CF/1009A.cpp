#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

map<int,int> mp[2];

int main() {
    int n = read();
    mp[0][0] = 1;
    for(int i = 1,x = 0;i <= n;i ++) {
        int d = read();
        x ^= d;
        mp[i%2][x] ++;
    }

    LL ans = 0;
    for(int i = 0;i < 2;i ++)
        for(auto it : mp[i]) {
            LL x = it.second;
            ans += x * (x - 1) / 2;
        }
    cout << ans << endl;
}
