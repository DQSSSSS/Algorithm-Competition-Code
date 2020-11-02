#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

char s[SZ];
int h[SZ],l[SZ];

map<pii,int> mp;

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 0;i < n;i ++) h[i] = 0;
        for(int i = 0;i < m;i ++) l[i] = 0;
        mp.clear();
        for(int i = 0;i < n;i ++) {
            scanf("%s",s);
            for(int j = 0;j < m;j ++)
                if(s[j] == '*') h[i] ++,l[j] ++,mp[make_pair(i,j)] = 1;
        }

        int ans = 0;
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m;j ++) {
                ans = max(ans,h[i]+l[j] - (mp[make_pair(i,j)] == 1));
            }
        }
        printf("%d\n",n+m-1 - ans);

    }
}

