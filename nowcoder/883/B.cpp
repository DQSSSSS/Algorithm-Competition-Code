#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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

char a[SZ];
map<int,int> mp;

int main() {
    int n = read();
    scanf("%s",a+1);
    int ans1 = 0,one = 0,zero = 0;
    mp[0] = 0;
    for(int i = 1,now = 0;i <= n;i ++) {
        if(a[i] == '0') now ++,zero ++;
        else now --,one ++;
        if(mp.count(now)) ans1 = max(ans1,i-mp[now]);
        if(!mp.count(now)) mp[now] = i;
    }
    cout << ans1 << " " << min(one,zero)*2 << endl;
}
