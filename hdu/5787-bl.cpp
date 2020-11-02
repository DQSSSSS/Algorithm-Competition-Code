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

int k;

bool check(int x) {
    int num[110] = {0},n = 0;
    while(x) n ++,num[n] = x % 10,x /= 10;
    for(int i = 1;i <= n;i ++) {
		for(int j = i + 1;j <= min(n,i + k - 1);j ++)
            if(num[i] == num[j]) return false;
    }
    return true;
}

int main() {
	//freopen("in.in","r",stdin);
	//freopen("std.out","w",stdout);
	int n;
    while(cin >> n >> k) {
    	int ans = 0;
    	for(int i = 1;i <= n;i ++) {
    		if(check(i)) ans ++;
    	}
        cout<< ans << endl;
    }
}
