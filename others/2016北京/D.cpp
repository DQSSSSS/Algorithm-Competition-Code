#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
const LL INF = 1e18 + 10;
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

const int M[] = {0,1,2,3,4,13,12,11,10,9,10,11,12,13,4,3,2,1};

pii move(int x,int y,string s) {
	if(s == "L") return make_pair(0,-1);
	if(s == "R") return make_pair(0,1);
	if(x <= 9) {
		if(s == "LL") {
			return make_pair(0,1);
		if(s == "LR") return make_pair(0,1);
		if(s == "UL") return make_pair(0,1);
		if(s == "UR") return make_pair(0,1);
	}
	if(s == "LL") {
		return make_pair(0,1);
	if(s == "LR") return make_pair(0,1);
	if(s == "UL") return make_pair(0,1);
	if(s == "UR") return make_pair(0,1);
}

void init() {
	memset(mp,0,sizeof(mp));
	for(int i = 1;i <= 4;i ++)
		for(int j = 1;j <= i;j ++)
			mp[i][j] = 1;
	for(int i = 5;i <= 8;i ++)
		for(int j = 1;j <= 9-i;j ++)
			mp[i][j] = 6;
	for(int i = 10;i <= 13;i ++)
		for(int j = 1;j <= i-9;j ++)
			mp[i][j] = 3;
	for(int i = 13;i <= 16;i ++)
		for(int j = 1;j <= 17-i;j ++)
			mp[i][j] = 2;
	for(int i = 5;i <= 8;i ++)
		for(int j = 10;j <= 18-i;j ++)
			mp[i][j] = 4;
	for(int i = 10;i <= 13;i ++)
		for(int j = 10;j <= i;j ++)
			mp[i][j] = 5;
}

int main() {
	while(~scanf("%d",&n)) {
		init();
		int now = 1;
		for(int i = 1;i <= n;i ++) {
			
		}
	}
	return 0;
}	
