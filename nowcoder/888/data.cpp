#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

mt19937 rd(time(0));

int rdlr(int l,int r) { return rd()%(r-l+1)+l; }

map<pii,int> mp;

int main() {
    freopen("F.in","w",stdout);
    int n = 1000,val = 1e9;
    printf("%d\n",n);
    for(int i = 1;i <= n;i ++) {
        int x,y;
        do {
            x = rdlr(-val,val);
            y = rdlr(-val,val);
        }while(mp[make_pair(x,y)]);
        mp[make_pair(x,y)] = 1;
        printf("%d %d\n",x,y);
    }
}
