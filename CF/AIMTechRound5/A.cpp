#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

char mp[233][233];

int main() {
	int n = read(),m = read();
    for(int i = 1;i <= n;i ++)
    	scanf("%s",mp[i] + 1);
    int sx = INF,sy = INF,ex = 0,ey = 0;
    for(int i = 1;i <= n;i ++)
    	for(int j = 1;j <= m;j ++)
    		if(mp[i][j] == 'B')
                sx = min(sx,i),sy = min(sy,j),
                ex = max(ex,i),ey = max(ey,j);
    int ansx = sx + ex >> 1;
    int ansy = sy + ey >> 1;
    cout << ansx << " " << ansy <<endl;
	return 0;
}
